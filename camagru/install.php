<?php

$conn = new PDO("mysql:host=localhost", "root", "root");
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$sql = "CREATE DATABASE IF NOT EXISTS camagru";
$conn->exec($sql);
$tab = "CREATE TABLE IF NOT EXISTS users (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    login VARCHAR(30) NOT NULL,
    password VARCHAR(300) NOT NULL,
    email VARCHAR(50) NOT NULL
    )";

$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$conn->exec($tab);

$tab = "CREATE TABLE IF NOT EXISTS secure ( 
    hash VARCHAR(200) NOT NULL
    )";

$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$conn->exec($tab);

$tab = "CREATE TABLE IF NOT EXISTS changepass ( 
    pass VARCHAR(200) NOT NULL
    )";

$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$conn->exec($tab);

$tab = "CREATE TABLE IF NOT EXISTS image ( 
    ima TEXT NOT NULL,
    login  VARCHAR(30) NOT NULL
    )";

$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$conn->exec($tab);
?>