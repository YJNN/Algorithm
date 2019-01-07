import java.util.Scanner;

public class BOJ_4811 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n;
		
		while(true) {
			n = scan.nextInt();
			if(n==0)
				break;
			
			
			long[][] pillNum = new long[n*2+1][n*2+1];
			System.out.println(pill(n,0,pillNum));
			
		}
	}
	
	private static long pill(int full, int half, long[][] pillNum) {
		if((full==1 && half==0)||full==0) {
			pillNum[full][half]=1;
			return 1;
		}
		else if(half<0)
			return 0;
		
		if(pillNum[full][half]==0) {
			pillNum[full][half] = pill(full-1,half+1,pillNum)+pill(full,half-1,pillNum);
		}
		return pillNum[full][half];
	}

}
