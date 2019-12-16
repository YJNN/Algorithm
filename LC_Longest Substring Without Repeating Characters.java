
public class Solution {
	public static int lengthOfLongestSubstring(String s) {  
		 String tmpAns="";
	     int maxNum = 1;
	     int len = 1;
	     if(s.equals("")) {
	    	 len=0;
	    	 return len;
	     }
	     else {
	    	 tmpAns = s.charAt(0)+""; 
	     }
	    	 
	     
	     for(int i=1; i<s.length(); i++) {	  
	    	 if(s.charAt(i-1)==s.charAt(i)) {
	    		 if(maxNum<len) {
	    			 maxNum = len;
	    		 }
   			 len = 1;
   			 tmpAns = s.charAt(i)+"";
	    	 }
	    	 
	    	 else if(tmpAns.contains(s.charAt(i)+"")) {
	    		 if(maxNum<len) {
	    			 maxNum = len;
	    		 }
   			 len = 1;
   			 int idx = s.indexOf(s.charAt(i));
   			 tmpAns = s.charAt(idx+1)+"";
   			 s=s.substring(idx+1);
   			 i=0;
	    	 }
	    	 
	    	 else {
	    		 ++len;
	    		 tmpAns = tmpAns + s.charAt(i);
	    		 if(maxNum<len)
	    			 maxNum=len;
	    	 } 
	     }
	     return maxNum;
	}

}
