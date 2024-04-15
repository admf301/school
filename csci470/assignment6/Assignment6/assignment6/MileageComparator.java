package com.example.assignment6.assignment6;
import java.util.Comparator;

public class MileageComparator implements Comparator<Destination> {
    @Override
    public int compare(Destination d1, Destination d2) {
        return (d2.getBaseMileage() - d1.getBaseMileage());
    }
}
