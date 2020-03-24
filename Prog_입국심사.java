import java.util.*;
class Solution {
    public static long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE;
        long left = 0;
        long right = 0;
        long mid = 0;
        for(int i=0; i<times.length; i++) right = Math.max(right, times[i]);
        right = n*right;
        while(left<=right) {
        	long possibleNum = 0;
        	mid = (left+right)/2;
        	for(int i=0; i<times.length; i++) possibleNum += mid/(times[i]);
        	
        	if(possibleNum < n) left = mid+1;
        	else {
        		if(answer > mid) answer = mid;
        		right = mid-1;
        	}	
        }  
        return answer;
    }
}
