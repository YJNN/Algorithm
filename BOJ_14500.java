import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_14500 {
	static int n,m;
	static int[][] board;
	static boolean[][] visited;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int sum=0;
	static int sum2=0;
	static int maxNum=-1;
	static int minNum=987654321;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(br.readLine());
		n = Integer.parseInt(s.nextToken());
		m = Integer.parseInt(s.nextToken());
		
		board = new int[n][m];
		visited = new boolean[n][m];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!visited[i][j]) {
					visited[i][j]=true;
					sum += board[i][j];
					dfs(i,j,1);
					sum = 0;
					visited[i][j]=false;
				}
				
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				sum2=0;
				minNum=987654321;
				fYou(i,j);
			}
		}
		
		System.out.println(maxNum);
		
	}
	
	private static void fYou(int x, int y) {
		int first = board[x][y];
		int cnt=0;
		sum2 += first;
		for(int i=0; i<4; i++) {
			int cx = x+dx[i];
			int cy = y+dy[i];
			
			if(cx<0 || cy<0 || cx>=n || cy>=m)
				continue;
			if(board[cx][cy]<minNum)
				minNum=board[cx][cy];
			sum2 += board[cx][cy];
			cnt++;
		}
		
		if(cnt==4)
			sum2 -= minNum;
		
		if(sum2>maxNum)
			maxNum=sum2;
	}
	
	private static void dfs(int x, int y, int cnt) {
		if(cnt==4) {
			if(sum>maxNum)
				maxNum = sum;
			return;
		}
		
		for(int i=0; i<4; i++) {
			int cx = x+dx[i];
			int cy = y+dy[i];
			
			if(cx<0 || cy<0 || cx>=n || cy>=m || visited[cx][cy])
				continue;
			
			visited[cx][cy]=true;
			sum += board[cx][cy];
			dfs(cx,cy,cnt+1);
			visited[cx][cy]=false;
			sum -= board[cx][cy];
			
		}
	}

}
