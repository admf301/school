<html><head><title>GROUPPROJECTTEST_USERORDERS</title></head><body><pre>
<?php

include('login.php');
session_start();
$clientusername = $_SESSION['clientusername'];

try
{ // if something goes wrong, an exception is thrown
    $dsn = "mysql:host=courses;dbname=z1726017";
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $orders = $pdo->query("SELECT * FROM ORDERS WHERE USERNAME = '$clientusername';");
    
    foreach($orders as $order)
    {
        $id = $order["ORDER_ID"];
        $name = $order["USERNAME"];
        $inventory = $pdo->query("SELECT * FROM ORDER_INVENTORY WHERE ORDER_ID = '$id';");

        echo "Order $id for $name\n";
        echo "<table border=1 cellspacing=1>";
    
        echo "<tr>";
        echo "<td>" . 'ID' . "</td>";
        echo "<td>" . 'Amount Paid' . "</td>";
        echo "<td>" . 'Tracking #' . "</td>";
        echo "<td>" . 'Status' . "</td>";
        echo "</tr>\n";

        while ($row = $order->fetch(PDO::FETCH_ASSOC))
        {
            echo "<tr>";
            echo "<td>" . $row["ORDER_ID"] . "</td>";
            echo "<td>" . $row["PAID_AMOUNT"] . "</td>";
            echo "<td>" . $row["TRACK_NUM"] . "</td>";
            echo "<td>" . $row["ORD_STATUS"] . "</td>";
            echo "</tr>\n";
        }
        echo "</table>\n";

        echo "Order Details\n";
        echo "<table border=1 cellspacing=1>";
    
        echo "<tr>";
        echo "<td>" . 'Order ID' . "</td>";
        echo "<td>" . 'Product ID' . "</td>";
        echo "<td>" . 'Store ID' . "</td>";
        echo "</tr>\n";

        while ($row = $inventory->fetch(PDO::FETCH_ASSOC))
        {
            echo "<tr>";
            echo "<td>" . $row["ORDER_ID"] . "</td>";
            echo "<td>" . $row["PROD_ID"] . "</td>";
            echo "<td>" . $row["STORE_ID"] . "</td>";
            echo "</tr>\n";
        }
        echo "</table>\n";
    }
}
catch(PDOexception $e)
{ // handle that exception
    echo "Connection to database failed: " . $e->getMessage();
}

?>
</pre></body></html>