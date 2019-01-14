import java.util.Scanner;

public class BOJ_1149 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[][] arr = new int[n+1][3];
		int[][] dp = new int[n+1][3];
		
		for(int i=1; i<=n; i++) {
			for(int j=0; j<3; j++) {
				arr[i][j] = scan.nextInt();
			}
		}
		dp[0][0] = arr[0][0] = 0;
		dp[0][1] = arr[0][1] = 0;
		dp[0][2] = arr[0][2] = 0;
		
		for(int i=1; i<=n; i++) {
			dp[i][0] = arr[i][0] + Math.min(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = arr[i][1] + Math.min(dp[i-1][2], dp[i-1][0]);
			dp[i][2] = arr[i][2] + Math.min(dp[i-1][0], dp[i-1][1]);
		}
		
		System.out.println(Math.min(Math.min(dp[n][0], dp[n][1]), dp[n][2]));
		

	}

}
