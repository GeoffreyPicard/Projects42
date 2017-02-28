<?php

	$conn = new PDO("mysql:host=localhost;dbname=camagru", 'root', 'root');
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "UPDATE image SET nblike='2'";
    $stmt = $conn->prepare($sql);
    $stmt->execute();	

?>