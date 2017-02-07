<?php session_start(); ?>
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
		<p class="insc">Inscription / Connection</p>
		<form action="users.php" method="post">
		<input type="text" value="Login" class="login" name="login">
		<input type="text" value="Password" class="Password" name="password">
		<br/>
		<br/>
		<input type="text" value="Adresse mail" class="mail" name="mail">
		</br>
		</br>
		<input type="submit" value="Inscription" class="but">
		</form>
		
	</div>
	<div class="footer">
	</div>
</body>
</html>