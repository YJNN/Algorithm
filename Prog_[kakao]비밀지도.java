import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	  public static String[] solution(int n, int[] arr1, int[] arr2) {
	      String[] answer = new String[n];
	      char[] tmpAns = new char[n];    
	      String[] stArr1 = new String[n];
	      String[] stArr2 = new String[n];
	      for(int i=0; i<n; i++) {
	    	  stArr1[i]="";
	    	  stArr2[i]="";
	      }
	      
	      for(int i=0; i<arr1.length; i++) {
	    	  int[] tmpNum = new int[n];
	    	  int num = arr1[i];
	    	  int cnt = arr1.length-1;
	    	  while(num!=0) {
	    		  int res = num%2;
	    		  tmpNum[cnt] = res;
	    		  --cnt;
	    		  num = num/2;
	    	  }
	    	  for(int j=0; j<tmpNum.length; j++) stArr1[i] = stArr1[i]+tmpNum[j];  
	      }
	      for(int i=0; i<arr2.length; i++) {
	    	  int[] tmpNum = new int[n];
	    	  int num = arr2[i];
	    	  int cnt = arr2.length-1;
	    	  while(num!=0) {
	    		  int res = num%2;
	    		  tmpNum[cnt] = res;
	    		  --cnt;
	    		  num = num/2;
	    	  }
	    	  for(int j=0; j<tmpNum.length; j++) stArr2[i] = stArr2[i]+tmpNum[j];  
	      }
	      for(int i=0; i<stArr1.length; i++) {
	    	  for(int j=0; j<stArr1.length; j++) {
	    		  if(stArr1[i].charAt(j)=='0' && stArr2[i].charAt(j)=='0') tmpAns[j] = ' ';
	    		  else tmpAns[j] = '#';	  
	    	  } 
	    	  answer[i] = String.valueOf(tmpAns);
	      }
	      return answer;
	  }
}
