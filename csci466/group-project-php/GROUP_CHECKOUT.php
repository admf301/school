<html>
    <head>
        <title>Order Confirmation</title>
    </head>
    <body>
        <?php
        session_start();

        include('login.php');
        try {
            $dsn = "mysql:host=courses;dbname=z1893300";
            $pdo = new PDO($dsn, $username, $password);
         } //catches exception if fails
         catch(PDOexception $e) {
             echo "Connection to database failed: " . $e->getMessage();
         }

        //inserts new part into the row
        $rsP = $pdo->prepare("INSERT INTO ORDERS
        (USERNAME, PAID_AMOUNT, TRACK_NUM, ORDSTATUS, CREDNUM, CVC, EXPDATE, ADDR)
        VALUES(?, ?, ?, ?, ?, ?, ?, ?);");

        $track_num = rand(1000, 100000);



        //shows if successfully added
        if($rsP->execute(array($_POST['Username'],
                                $_POST['Payment'],
                                $track_num,
                                $_POST['OrdStatus'],
                                $_POST['CredNum'],
                                $_POST['CVC'],
                                $_POST['ExpDate'],
                                $_POST['Address'])) == true)


        echo "<h2>Successfully Ordered</h2>";
        ?>
    </body>
</html>




