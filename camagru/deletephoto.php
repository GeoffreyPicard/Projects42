<?php
	session_start();
	include "function.php";
	$login = $_SESSION['login'];

     class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
    }
    $number = secure_db($_POST['number']);
    $i = 0;

    $conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT ima FROM image WHERE login='$login'" ); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
         $i++;
        }
     if (!is_numeric($number) || $number <= 0 || $number > $i)
     {
     	$message = "You must enter a number of photo";
        echo "<script type='text/javascript'>alert('$message');</script>";
     	 echo "<script language='javascript'>document.location.href='myphoto.php'</script>";
     }

     $conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT ima FROM image WHERE login='$login'" ); 
    $stmt->execute();
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    $i = 1;
     foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
     	if ($i === $number)
     	{

     		$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
   			$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    		$sql = "DELETE FROM image WHERE ima='$v'";
    		$conn->exec($sql);
    		$del = 'montage/'.$v.'.png';
    		unlink($del);

     	}
     	$i++;
        }
        header('location: myphoto.php');
?>