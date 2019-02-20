import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14503 {
	static int n,m;
	static int[][] map;
	static boolean[][] visited;
	static int startX, startY, dir;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static int ans = 1;
	static int tmpX,tmpY;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		map = new int[n][m];
		visited = new boolean[n][m];
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		startX = Integer.parseInt(st2.nextToken());
		startY = Integer.parseInt(st2.nextToken());
		dir = Integer.parseInt(st2.nextToken());
		
		for(int i=0; i<n; i++) {
			StringTokenizer st3 = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(st3.nextToken());
			}
		}
		visited[startX][startY] = true;
		dfs(startX, startY, dir, 0);
		
		//map[startX][startY] = 2;
		System.out.println(ans);
		/*
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				System.out.print(map[i][j]+" ");
			}
			System.out.println();
		}*/
	}
	
	private static void dfs(int x, int y, int d, int dirNum) {
	
		if(dirNum==4) {
			//visited[tmpX][tmpY]=true;
			int tmp;
			if(d==0) {
				tmp = 2;
			}else if(d==1) {
				tmp = 3;
			}else if(d==2) {
				tmp = 0;
			}else {
				tmp = 1;
			}
			
			int cx = tmpX+dx[tmp];
			int cy = tmpY+dy[tmp];
			
			if(map[cx][cy]==1) 
				return;
				
			else
				dfs(cx,cy,d,0);
		}
		else {
			int newDir;
			if(d==0)
				newDir = 3;
			else
				newDir = d-1;
			
			int cx = x+dx[newDir];
			int cy = y+dy[newDir];
			
			
			if(map[cx][cy]==0 && visited[cx][cy]==false) {
				ans++;
				//map[cx][cy]=2;
				visited[cx][cy]=true;
				dfs(cx,cy,newDir,0);
			}
			
			else if(map[cx][cy]==1 || visited[cx][cy]==true || cx<0 || cy<0 || cx>=n || cy>=m) {
				tmpX = x;
				tmpY = y;
				dfs(x,y,newDir,dirNum+1);
			}
		}
	}

}
