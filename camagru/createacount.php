<?php session_start();
	 class TableRows extends RecursiveIteratorIterator { 
    function __construct($it) { 
        parent::__construct($it, self::LEAVES_ONLY); 
    }
}
include "function.php";
include "config/database.php";
if (!($_GET['login'] && $_GET['password'] && $_GET['hash']))
{
    $message = "Error, rety to click on the link please";
    echo "<script type='text/javascript'>alert('$message');</script>";
    echo "<script language='javascript'>document.location.href='index.php'</script>";
}

    $conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT hash FROM secure"); 
    $stmt->execute();

    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
        	if ($v === secure_db($_GET['hash']))
        	{
        		$name =  secure_db($_GET['login']);
   				$pass = secure_db($_GET['password']);
   				$email = secure_db($_GET['email']);
    			$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    			$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    			$sql = "INSERT INTO users (login, password, email)
    			VALUES ('$name', '$pass', '$email')";
    			$conn->exec($sql);

    			$conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
   				$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
   				$del = secure_db($_GET['hash']);
   				$sql = "DELETE FROM secure WHERE hash='$del'";
    			$conn->exec($sql);
    			$msg = "Your account has been created";
    			$msg = wordwrap($msg,70);
   				mail($email, "Confirm account Camagru", $msg);
    			echo "<script language='javascript'>document.location.href='accountcreated.php'</script>";
    			exit();
        	}
        }
    }
?>
<html>
	<head>
		<?php include "install.php"; ?>
		<link rel="stylesheet" href="style.css" />
        <meta charset="utf-8" />
        <title>Camagru</title>
    </head>

<body class="back">
	<center><div class="header">
		<p class="camagru">Camagru</p>
	</div></center>
	<div class="inscription">
		<p class="insc">An error has occured, please retry to click on the link</p>
	</div>
	<div class="footer">
	</div>
</body>
</html>
