<?php 
session_start();


function item_list(){
	try { // if something goes wrong, an exception is thrown
		$dsn = "mysql:host=courses;dbname=z1726017";
		include("login.php");
		$pdo = new PDO($dsn, $username, $password);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$clientusername = $_SESSION['clientusername'];
		
		$items = $pdo->query("SELECT *
							 FROM STORE_INVENTORY
							 INNER JOIN INVENTORY ON STORE_INVENTORY.PROD_ID = INVENTORY.PROD_ID
							 INNER JOIN STORE ON STORE.STORE_ID = STORE_INVENTORY.STORE_ID
							 ORDER BY PROD_NAME;")->fetchAll(PDO::FETCH_ASSOC);

		echo "<form action='' method='POST'>";
		echo "<table>";
		echo "<tr>";
		echo "<td> Product Name </td>";
		echo "<td> Store </td>";
		echo "<td> Price </td>";
		echo "<td> Stock </td>";
		echo "<td> Amount Bought </td>";
		echo "<td> Buy </td>";
		echo "</tr>";

		foreach($items as $item){
			$product = $item['PROD_ID'];
			$store = $item["STORE_ID"];
			echo "<tr>";
			echo "<td>" . $item['PROD_NAME'] . "</td>";
			echo "<td>" . $item['NAME']      . "</td>";
			echo "<td>" . $item['PRICE']     . "</td>";
			echo "<td>" . $item['STOCK']     . "</td>";
			echo "<td>" . '<input type="number" name="' . $item['PROD_ID'] .'" value = "1" min = "1" max = "' . $item['STOCK'] . '">';
			echo "<td>" . "<input type=\"submit\" name = \"submit_button\" value = \"Add to Cart\" onclick = \"setValues($product, $store)\"><td>";
			echo "</tr>";

		}

		echo "</table>";
		echo '<input type="hidden" name="PROD_ID" value = "-1" id = "product_id">';
		echo '<input type="hidden" name="STORE_ID" value = "-1" id = "store_id">';
		echo "</form>";
		$dsn = null;
		$pdo = null;

	}
	catch(PDOexception $e) { // handle that exception
		echo "Connection to database failed: " . $e->getMessage();
	}
}
?>

<?php 
if($_SERVER['REQUEST_METHOD'] == "POST")
{
	try { // if something goes wrong, an exception is thrown
		$dsn = "mysql:host=courses;dbname=z1726017";
		include("login.php");
		$pdo = new PDO($dsn, $username, $password);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$clientusername = $_SESSION['clientusername'];
		
		$item = $_POST['PROD_ID'];
		$store = $_POST['STORE_ID'];
		$item_amount = $_POST[$item];
		$item_name_query = $pdo->query("SELECT PROD_NAME FROM INVENTORY WHERE PROD_ID = '$item';")->fetch(PDO::FETCH_ASSOC);
		$item_name = $item_name_query['PROD_NAME'];

		$cart_query = $pdo->query("SELECT CART_ID 
							 FROM SHOPPING_CART 
							 WHERE USERNAME = '$clientusername';")->fetch(PDO::FETCH_ASSOC);
		$cart_id = $cart_query['CART_ID'];

		if($item_amount > 0 && $cart_id > 0 && $item > 0 && $store >0)
		{
			$query = "INSERT INTO INVENTORYINCART
							   (PROD_ID, CART_ID, STORE_ID, QTY)
							   VALUES($item, $cart_id, $store, $item_amount);";
			echo $query;
			$exc = $pdo->exec($query);
			echo '<script> alert(" ' . $item_amount . ' of ' . $item_name . ' added to cart") </script>';
		} 
		$dsn = null;
		$pdo = null;

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
	<title>Item List</title>
</head>
	
<body>
	<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/main_page.php">Home</a> <br><br>
	<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/GROUP_USERCART.php">Cart</a> <br><br>
	<?php item_list(); ?>
</body>
</html>

<script>
	function setValues(product, store){
		document.getElementById("product_id").value = product;
		document.getElementById("store_id").value = store;
		message = "product id = " + product + " store id =" + store;
		alert(message);
	}
</script>