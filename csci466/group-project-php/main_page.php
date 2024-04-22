<?php 
session_start();

function employee(){
	try { // if something goes wrong, an exception is thrown
		$dsn = "mysql:host=courses;dbname=z1726017";
		include("login.php");
		$pdo = new PDO($dsn, $username, $password);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$clientusername = $_SESSION['clientusername'];
		$isEmployee = false;
		$isOwner = false;

		$q = $pdo->query("SELECT * FROM EMPLOYEES WHERE USERNAME = '$clientusername';")->fetch(PDO::FETCH_NUM);

		if(!(! $q))
		{
			$query = "SELECT EMPLOYEES.USERNAME, EMPLOYEES.STORE_ID, STORE.NAME, EMPLOYEES.OWNER
					  FROM EMPLOYEES
			 		  INNER JOIN STORE ON EMPLOYEES.STORE_ID = STORE.STORE_ID
			 		  WHERE USERNAME = '$clientusername';";
			$store = $pdo->query($query)->fetchAll(PDO::FETCH_NUM);
			foreach ($store as $row)
			{
				$isEmployee = true;
				
				if($row[3]){
					$isOwner = true;
				}
			}
			if($isEmployee){
				echo '<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/GROUPPROJECT_EMPL.php">Store Orders</a> <br><br>';
			}
			if($isOwner){
				echo '<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/GROUPPROJECT_OWNER.php">Store Inventory</a> <br><br>';
			}
		}



	}
	catch(PDOexception $e) { // handle that exception
		echo "Connection to database failed: " . $e->getMessage();
	}
}

 ?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Main Page</title>
	<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>
	
<body>
	<div>
		<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/item_list.php">Shopping</a> <br><br>
		<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/GROUP_USERCART.php">Cart</a> <br><br>
		<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="">My Orders</a> <br><br>
		<?php employee(); ?>
	</div>
</body>
</html>