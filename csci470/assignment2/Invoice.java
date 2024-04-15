
public class Invoice {
    private String partNumber;
    private String partDesc;
    private int quantity;
    private double itemPrice;

    public Invoice(String partNumber, String partDesc, int quantity, double itemPrice) {
        this.partNumber = partNumber;
        this.partDesc = partDesc;
        this.quantity = quantity;
        this.itemPrice = itemPrice;
    }

    public Invoice() {
        this.partNumber = "";
        this.partDesc = "";
        this.quantity = 0;
        this.itemPrice = 0.0;
    }

    public String getPartNumber() {
        return partNumber;
    }

    public void setPartNumber() {
        this.partNumber = partNumber;
    }

    public String getPartDesc() {
        return partDesc;
    }

    public void setPartDesc() {
        this.partDesc = partDesc;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        if(quantity <= 0) {
            this.quantity = 0;
        }

        else {
            this.quantity = quantity;
        }
    }

    public double getItemPrice() {
        return itemPrice;
    }

    public void setItemPrice(double itemPrice) {
        if(itemPrice <= 0) {
            this.itemPrice = 0.0;
        }

        else {
            this.itemPrice = itemPrice;
        }
    }

    public double getInvoiceAmount() {
        return quantity * itemPrice;
    }
}
