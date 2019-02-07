import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_12100 {
	static int n;
	static int[][] map;
	static int[] dx = {-1,1,0,0}; //위,아래,왼,
	static int[] dy = {0,0,-1,1};
	static int ans=0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		map = new int[n][n];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j]=Integer.parseInt(st.nextToken());
			}
		}
	
		dfs(0);	
		System.out.println(ans);
	}
	
	private static void dfs(int cnt) {
		if(cnt==5) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(map[i][j]>ans)
						ans=map[i][j];
				}
			}
			return;
		}
		
		int[][] copyMap = new int[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				copyMap[i][j]=map[i][j];
			}
		}
		
		for(int i=0; i<4; i++) {
			move(i);
			dfs(cnt+1);
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
					map[j][k]=copyMap[j][k];
				}
			}
			
		}
		
	}
	
	private static void move(int dir) {
		if(dir==0) { //위 
			Queue<Integer> q = new LinkedList<Integer>();
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(map[j][i]!=0) {
						q.add(map[j][i]);
						map[j][i]=0;
					}
				}
				int x=0;
				while(!q.isEmpty()) {
					int now = q.poll();
					if(map[x][i]==now) {
						map[x][i] = map[x][i]*2;
						x++;
					}else if(map[x][i]==0) {
						map[x][i]=now;
					}else {
						map[++x][i]=now;
					}
				}	
			}	
		}else if(dir==1) {//아래 
			Queue<Integer> q = new LinkedList<Integer>();
			for(int i=0; i<n; i++) {
				for(int j=n-1; j>=0; j--) {
					if(map[j][i]!=0) {
						q.add(map[j][i]);
						map[j][i]=0;
					}
				}
				int x=n-1;
				while(!q.isEmpty()) {
					int now = q.poll();
					if(map[x][i]==now) {
						map[x][i] = map[x][i]*2;
						x--;
					}else if(map[x][i]==0) {
						map[x][i]=now;
					}else {
						map[--x][i]=now;
					}
				}	
			}
			
		}else if(dir==2) { //왼 
			Queue<Integer> q = new LinkedList<Integer>();
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(map[i][j]!=0) {
						q.add(map[i][j]);
						map[i][j]=0;
					}
				}
				int y=0;
				while(!q.isEmpty()) {
					int now = q.poll();
					if(map[i][y]==now) {
						map[i][y] = map[i][y]*2;
						y++;
					}else if(map[i][y]==0) {
						map[i][y]=now;
					}else {
						map[i][++y]=now;
					}
				}	
			}
	
		}else if(dir==3) { //오 	
			Queue<Integer> q = new LinkedList<Integer>();
			for(int i=0; i<n; i++) {
				for(int j=n-1; j>=0; j--) {
					if(map[i][j]!=0) {
						q.add(map[i][j]);
						map[i][j]=0;
					}
				}
				int y=n-1;
				while(!q.isEmpty()) {
					int now = q.poll();
					if(map[i][y]==now) {
						map[i][y] = map[i][y]*2;
						y--;
					}else if(map[i][y]==0) {
						map[i][y]=now;
					}else {
						map[i][--y]=now;
					}
				}	
			}
			
		}
		
	}
}
