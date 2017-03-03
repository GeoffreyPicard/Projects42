<?php
	session_start();
  include "config/database.php";
	$img = $_POST['image'];
	$montage = $_POST['png'];
	$image = hash('whirlpool', $img);
	$login = $_SESSION['login'];
	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "INSERT INTO image (ima, login)
    VALUES ('$image', '$login')";
    $conn->exec($sql);


    //montage
    if ($montage == "Risitas_police")
    	$photo2 = 'image/image01.png';
    else if ($montage == "Bubble")
    	$photo2 = 'image/image02.png';
    else if ($montage == "Mustache")
    	$photo2 = 'image/image03.png';
    else if ($montage == "Risitas_commando")
    	$photo2 = 'image/image04.png';
    else if ($montage == "Risitas_francais")
    	$photo2 = 'image/image05.png';
    else if ($montage == "Risitas_priere")
    	$photo2 = 'image/image06.png';
    else if ($montage == "Risitas_judge")
    	$photo2 = 'image/image07.png';
    else if ($montage == "Risitas_pope")
    	$photo2 = 'image/image08.png';
    else if ($montage == "Risitas_tacos")
    	$photo2 = 'image/image09.png';
    else if ($montage == "Risitas_dicaprio")
    	$photo2 = 'image/image10.png';
    else if ($montage == "Risitas_lover")
    	$photo2 = 'image/image11.png';
    else if ($montage == "tepu")
      $photo2 = 'image/image12.png';


  if (!file_exists('campicture')) {
      mkdir('campicture', 0775, true);
  }
  $upload_dir = 'campicture/';
  $img = str_replace('data:image/png;base64,', '', $img);
  $img = str_replace(' ', '+', $img);
  $data = base64_decode($img);
  $hash = hash('whirlpool', $img);
  $file = $upload_dir.$hash.'.png';
  $success = file_put_contents($file, $data);
 // echo $success ? $file : 'Unable to save the file.';


$source = imagecreatefrompng($photo2);
$largeur_source = imagesx($source);
$hauteur_source = imagesy($source);

$destination = imagecreatefrompng($file);
$largeur_destination = imagesx($destination);
$hauteur_destination = imagesy($destination);
$destination_x = ($largeur_destination - $largeur_source)/2;
$destination_y =  ($hauteur_destination - $hauteur_source)/2;
imagecopy($destination, $source, $destination_x, $destination_y, 0, 0, $largeur_source, $hauteur_source);
 
header('Content-Type: image/png');

$res = 'montage/'.$image.'.png';
imagepng($destination, $res);
	echo $res;

$del = 'campicture/'.$file;
unlink($file);

?>