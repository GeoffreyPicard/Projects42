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
    <?php
    class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
    }  

    $conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT ima, nblike  FROM image" ); 
    $stmt->execute();
    $i = 1;
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
        if (is_numeric($v))
            echo "<div id='like_number'>" . $v . "</div>";
        else
        {
  ?>
<div class='wall'>
<img class='gallery' src='montage/<?=$v?>.png'>
</br>
<input type='button' name='Like !' value='Like !' class='action-button animate' onclick='uplike()'>
</br>   
<?=$i?>
</br>
</div>
<script type="text/javascript" src="gallery.js"></script>


<?php
     }
         $i++;


        }
    ?>

    </br>
    </br>
    </br>
    </br>
    </br>
