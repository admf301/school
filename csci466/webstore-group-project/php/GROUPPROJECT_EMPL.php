<html><head><title>Orders</title></head><body><pre>
<?php

include('login.php');

try
{ // if something goes wrong, an exception is thrown
    $dsn = "mysql:host=courses;dbname=z1726017";
    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $rs = $pdo->query("SELECT * FROM ORDERS WHERE ORDSTATUS = 'processing';");

    echo "Outstanding Orders\n";
    echo "<table border=1 cellspacing=1>";

    echo "<tr>";
    echo "<td>" . "Order ID" . "</td>";
    echo "<td>" . "Order Status" . "</td>";
        echo "<td>" . "Tracking Number" . "</td>";
    echo "</tr>\n";

    while ($row = $rs->fetch(PDO::FETCH_ASSOC))
    {
        echo "<tr>";
        echo "<td>" . $row["ORDER_ID"] . "</td>";
        echo "<td>" . $row["ORDSTATUS"] . "</td>";
        echo "<td>" . $row["TRACK_NUM"] . "</td>";
        echo "</tr>\n";
    }


    echo "</table>\n";

    $rs = $pdo->query("SELECT *
                        FROM ORDERS, USER
                        WHERE ORDERS.USERNAME = USER.USERNAME;");

    echo "Order Information\n";
    echo "<table border=1 cellspacing=1>";

    echo "<tr>";
    echo "<td>" . "Order ID" . "</td>";
    echo "<td>" . "Order Status" . "</td>";
        echo "<td>" . "Tracking Number" . "</td>";
        echo "<td>" . "Paid Amount" . "</td>";
        echo "<td>" . "Username" . "</td>";
        echo "<td>" . "Phone Number" . "</td>";

    echo "</tr>\n";
        $rows = $rs->fetchAll(PDO::FETCH_ASSOC);
    foreach ($rows as $row) :
        echo "<tr>";
        echo "<td>" . $row["ORDER_ID"] . "</td>";
        echo "<td>" . $row["ORDSTATUS"] . "</td>";
        echo "<td>" . $row["TRACK_NUM"] . "</td>";
        echo "<td>" . $row["PAID_AMOUNT"] . "</td>";
        echo "<td>" . $row["USERNAME"] . "</td>";
        echo "<td>" . $row["PHONE"] . "</td>";
        echo "</tr>\n";
    endforeach;
        
    echo "</table>";
        
        
        }
        catch(PDOexception $e)
        { // handle that exception
            echo "Connection to database failed: " . $e->getMessage();
        }
        
        ?>
        
        
            <form action="http://students.cs.niu.edu/~z1893300/GROUPPROJECT_ORDUPT.php" method="POST">
                 <select name="orderID">
                     <?php
                        foreach($rows as $option) : ?>
                                <option value="<?php echo $option['ORDER_ID']; ?>"><?php echo $option['ORDER_ID']; ?></optio>
                                 <?php endforeach; ?>
                </select>
                        <select name = "newStatus">
                                <option value = "processing">Processing</option>
                                <option value = "shipped">Shipped</option>
                                <option value = "received">Received</option>
                        </select>
                <input type="submit" name="updateStatus" value="Update Order Status."/>
            </form>
        
        
        
        </pre></body></html>
        