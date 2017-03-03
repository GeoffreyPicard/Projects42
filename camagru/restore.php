<?php
include "function.php";
 include "config/database.php";
$login = secure_db($_POST['login']);
$email = secure_db($_POST['mail']);

 $conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT id, login, password, email FROM users"); 
    $stmt->execute();

    $count = 0;
    $res = 0;
    class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
            if ($k === 'login')
                if ($v === $login)
                {
                    $count = 1;
                }
            if ($k === 'email')
                if ($v === $email && $count === 1)
                {
                   $res = 1;
                }
        }
    }
if ($res === 0)
{
	$message = "Invalid Login or Email";
	echo "<script type='text/javascript'>alert('$message');</script>";
    echo "<script language='javascript'>document.location.href='index.php'</script>";
	exit();
}
$ha = hash('whirlpool', secure_db($_POST['login']));
$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
$sql = "INSERT INTO changepass (pass)
VALUES ('$ha')";
$conn->exec($sql);


$hash = hash('whirlpool', secure_db($_POST['login']).hash('whirlpool', secure_db($_POST['mail'])));
$msg = "Click on the link for restore your password\n\nhttp://localhost:8080/camagru/changepassword.php?login=$login&email=$email&hash=$hash";
$msg = wordwrap($msg,70);
mail($email, "Restore password Camagru", $msg);
$message = "An email was sent to you";
echo "<script type='text/javascript'>alert('$message');</script>";
echo "<script language='javascript'>document.location.href='index.php'</script>";

?>