package edu.niu.cs.adam.portfolio14;

public class Product {
    private int id;
    private String name;
    private int quantity;
    private double price;

    public Product( int newId, String newName, int newQty, double newPrice )
    {
        setId( newId );
        setName( newName );
        setQuantity(newQty);
        setPrice( newPrice );
    }//end constructor

    //Getters
    public int getId()
    {
        return id;
    }

    public String getName()
    {
        return name;
    }

    public double getPrice()
    {
        return price;
    }

    public int getQuantity()
    {
        return quantity;
    }

    //Setters
    public void setId( int newId )
    {
        id = newId;
    }

    public void setName( String newName )
    {
        name = newName;
    }

    public void setPrice( double newPrice )
    {
        price = 0.00;
        if( newPrice >= 0.00 )
            price = newPrice;
    }

    public void setQuantity(int newQuantity)
    {
        quantity = 0;
        if (newQuantity >= 0)
            quantity = newQuantity;
    }

    //Method to make displaying a Product object easier
    public String productToString()
    {
        return id + " " + name + " " + quantity + " " + price;
    }
}//end Product class

