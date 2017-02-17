<?php
	session_start();
	$image = $_POST['image'];
	$login = $_SESSION['login'];
	$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "INSERT INTO image (ima, login)
    VALUES ('$image', '$login')";
    $conn->exec($sql);

    $message =  "bonjour";
    echo "<script type='text/javascript'>alert('$message');</script>";
?>