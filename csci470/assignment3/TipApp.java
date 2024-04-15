
import java.util.Scanner;

public class TipApp {
    private TipCalculator tipCalculator;
    private Scanner scanner;
    public TipApp() {
        tipCalculator = new TipCalculator();
        scanner = new Scanner(System.in);
    }

    public static void main(String[] args){
        System.out.println("*** Tip Calculator ***");
        TipApp tipApp = new TipApp();
        tipApp.calculateTips();
    }

    public void calculateTips() {
        do {
            System.out.print("\nEnter the bill amount: ");
            double tempAmount = checkValidBillAmount();

            System.out.print("Enter your desired tip percentage (20 equals 20%): ");
            int tempPercent = checkValidPercent();

            System.out.print("Enter the party size: ");
            int tempSize = checkValidSize();

            tipCalculator.setBillAmount(tempAmount);
            tipCalculator.setTipPercent(tempPercent);
            tipCalculator.setPartySize(tempSize);

            double totalBill = tipCalculator.getTotalBill();
            double divShare = tipCalculator.getIndividualShare();

            System.out.println("\n*** Your Bill ***\n");
            System.out.println("Bill Amount: $" + tipCalculator.getBillAmount());
            System.out.println("Tip Percentage: " + tipCalculator.getTipPercent() + "%");
            System.out.println("Party Size: " + tipCalculator.getPartySize() + "\n");
            System.out.printf("Total bill (with Tip): $%.2f%n", totalBill);
            System.out.printf("Share for Each Individual: $%.2f%n", divShare);
            System.out.print("\nAnother bill? (y/n): ");
        } while(scanner.next().equalsIgnoreCase("y"));

        System.out.println("\nGoodbye!");
    }

    public double checkValidBillAmount() {                          //these helper functions all work the same way
        double value = 0;                                           //since all values entered into the calculator
        boolean flag = false;                                       //have to be valid for their type and positive,
                                                                    //or >= zero in the case of tip percentage
        while(!flag) {
            if(scanner.hasNextDouble()) {
                value = scanner.nextDouble();

                if(value > 0) {
                    flag = true;
                }
                else {
                    System.out.println("Please enter a valid bill amount. \n");
                    System.out.print("Enter the bill amount: ");
                }
            }
            else {
                System.out.println("Please enter a valid bill amount. \n");
                scanner.next();
                System.out.print("Enter the bill amount: ");
            }
        }
        return value;
    }

    public int checkValidPercent() {
        int value = 0;
        boolean flag = false;

        while(!flag) {
            if(scanner.hasNextInt()) {
                value = scanner.nextInt();

                if(value >= 0) {
                    flag = true;
                }
                else {
                    System.out.println("Please enter a valid tip percentage. \n");
                    System.out.print("Enter your desired tip percentage (20 equals 20%): ");
                }
            }
            else {
                System.out.println("Please enter a valid tip percentage. \n");
                scanner.next();
                System.out.print("Enter your desired tip percentage (20 equals 20%): ");
            }
        }
        return value;
    }

    public int checkValidSize() {
        int value = 0;
        boolean flag = false;

        while(!flag) {
            if(scanner.hasNextInt()) {
                value = scanner.nextInt();

                if(value > 0) {
                    flag = true;
                }
                else {
                    System.out.println("Please enter a valid party size. \n");
                    System.out.print("Enter the party size: ");
                }
            }
            else {
                System.out.println("Please enter a valid party size. \n");
                scanner.next();
                System.out.print("Enter the party size: ");
            }
        }
        return value;
    }
}
