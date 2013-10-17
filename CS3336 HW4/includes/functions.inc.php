<?php

function process_script() {
	

	$action=strtolower(getRequest('action',true,'get'));
	$accepted_actions='login,signup,account,edit,logout,cancel';

	//print_r($_SESSION);
	//print_r(get_SESSION('userid'));
	// Analyze accepted actions here
	//echo $HTML['country_options_escape'];
	//limit only to login!

	if(empty($action)) {$action='login';}
	if(empty($_SESSION['userid']) and $action!='signup'){
		$action='login';
	}elseif(!empty($_SESSION['userid']) and ($action =='login' or $action == 'signup')){
		$action='account';
	}

	return get_template($action, $action()); 
}



function set_header($action=null) {
	$url = (empty($action)) ? urlhost() : urlhost().'?action='.$action;
	header('Location: '. $url );
	exit();
}


function &account() {
	
	$HTML=array();

	return $HTML;
}


function &cancel() {
	// You need to implement it.
	// Given version is for test purposes only!
	
	mysql_query('DELETE FROM users WHERE id="'. get_SESSION("userid") . '"');
	
	session_destroy();
	set_header('login'); 
	exit();
}


function &logout() {
	// You need to implement it	
	// Given version is for test purposes only!
	session_destroy();
	set_header('login'); 
	exit();
}


function &login(){
	// You need to implement Password Encryption or Reset	
	$HTML=array();
	$HTML['email']='';
	$HTML['password']='';
	
	$HTML['login_error']=''; //Reset Error

	if (getRequest('submitted',true,'post') !=='yes') {return $HTML;}
	
	foreach($HTML as $key=> &$value) {
		$value=getRequest($key, true, 'post');
	}
	
	//print_r(encrypt('P@ssw0rd') . "           password         : " . decrypt('P@ssw0rd'));

	$userID = array();
	if (empty($HTML['email'])) {
		$HTML['login_error'] = 'Email Cannot be empty';
	}
	elseif (empty($HTML['password'])) { 
		$HTML['login_error'] ='Password cannot be empty'; //Security measure!
	}
	elseif (filter_var($HTML['email'],FILTER_VALIDATE_EMAIL) ===false) {
		$HTML['login_error'] ='Invalid Email Address';
	}
	else {
		$userID = validate_record($HTML['email'],$HTML['password']);
		
		if (empty($userID)) {
			$HTML['login_error'] ='Account not found or invalid Email/Password';
		}
	}

	
	if (empty($HTML['login_error'])) {
		// You need to set session data here
		
		set_SESSION("userid", $userID['id']);
		set_SESSION("email", $userID['email']);
		set_SESSION("city", $userID['city']);
		set_SESSION("country", $userID['country']);
		set_header('account'); //If no errors -> go to account
		exit();
	}
	
	

	return $HTML;
}



function &edit() {
	// You need to implement it	
	// Code below is for test purposes only!
	
	$HTML=array();
	$HTML['email']='';
	$HTML['password']='';
	$HTML['confirm_password']='';
	$HTML['city'] = '';
	$HTML['countryID'] = '';
	$HTML['country_options_escape'] = getContries();
	$HTML['email_error']=''; //Reset Error
	$HTML['confirm_password_error']=''; //Reset Error
	$HTML['city_error']=''; //Reset Error
	$HTML['countryID_error']=''; //Reset Error
	$HTML['signup_error']=''; //Reset Error

	if (getRequest('submitted',true,'post') !=='yes') {
		
		$HTML['country_options_escape'] = getContries();
		$HTML['email'] = get_SESSION('email');
		$HTML['city'] = get_SESSION('city');
		return $HTML;
	}
	
	
	//print_r($_POST);
	// foreach($_POST as $key => $value)
	// {
	//     $HTML[$key] = $value;
	// }
	foreach($HTML as $key=> &$value) {
		$value=getRequest($key, true, 'post');
	}
	
	$userID = array();
	if (empty($HTML['email'])) {
		$HTML['email_error'] = 'Email Cannot be empty';
	}
	if (filter_var($HTML['email'],FILTER_VALIDATE_EMAIL) ===false) {
		$HTML['email_error'] ='Invalid Email Address';
	}
	if (!empty($HTML['password']) and empty($HTML['confirm_password'])) {
		if (!preg_match('((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})', $HTML['password'])) {
			$HTML['confirm_password_error'] = 'Passwords have to be 6-20 chars and more secure!';
		}else{  
			$HTML['confirm_password_error'] ='Confirm password cannot be empty'; //Security measure!
		}
	}
	if ($HTML['password'] != $HTML['confirm_password']){
		$HTML['confirm_password_error'] = 'Passwords do not match';
	}
	if (empty($HTML['city'])) { 
		$HTML['city_error'] ='City cannot be empty'; //Security measure!
	}
	if (empty($HTML['countryID'])) { 
		$HTML['countryID_error'] ='Country cannot be empty'; //Security measure!
	}
	if (filter_var($HTML['city'],FILTER_SANITIZE_SPECIAL_CHARS) ===false) {
		$HTML['city_error'] ='Invalid city input';
	}

	
	if (empty($HTML['signup_error']) and empty($HTML['city_error']) and empty($HTML['countryID_error']) and empty($HTML['confirm_password_error'])) {
		if(empty($HTML['password'])){
			connect("UPDATE users SET email='". $HTML['email'] ."', city='". $HTML['city'] ."', country='". $HTML['countryID'] ."' WHERE id='". get_SESSION('userid') ."'");
		
		}
		else{
		connect("UPDATE users SET email='". $HTML['email'] ."', password='". encrypt($HTML['password']) ."', city='". $HTML['city'] ."', country='". $HTML['countryID'] ."' WHERE id='". get_SESSION('userid') ."'");
		}
		set_SESSION("email", $HTML['email']);
		set_SESSION("city", $HTML['city']);
		set_SESSION("country", $HTML['countryID']);
		set_header('account'); //If no errors -> go to account
		exit();
	}
	
	
	$HTML['country_options_escape'] = getSContries($HTML['countryID']);;
	return $HTML;

} 


function &signup($edit=false){
	// You need to implement it	
	// Code below is for test purposes only!

	$HTML=array();
	$HTML['email']='';
	$HTML['password']='';
	$HTML['confirm_password']='';
	$HTML['city'] = '';
	$HTML['countryID'] = '';
	$HTML['country_options_escape'] = getContries();
	$HTML['email_error']=''; //Reset Error
	$HTML['confirm_password_error']=''; //Reset Error
	$HTML['city_error']=''; //Reset Error
	$HTML['countryID_error']=''; //Reset Error
	$HTML['signup_error']=''; //Reset Error

	if (getRequest('submitted',true,'post') !=='yes') {
		
		$HTML['country_options_escape'] = getContries();
		return $HTML;
	}
	
	print_r($_POST);
	// foreach($_POST as $key => $value)
	// {
	//     $HTML[$key] = $value;
	// }
	foreach($HTML as $key=> &$value) {
		$value=utf8HTML(getRequest($key, true, 'post'));
	}
	
	$userID = array();
	if (empty($HTML['email'])) {
		$HTML['email_error'] = 'Email Cannot be empty';
	}
	if (empty($HTML['password'])) { 
		$HTML['confirm_password_error'] ='Password cannot be empty'; //Security measure!
	}
	if (empty($HTML['confirm_password'])) { 
		$HTML['confirm_password_error'] ='Confirm password cannot be empty'; //Security measure!
	}
	if (!preg_match('((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})', $HTML['password'])) {
		$HTML['confirm_password_error'] = 'Passwords have to be 6-20 chars and more secure!';
	} 
	if ($HTML['password'] != $HTML['confirm_password']){
		$HTML['confirm_password_error'] = 'Passwords do not match';
	}
	if (empty($HTML['city'])) { 
		$HTML['city_error'] ='City cannot be empty'; //Security measure!
	}
	if (empty($HTML['countryID'])) { 
		$HTML['countryID_error'] ='Country cannot be empty'; //Security measure!
	}
	if (filter_var($HTML['email'],FILTER_VALIDATE_EMAIL) ===false) {
		$HTML['email_error'] ='Invalid Email Address';
	}
	// FILTER_SANITIZE_SPECIAL_CHARS
	if (filter_var($HTML['city'],FILTER_SANITIZE_SPECIAL_CHARS) ===false) {
		$HTML['city_error'] ='Invalid city input';
	}
	
	set_SESSION("country", $HTML['countryID']);
	$arr = connect('Select * from users where email="' . $HTML['email'] . '"');
	$count = count($arr);
	if($count > 0){
		$HTML['signup_error'] = "That email already exists";
	}
	$HTML['encrypted'] = encrypt($HTML['password']);
	
	if (empty($HTML['signup_error']) and empty($HTML['city_error']) and empty($HTML['countryID_error']) and empty($HTML['confirm_password_error'])) {
		connect("INSERT INTO users (email, password, city, country) VALUES ('".$HTML['email']."', '".encrypt($HTML['password'])."' , '".$HTML['city']."' , '".$HTML['countryID']."')");
		print_r($arr);
		set_SESSION("userid", mysql_insert_id());
		set_SESSION("email", $HTML['email']);
		set_SESSION("city", $HTML['city']);
		set_SESSION("country", $HTML['countryID']);
		set_header('account'); //If no errors -> go to account
		exit();
	}
	
	
	$HTML['country_options_escape'] = getSContries($HTML['countryID']);
	return $HTML;
	// $HTML=array();
	// $HTML['country_options_escape'] = getContries();
	// return $HTML;
}


function validate_record($email, $password=NULL, $userID=null) {
	
	$arr = connect('Select * from users where email="' . $email . '" and password="' . encrypt($password) . '"');
	if(!empty($arr)){
		return $arr[0];
		
	}
	return array();
	

	// You need to implement it. For test purposes returns true always.
	
}



function get_SESSION($key) {
	return ( !isset($_SESSION[$key]) ) ? NULL : decrypt($_SESSION[$key]);
}


function set_SESSION($key, $value='') {
	if (!empty($key)) {
		$_SESSION[$key]=encrypt($value);
		return true;
	}
	return false;
}



function util_getenv ($key) {
		return ( isset($_SERVER[$key])? $_SERVER[$key]:(isset($_ENV[$key])? $_ENV[$key]:getenv($key)) );
}


function host ($protocol=null) {
	$host = util_getenv('SERVER_NAME');
	if (empty($host)) {	$host = util_getenv('HTTP_HOST'); }
	return (!empty($protocol)) ? $protocol.'//'.$host  : 'http://'.$host;
}


function urlhost ($protocol=null) {
	return host($protocol).$_SERVER['SCRIPT_NAME'];
}


function get_template($file, &$HTML=null){
	// You might want to modify $HTML data before processing templates
	// .....................
		$content='';
		ob_start();
			if (@include(TMPL_DIR . '/' .$file .'.tmpl.php')):
			$content=ob_get_contents();
		endif;
		ob_end_clean();
		return $content;
}

	
function getRequest($str='', $removespace=false, $method=null){
	if (empty($str)) {return '';}
  		switch ($method) {
			case 'get':
				$data=(isset($_GET[$str])) ? $_GET[$str] : '' ;
				break;
			case 'post':
				$data=(isset($_POST[$str])) ? $_POST[$str] : '';
				break;
				
			default:
				$data=(isset($_REQUEST[$str])) ? $_REQUEST[$str] : '';
		}
 		
		if (empty($data)) {return $data;}
		
		
		if (get_magic_quotes_gpc()) {
			$data= (is_array($data)) ? array_map('stripslashes',$data) : stripslashes($data);	
		}

		if (!empty($removespace)) {
			$data=(is_array($data)) ? array_map('removeSpacing',$data) : removeSpacing($data);
		}

		return $data;
	}


	
function removeSpacing($str) {
		return trim(preg_replace('/\s\s+/', ' ', $str));
}
	
	
function utf8HTML ($str='') {
  	   	return htmlentities($str, ENT_QUOTES, 'UTF-8', false); 
}
	



function encrypt($text, $SALT=null) {
	// You need to implement your own encrypt function
	// .....................
    //return base64_encode($text);
	$key = '!QWERTY123';
	return base64_encode(mcrypt_encrypt(MCRYPT_RIJNDAEL_256, md5($key), $text, MCRYPT_MODE_CBC, md5(md5($key))));

    
} 

    
function decrypt($text, $SALT=null) { 
	// You need to implement your own decrypt function
	// .....................
	//return base64_decode($text);
   	$key = '!QWERTY123';
    return rtrim(mcrypt_decrypt(MCRYPT_RIJNDAEL_256, md5($key), base64_decode($text), MCRYPT_MODE_CBC, md5(md5($key))), "\0");;	
}  

function getContries(){
	
	$arr = connect('select * from countries');
	$strContries = "<option value=''>Please Select</option>\n";
	for($i = 0; $i < count($arr); $i++) {
		$row = $arr[$i];
		if($row['active'] != "NO"){
			if(get_SESSION('country') == $row['countryID']){
				$strContries .= "<option value='" . $row['countryID'] . "' selected='selected'>" . $row['country'] . "</option>\n";
			}else{
				$strContries .= "<option value='" . $row['countryID'] . "'>" . $row['country'] . "</option>\n";
			}
		}
	}

	return $strContries;
}

function getSContries($selected){
	
	$arr = connect('select * from countries');
	$strContries = "<option value=''>Please Select</option>\n";
	for($i = 0; $i < count($arr); $i++) {
		$row = $arr[$i];
		if($row['active'] != "NO"){
			if($selected == $row['countryID']){
				$strContries .= "<option value='" . $row['countryID'] . "' selected='selected'>" . $row['country'] . "</option>\n";
			}else{
				$strContries .= "<option value='" . $row['countryID'] . "'>" . $row['country'] . "</option>\n";
			}
		}
	}

	return $strContries;
}

function connect( $query ){
	
	$result = mysql_query($query, $GLOBALS['DB']);
	
	if(!$result){
		$message  = 'Invalid query: ' . mysql_error() . "\n";
	    $message .= 'Whole query: ' . $query;
	    die($message);
	}

	$result_array = array();
	while($row = mysql_fetch_assoc($result))
	{
	    $result_array[] = $row;
	}
	

	mysql_free_result($result); 
	return $result_array;
}

?>