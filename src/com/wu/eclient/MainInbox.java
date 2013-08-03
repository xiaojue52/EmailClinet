package com.wu.eclient;

import com.wu.e_clinet.R;
import com.wu.serverjni.ServerJni;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainInbox extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main_index);
		TextView accountMes = (TextView)this.findViewById(R.id.accountMes);
		Button logout = (Button)this.findViewById(R.id.logout);
		logout.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				ServerJni.logout();
				finish();
			}
			
		});
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
