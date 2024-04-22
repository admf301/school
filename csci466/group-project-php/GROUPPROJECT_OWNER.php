<html>
<head>
    <title>Inventory</title>
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>

<body><pre>
<a class="w3-btn w3-round-xxlarge  w3-dark-grey" href="http://students.cs.niu.edu/~z1726017/group_project/main_page.php">Home</a> <br><br>
<?php

include('login.php');
session_start();

$clientusername = $_SESSION['clientusername'];

try
{ // if something goes wrong, an exception is thrown
    $dsn = "mysql:host=courses;dbname=z1726017";
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stores = $pdo->query(" SELECT NAME, ADDRESS, STORE.STORE_ID 
                            FROM EMPLOYEES, STORE
                            WHERE STORE.STORE_ID = EMPLOYEES.STORE_ID AND EMPLOYEES.USERNAME = '$clientusername' AND EMPLOYEES.OWNER = TRUE;")->fetchAll(PDO::FETCH_ASSOC);
    foreach($stores as $store)
    {
        $id = $store['STORE_ID'];
        $name = $store['NAME'];
        $address = $store['ADDRESS'];
        $rs = $pdo->query("SELECT PROD_NAME, STOCK, PRICE
                       FROM INVENTORY, STORE_INVENTORY, EMPLOYEES
                       WHERE INVENTORY.PROD_ID = STORE_INVENTORY.PROD_ID AND STORE_INVENTORY.STORE_ID = EMPLOYEES.STORE_ID AND EMPLOYEES.USERNAME = '$clientusername' AND EMPLOYEES.OWNER = TRUE AND STORE_INVENTORY.STORE_ID = '$id';");

        echo "Inventory for $name at $address\n";
        echo "<table border=1 cellspacing=1>";

        echo "<tr>";
        echo "<td>" . 'GameName' . "</td>";
        echo "<td>" . 'Stock' . "</td>";
        echo "<td>" . 'Price' . "</td>";
        echo "</tr>\n";

        while ($row = $rs->fetch(PDO::FETCH_ASSOC))
        {
            echo "<tr>";
            echo "<td>" . $row["PROD_NAME"] . "</td>";
            echo "<td>" . $row["STOCK"] . "</td>";
            echo "<td>" . $row["PRICE"] . "</td>";
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
