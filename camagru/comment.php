<?php
	session_start();
    include "config/database.php";
	$login = $_SESSION['login'];
	$image = $_POST['photo'];
	$comment = $_POST['comment'];
	if (empty($comment))
	{
		$message = "You must write something";
    	echo "<script type='text/javascript'>alert('$message');</script>";
		echo "<script language='javascript'>document.location.href='galerie.php?page=1'</script>";
		exit();
	}
	if (strlen($comment) > 200)
	{
		$message = "Your comment must have less than 200 caracter";
    	echo "<script type='text/javascript'>alert('$message');</script>";
		echo "<script language='javascript'>document.location.href='galerie.php?page=1'</script>";
		exit();
	}

	class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}


	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "INSERT INTO comment (com, image, login)
    VALUES ('$comment', '$image', '$login')";
    $conn->exec($sql);



  
	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT login FROM image WHERE ima='$image'"); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
         $log = $v;
    }
}

	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT email FROM users WHERE login='$log'"); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
         $tosend = $v;
    }
}

	$msg = "You have a new comment on you photo";
    $msg = wordwrap($msg,70);
    mail($tosend, "Camagru- New comment", $msg);
    header('location: galerie.php?page=1');
?>