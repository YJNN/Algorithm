import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	  public String solution(String s, int n) {
		   String answer = "";
			   for(int i=0; i<s.length(); i++) {
				  if(s.charAt(i)==' ') answer+=' ';
				  else {
					  if((s.charAt(i)+n)>90 && (s.charAt(i)+0)<=90) {
						  answer += (char)(s.charAt(i)+n-26);  
					  }else if((s.charAt(i)+0)>=97 && (s.charAt(i)+n)>122)
						  answer += (char)(s.charAt(i)+n-26);
					  else
						  answer += (char)(s.charAt(i)+n);  
				  }			 	  
			   }	
			   return answer;
		  }
}
