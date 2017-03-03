<?php
     session_start();
     include "function.php";
     include "config/database.php";
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
        <li><a href="galerie.php?page=1">Gallery</a></li>
    </ul>
    <?php
    class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
    } 
    $count = 0;
    $nbpage = secure_db($_GET['page']);
    $lik = 0;
    $conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT ima, nblike  FROM image" ); 
    $stmt->execute();
    $i = 1;
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
        if (!is_numeric($v))
            $img = $v;
        else
        {
            if ($count <= $nbpage * 10 && $count >= $nbpage * 10 - 10)
             {   
  ?>
<div class='wall'>
<img class='gallery' src='montage/<?=$img?>.png'>
</br>
<form action="uplike.php" method="post" >
    <input type="hidden" name="photo" value="<?=$img?>">
    <?php echo "<p class='nb_like'>$v</p>"; ?>
    <input type='submit' name='Like !' value='Like !' class='action-button animate'>
</form>
</br>
<p class='COM'>Comments :</p>
<?php

    $j = 0;
    $conne = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conne->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conne->prepare("SELECT image, login, com FROM comment"); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $u=>$d) { 
        {
            if ($d === $img)
            {
                $j = 1;
            }
            else if ($j === 1)
            {
                echo "<p class='commentaire'>$d</p>";
                echo ":  ";
                $j = 2;
            }
            else if ($j === 2)
            {
                echo "<p class='commentaire'>$d</p>";
                echo "</br>";
                $j = 0;
            }
    }
}

?>
</br>
<div class='wall'>
<form action='comment.php' method='post'>
    <input type="hidden" name="photo" value="<?=$img?>">
    <input class='comment' type='text' name='comment'>
    <input type='submit' name='Like !' value='Add comment' class='addcomment'>
</form>
</div>
</div>
   


<?php
     }
 }
    $count++;
         $i++;


        }

$page = floor(($count - 10) / 5);
?>
</br>
<div class='pagination'>
<p>Page :</p>
<?php
    $k = 1;
    while ($k <= $page)
    {
        echo "<a href=galerie.php?page=$k class='buttonpage'>[$k]</a>";
        $k++;
    }

?>
</div>

    </br>
    </br>
    </br>
    </br>
    </br>
