import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_15683 {
	static int n,m;
	static int[][] map;
	static boolean[][] visited;
	static ArrayList<Cctv> cctvList = new ArrayList<Cctv>();
	static int[] dx = {-1,0,1,0};   //북동남서 
	static int[] dy = {0,1,0,-1};
	static int[][] cctvDirection = {
			{},
			{1},
			{1,3},
			{0,1},
			{0,1,3},
			{0,1,2,3}
	};
	static int minNum = 987654321;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		map = new int[n][m];
		visited = new boolean[n][m];
		
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());
				if(map[i][j]!=0 && map[i][j]!=6)
					cctvList.add(new Cctv(i,j,map[i][j]));
			}
		}
		
		dfs(0,map);
		System.out.println(minNum);
	}
	
	private static void dfs(int cnt, int a[][]) {
		if(cnt==cctvList.size()) {
			int ret=0;
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					if(a[i][j]==0)
						ret++;
				}
			}
			if(minNum>ret)
				minNum=ret;	
			return;
		}
		
		Cctv cctvInf = cctvList.get(cnt);
		
		for(int i=0; i<4; i++) {
			int[][] tmpMap = new int[n][m];
			for(int j=0; j<n; j++) {
				for(int k=0; k<m; k++) {
					tmpMap[j][k] = a[j][k];
				}
			}
			
			
			for(int j=0; j<cctvDirection[cctvInf.cctv].length; j++) {
				int cx = cctvInf.x;
				int cy = cctvInf.y;
				int dir = (cctvDirection[cctvInf.cctv][j]-i+3)%4;
				
				while(true) {
					cx += dx[dir];
					cy += dy[dir];
					if(cx<0 || cy<0 || cx>=n || cy>=m || tmpMap[cx][cy]==6)
						break;
					tmpMap[cx][cy]=8;
				}
			}
			
			dfs(cnt+1, tmpMap);		
		}
		
	}

}

class Cctv{
	int x, y, cctv;
	Cctv(int x, int y, int cctv){
		this.x = x;
		this.y = y;
		this.cctv = cctv;
	}
	
}
