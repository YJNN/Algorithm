import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_9465 {
	static long[][] map;
	static long[][] dp;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t;
		t = Integer.parseInt(br.readLine());
		
		for(int l=0; l<t; l++) {
			
			int n = Integer.parseInt(br.readLine());
			map = new long[2][n+1];
			dp = new long[2][n+1];
			
			//String[] line1 = br.readLine().split(" ");
			//String[] line2 = br.readLine().split(" ");
			
			for(int i=0; i<2; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j=1; j<=n; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			map[0][0]=dp[0][0]=0;
			map[1][0]=dp[1][0]=0;
			dp[0][1]=map[0][1];
			dp[1][1]=map[1][1];
			
			for(int i=2; i<=n; i++) {
				dp[0][i] = Math.max(dp[1][i-1], dp[1][i-2])+map[0][i];
				dp[1][i] = Math.max(dp[0][i-1], dp[0][i-2])+map[1][i];	
			}
			
			long ans = Math.max(dp[0][n], dp[1][n]);
			System.out.println(ans);
			
		}
	}
}
