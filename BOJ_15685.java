import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_15685 {
	static int n;
	static int[][] map = new int[101][101];
	static int[] dx = {0,-1,0,1};
	static int[] dy = {1,0,-1,0};
	static int endX;
	static int endY;
	static ArrayList<Integer> curveDir = new ArrayList<Integer>();
	static int ans=0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int g = Integer.parseInt(st.nextToken());
			
			curveDir.clear();
			
			endX = x;
			endY = y;
			map[endX][endY]=1;
			
			endX = x+dx[d];
			endY = y+dy[d];
			map[endX][endY]=1;
			
			curveDir.add(d);
			
			for(int j=0; j<g; j++) {
				makeCurve(curveDir);
			}	
		}
		for(int i=0; i<100; i++) {
			for(int j=0; j<100; j++) {
				if(map[i][j]==1 && map[i][j+1]==1 && map[i+1][j]==1 && map[i+1][j+1]==1)
					ans++;
			}
		}
		
		System.out.println(ans);
	}
	
	private static void makeCurve(ArrayList<Integer> curD) {
		int curSize = curD.size();
		
		for(int i=curSize-1; i>=0; i--) {
			int dir = (curD.get(i)+1)%4;
			endX = endX+dx[dir];
			endY = endY+dy[dir];
			
			map[endX][endY]=1;
			
			curD.add(dir);
		}
	}
	

}
