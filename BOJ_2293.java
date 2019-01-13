import java.util.Scanner;

public class BOJ_2293 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n, k, tmp;
		int[] dp = new int[10001];
		
		n = scan.nextInt();
		k = scan.nextInt();
		int[] coin = new int[n];
		
		for(int i=0; i<n; i++) {
			tmp = scan.nextInt();
			coin[i]=tmp;
		}
		
		dp[0]=1;
		for(int i=0; i<n; i++) {
			for(int j=coin[i]; j<=k; j++) {
				dp[j] = dp[j] + dp[j-coin[i]];
			}
		}
		
		System.out.println(dp[k]);
	}

}
