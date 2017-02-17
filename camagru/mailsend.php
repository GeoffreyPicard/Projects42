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
		<p class="insc">An email was sent to you</p>
	</div>
	<div class="footer">
	</div>
</body>
</html>
<?php
	$message = "An email was sent to you to finish the registration";
	echo "<script type='text/javascript'>alert('$message');</script>";
    echo "<script language='javascript'>document.location.href='index.php'</script>";

?>