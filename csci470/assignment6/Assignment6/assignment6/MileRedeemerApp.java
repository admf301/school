package com.example.assignment6.assignment6;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import java.io.File;

public class MileRedeemerApp extends Application {

    public static void main(String[] args) {
        launch(args);
    }       //invokeLater would cause infinite loading(?)

    @Override
    public void start(Stage stage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("MileRedeemerAppUI.fxml"));
        Scene scene = new Scene(root);
        stage.setTitle("Mile Redeemer App");                                    //call the MileRedeemerAppUI
        stage.setScene(scene);
        stage.show();
    }

    //this function prompts for and returns the selected file used for input
    public String getSelectedFile() {
        try {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Select File");
            File selectedFile = fileChooser.showOpenDialog(null);   //prompt the user for an input file
            return selectedFile.toString();                                     //return the filename as a string
        }
        catch (NullPointerException e) {                                        //error if file is not found
            System.err.println("Error: Can not Find File");
            e.printStackTrace();
            return null;
        }
    }
}
