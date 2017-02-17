<?php

	session_start();
	$_SESSION['login'] = NULL;
	$_SESSION['password'] = NULL;
	$_SESSION['email'] = NULL;
	echo "<script language='javascript'>document.location.href='index.php'</script>";

?>