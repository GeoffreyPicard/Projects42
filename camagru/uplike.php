<?php
	session_start();

  include "function.php";
  include "config/database.php";

	$login = $_SESSION['login'];
	$photo = secure_db($_POST['photo']);


	class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}
	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT image, login FROM vote"); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
          if ($im === $photo && $v === $login)
          {
          		$message = "Vous aimez deja cette photo";
          		echo "<script type='text/javascript'>alert('$message');</script>";
          		echo "<script language='javascript'>document.location.href='galerie.php?page=1'</script>";
          		exit();
          }
          $im = $v;
    }
}


	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "INSERT INTO vote (image, login)
    VALUES ('$photo', '$login')";
    $conn->exec($sql);


	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "UPDATE image SET nblike=nblike+1 WHERE ima='$photo'";
    $stmt = $conn->prepare($sql);
    $stmt->execute();
    header('location: galerie.php?page=1');
    exit();

?>