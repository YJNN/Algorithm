import java.util.ArrayList;

public class Solution {
	public static boolean isPalindrome(int x) {
		boolean ans = true;
		String str = x+"";
		ArrayList<String> aList = new ArrayList<String>();
		
		if(str.length()==1)
			return true;
		if(x<0)
			return false;
		if(str.length()%2==0) {
			for(int i=0; i<str.length()/2; i++) {
				aList.add(str.charAt(i)+"");
			}
			for(int i=str.length()-1; i>=str.length()/2; i--) {
				if(!(str.charAt(i)+"").equals(aList.get((i-str.length()+1)*-1))){
					return false;
				}
			}
			
		}else {
			for(int i=0; i<str.length()/2; i++) {
				aList.add(str.charAt(i)+"");
			}
			for(int i=str.length()-1; i>str.length()/2; i--) {
				if(!(str.charAt(i)+"").equals(aList.get((i-str.length()+1)*-1))){
					return false;
				}
			}
		}
		return ans;      
    }
}
