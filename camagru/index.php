<?php session_start(); ?>
<html>
	<head>
		<?php include "config/setup.php"; ?>
		<link rel="stylesheet" href="style.css" />
        <meta charset="utf-8" />
        <title>Camagru</title>
    </head>

<body class="back">
	<center><div class="header">
		<p class="camagru">Camagru</p>
	</div></center>
	<div class="inscription">
		<p class="insc">Connection</p>
		<form action="connection.php" method="post">
		<input type="text" value="Login" class="login" name="login">
		<input type="text" value="Password" class="Password" name="password">
		<br/>
		<br/>
		<input type="text" value="Adresse mail" class="mail" name="mail">
		</br>
		</br>
		<input type="submit" value="Connection" class="but">
		</form>		
	</div>
	<div class="inscription">
		<p class="insc">Registration</p>
		<form action="users.php" method="post">
		<input type="text" value="Login" class="login" name="login">
		<input type="text" value="Password" class="Password" name="password">
		<br/>
		<br/>
		<input type="text" value="Adresse mail" class="mail" name="mail">
		</br>
		</br>
		<input type="submit" value="Registration" class="but">
		</form>		
	</div>
	<div class="inscription">
		<form action="restore.php" method="post">
		<p class="insc">Forgotten password</p>
		<input type="text" value="Login" class="login" name="login">
		</br>
		</br>
		<input type="text" value="Adresse mail" class="mail" name="mail">
		</br>
		</br>
		<input type="submit" value="Restore with email" class="but">
		</form>		
	</div>
	<img src="image/background.png" class="foot">
</body>
</html>