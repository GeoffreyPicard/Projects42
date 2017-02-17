<?php
	include "function.php";
	$email = secure_db($_GET['email']);
	$login = secure_db($_GET['login']);
	if ($_GET['hash'] === hash('whirlpool', $login).hash('whirlpool', $email))
	echo "<script type='text/javascript'>alert('$message');</script>";

?>