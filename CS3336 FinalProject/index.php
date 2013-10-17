<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" xml:lang="en-US" lang="en-US">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Eric Robinson | CS3336 Project</title>
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script>
<script src="//ajax.googleapis.com/ajax/libs/jqueryui/1.9.2/jquery-ui.min.js"></script>

<!-- <script type="text/javascript" src="https://www.google.com/jsapi"></script>
<script type="text/javascript">google.load('visualization', '1', {packages: ['corechart']});</script> -->
<script src="./jquery/project.js"></script>

<link rel="stylesheet" href="./css/project.css" type="text/css" media="screen" />
<link rel="stylesheet" href="http://code.jquery.com/ui/1.9.2/themes/base/jquery-ui.css" />





</head>

<body>
	<?php 
		session_start();
		include('php/functions.php');
	?>	
	<div id="login" class="
	<?php 
		if(!empty($_SESSION)){
			echo "hide";
		}
	?>	
	">
		<div id="inputArea">
			
			<p>
				
				<label for="email">Email</label>
				<input type="text" id="email" name="email" value="" />
				<!-- <span><?php echo $HTML['email_error'];?></span> -->

				<label for="dob">Date of Birth (mm-dd-yyyy)</label>
				<input id="datepicker" type="text" value="" />
				<!-- <span><?php echo $HTML['city_error'];?></span> -->
				


				<div id="error"></div>
				<br />
				<input id="btnLogin" class="submit" type="submit" value="Login" />
				<input type="hidden" name="submitted" value="yes" />
			</p>
			
		</div>

		
	</div>
	<div id="chart" class="
	<?php 
	
		if(empty($_SESSION)){
			echo "hide";
		}
	?>	
	">
		<div id="topbanner">
			<form action="php/logout.php" method="post">
				<input type="submit" value="Logout" />
			</form>
		</div>
		<div id="sidebar">
			<p id="dob">Date of Birth: <?php echo get_SESSION('dob'); ?></p>
			<label for="dob">Select a Date:</label>
			<input id="datepicker2" type="text" value="" />
		</div>
		<div id="graph">
			<div class="arrow"><img src="img/leftarrow.png"></div>
			<div>
				<img width='600' id="googleimage" height='400' src='./img/chart.png'>
			<div class="arrow"><img src="img/rightarrow.png"></div>
		</div>
	</div>
	
</body>
</html>