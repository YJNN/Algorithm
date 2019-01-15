import java.util.Scanner;

public class BOJ_9663 {
	static int[] cols;
	static int cnt = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		cols = new int[n+1];
		dfs(0,n);
		
		
		System.out.println(cnt);
	}
	
	private static void dfs(int level, int maxLow) {
		if(!isPossible(level)) {
			return;
		}else if(level==maxLow){
			cnt++;
			return;
		}
		else {
			for(int i=1; i<=maxLow; i++) {
				cols[level+1] = i;
				dfs(level+1, maxLow);
			}
		}
	}
	
	private static boolean isPossible(int level) {
		for(int i=1; i<level; i++) {
			if(cols[i]==cols[level])
				return false;
			else if((level-i)==Math.abs(cols[level]-cols[i]))
				return false;
		}
		return true;
	}

}
