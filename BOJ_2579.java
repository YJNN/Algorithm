import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2579 {
	static int n;
	static int[] stairs;
	static int[] dp;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		stairs = new int[n+1];
		dp = new int[n+1];
		
		for(int i=1; i<=n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			stairs[i] = Integer.parseInt(st.nextToken());
		}
		
		stairs[0] = dp[0] = 0;
		dp[1] = stairs[1];
		dp[2] = stairs[1]+stairs[2];
		
		for(int i=3; i<=n; i++) {
			dp[i] = Math.max(dp[i-3]+stairs[i]+stairs[i-1], dp[i-2]+stairs[i]);	
		}
		
		System.out.println(dp[n]);
	}

}
