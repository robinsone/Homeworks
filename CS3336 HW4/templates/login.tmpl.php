<?php if (!defined('TMPL_DIR')) return; ?>

<form id="inputArea" action="index.php?action=login" method="post">
	<p>
        <label for="email">Email</label>
        <input type="text" name="email" value="<?php echo $HTML['email'];?>" />
   
        <label for="password">Password</label>
        <input type="password" name="password" value="<?php echo $HTML['password'];?>" />
    
        <span><?php echo $HTML['login_error'];?></span>
    
	<input class="submit" type="submit" value="Login" />
	</p>
	<div class="user">
		New User?  <a href="index.php?action=signup">Sign up here</a>
	</div>
	<p>	
	<input type="hidden" name="submitted" value="yes" />
	</p>
</form>
