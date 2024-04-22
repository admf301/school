<html>
    <head>
        <title>Order Updated</title>
    </head>
    <body>
        <?php
            //variables for login
            include ("secrets.php");

            //logins to database
            try {
               $dsn = "mysql:host=courses;dbname=z1893300";
               $pdo = new PDO($dsn, $username, $password);
            } //catches exception if fails
            catch(PDOexception $e) {
                echo "Connection to database failed: " . $e->getMessage();
            }

                        //updates database for product bought

            $rs = $pdo->prepare("UPDATE ORDERS SET ORDSTATUS = ? WHERE ORDER_ID = ?;");

                        //checks if execute worked, and prints a line
            if($rs->execute(array($_POST['newStatus'], $_POST['orderID'])) == true)
                echo "<h2>Successfully Updated</h2>";


        ?>
    </body>
</html>
