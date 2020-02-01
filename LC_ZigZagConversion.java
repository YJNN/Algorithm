import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static String convert(String s, int numRows) {
		if(numRows==1)
			return s;
		int row = 0;
		boolean updownFlag = false;
		ArrayList<StringBuilder> rows = new ArrayList<StringBuilder>();
		for(int i=0; i<numRows; i++)
			rows.add(new StringBuilder());
		
		for(int i=0; i<s.length(); i++) {
			rows.get(row).append(s.charAt(i));
			if(row==(numRows-1) && updownFlag==false) 
				updownFlag = true;
			else if(row==0 && updownFlag==true) 
				updownFlag = false;
			
			if(!updownFlag)
				++row;
			else if(updownFlag)
				--row;
		}
		String ans="";
		for(int i=0; i<rows.size(); i++)
			ans += rows.get(i).toString();
		return ans;
	}
}
