<?php

function getRealIpAddr()
{
	if (!empty($_SERVER['HTTP_CLIENT_IP']))
  //check ip from share internet
	{
		$ip=$_SERVER['HTTP_CLIENT_IP'];
	}
	elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
  //to check ip is pass from proxy
	{
		$ip=$_SERVER['HTTP_X_FORWARDED_FOR'];
	}
	else
	{
		$ip=$_SERVER['REMOTE_ADDR'];
	}
	return $ip;
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

// function dateToDays ($dob=''){
// 	 $now = time();
//      $dob = strtotime($dob);
//      $days = $now - $dob;
//      return intval(floor($days/(60*60*24)));
// }
?> 