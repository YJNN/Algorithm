import java.util.*;
class Solution {	
    public static int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        Arrays.sort(rocks);
        int left = 1, right = distance;
        while(left<=right) {
        	int mid = (left+right)/2;
        	int prevDistance = 0;
        	int removeRockCnt = 0;
        	for(int i=0; i<rocks.length+1; i++) {
        		if(i==rocks.length) {
        			if(distance-rocks[i-1] < mid) ++removeRockCnt;
        		}else {          		
            		if(rocks[i]-prevDistance < mid) ++removeRockCnt;
            		else prevDistance = rocks[i];
        		}
        	}
        	
        	if(removeRockCnt > n) right = mid-1;
        	else {
        		left = mid+1;
        		answer = mid;
        	}       	
        }
        return answer;
    }
}
