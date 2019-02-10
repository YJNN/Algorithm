import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_3190 {
	static int n,k,L;
	static int[][] board;
	static boolean[][] visited;
	static Queue<Pos> q = new LinkedList<Pos>();
	static char[] c = new char[10001];
	static int[] dx = {0,1,0,-1};  //오, 아, 왼, 위 
	static int[] dy = {1,0,-1,0};
	static int ans=0;
	static int dir = 0;
	
	static class Pos{
		int x, y;
		public Pos(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		
		board = new int[n][n];
		visited = new boolean[n][n];
		
		for(int i=0; i<k; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[x-1][y-1]=1;
		}
		
		L = Integer.parseInt(br.readLine());
		for(int i=0; i<L; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			c[Integer.parseInt(s.nextToken())] = s.nextToken().charAt(0);
		}
		
		Pos curPos = new Pos(0,0);
		visited[curPos.x][curPos.y]=true;
		q.add(curPos);
		
		while(true) {
			++ans;
			curPos = new Pos(curPos.x+dx[dir], curPos.y+dy[dir]);
			
			if(curPos.x<0 || curPos.x>=n || curPos.y<0 || curPos.y>=n || visited[curPos.x][curPos.y])
				break;
			
			if(board[curPos.x][curPos.y]==0){
				Pos retail = q.poll();
				board[retail.x][retail.y]=0;
				visited[retail.x][retail.y]=false;
			}
			
			q.add(curPos);
			visited[curPos.x][curPos.y]=true;
			
			if(c[ans]=='D' || c[ans]=='L') {
				dir = move(dir,ans);
			}
		}
		
		System.out.println(ans);
	}
	
	private static int move(int curDir, int time) {
		int nextDir = 0;
		if(c[time]=='D') {
			if(curDir==3)
				nextDir=0;
			else
				nextDir=curDir+1;
			
		}else if(c[time]=='L') {
			if(curDir==0)
				nextDir=3;
			else
				nextDir=curDir-1;		
		}
		return nextDir;
	}
}
