<?php
//function mycount ($str) {

/*
	You do your programming here.
	You need to find $lucky  variable (lucky number).
	Example how you can do it:
*/
	//parse input
	$number = str_replace('"', '', str_replace('-','',$_GET['date']) . str_replace(',', '', $_GET['check']));
	
	
	$result = luckyNumber($number);
	$result = (empty($result)) ? 'Error: Invalid Number' : 'Your lucky number is '.$result;
	echo $result;


	function luckyNumber($num){
		if(empty($num) || $num == 0){
			return null;
		}
		$result = $num;
		do{
			$arr = str_split((string)$result);
			$result = 0;
			foreach ($arr as $key => $value) {
				$result += (int)$value;
			}
		}while($result >9 || $result<1);
		return $result;
	}

?>