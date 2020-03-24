import java.util.*;
class Solution {
	static int cnt;
	public static int solution(int[] numbers, int target) {
        int answer = 0;
        dfs(0,numbers,target,0);
        answer = cnt;
        return answer;
    }
	
	public static void dfs(int node, int[] numbers, int target, int sum) {
		if(numbers.length==node) {
			if(sum==target) ++cnt;
			return;
		}		
		dfs(node+1,numbers,target,sum+numbers[node]);
		dfs(node+1,numbers,target,sum-numbers[node]);		
	}
}