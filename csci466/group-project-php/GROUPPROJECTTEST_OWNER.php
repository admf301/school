<html><head><title>GROUPPROJECTTEST_OWNER</title></head><body><pre>
<?php

include('pass.php');

try
{ // if something goes wrong, an exception is thrown
    $dsn = "mysql:host=courses;dbname=z1907943";
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $rs = $pdo->query("SELECT * FROM S;");

    echo "Inventory\n";
    echo "<table border=1 cellspacing=1>";
    
    echo "<tr>";
    echo "<td>" . GameName . "</td>";
    echo "<td>" . Stock . "</td>";
    echo "<td>" . Price . "</td>";
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

    $rs = $pdo->query("SELECT * FROM P;");
 
    echo "Games in stock\n";
    echo "<table border=1 cellspacing=1>";
    
    echo "<tr>";
    echo "<td>" . GameName . "</td>";
    echo "<td>" . Stock . "</td>";
    echo "<td>" . Price . "</td>";
    echo "</tr>\n";

    while ($row = $rs->fetch(PDO::FETCH_ASSOC))
    {
        if($row["STOCK"] > 0)
        {
            echo "<tr>";
            echo "<td>" . $row["PROD_NAME"] . "</td>";
            echo "<td>" . $row["STOCK"] . "</td>";
            echo "<td>" . $row["PRICE"] . "</td>";
            echo "</tr>\n";
        }
    }

    
    echo "</table>\n";
}
catch(PDOexception $e) 
{ // handle that exception
    echo "Connection to database failed: " . $e->getMessage();
}

?>
</pre></body></html>