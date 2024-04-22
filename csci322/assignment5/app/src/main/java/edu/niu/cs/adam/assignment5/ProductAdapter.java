
package edu.niu.cs.adam.assignment5;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.TextView;
import java.util.ArrayList;

//this class creates the desired view for each item(row) on the main page by using a
//reference layout in list_item_layout.xml
public class ProductAdapter extends ArrayAdapter<Product> {
    private LayoutInflater inflater;
    public ProductAdapter(Context context, ArrayList<Product> products) {
        super(context, R.layout.list_item_layout, products);
        inflater = LayoutInflater.from(context);
    }

    //each created row needs a checkbox and a textview
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        //create new view from reference layout
        View view = inflater.inflate(R.layout.list_item_layout, parent, false);

        //get the item at the current position in the table
        Product product = getItem(position);

        //set the current textview and checkbox according to the database
        TextView nameTextView = view.findViewById(R.id.item_name_textview);
        nameTextView.setText(product.getName());

        CheckBox checkBox = view.findViewById(R.id.item_checkbox);
        checkBox.setChecked(product.isSelected());

        return view;
    }
}