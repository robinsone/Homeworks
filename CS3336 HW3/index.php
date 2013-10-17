<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" xml:lang="en-US" lang="en-US">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Eric Robinson | CS3336 HW3</title>

<link rel="stylesheet" href="./css/hw3.css" type="text/css" media="screen" />
<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>

<!-- ========= YOU NEED TO PUT links to jQuery, jQuery UI, EXTRA CSS files from jQuery UI =========== -->

<script type="text/javascript">
<![CDATA[
	$(document).ready(function() {

	//  ------------- YOUR jQuery Code goes HERE!! 
	//  ------ You can use .get() requests to  file process.php
    function isValidEmailAddress(emailAddress) {
    var pattern = new RegExp(/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/);
    return pattern.test(emailAddress);
    }

	$('#find').click(function () {
		if(isValidEmailAddress($('#search').val())) { /* do stuff here */ 
            $('#result').addClass("hide");
    		$('#loading').removeClass("hide");

            var data = 'data=' + $('#search').val();
            $.ajax({
                url: "process.php",  
                type: "GET",        
                data: data,
                dataType: 'json',     
                cache: false,
                success: function (html) {  
                    $('#result').html(html);
                    $('#loading').addClass("hide");
                    $('#result').removeClass("hide");
                }       
            });
        } else {
            $('#result').html('<span class="error">Invalid email address.</span>');
        }

	});

	});
]]>
</script>

</head>

<body>
<div id="mainbody">

<!--           YOUR HTML or PHP code goes here -->
<div>
<p>
Email: <input id="search" type="text" value="" /> <a href="#" id="find">Find</a>
</p>
</div>
<div id="loading" class="hide">
<img src="images/loading.gif" alt="" />
</div>
<div>
    <p id="result">

    </p>
</div>
</div>
</body>
</html>
