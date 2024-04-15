
import java.io.File;
import java.io.IOException;
import java.util.*;
public class MileRedeemer {
    ArrayList<Destination> destinationList = new ArrayList<Destination>();
    Destination[] destinationArray;

    public void readDestinations(Scanner filescanner) throws IOException {
        System.out.print("Please enter the name of the file: ");

        if(filescanner.hasNext()) {
            Scanner file = new Scanner(new File(filescanner.next()));

            while(file.hasNextLine()) {
                String line = file.nextLine();
                String[] fields = line.split(";");

                String place = fields[0];
                int baseMileage = Integer.parseInt(fields[1]);
                int superMileage = Integer.parseInt(fields[2]);
                int upgradeMileage = Integer.parseInt(fields[3]);

                String[] months = fields[4].split("-");
                int startMonth = Integer.parseInt(months[0]);
                int endMonth = Integer.parseInt(months[1]);

                Destination destination = new Destination(place, baseMileage, superMileage, upgradeMileage, startMonth, endMonth);
                destinationList.add(destination);
            }
            Collections.sort(destinationList, new MileageComparator());
        }
        destinationArray = (Destination[]) destinationList.toArray(new Destination[destinationList.size()]);
    }

    public String[] getCityNames() {
        String[] names = new String[destinationArray.length];

        for(int i = 0; i < destinationArray.length; i++) {
            names[i] = destinationArray[i].getPlace();
        }

        Arrays.sort(names);
        return names;
    }

    public String[] redeemMiles(int miles, int month) {
        List<String> redeemedTickets = new ArrayList<>();
        List<Destination> checkUpgrade = new ArrayList<>();
        int remainingMiles = miles;
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

        if(found == 0) {
            redeemedTickets.add("\n*** Your client has not accumulated enough Frequent Flyer Miles ***");
        }

        redeemedTickets.add("\nYour client's remaining Frequent Flyer Miles: " + remainingMiles);
        return redeemedTickets.toArray(new String[0]);
    }
}
