package com.wu.e_clinet;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.widget.TextView;

public class MainInbox extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main_index);
		TextView accountMes = (TextView)this.findViewById(R.id.accountMes);
		accountMes.setText(this.getLoginMes());
	}

	private String getLoginMes(){
		Bundle bundle = getIntent().getBundleExtra("loginMes");
		String name=bundle.getString("name");
		return name;
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		//getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}
