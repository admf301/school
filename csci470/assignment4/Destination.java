
public class Destination {
    private String place;
    private int baseMileage;
    private int superMileage;
    private int upgradeMileage;
    private int startDate;
    private int endDate;

    public Destination(String place, int baseMileage, int superMileage, int upgradeMileage, int startDate, int endDate) {
        this.place = place;
        this.baseMileage = baseMileage;
        this.superMileage = superMileage;
        this.upgradeMileage = upgradeMileage;
        this.startDate = startDate;
        this.endDate = endDate;
    }

    public String getPlace() {
        return place;
    }
    public void setPlace(String place) {
        this.place = place;
    }
    public int getBaseMileage() {
        return baseMileage;
    }
    public void setBaseMileage(int baseMileage) {
        this.baseMileage = baseMileage;
    }
    public int getSuperMileage() {
        return superMileage;
    }
    public void setSuperMileage(int superMileage) {
        this.superMileage = superMileage;
    }
    public int getUpgradeMileage() {
        return upgradeMileage;
    }
    public void setUpgradeMileage(int upgradeMileage) {
        this.upgradeMileage = upgradeMileage;
    }
    public int getStartDate() {
        return startDate;
    }
    public void setStartDate(int startDate) {
        this.startDate = startDate;
    }
    public int getEndDate() {
        return endDate;
    }
    public void setEndDate(int endDate) {
        this.endDate = endDate;
    }
}
