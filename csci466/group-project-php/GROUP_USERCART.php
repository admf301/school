<?php


session_start();

function cartList()
{
    try
    { // if something goes wrong, an exception is thrown
        include('login.php');
        $clientusername = $_SESSION['clientusername'];
        $dsn = "mysql:host=courses;dbname=z1726017";
        $pdo = new PDO($dsn, $username, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $stores = $pdo->query(" SELECT NAME, ADDRESS, STORE.STORE_ID
                                FROM EMPLOYEES, STORE
                                WHERE STORE.STORE_ID = EMPLOYEES.STORE_ID;")->fetchAll(PDO::FETCH_ASSOC);
        foreach($stores as $store)
        {
            $id = $store['STORE_ID'];
            $name = $store['NAME'];
            $address = $store['ADDRESS'];
            $query = "SELECT INVENTORY.PROD_NAME, INVENTORYINCART.QTY, INVENTORY.PRICE, STORE_INVENTORY.STOCK, INVENTORYINCART.PROD_ID, INVENTORYINCART.STORE_ID
                      FROM INVENTORYINCART
                      INNER JOIN SHOPPING_CART ON SHOPPING_CART.CART_ID = INVENTORYINCART.CART_ID
                      INNER JOIN INVENTORY ON INVENTORYINCART.PROD_ID = INVENTORY.PROD_ID
                      INNER JOIN STORE_INVENTORY ON STORE_INVENTORY.PROD_ID = INVENTORYINCART.PROD_ID AND STORE_INVENTORY.STORE_ID = INVENTORYINCART.STORE_ID
                      WHERE SHOPPING_CART.USERNAME = '$clientusername' AND INVENTORYINCART.STORE_ID = '$id';";
            $rs = $pdo->query($query);
            echo "Shopping Cart for $name at $address\n";
            echo "<form action=\"\" method=\"POST\">";
            echo "<table border=1 cellspacing=1>";

            echo "<tr>";
            echo "<td>" . 'GameName' . "</td>";
            echo "<td>" . 'Quantity' . "</td>";
            echo "<td>" . 'Price' . "</td>";
            echo "</tr>\n";

                    $sum = 0;

            $rownumber = 0;
            while ($row = $rs->fetch(PDO::FETCH_ASSOC))
            {   
                
                $product = $row['PROD_ID'];
                $qty = $row["QTY"];
                $store = $row['STORE_ID'];
                $testfunc = "testaroo(\"hello\")";
                $deleteFunc = "setValues($product, $store, 0, $rownumber)";
                $updateFunc = "setValues($product, $store, 1, $rownumber)";
                echo $deleteFunc;
                echo $updateFunc;
                echo "<tr>";
                echo "<td>" . $row["PROD_NAME"] . "</td>";
                echo "<td>" . '<input name="' . $rownumber .'" type="number" value="' . $row["QTY"] . '" min="1" max=" ' . $row['STOCK'] . '">' . "</td>";
                echo "<td>" . $row["PRICE"] . "</td>";
                echo "<td>" . "<input type=\"submit\" name=\"update\" onclick = \"$updateFunc\" value=\"update\">" . "</td>";
                echo "<td>" . "<input type=\"submit\" name=\"delete\" onclick = \"$deleteFunc\" value=\"remove\">" . "</td>";
                echo "</tr>\n";
                $rownumber += 1;
            }


            echo "</table>";
            echo '<input type="hidden" name="PROD_ID" value = "-1" id = "product_id">';
            echo '<input type="hidden" name="STORE_ID" value = "-1" id = "store_id">';
            echo '<input type="hidden" name="ACTION_TYPE" value = "-1" id = "action_type">';
            echo '<input type="hidden" name="ROW" value = "-1" id = "row_number">';
            echo "</form>\n";


        }





    }
    catch(PDOexception $e)
    { // handle that exception
        echo "Connection to database failed: " . $e->getMessage();
    }
}
?>

<?php 
if($_SERVER['REQUEST_METHOD'] == "POST")
{
    try { // if something goes wrong, an exception is thrown
        echo "Hello";
        $dsn = "mysql:host=courses;dbname=z1726017";
        include("login.php");
        $pdo = new PDO($dsn, $username, $password);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $clientusername = $_SESSION['clientusername'];
        
        $item = $_POST['PROD_ID'];
        $store = $_POST['STORE_ID'];
        $action = $_POST['ACTION_TYPE'];
        $qty = $_POST['ROW'];
        echo $action;
        echo $item;
        echo $store;
        echo $qty;
        $cart_query = $pdo->query("SELECT CART_ID 
                             FROM SHOPPING_CART 
                             WHERE USERNAME = '$clientusername';")->fetch(PDO::FETCH_ASSOC);
        $cart_id = $cart_query['CART_ID'];

        if($action == 0){
            #delete
            $query = "DELETE FROM INVENTORYINCART WHERE CART_ID = $cart_id AND STORE_ID = $store AND PROD_ID = $item;";
            echo $query;
            $pdo->exec($query);
        }

        if($action == 1){
            $query = "UPDATE INVENTORYINCART 
                      SET QTY = $qty
                      WHERE CART_ID = $cart_id AND STORE_ID = $store AND PROD_ID = $item;";
            echo $query;
            $pdo->exec($query);
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
    <title>Shopping Cart</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>

<body>
<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/main_page.php">Home</a> <br><br>

<?php cartList(); ?>
<form action="http://students.cs.niu.edu/~z1893300/groupcheckout.php" method="POST">
    <input type="hidden" name="Username" value = "<?php echo $clientusername ?>"/>
    <input type="hidden" name="Payment" value = "<?php echo $sum ?>"/>
    <input type="hidden" name="OrdStatus" value = 'processing'/>
    <br>
    <label for="CredNum">Credit Card Number</label>
    <input type="text" name="CredNum" required/>
    <br>
    <label for="CVC">CVC</label>
    <input type="text" name="CVC" required/>
    <br>
    <label for="ExpDate">ExpDate MM/YY</label>
    <input type="text" name="ExpDate" required/>
     <br>
     <label for="Address">Billing Address</label>
    <input type="text" name="Address" required/>
    <br>
    <input type="submit" name="Checkout" value="Checkout."/>
</form>

</body>

</html>

<script>
    function testaroo(thing){
        alert("WRYYYYYY");
    }
    function setValues(product, store, actionType, row){
        document.getElementById("product_id").value = product;
        document.getElementById("store_id").value = store;
        document.getElementById("action_type").value = actionType;
        document.getElementById("row_number").value = row;
        alert("action: " + actionType + " store: " + store + "product " + product);
    }
</script>