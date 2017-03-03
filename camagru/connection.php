<?php
	session_start();
    include "function.php";
    include "config/database.php";
	$name =  secure_db($_POST['login']);
    $pass = hash('whirlpool', secure_db($_POST['password']));
    $email = secure_db($_POST['mail']);
	class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}
	$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT id, login, password, email FROM users"); 
    $stmt->execute();

    $count = 0;
    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
            if ($k === 'login')
                if ($v === $name)
                {
                	$count = 1;
                }
            if ($k === 'password')
            {
                if ($v === $pass && $count === 1)
                {
                   $count = 2;
                }
                else
                    $count = 0;
            }
            if ($k === 'email')
            {
                if ($v === $email && $count === 2)
                {
                    $_SESSION['login'] = secure_db($_POST['login']);
                    $_SESSION['password'] = hash('whirlpool', secure_db($_POST['password']));
                    $_SESSION['email'] = secure_db($_POST['mail']);
                    echo "<script language='javascript'>document.location.href='cam.php'</script>";
                    exit();
            	}
                else
                    $count = 0;
              }
        }
    }
    $message = "Invalid Login, Password or Email";
    echo "<script type='text/javascript'>alert('$message');</script>";
    echo "<script language='javascript'>document.location.href='index.php'</script>";
    
?>