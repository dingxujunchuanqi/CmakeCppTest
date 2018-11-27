package com.example.administrator.myfirstc;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.util.Arrays;

/**
 * JNI初步用法
 */
public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /**************调用本地方法**********/
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());

        tv.setText(myJni());

        tv.setText(getSum(1, 2) + "");

        tv.setText(getStr("AAAAAAAAAAAAAA"));

        int[] arr = {1, 3, 5, 2, 4};
        showElemnet(arr);

        int[] arr_ = getArr();

        Log.i("DD", Arrays.toString(arr_) + "");
    }

    /**
     * JNI本地方法
     *
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String myJni();

    public native int getSum(int a, int b);

    public native String getStr(String str);

    public native void showElemnet(int[] arr);

    public native int[] getArr();
}
