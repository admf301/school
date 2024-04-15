
import java.io.IOException;
import java.util.Scanner;

public class MileRedeemerApp {
    public static MileRedeemer mileRedeemer = new MileRedeemer();
    public static Scanner inputScanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        mileRedeemer.readDestinations(inputScanner);
        String[] cityNames = mileRedeemer.getCityNames();
        String givenInput;

        System.out.println("\n----------------------------------------------------------------");
        System.out.println("\t\tWELCOME TO THE JAVA AIRLINES MILES REDEEMER APP");
        System.out.println("----------------------------------------------------------------\n");
        System.out.println("List of destination cities your client can travel to: \n");
        for (String cityName : cityNames) {
            System.out.println(cityName);
        }

        do {
            System.out.println("\n----------------------------------------------------------------\n");
            System.out.print("Please enter your client's accumulated Frequent Flyer Miles: ");
            int givenMiles = inputScanner.nextInt();
            System.out.print("\nPlease enter your client's month of departure (1-12): ");
            int givenMonth = inputScanner.nextInt();

            String[] validOffers = mileRedeemer.redeemMiles(givenMiles, givenMonth);

            if (validOffers.length > 2) {
                System.out.println("\nYour client's Frequent Flyer Miles can be used to redeem the following tickets: \n");
            }

            for (String validOffer : validOffers) {
                System.out.println(validOffer);
            }

            System.out.println("\n----------------------------------------------------------------\n");
            System.out.print("Do you want to continue (y/n)? ");
            givenInput = inputScanner.next().toLowerCase();
        } while (givenInput.equals("y") || givenInput.equals("yes"));

        System.out.println("\n----------------------------------------------------------------");
        System.out.println("\tTHANK YOU FOR USING THE JAVA AIRLINES MILES REDEEMER APP");
        System.out.println("----------------------------------------------------------------\n");
    }
}
