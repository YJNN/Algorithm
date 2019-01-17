import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_15649 {
	static int n;
	static int m;
	static boolean[] isVisited = new boolean[9];
	static ArrayList aList = new ArrayList();
	static int cnt=0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		n = scan.nextInt();
		m = scan.nextInt();
		
		aList.clear();
		dfs(m);
		
	}
	
	private static void dfs(int num) {
		if(cnt==num) {
			for(int i=0; i<aList.size(); i++) {
				System.out.print(aList.get(i).toString()+" ");
			}
			System.out.println();
			return;
		}
		
		for(int i=0; i<n; i++) {
			if(isVisited[i])
				continue;
			isVisited[i]=true;
			cnt++;
			String s = String.valueOf(i+1);
			aList.add(s);
			dfs(num);
			cnt--;
			isVisited[i]=false;
			int tmp = aList.size();
			aList.remove(tmp-1);
		}
	}

}
