package com.example.assignment6.assignment6;
import java.io.File;
import java.io.IOException;
import java.util.*;

public class MileRedeemer {
    ArrayList<Destination> destinationList = new ArrayList<Destination>();
    Destination[] destinationArray;
    int remainingMiles;

    public void readDestinations(String readFile) throws IOException {
        Scanner file = new Scanner(new File(readFile));         //read in the file passed from the controller

        while(file.hasNextLine()) {
            String line = file.nextLine();                      //this function takes each line of the input file
            String[] fields = line.split(";");            //and breaks it up based on the delimiter ; or -

            String place = fields[0];
            int baseMileage = Integer.parseInt(fields[1]);
            int superMileage = Integer.parseInt(fields[2]);
            int upgradeMileage = Integer.parseInt(fields[3]);

            String[] months = fields[4].split("-");
            int startMonth = Integer.parseInt(months[0]);       //then it creates a destination based on the input
            int endMonth = Integer.parseInt(months[1]);

            Destination destination = new Destination(place, baseMileage, superMileage, upgradeMileage, startMonth, endMonth);
            destinationList.add(destination);                   //and adds the newly created destination to the list
        }

        Collections.sort(destinationList, new MileageComparator());     //the created list is then sorted
        destinationArray = destinationList.toArray(new Destination[destinationList.size()]);
    }

    public String[] getCityNames() {
        String[] names = new String[destinationArray.length];   //this function just takes the name of each
                                                                //destination and adds it to an array
        for(int i = 0; i < destinationArray.length; i++) {
            names[i] = destinationArray[i].getPlace();
        }

        Arrays.sort(names);                                     //then sorts the array for printing
        return names;
    }

    public String[] redeemMiles(int miles, int month) {         //this function takes the input miles and month
        List<String> redeemedTickets = new ArrayList<>();       //and calculates valid offers from the given input
        List<Destination> checkUpgrade = new ArrayList<>();     //then returns the valid offers as a string[]
        remainingMiles = miles;
        int found = 0;

        for(Destination destination : destinationList) {        //for every destination available, check super then base
                                                                //(already sorted)
            if(destination.getSuperMileage() <= remainingMiles && (month >= destination.getStartDate() && month <= destination.getEndDate())) {
                checkUpgrade.add(destination);
                redeemedTickets.add("* A trip to " + destination.getPlace() + " In Economy Class");
                remainingMiles -= destination.getSuperMileage();
                found++;
            }
            else if(destination.getBaseMileage() <= remainingMiles) {
                checkUpgrade.add(destination);
                redeemedTickets.add("* A trip to " + destination.getPlace() + " In Economy Class");
                remainingMiles -= destination.getBaseMileage();
                found++;
            }
        }

        Collections.sort(checkUpgrade, new MileageComparator());    //sort valid destinations from longest to shortest
        for(Destination destination : checkUpgrade) {               //check all valid offers for upgrade (high to low)

            int index = redeemedTickets.indexOf("* A trip to " + destination.getPlace() + " In Economy Class");
            if(destination.getUpgradeMileage() <= remainingMiles) {
                redeemedTickets.set(index, "* A trip to " + destination.getPlace() + " In First Class");
                remainingMiles -= destination.getUpgradeMileage();
            }
        }

        if(found == 0) {                                            //if no offers are found, print no offers available
            redeemedTickets.add("Your client has not accumulated enough Frequent Flyer Miles");
        }

        return redeemedTickets.toArray(new String[0]);              //return the completed valid offers list
    }

    //helper function that returns the remaining miles after calculating the used miles
    public int getRemainingMiles() {
        return remainingMiles;
    }

    //helper function that passes the made destinationList to the controller
    public ArrayList<Destination> getDestinationList() {
        return destinationList;
    }
}
