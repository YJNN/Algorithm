import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static int romanToInt(String s) {
		 Map<String, Integer> map = new HashMap<String, Integer>();
		 map.put("I", 1);
		 map.put("V", 5);
		 map.put("X", 10);
		 map.put("L", 50);
		 map.put("C", 100);
		 map.put("D", 500);
		 map.put("M", 1000);
		 int ans = 0;
		 
		 
		 for(int i=0; i<s.length(); i++) {
			 if(i==s.length()-1) {
				 return ans+map.get(s.charAt(i)+"");
				 
			 }else {
				 if(map.get(s.charAt(i)+"") >= map.get(s.charAt(i+1)+"")) {
					 ans += map.get(s.charAt(i)+"");
				 }else {
					 ans -= map.get(s.charAt(i)+"");
				 }
			 }
		 }
		 
	     return ans;   
	 }
}
