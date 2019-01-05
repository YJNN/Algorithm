import java.util.Scanner;

public class BOJ_1074 {
	public static int N,R,C,cnt=0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		N = scan.nextInt();
		R = scan.nextInt();
		C = scan.nextInt();
		
		dfs((int) Math.pow(2, N),0,0);

	}
	
	public static void dfs(int n, int r, int c) {
		if(n==2) {
			if(r==R && c==C) {
				System.out.println(cnt++);
				return;
			}
			cnt++;
			
			if(r==R && c+1==C) {
				System.out.println(cnt++);
				return;
			}
			cnt++;
			
			if(r+1==R && c==C) {
				System.out.println(cnt++);
				return;
			}
			cnt++;
			
			if(r+1==R && c+1==C) {
				System.out.println(cnt++);
				return;
			}
			cnt++;
			return;
		}
		
		dfs(n/2, r, c);
		dfs(n/2, r, c+n/2);
		dfs(n/2, r+n/2, c);
		dfs(n/2, r+n/2, c+n/2);
		
	}

}
