import java.io.*;
import java.util.*;
class Solution {
	  public static int solution(String dartResult) {
	      int answer = 0;
	      int numPoint = 0;
	      String[] scores = new String[3];
	      for(int i=0; i<scores.length; i++) scores[i] = "";
	      for(int i=0; i<scores.length; i++) {
	    	  for(int j=numPoint; j<dartResult.length()-1; j++) {
	    		  scores[i] += dartResult.charAt(j)+"";
	    		  if(Character.isDigit(dartResult.charAt(j+1))) {
	    			  if(!Character.isDigit(dartResult.charAt(j))) {
	    				  numPoint = j+1;
	    				  break;
	    			  }
	    		  }
	    	  }
	      }
	      scores[2] += dartResult.charAt(dartResult.length()-1);
	      int[] score = new int[3];
	      for(int i=0; i<score.length; i++) score[i]=0;
	      for(int i=0; i<scores.length; i++) {
	    	  int tmpNum= 0 ;
	    	  String tmp="";
	    	  for(int j=0; j<scores[i].length(); j++) {    		  
	    		  if(Character.isDigit(scores[i].charAt(j))) {
	    			  tmp += scores[i].charAt(j);
	    			  continue;
	    		  }
	    		  tmpNum = Integer.parseInt(tmp);
	    		  if(scores[i].charAt(j)=='S') {
	    			  tmpNum *= 1;
	    			  break;
	    		  }
	    		  else if(scores[i].charAt(j)=='D') {
	    			  tmpNum = tmpNum*tmpNum;
	    			  break;
	    		  }
	    		  else if(scores[i].charAt(j)=='T') {
	    			  tmpNum = tmpNum*tmpNum*tmpNum;
	    			  break;
	    		  }
	    	  }
  		  score[i] = tmpNum; 
	      }
	      for(int i=0; i<scores.length; i++) {
	    	  if(scores[i].contains("#")) {
	    		  score[i] *= -1;
	    	  }
	    	  else if(scores[i].contains("*")) {
	    		  if(i==0) score[i] *= 2;
	    		  else {
	    			  score[i-1] *= 2;
	    			  score[i] *= 2;
	    		  } 
	    	  }
	    	  
	      }
	      for(int i=0; i<score.length; i++) answer += score[i];      
	      return answer;
	  }
}