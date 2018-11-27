package com.example.administrator.myfirstc;

/**
 * Created by dingxujun on 2018/3/5.
 *
 * @project ASwork
 */

public class CC {
    private MainActivity activity;

    public CC(MainActivity activity) {
        this.activity = activity;
    }
     public void get(){
         activity.getArr();
     }
}
