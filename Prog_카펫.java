import java.util.*;
class Solution {
	   public static int[] solution(int brown, int red) {
	        int[] answer = new int[2];
	        int tileNum = brown+red;
	        for(int i=tileNum-1; i>=1; i--) {
	        	int horizon = i;
	        	if(tileNum%horizon==0) {
	        		int vertical = tileNum/horizon;
	        		if(horizon*2 + (vertical-2)*2 == brown) {
	        			answer[0] = horizon;
	        			answer[1] = vertical;
	        			break;
	        		}
	        	}
	        }
	        return answer;
	    }
}