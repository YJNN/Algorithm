import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_14620 {
	static int n;
	static int[][] map;
	static boolean[][] isVisited;
	static int[] dx = {1,-1,0,0};
	static int[] dy = {0,0,1,-1};
	static int minNum = 987654321;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		map = new int[n][n];
		isVisited = new boolean[n][n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(1,0,0);
		System.out.println(minNum);
		

	}
	
	private static void dfs(int x, int cnt, int sum) {
		if(cnt==3) {
			minNum = Math.min(sum, minNum);
			return;
		}
		
		for(int i=x; i<n-1; i++) {
			for(int j=1; j<n-1; j++) {
				if(isVisited[i][j])
					continue;
				if(!checkXY(i,j))
					continue;
				int cost = map[i][j];
				isVisited[i][j]=true;
				for(int k=0; k<4; k++) {
					int cx = i+dx[k];
					int cy = j+dy[k];
					
					isVisited[cx][cy]=true;
					cost += map[cx][cy];
				}
				dfs(i,cnt+1,sum+cost);
				
				isVisited[i][j]=false;
				for(int k=0; k<4; k++) {
					int fx = i+dx[k];
					int fy = j+dy[k];
					
					isVisited[fx][fy]=false;
				}
			}
		}
		
		
	}
	
	private static boolean checkXY(int x, int y) {
		for(int k=0; k<4; k++) {
			int cx = x+dx[k];
			int cy = y+dy[k];
			
			if(cx<0 || cy<0 || cx>=n || cy>=n || isVisited[cx][cy])
				return false;
		}
		return true;
	}

}
