<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" dir="ltr" xml:lang="en-US" lang="en-US">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>Eric Robinson | CS3336 HW2</title>

    <link rel="stylesheet" href="./css/hw2.css" type="text/css" media="screen" />
    <link href="css/ui-lightness/jquery-ui-1.9.0.custom.css" rel="stylesheet" />

    <!--           YOU NEED TO PUT links to jQuery, jQuery UI, EXTRA CSS files from jQuery UI -->
    <script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
    <script type="text/javascript" src="js/jquery-ui-1.9.0.custom.min.js"></script>
    <script type="text/javascript">
//  You might want to use CDATA statement!
    /*<![CDATA[*/
        $(document).ready(function() {

            $(function() {
                $( "#datepicker" ).datepicker({
                    showOn: "button",
                    buttonImage: "images/calendar.gif",
                    buttonImageOnly: true,
                    dateFormat: "mm-dd-yy"
                });
            });

            function ajaxFunction(){
                var values = $("input[type='checkbox']:checked").map(function () {
                    return this.value;
                }).get();

                var data = 'check="'+values+'"&date="'+$("#datepicker").val()+'"';
                $.ajax({
                    url: "process.php",  
                    type: "GET",        
                    data: data,     
                    cache: false,
                    success: function (html) {  
                        $('#lucky').html(html);
                    }       
                });
            }
            $(function() {
                $('#tooltip').tooltip();
            });

            $("input[type='checkbox']").click(ajaxFunction);
            $("#datepicker").change(ajaxFunction);
            $("#datepicker").keyup(ajaxFunction);

        });
        /*]]>*/
        </script>
</head>
<body>
    <div id="mainbody">

        <!--           YOUR HTML code goes here -->
    <div class="leftside">
        <h3>Pick Numbers:</h3>
        <?php
            $i = 1;
            while ($i <= 9) {
              echo '<label class="checked"><input type="checkbox" value="'.$i.'" />'.$i.'</label><br />';
            $i = $i+1; # code...
            }
        ?>
    </div>
    <div class="rightside">
        <h3>Pick a date:</h3>
        <p>
            <input id="datepicker" type="text" title="Please pick a date"/>
        </p>
        <div id="lucky" class="top">
            <br />
        </div>
        <p id="tooltip" title="calculates your lucky number" class="top">
            This script calculates you lucky number
            <img src="images/info.jpg" alt="" />
        </p>
    </div>

</div>
</body>
</html>