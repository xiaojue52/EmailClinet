package com.wu.e_clinet;

import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.view.Menu;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class LoginActivity extends Activity {

	private Context context;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.login);
		context = this;
		this.setListener();
		
	}

	private void setListener(){
		Button login = (Button)this.findViewById(R.id.login);
		final EditText eUsername = (EditText)this.findViewById(R.id.eUsername);
		final EditText ePassword = (EditText)this.findViewById(R.id.ePassword);
		final Spinner serverAdd = (Spinner)this.findViewById(R.id.serItems);
		ArrayAdapter< String> adapter =new ArrayAdapter< String>( this,android.R.layout.simple_spinner_item);
		adapter.add("qq.com");
		adapter.add("126.com");
		adapter.add("163.com");
		adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
		serverAdd.setAdapter(adapter);
		login.setOnClickListener(new Button.OnClickListener(){

			
			@Override
			public void onClick(View arg0) {
				// TODO Auto-generated method stub
				String username = eUsername.getText().toString();
				String password = ePassword.getText().toString();
				String server = serverAdd.getSelectedItem().toString();
				Toast.makeText(context, username+password+server, Toast.LENGTH_LONG).show();
				Intent intent = new Intent(LoginActivity.this,MainInbox.class);
				Bundle bundle=new Bundle();
				bundle.putString("name",username+"@"+server);
				intent.putExtra("loginMes",bundle);
				startActivity(intent);
			}
			
		});
		Button logCancel = (Button)this.findViewById(R.id.cancel);
		logCancel.setOnClickListener(new Button.OnClickListener(){

			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				finish();
			}
			
		});
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		//getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
