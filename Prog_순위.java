import java.util.*;
class Solution {
	   public static int solution(int n, int[][] results) {
	        int answer = 0;
	        int[][] map = new int[n+1][n+1];    

	        for(int i=0; i<results.length; i++) {
	        	map[results[i][0]][results[i][1]] = 1;
	        }
	        
	        for(int i=1; i<=n; i++) {
	        	for(int j=1; j<=n; j++) {
	        		for(int k=1; k<=n; k++) {
	        			if(map[j][i]==1 && map[i][k]==1) map[j][k] = 1;
	        		}
	        	}
	        }
	        for(int i=1; i<=n; i++) {
	        	for(int j=1; j<=n; j++) {
	        		if(map[i][j]==1) map[j][i] = 1;
	        	}
	        }
	        
	        for(int i=1; i<=n; i++) {
	        	int possibleNum = 0;
	        	for(int j=1; j<=n; j++) {
	        		if(map[i][j]==1) ++possibleNum;
	        	}
	        	if(possibleNum == (n-1)) ++answer;
	        }
	        return answer;
	    }
}
