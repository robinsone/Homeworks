
$(document).ready(function() {
        var emailregex = /^([a-zA-Z0-9_\.\-\+])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        var dateregex = /(0[1-9]|1[012])[\-.](0[1-9]|[12][0-9]|3[01])[\-.](19|20)\d\d/;
        var dob;
        var current = '12-02-2012';
        
        $( "#datepicker" ).datepicker({ dateFormat: 'mm-dd-yy' });
        //$( "#datepicker2" ).datepicker({ dateFormat: 'mm-dd-yy' });
        $( "#datepicker2" ).datepicker({
            showOn: "button",
            buttonImage: "img/cal.png",
            dateFormat: 'mm-dd-yy',
            buttonImageOnly: true
        });
        

        $("#datepicker2").val("12-02-2012");

        $("#test").click(function(){
          updateChart();
        });


        $( "#btnLogin").click(function() {
                $('#error').empty();
                if (!emailregex.test($('#email').val()) && !dateregex.test($('#datepicker').val())) {
                        $("#error").text('Invalid Email and Date of Birth');
                        return false;
                }
                else if(!dateregex.test($('#datepicker').val())){
                        $('#error').text('Invalid Date of Birth');
                        return false;
                }
                else if(!emailregex.test($('#email').val())){
                        $("#error").text('Invalid Email');
                        return false;
                }

                $("#dob").text('Date of Birth: ' + $('#datepicker').val());
                var dataString = 'email='+ $('#email').val() + '&dob=' + $('#datepicker').val(); 
                dob = $('#datepicker').val();
                $.ajax({  
                        type: "POST",  
                        url: "php/login.php",  
                        data: dataString,  
                        success: function() { 
                               $('#login').addClass("hide");
                               $('#chart').removeClass("hide");
                               updateChart();
                                // $('#contact_form').html("<div id='message'></div>");  
                                // $('#message').html("<h2>Contact Form Submitted!</h2>")  
                                // .append("<p>We will be in touch soon.</p>")  
                                // .hide()  
                                // .fadeIn(1500, function() {  
                                //         $('#message').append("<img id='checkmark' src='images/check.png' />");  
                                // });

      
                        }  
                }); 
        });


$('#datepicker2').change(function() {
  current = $('#datepicker2').val();
  updateChart();
});

function updateChart(){
  

  $.ajax({  
    type: "POST",  
    url: "php/chart.php",  
    data: 'dob=' + dob + '&curr=' + current,  
    success: function() { 
     $("#googleimage").attr("src", "img/chart.png?timestamp=" + new Date().getTime());
    }  
    });
}

});



