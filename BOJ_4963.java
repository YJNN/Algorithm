import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_4963 {
	static int w,h;
	static int[][] island;
	static boolean[][] isVisited;
	static int[] dx = {-1,1,0,0,1,1,-1,-1};
	static int[] dy = {0,0,1,-1,-1,1,-1,1};
	static int cnt=0;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());
			island = new int[h+1][w+1];
			isVisited = new boolean[h+1][w+1];
			cnt=0;
			
			if(w==0 && h==0)
				break;
			
			for(int i=0; i<h; i++) {
				StringTokenizer s = new StringTokenizer(br.readLine());
				for(int j=0; j<w; j++) {
					island[i][j] = Integer.parseInt(s.nextToken());
				}
			}
			
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					if(isVisited[i][j])
						continue;
					else if(isVisited[i][j]==false && island[i][j]==1){
						cnt++;
						isVisited[i][j]=true;
						dfs(i,j);
					}
					
				}
			}
			System.out.println(cnt);
		}
	}
	
	private static void dfs(int x, int y) {
		
		for(int i=0; i<8; i++) {
			int cx = x+dx[i];
			int cy = y+dy[i];
			
			if(cx<0 || cy<0 || cx>=h || cy>=w)
				continue;
			
			if(isVisited[cx][cy]==false && island[cx][cy]==1) {
				isVisited[cx][cy]=true;
				dfs(cx, cy);
			}	
		}
	}

}
