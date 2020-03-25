import java.util.*;
class Solution {
	   public static int solution(int n, int[][] costs) {
	       int answer = 0;
	       int islandNum = 0;
	       boolean[] lineCheck = new boolean[costs.length];
	       boolean[] isVisited = new boolean[n];
	       Arrays.sort(costs, (o1, o2) -> {
	    	   if(o1[2] > o2[2]) return 1;
	    	   else return -1;
	       });
	       
	       answer = costs[0][2];
	       lineCheck[0] = true;
	       isVisited[costs[0][0]] = true;
	       isVisited[costs[0][1]] = true;
	       
	       while(true) {
	    	   for(int i=1; i<costs.length; i++) {
	    		   if(!lineCheck[i] && (isVisited[costs[i][0]] && !isVisited[costs[i][1]]) || 
	    				   (!isVisited[costs[i][0]]) && isVisited[costs[i][1]]) {
	    			   isVisited[costs[i][0]] = true;
	    			   isVisited[costs[i][1]] = true;
	    			   lineCheck[i] = true;
	    			   answer += costs[i][2];
	    			   ++islandNum;
	    			   break;
	    		   }  
	    	   }
	    	   if(islandNum==(n-2)) break;
	       }
	        return answer;
	    }
}
