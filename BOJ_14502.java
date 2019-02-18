import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_14502 {
	static int n,m;
	static int[][] map;
	static int[][] copyMap;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int maxNum = -1;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		map = new int[n][m];
		
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());
			}
		}
		
		dfs(0,0,0);
		System.out.println(maxNum);

	}
	
	private static void virus() {
		Queue<Point> q = new LinkedList<Point>();
		
		copyMap = new int[n][m];
		boolean[][] visited = new boolean[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				visited[i][j]=false;
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				copyMap[i][j]=map[i][j];
				if(copyMap[i][j]==2) {
					Point p  = new Point(i,j);
					q.add(p);
					visited[i][j]=true;
				}
			}
		}
		
	
	
		while(!q.isEmpty()) {
			Point point = q.poll();
			int px = point.x;
			int py = point.y;
			
			
			for(int i=0; i<4; i++) {
				int cx = px + dx[i];
				int cy = py + dy[i];
				Point nP = new Point(cx,cy);
				
				if(cx<0 || cy<0 || cx>=n || cy>=m)
					continue;
				
				if(copyMap[cx][cy]==0 && visited[cx][cy]==false) {
					visited[cx][cy]=true;
					copyMap[cx][cy]=2;
					q.add(nP);
				}
			}	
		}
		int zeroNum=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(copyMap[i][j]==0)
					zeroNum++;
			}
		}
		
		if(zeroNum > maxNum)
			maxNum = zeroNum;	
	}
	
	private static void dfs(int x, int y, int cnt) {
		if(cnt==3) {
			virus();
			return;
		}
		
		for(int i=x; i<n; i++) {
			for(int j=y; j<m; j++) {
				if(map[i][j]==0) {
					map[i][j]=1;
					dfs(i,j,cnt+1);
					map[i][j]=0;
				}
			}
			y=0;
		}
	}
}

class Point{
	int x, y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
