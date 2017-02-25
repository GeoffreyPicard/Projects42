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
        <a href="galerie.php"><img src="image/galerie.png" class="galeriebutton"></a>
    </head>

<body class="back">
	<center><div class="header">
		<p class="camagru">Camagru</p>
	</div></center>
	</br>
	</br>
	<div class="photo">
		<img src="image/image02.png" width="80">
		<img src="image/image03.png" width="80">
		<img src="image/image01.png" width="80">
		<img src="image/image04.png" width="80">
		<img src="image/image05.png" width="80">
		<img src="image/image06.png" width="80">
		<img src="image/image07.png" width="80">
		<img src="image/image08.png" width="80">
		<img src="image/image09.png" width="80">
		<img src="image/image10.png" width="80">
		<img src="image/image11.png" width="80">
		<img src="image/image12.png" width="80">

		</br>
		</br>
		<select id="choix">
			<option value="Empty">Empty</option>  			
  			<option value="Bubble">Bubble</option>
  			<option value="Mustache">Mustache</option>
  			<option value="Risitas_police">Risitas Police</option>
  			<option value="Risitas_commando">Risitas Commando</option>
  			<option value="Risitas_francais">French Risitas</option>
  			<option value="Risitas_priere">Risitas muslin</option>
  			<option value="Risitas_judge">Risitas judge</option>
  			<option value="Risitas_pope">Risitas pope</option>
  			<option value="Risitas_tacos">Risitas tacos</option>
  			<option value="Risitas_dicaprio">Risitas di caprio</option>
  			<option value="Risitas_lover">Risitas lover</option>
  			<option value="tepu">Tepu</option>
		</select>
	</div>
	<div class="maine">

	<video id="video" width="300" height="300" autoplay></video>
	</br>
	<button id="snap" class="snap">Snap Photo</button>
	</br>
	</br>
	<input type="file" id="myFile" class="snap"></input>
	</br>
	</br>
	<button id="myFile" class="snap" onclick="upload()">Upload photo</button>
	<div id="preview"></div>
	</br>
	</br>
	<canvas id="canvas" width="300" height="300"></canvas>


	<div class="droite" action="putimage.php">
	<canvas id="galerie" width="250" height="1000"></canvas>
	</div>
			

	<script type="text/javascript" src="cam.js"></script>
	<img src="image/background.png" class="foot">
</body>
</html>