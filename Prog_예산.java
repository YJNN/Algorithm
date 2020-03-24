import java.util.*;
class Solution {
	public static int solution(int[] budgets, int M) {
        int answer = 0;
        long sum = 0;
        int mid = 0;
        Arrays.sort(budgets);
        for(int i=0; i<budgets.length; i++) sum += budgets[i];
        if(sum<=M) return budgets[budgets.length-1];
        
        int left = 0;
        int right = 100000;
        while(left<=right) {
        	sum = 0;
        	mid = (left+right)/2;
        	for(int i=0; i<budgets.length; i++) {
        		if(mid <= budgets[i]) {
        			sum += mid*(budgets.length-i);
        			break;
        		}else {
        			sum += budgets[i];
        		}
        	}        
        	if(sum<=M) {
        		left = mid+1;
        		answer = mid;
        	}
        	else right = mid-1;	
        }       
        return answer;
    }
}