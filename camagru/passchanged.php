<?php
    include "function.php";
	$conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT pass FROM changepass"); 
    $stmt->execute();
    class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
        	$hash = hash('whirlpool', secure_db($_POST['login']));
        	if ($v === $hash)
        	{

                $conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
                $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                if (strlen(secure_db($_POST['mail'])) < 5)
                {
                $message = "Password must have more than 5 caracters, click on the email link, and retry";
                echo "<script type='text/javascript'>alert('$message');</script>";
                echo "<script language='javascript'>document.location.href='index.php'</script>";
                exit();
                }
                $new = hash('whirlpool', secure_db($_POST['mail']));
                $login = secure_db($_POST['login']);
                $sql = "UPDATE users SET password='$new' WHERE login='$login'";
                $stmt = $conn->prepare($sql);
                $stmt->execute();

                $conn = new PDO("mysql:host=localhost;dbname=camagru", "root", "root");
                $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                $sql = "DELETE FROM changepass WHERE pass='$hash'";
                $conn->exec($sql);


    			$msg = "Your password has been changed";
    			$msg = wordwrap($msg,70);
   			    mail($email, "Confirm password changed", $msg);
    			echo "<script language='javascript'>document.location.href='accountcreated.php'</script>";
    			exit();
        	}
        }
    }
    $message = "A problem has arisen, please retry";
    echo "<script type='text/javascript'>alert('$message');</script>";
    echo "<script language='javascript'>document.location.href='index.php'</script>";
?>