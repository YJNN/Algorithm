import java.io.*;
import java.util.*;
class Solution {
       public static int solution(String numbers) {
       int answer = 0;
       char[] tmp = numbers.toCharArray();
       String tmp2 = "";
       int maxNum = 0;
       boolean[] isPrime;
       boolean[] isCheck = new boolean[10];
       int[] isCheckNum = new int[10];
       for(int i=0; i<tmp.length; i++) {
    	   isCheck[Integer.parseInt(tmp[i]+"")] = true;
    	   ++isCheckNum[Integer.parseInt(tmp[i]+"")];
       }       
       Arrays.sort(tmp);
       for(int i=tmp.length-1; i>=0; i--) tmp2 += tmp[i];
       maxNum = Integer.parseInt(tmp2);  
       isPrime = new boolean[maxNum+1];
       isPossible(maxNum, isPrime);
       for(int i=2; i<=maxNum; i++) {
    	   if(!isPrime[i]) continue;
    	   String ansNum = i+"";
    	   int[] isCheckNum2 = new int[10];
    	   boolean flag = false;
    	   for(int j=0; j<ansNum.length(); j++) {
    		   ++isCheckNum2[Integer.parseInt(ansNum.charAt(j)+"")];
    		   if(!isCheck[Integer.parseInt(ansNum.charAt(j)+"")]) break;   		   
    		   else {      		   
    			   if(j==ansNum.length()-1) {
    				   for(int k=0; k<isCheckNum2.length;k++) {
    					   if(isCheckNum2[k]>isCheckNum[k]) {
    						   flag = true;
    						   break;  						   
    					   }
    				   }
    				   if(flag) break;
    				   ++answer;
    			   }
    		   }
    	   }   
       }
       return answer;
    }
    public static void isPossible(int maxNum, boolean[] isPrime) {
    	isPrime[0] = isPrime[1] = false;
    	for(int i=2; i<=maxNum; i++) isPrime[i] = true;
    	for(int i=2; i*i<=maxNum; i++) {
    		for(int j=i*i; j<=maxNum; j+=i) {
    			isPrime[j] = false;
    		}	
    	}
    }
}