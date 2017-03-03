<?php
	session_start();
    include "function.php";
    include "config/database.php";
    if (strlen(secure_db($_POST['password'])) < 5)
    {
        $message = "Password must have more than 5 caracter";
        echo "<script type='text/javascript'>alert('$message');</script>";
        echo "<script language='javascript'>document.location.href='index.php'</script>";
        exit();
    }
    if (strlen(secure_db($_POST['login'])) < 5)
    {
        $message = "Login must have more than 5 caracter";
        echo "<script type='text/javascript'>alert('$message');</script>";
        echo "<script language='javascript'>document.location.href='index.php'</script>";
        exit();
    }
     if (strlen(secure_db($_POST['mail'])) < 5)
    {
        $message = "Email must have more than 5 caracter";
        echo "<script type='text/javascript'>alert('$message');</script>";
        echo "<script language='javascript'>document.location.href='index.php'</script>";
        exit();
    }
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

    $result = $stmt->setFetchMode(PDO::FETCH_ASSOC); 
    foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) { 
        {
            if ($k === 'login')
                if ($v === $name)
                {
                    $message = "Login already used";
                    echo "<script type='text/javascript'>alert('$message');</script>";
                    echo "<script language='javascript'>document.location.href='index.php'</script>";
                    exit();
                }
            if ($k === 'email')
                if ($v === $email)
                {
                    $message = "Email already used";
                    echo "<script type='text/javascript'>alert('$message');</script>";
                    echo "<script language='javascript'>document.location.href='index.php'</script>";
                    exit();
                }
        }
    }
    $sec =  hash('whirlpool', secure_db($_POST['password']).secure_db($_POST['login']));
    $conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "INSERT INTO secure (hash)
    VALUES ('$sec')";
    $conn->exec($sql);

    $msg = "Click on the link for confirm inscription\n\nhttp://localhost:8080/camagru/createacount.php?email=$email&login=$name&password=$pass&hash=$sec";
    $msg = wordwrap($msg,70);
    mail($email, "Confirm inscription Camagru", $msg);
    echo "<script language='javascript'>document.location.href='mailsend.php'</script>";

?>