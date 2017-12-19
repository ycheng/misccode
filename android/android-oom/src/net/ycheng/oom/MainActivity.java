package net.ycheng.oom;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity {

	private Button btn;
	private EditText dataSize;
	boolean dataAllocated;
	byte oomData1[];
	byte oomData2[];
	byte oomData3[];
	byte oomData4[];
	byte oomData5[];
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		Object o;
		o = findViewById(R.id.button1);
		btn = (Button) o;
		dataSize = (EditText) findViewById(R.id.editTextSizeToUse);
		oomData1 = null;
		oomData2 = null;
		oomData3 = null;
		oomData4 = null;
		oomData5 = null;
		
		dataAllocated = false;
		updateBtnStatus();
		
		btn.setOnClickListener(new OnClickListener()
		{
			public void onClick(View v)
			{
				if (dataAllocated) { // to free
					oomData1 = null;
					oomData2 = null;
					oomData3 = null;
					oomData4 = null;
					oomData5 = null;
					
					dataAllocated = false;
					updateBtnStatus();
				} else { // to allocate
					int dataLen = Integer.parseInt(dataSize.getText().toString()) / 5;
					oomData1 = new byte[dataLen * 1024];
					oomData2 = new byte[dataLen * 1024];
					oomData3 = new byte[dataLen * 1024];
					oomData4 = new byte[dataLen * 1024];
					oomData5 = new byte[dataLen * 1024];

					dataAllocated = true;
					updateBtnStatus();
				}
			}
		});
	}
	
	private void updateBtnStatus() {
		String title;
		if (dataAllocated) {
			title = "To Release";
		} else {
			title = "To Allocate";
		}
		
		btn.setText(title);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
