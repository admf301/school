package com.example.assignment6.assignment6;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class MileRedeemerAppController {
    MileRedeemer mileRedeemer = new MileRedeemer();
    MileRedeemerApp mileRedeemerApp = new MileRedeemerApp();
    ArrayList<Destination> destinationList = mileRedeemer.getDestinationList();
    ObservableList<String> items = FXCollections.observableArrayList();

    @FXML
    private ListView<String> cityListView = new ListView<>();
    @FXML
    private TextField normMilesLabel = new TextField();
    @FXML
    private TextField superMilesLabel = new TextField();
    @FXML
    private TextField upgradeMilesLabel = new TextField();
    @FXML
    private TextField superDateLabel = new TextField();
    @FXML
    private TextField enterMilesTextField = new TextField();
    @FXML
    private TextField remainingMilesTextField = new TextField();
    @FXML
    private ChoiceBox<String> departureChoiceBox = new ChoiceBox<>();
    @FXML
    private TextArea redeemMilesTextArea = new TextArea();
    @FXML
    private Button redeemMilesButton = new Button();

    public void initialize() throws IOException {
        String file = mileRedeemerApp.getSelectedFile();        //read and process the destination file

        try {
            mileRedeemer.readDestinations(file);                //try to read the destinations of the file
        }
        catch (ArrayIndexOutOfBoundsException e) {              //error if file is not formatted correctly
            System.err.println("Error: Incorrect File Format");
            e.printStackTrace();
        }

        try {
            String[] cityNames = mileRedeemer.getCityNames();   //try to prepare/display the list of cities available
            items.addAll(Arrays.asList(cityNames));
            cityListView.setItems(items);
        }
        catch (NullPointerException e) {                        //error if file is not formatted correctly
            System.err.println("Error: Incorrect File Format");
            e.printStackTrace();
        }

        cityListView.setOnMouseClicked(event -> {               //when a city in the list is clicked
            String selectedPlace = cityListView.getSelectionModel().getSelectedItem();

            if(selectedPlace != null) {                         //populate the text views with the correct information
                for(Destination destination : destinationList) {
                    if(selectedPlace.equals(destination.getPlace())) {
                        normMilesLabel.setText(Integer.toString(destination.getBaseMileage()));
                        superMilesLabel.setText(Integer.toString(destination.getSuperMileage()));
                        upgradeMilesLabel.setText(Integer.toString(destination.getUpgradeMileage()));

                        String startMonth = monthToWord(destination.getStartDate());
                        String endMonth = monthToWord(destination.getEndDate());
                        String validMonths = startMonth + " - " + endMonth;
                        superDateLabel.setText(validMonths);
                    }
                }
            }
        });
                                                                //populate the choice box with all month options
        departureChoiceBox.getItems().addAll("Jan", "Feb", "March", "April", "May",
                                             "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec");
        departureChoiceBox.setValue("Jan");                     //and set a default choice

        redeemMilesButton.setOnAction(event -> {                //when redeem your miles button is clicked
            redeemMilesTextArea.clear();                        //clear the to-be populated areas to prepare for print
            remainingMilesTextField.clear();

            if(!isInteger(enterMilesTextField.getText())) {     //check if the given input for givenMiles is an integer
                redeemMilesTextArea.clear();                    //error if not an integer
                redeemMilesTextArea.appendText("Please enter a valid mile amount");
            }

            else {                                              //if the given input is valid
                int givenMiles = Integer.parseInt(enterMilesTextField.getText());   //get the given miles
                int givenMonth = wordToMonth(departureChoiceBox.getValue());        //and get the given month

                String[] validOffers = mileRedeemer.redeemMiles(givenMiles, givenMonth);    //get the valid offers
                for (String validOffer : validOffers) {
                    redeemMilesTextArea.appendText(validOffer + "\n");              //print each offer out
                }
                                                                                    //and print the remaining miles
                remainingMilesTextField.setText(String.valueOf(mileRedeemer.getRemainingMiles()) + " Miles");
            }
        });
    }

    //helper function that turns the integer representation of a month into the name of the month in words
    public String monthToWord(int month) {
        String[] months = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
        return months[month - 1];
    }

    //helper function that turns the name of the month in words into its integer representation
    public int wordToMonth(String month) {
        String[] months = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec"};
        int foundMonth = 0;

        for(int i = 0; i < months.length; i++) {
            if(months[i].equals(month)) {
                foundMonth = (i + 1);
            }
        }
        return foundMonth;
    }

    //helper function to determine if the given input for givenMiles is a valid integer
    public boolean isInteger(String input) {
        try {
            Integer.parseInt(input);
            return true;
        }
        catch (NumberFormatException e) {
            return false;
        }
    }
}
