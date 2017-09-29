package omg.jd.ndkexample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button helloBtn = (Button)findViewById(R.id.btn_hello);
        helloBtn.setOnClickListener(this);
        Button sumBtn = (Button)findViewById(R.id.btn_sum);
        sumBtn.setOnClickListener(this);
    }


    @Override
    public void onClick(View view) {
        switch (view.getId())
        {
            case R.id.btn_hello:
                String nativeString = helloFromNative("Your name");
                Toast.makeText(getApplicationContext(),nativeString,Toast.LENGTH_SHORT).show();
                break;
            case R.id.btn_sum:
                double[] input = new double[] { 1.0, 5.0, 3.5, 12.3, 15.0, 20.0, -2.5 };
                double sum = quadraticSum(input); // should be 820.79
                Toast.makeText(getApplicationContext(),String.valueOf(sum),Toast.LENGTH_SHORT).show();
                break;
        }
    }

    /**
     * Returns String "Hello, name!"
     * @param name - name for the input
     * @return - "Hello, name!"
     */
    private native String helloFromNative(String name);

    /**
     * Calculates quadratic sum of input array (a^2 + b^2 + ... + z^2).
     * Also prints some log from the native.
     * @param toSum - input array
     * @return - quadratic sum of the array
     */
    private native double quadraticSum(double[] toSum);

    /*
        You can of course define your own native function,
        then press alt+enter to generate necessary things into C++ files.
     */
    //private native int nativeFunction();
}
