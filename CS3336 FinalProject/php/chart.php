<?php


 session_start();
 //include('functions.php');
 // Create some random text-encoded data for a line chart.
//$day = dateToDays('04-22-1988');



$now = time();
$dob = time();
$curr = time();
if(!empty($_POST['dob'])){
  $dob = strtotime(str_replace('-', '/',$_POST['dob']));
}
if(!empty($_POST['curr'])){
  $curr = strtotime(str_replace('-', '/',$_POST['curr']));
}


$days = $curr - $dob;
$days = intval(floor($days/(60*60*24)));

drawGraph($days,$curr);

function drawGraph($days,$curr){
  header('content-type: image/png');
  $url = 'http://chart.apis.google.com/chart';


  $day = $days;
/** 
Physical 
**/
$chd = 't:';

for ($i = $day-10; $i <= $day+10; ++$i) {
  $data = sin((2*pi()*$i)/23);  
  $chd .= $data . ',';
}

$chd = substr($chd, 0, -1);

/** 
Emotional 
**/
$chd2 = '|';

for ($i = $day-10; $i <= $day+10; ++$i) {
  $data = sin((2*pi()*$i)/28);
  $chd2 .= $data . ',';
}

$chd2 = substr($chd2, 0, -1);

/** 
intellectual 
**/
$chd3 = '|';

for ($i = $day-10; $i <= $day+10; ++$i) {
  $data = sin((2*pi()*$i)/33);
  $chd3 .= $data . ',';
}

$chd3 = substr($chd3, 0, -1);

/**
Date Scale
**/
$datescale = "0:|";
// $date = '12-02-2012';
// $date = str_replace('-', '/',$date);
//$date = date_format('04-22-1988', 'Y/m/d');
for($i = -10; $i <=10; $i+=2){
  $temp = strtotime($i.' day', $curr);
  $datescale .= date('M j',$temp) . '|';
}

$datescale = substr($datescale, 0, -1);

// Add data, chart type, chart size, and scale to params.
$chart = array(
  'cht' => 'lc',
  'chs' => '600x400',
  'chds' => '-1,1',
  'chm' => 'H,ff9900,0,0,1.0|V,ff9900,0,10,1',
  'chma' => '10,10,10,10|100,350',
  'chg' => '5,12.5,2,5,0,0',
  'chdl' => 'Physical: '.intval(100*sin((2*pi()*$day)/23)) .'|Emotional: '.intval(100*sin((2*pi()*$day)/28)) .'|intellectual: '.intval(100*sin((2*pi()*$day)/33)),
  'chco' => 'ff0000,00ff00,0000ff',
  'chxt' => 'x,y',
  'chxr' => '1,-100,100,20',
  'chxl' => $datescale,
  'chd' => $chd . $chd2 . $chd3);

$query = http_build_query($chart);

$fullurl = $url."?".$query;

$context = stream_context_create(

  array(
    'http' => array(
      'method' => 'GET',
      'header' => "Content-type: application/x-www-form-urlencoded\r\n" .
      "Content-length: 0",

      )
    )
  ); 


$ch = curl_init ($fullurl);
curl_setopt($ch, CURLOPT_HEADER, 0);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($ch, CURLOPT_BINARYTRANSFER,1);
$raw=curl_exec($ch);
curl_close ($ch);
$fp = fopen('../img/chart.png','w');
fwrite($fp, $raw);
fclose($fp);


$ret = fopen($fullurl, 'r', false, $context);
fpassthru($ret);
}

?>