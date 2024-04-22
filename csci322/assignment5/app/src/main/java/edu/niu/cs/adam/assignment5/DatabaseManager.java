
package edu.niu.cs.adam.assignment5;

import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.NonNull;

import java.util.ArrayList;

public class DatabaseManager extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "productDB",
            TABLE_NAME = "productTable",
            ITEM_ID = "id",
            ITEM_NAME = "name";

    private static final int DATABASE_VERSION = 2;

    public DatabaseManager(@NonNull Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    //create the db
    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String sqlCreate = "create table " + TABLE_NAME + "( " +
                ITEM_ID + " integer primary key autoincrement, " +
                ITEM_NAME + " text )";

        sqLiteDatabase.execSQL(sqlCreate);
    }

    //delete the table if it exists
    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int oldVersion, int newVersion) {
        String sqlDrop = "drop table if exists " + TABLE_NAME;
        sqLiteDatabase.execSQL(sqlDrop);
        onCreate(sqLiteDatabase);
    }

    //insert product into the table
    public void insertProduct(Product product) {
        String sqlInsert = "insert into " + TABLE_NAME + " values( null, '" + product.getName() + "' )";

        SQLiteDatabase database = getWritableDatabase();
        database.execSQL(sqlInsert);
        database.close();
    }

    //select all items in the current table
    public ArrayList<Product> selectAll() {
        String sqlSelect = "select * from " + TABLE_NAME;

        SQLiteDatabase database = getWritableDatabase();
        Cursor cursor = database.rawQuery(sqlSelect, null);
        ArrayList<Product> products = new ArrayList<>();

        while(cursor.moveToNext()) {
            Integer currentID = cursor.getInt(0);
            String currentName = cursor.getString(1);

            Product product = new Product(currentID, currentName);
            products.add(product);
        }

        database.close();
        return products;
    }

    public void deleteAll() {
        String sqlDrop = "delete from " + TABLE_NAME;

        SQLiteDatabase database = getWritableDatabase();
        database.execSQL(sqlDrop);
        database.close();
    }

    //delete table item by id
    public void deleteById(int id) {
        String sqlDelete = "delete from " + TABLE_NAME + " where " + ITEM_ID + "='" + id + "'";

        SQLiteDatabase database = getWritableDatabase();
        database.execSQL(sqlDelete);
        database.close();
    }

    //update table item by id
    public void updateById(int id, String name) {
        String sqlUpdate = "update " + TABLE_NAME + " set " +
                ITEM_NAME + " = '" + name + "' where " +
                ITEM_ID + " = " + id;

        SQLiteDatabase database = getWritableDatabase();
        database.execSQL(sqlUpdate);
        database.close();
    }
}
