<?php
     session_start();

	if (!($_SESSION['login'] && $_SESSION['email'] && $_SESSION['password']))
	{
		$message = "You must log in to access this page";
    	echo "<script type='text/javascript'>alert('$message');</script>";
   		echo "<script language='javascript'>document.location.href='index.php'</script>";
	}

?>
<html>
	<head>
		<link rel="stylesheet" href="style.css" />
        <meta charset="utf-8" />
        <title>Camagru</title>
        <a href="disconnect.php"><img src="image/off.png" class="off"></a>
        <a href="cam.php"><img src="image/camera.png" class="galeriebutton"></a>
    </head>
    <body class="back">
    <center><div class="header">
        <p class="camagru">Camagru</p>
    </div></center>
    <img src="image/background.png" class="foot">
    <ul class="soustop">
        <li><a href="myphoto.php">My photo</a></li>
        <li><a href="galerie.php">Gallery</a></li>
    </ul>