<?php
// HAS TO BE IN THE ROOT DIRECTORY OF THE SITE!!!
set_time_limit(0); 
error_reporting(E_ALL);
ini_set('session.use_cookies',1);
ini_set('session.use_only_cookies',1);
ini_set('session.use_trans_sid',0);
ini_set('session.gc_maxlifetime',7200); // 2 hour session!
ini_set('default_charset', 'UTF-8');

mb_internal_encoding('UTF-8');
mb_http_output('UTF-8');

@set_magic_quotes_runtime(0);

// Session should start here!
session_start();

// So templates can be included
define ('TMPL_DIR', './templates');
define ('SECURE_KEY', '===PUT-YOUR-KEY-HERE==='); //Used in encrypt/decrypt functions!

// You need to set your own parameters!!
define('MYSQL_SERVER', 'localhost:3306');
define('MYSQL_USER', 'erobin258791_db');
define('MYSQL_DB', 'erobin258791_db');
define('MYSQL_PASSWORD', '7d0H8hWG');

// You'd need to activate it once you have operational system
$GLOBALS['DB'] = mysql_connect(MYSQL_SERVER, MYSQL_USER, MYSQL_PASSWORD) or die ("Cannot connect to the MySQL server: \n" . mysql_error());
mysql_select_db(MYSQL_DB, $GLOBALS['DB']) or die ('Cannot select MySQL database');


//require_once('./includes/functions.inc.php');
?>