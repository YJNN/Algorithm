import java.util.*;
class Solution {
	   public static long solution(int n, int[] works) {
	        long answer = 0;
	        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
	        for(int i=0; i<works.length; i++) pq.offer(works[i]);
	        while(n!=0) {	
	        	if(pq.peek()==0) break;
	        	int maxNum = pq.poll();
	        	--maxNum;
	        	pq.offer(maxNum);
	        	--n;
	        }	        
	        while(!pq.isEmpty()) {
	        	answer += Math.pow(pq.poll(), 2);
	        }	        
	        return answer;
	    }
}
