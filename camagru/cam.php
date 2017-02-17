<?php session_start();

	if (!($_SESSION['login'] && $_SESSION['email'] && $_SESSION['password']))
	{
		$message = "You must log in to access this page";
    	echo "<script type='text/javascript'>alert('$message');</script>";
   		echo "<script language='javascript'>document.location.href='index.php'</script>";
	}

?>
<html>
	<head>
		<?php include "install.php"; ?>
		<link rel="stylesheet" href="style.css" />
        <meta charset="utf-8" />
        <title>Camagru</title>
        <a href="disconnect.php"><img src="off.png" class="off"></a>
    </head>

<body class="back">
	<center><div class="header">
		<p class="camagru">Camagru</p>
	</div></center>
	<div class="maine">



	<video id="video" width="300" height="300" autoplay></video>
	<button id="snap">Snap Photo</button>
	</br>
	<canvas id="canvas" width="300" height="300"></canvas>
	<script type="text/javascript" src="cam.js"></script>



	<div class="droite" action="putimage.php">
	</div>

			
	</div>
	<div class="footer">
	</div>
</body>
</html>