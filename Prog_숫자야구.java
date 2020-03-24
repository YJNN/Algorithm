import java.util.*;
class Solution {
    public static int solution(int[][] baseball) {
        int answer = 0;
        for(int i=123; i<=987; i++) {
        	String numStr = i+"";
        	boolean isPossible = false;
        	if(numStr.contains("0")) continue;
        	if(numStr.charAt(0)==numStr.charAt(1) || numStr.charAt(0)==numStr.charAt(2) ||
        			numStr.charAt(1)==numStr.charAt(2)) continue;
        	
        	for(int j=0; j<baseball.length; j++) {
        		isPossible = false;
        		int strike = 0;
        		int ball = 0;
        		String questionNumStr = baseball[j][0]+""; 
        		for(int k=0; k<3; k++) {
        			for(int l=0; l<3; l++) {
        				if(k==l && numStr.charAt(k)==questionNumStr.charAt(l)) ++strike;
        				else if(k!=l && numStr.charAt(k)==questionNumStr.charAt(l)) ++ball;
        			}
        		}
        		if(strike==baseball[j][1] && ball==baseball[j][2]) isPossible = true;
        		else break;
        	}	        	
        	if(isPossible) ++answer;	
        }
        return answer;
    }
}
