
public class TipCalculator {
    private double billAmount;
    private int tipPercent;
    private int partySize;

    public TipCalculator() {
        billAmount = 0.0;
        tipPercent = 20;
        partySize = 1;
    }
    public double getBillAmount() {
        return billAmount;
    }
    public void setBillAmount(double billAmount) {
        this.billAmount = billAmount;
    }
    public int getTipPercent() {
        return tipPercent;
    }
    public void setTipPercent(int tipPercent) {
        this.tipPercent = tipPercent;
    }
    public int getPartySize() {
        return partySize;
    }
    public void setPartySize(int partySize) {
        this.partySize = partySize;
    }
    public double getTotalBill() {
        return billAmount + (billAmount * tipPercent/100);
    }
    public double getIndividualShare() {
        return getTotalBill()/partySize;
    }
}
