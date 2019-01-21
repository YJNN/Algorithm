import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class BOJ_15663 {
	static Boolean[] visited;
	//static Boolean[] checked;
	static int[] arr;
	static int[] ret;
	static int n,m;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		n = scan.nextInt();
		m = scan.nextInt();
		
		arr = new int[n];
		ret = new int[n];
		//checked = new Boolean[n+1];
		visited = new Boolean[n];
		for(int i=0; i<visited.length; i++)
			visited[i]=false;
		for(int i=0; i<n; i++) {
			int tmp = scan.nextInt();
			arr[i] = tmp;
		}

		Arrays.sort(arr);
		
		dfs(0);
	
	}
	
	private static void dfs(int length) {
		if(length==m) {
			for(int i=0; i<m; i++) {
				System.out.print(ret[i]+" ");
			}
			System.out.println();
			return;
		}
		Boolean[] checked = new Boolean[10001];
		for(int i=0; i<checked.length; i++)
			checked[i]=false;
		for(int i=0; i<n; i++) {
			if(visited[i]==false && checked[arr[i]]==false) {
				visited[i]=true;
				checked[arr[i]]=true;
				ret[length]=arr[i];
				
				dfs(length+1);
				visited[i]=false;
			}	
		}
		
		
	}

}
