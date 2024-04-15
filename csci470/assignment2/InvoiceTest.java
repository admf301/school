
import java.text.DecimalFormat;

public class InvoiceTest {
    public static void main(String[] args) {
        DecimalFormat givenFormat = new DecimalFormat("$#,###,###,##0.00");
        Invoice invoice1 = new Invoice("AB-23-4312", "Cordless Drill", 10, 189.00);
        Invoice invoice2 = new Invoice("FC-96-78C3", "Shop-vac", 4, 114.99);
        Invoice invoice3 = new Invoice("TG-80-B441", "Hammer", 12, 34.50);
        Invoice invoice4 = new Invoice("ZR-39-790E", "Hacksaw", 8, 59.50);
        Invoice invoice5 = new Invoice("JN-55-AD4F", "Stud Finder", 2, 89.99);

        Invoice[] invoiceArray = {invoice1, invoice2, invoice3, invoice4, invoice5};

        int count = 1;
        for(Invoice invoice : invoiceArray) {                               //for each invoice in the invoice array,
            System.out.println("Invoice #" + count);                        //print a formatted output.
            System.out.println("\t" + "    Part No.: " + invoice.getPartNumber());
            System.out.println("\t" +"  Part Desc.: " + invoice.getPartDesc());
            System.out.println("\t" +"    Quantity: " + invoice.getQuantity());
            System.out.printf("\t" +"  Item Price: %.2f%n", invoice.getItemPrice());
            System.out.println("Invoice Subtotal:" + "\t" + "   " + givenFormat.format(invoice.getInvoiceAmount()));
            System.out.println("*********************************\n");
            count++;
        }
    }
}
