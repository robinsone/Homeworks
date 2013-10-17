<?php

// Put any functions you want!
function file_get_contents_curl($url) {
    $ch = curl_init();

    curl_setopt($ch, CURLOPT_AUTOREFERER, TRUE);
    curl_setopt($ch, CURLOPT_HEADER, 0);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, TRUE);       

    $data = curl_exec($ch);
    curl_close($ch);

    return $data;
}

function firstlast($text){
	$result = "";
	$temp = explode(' ', $text);
	for($i = 1; $i < count($temp); $i++){
		$result .= $temp[$i] . " ";
	}
	return  trim($result) . " " . trim($temp[0]); 
}

function searching($key){
	$file = fopen(FACULTY_FILE, 'r');
	$email_regex = '/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/'; 
	

	if(preg_match($email_regex, $key)){
		while (($line = fgetcsv($file)) !== FALSE) {  
			list($email, $name, $department) = $line;

		    if($key == $email) { //$key
		    	return "<span>Name:</span> $name<br /><span>Area:</span> $department<br /><span>Email:</span> $email<br />\n";
		    }
		}
		return '<span class="error">No results</span>';
	}else{
		return '<span class="error">Invalid email address.</span>';
	}
}

function buildCSV(){
	$html = file_get_contents_curl(FACULTY_WEB);

$matches;
$table_regex = '/<td[^>]*>(.*?)<\/td>/';
preg_match_all($table_regex, $html, $matches);

$clean = array();
$email = "";
$name = "";
$department = "";

for($i = 3; $i < count($matches[0]); $i++){
	$text = strip_tags($matches[0][$i]);
	
	if(($i % 3) == 0){
		$text = preg_replace('(\(.*\))', '', $text);
		$text = firstlast($text);
		$text = str_replace(",", "", $text);
		$name = $text;
	}
	if(($i % 3) == 1){
		$text = preg_replace('(\(.*\))', '', $text);
		$text = str_replace(",", "", $text);
		$department = $text;
	}
	if(($i % 3) == 2){
		$text = str_replace("*", "@uwo.ca", $text);
		$email = $text;
		array_push($clean, $email, $name, $department);
	}
}

$final = "";
for($i = 0; $i < count($clean); $i++){
	$final .= "\"" . $clean[$i++] . "\", \"" . $clean[$i++] . "\", \"" . $clean[$i] . "\"\n";
}


file_put_contents(FACULTY_FILE, $final);
}
?>