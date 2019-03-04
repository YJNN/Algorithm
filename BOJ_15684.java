import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;

public class BOJ_15684 {
	static int n,m,h;
	static int[][] map;
	//static int minNum = 987654321;
	static int ans;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		map = new int[h+1][n+1];
		
		for(int i=0; i<m; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(s.nextToken());
			int y = Integer.parseInt(s.nextToken());
				
			map[x][y]=1;
		}
		
		ans=4;
		dfs(0,1,1);
		if(ans==4)
			ans=-1;
		System.out.println(ans);
	}
	
	private static boolean move() {
		boolean flag = true;
		
		for(int i=1; i<=n; i++) {
			int ansY = i;
			for(int j=0; j<=h; j++) {
				if(map[j][ansY]==1) {
					++ansY;
				}else if(map[j][ansY-1]==1) {
					--ansY;
				}
			}
			if(ansY!=i)
				flag=false;
		}
		return flag;
	}
	
	
	private static void dfs(int cnt, int x, int y) {
		if(cnt>=ans)
			return;
		if(cnt>3)
			return;
		if(move()) {
			ans = cnt;
			return;
		}
		
		for(int i=x; i<=h; i++) {
			for(int j=y; j<n; j++) {
				if(map[i][j]==0 && map[i][j+1]==0 && map[i][j-1]==0) {
					map[i][j]=1;
					dfs(cnt+1,i,j);
					map[i][j]=0;
				}
			}
			y=1;
		}
		
	}
}
