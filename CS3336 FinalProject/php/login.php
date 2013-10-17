<?php

include('functions.php');

session_start();
	// You need to set your own parameters!!
define('MYSQL_SERVER', 'localhost:3306');
define('MYSQL_USER', 'erobin258791_db');
define('MYSQL_DB', 'erobin258791_db');
define('MYSQL_PASSWORD', '7d0H8hWG');

	// You'd need to activate it once you have operational system
$GLOBALS['DB'] = mysql_connect(MYSQL_SERVER, MYSQL_USER, MYSQL_PASSWORD) or die ("Cannot connect to the MySQL server: \n" . mysql_error());
mysql_select_db(MYSQL_DB, $GLOBALS['DB']) or die ('Cannot select MySQL database');


$HTML['email'] = "";
$HTML['dob'] = "";


foreach($HTML as $key=> &$value) {
	$value=utf8HTML(getRequest($key, true, 'post'));
}
$HTML['id'] = "";
$HTML['ip'] = getRealIpAddr();


connect("INSERT INTO project (email, dob, ip) VALUES ('".$HTML['email']."', '".$HTML['dob']."' , '".$HTML['ip']."')");

set_SESSION("id", mysql_insert_id());
set_SESSION("email", $HTML['email']);
set_SESSION("dob", $HTML['dob']);
set_SESSION("ip", $HTML['ip']);


return true;



?>