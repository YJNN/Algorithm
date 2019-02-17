import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14501 {
	static int n;
	static int[] days;
	static int[] costs;
	static boolean[] visited;
	static int maxNum = -1;
	static int sum = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		days = new int[n+1];
		costs = new int[n+1];
		visited = new boolean[n+1];
		days[0]=0;
		costs[0]=0;
		
		for(int i=1; i<=n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			days[i] = Integer.parseInt(st.nextToken());
			costs[i] =Integer.parseInt(st.nextToken());
		}
		
		dfs(1,0);
		
		System.out.println(maxNum);
	}
	
	private static void dfs(int start, int sum) {
		if(start>n) {
			if(sum>maxNum)
				maxNum=sum;
			return;
		}
		
		if(start+days[start]<=n+1) {
			dfs(start+days[start],sum+costs[start]);
		}
			
		if(start+1<=n+1)
			dfs(start+1,sum);
	}
}
