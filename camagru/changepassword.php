<?php session_start();
	include "function.php";
	if (!(secure_db($_GET['login']) && secure_db($_GET['email']) && secure_db($_GET['hash'])))
	{
		$message = "An error was detected, try to click on the link";
		echo "<script type='text/javascript'>alert('$message');</script>";
    	echo "<script language='javascript'>document.location.href='index.php'</script>";
    	exit();
	}
?>
<html>
	<head>
		<?php include "install.php"; ?>
		<link rel="stylesheet" href="style.css" />
        <meta charset="utf-8" />
        <title>Camagru</title>

    </head>

<body class="back">
	<center><div class="header">
		<p class="camagru">Camagru</p>
	</div></center>
	<div class="inscription">
		<form  action="passchanged.php" method="post">
		<p class="insc">Restore password</p>
		<input type="text" value="Login" class="login" name="login">
		</br>
		</br>
		<input type="text" value="New password" class="mail" name="mail">
		</br>
		</br>
		<input type="submit" value="Restore" class="but">
		</form>		
	</div>
	<div class="footer">
	</div>
</body>
</html>
