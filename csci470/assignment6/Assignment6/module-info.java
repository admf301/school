module com.example.assignment6.assignment6 {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.desktop;


    opens com.example.assignment6.assignment6 to javafx.fxml;
    exports com.example.assignment6.assignment6;
}