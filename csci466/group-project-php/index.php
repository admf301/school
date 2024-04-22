<?php
session_start();
$clientusername = "";
$usernameErr = "";

try { // if something goes wrong, an exception is thrown
	

	if($_SERVER['REQUEST_METHOD'] == "POST")
	{
		if(empty($_POST['clientusername']))
		{
			$usernameErr = "User Name Required";
		}
		else 
		{
			$clientusername = $_POST['clientusername'];
			include("login.php");
			$dsn = "mysql:host=courses;dbname=z1726017";
			$pdo = new PDO($dsn, $username, $password);
			$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$q = $pdo->query("SELECT * FROM USER WHERE USERNAME = '$clientusername';")->fetch(PDO::FETCH_NUM);
			$dsn = null;
			$pdo = null;

			if(! $q)
			{
				$usernameErr = "Username doesn't exist";
			} 
			else 
			{
				$_SESSION['clientusername'] = $clientusername;
				header("Location: http://students.cs.niu.edu/~z1726017/group_project/main_page.php");
				exit();
			}

		}
	}		

}
catch(PDOexception $e) { // handle that exception
	echo "Connection to database failed: " . $e->getMessage();
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Login</title>
</head>
	
<body>
	<form action="" method="POST">
		<label for="user_name">Username</label><input type="text" name="clientusername" value="<?php echo $clientusername;?>">
		<span> <?php echo $usernameErr; ?> </span>
		<br> <br>
		<input type="submit" name="login">
	</form>
</body>
</html>