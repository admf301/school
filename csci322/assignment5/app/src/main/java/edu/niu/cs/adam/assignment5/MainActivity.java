
package edu.niu.cs.adam.assignment5;

import android.os.Bundle;

import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;

import android.view.View;

import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import androidx.navigation.ui.AppBarConfiguration;
import androidx.navigation.ui.NavigationUI;

import edu.niu.cs.adam.assignment5.databinding.ActivityMainBinding;
import android.content.Intent;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;
import android.widget.TextView;
import java.util.ArrayList;
public class MainActivity extends AppCompatActivity {

    private AppBarConfiguration appBarConfiguration;
    private ActivityMainBinding binding;
    private DatabaseManager databaseManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        setSupportActionBar(binding.toolbar);

        binding.fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "New list", Snackbar.LENGTH_LONG).setAction("Action", null).show();
                databaseManager.deleteAll();
                updateScreen();
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        updateScreen();
    }

    public void updateScreen() {
        databaseManager = new DatabaseManager(this);
        ArrayList<Product> products = databaseManager.selectAll();
        ListView listView = findViewById(R.id.listview);

        ProductAdapter adapter = new ProductAdapter(this, products);
        listView.setAdapter(adapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement

        //add action intent
        if (id == R.id.action_add) {
            Snackbar.make(findViewById(android.R.id.content), "Add selected", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();

            Intent addIntent = new Intent(MainActivity.this, InsertActivity.class);
            startActivity(addIntent);
            return true;
        }

        //update action intent
        else if (id == R.id.action_update) {
            Snackbar.make(findViewById(android.R.id.content), "update selected", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();

            Intent updateIntent = new Intent(MainActivity.this, UpdateActivity.class);
            startActivity(updateIntent);
            return true;
        }

        //delete action intent
        else if (id == R.id.action_delete) {
            Snackbar.make(findViewById(android.R.id.content), "delete selected", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();

            Intent deleteIntent = new Intent(MainActivity.this, DeleteActivity.class);
            startActivity(deleteIntent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}