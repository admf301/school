
package edu.niu.cs.adam.assignment5;

public class Product {
    private int id;
    private String name;
    private boolean isSelected;
    public Product(int newId, String newName)
    {
        setId( newId );
        setName( newName );
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
    public boolean isSelected() { return isSelected; }

    //Setters
    public void setId( int newId )
    {
        id = newId;
    }

    public void setName( String newName )
    {
        name = newName;
    }
    public void setSelected(boolean selected) { isSelected = selected; }

    //Method to make displaying a Product object easier
    public String productToString()
    {
        return name;
    }
}//end Product class
