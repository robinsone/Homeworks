<?php
require_once('./includes/config.inc.php');
require_once('./includes/functions.inc.php');

sleep(2); // Don't touch this!

$key = (string)$_GET['data'];



if (file_exists(FACULTY_FILE)) {
	echo json_encode(searching($key));
	
} else {
	buildCSV();
	echo json_encode(searching($key));
}





//print_r($clean);
// for($i = 0; $i < 20; $i++){
// }

//var_dump($matches);
// Do any magic you want!

?>