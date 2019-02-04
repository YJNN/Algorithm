import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13460 {
	static int n,m;
	static int ans = 987654321;
	static char[][] board;
	static int[] dx = {-1,1,0,0}; //위,아래,왼,오 
	static int[] dy = {0,0,-1,1};
	//static int cnt=0;
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		board = new char[n+1][m+1];
		
		Point R=null;
		Point B=null;
		
		for(int i=0; i<n; i++) {
			String s = br.readLine();
			for(int j=0; j<m; j++) {
				board[i][j] = s.charAt(j);
				if(board[i][j]=='R')
					R = new Point(i,j);
				else if(board[i][j]=='B')
					B = new Point(i,j);
			}
		}
		
		for(int i=0; i<4; i++)
			dfs(R,B,0,i,board);
		if(ans==987654321)
			System.out.println("-1");
		else
			System.out.println(ans);
	}
	
	private static void dfs(Point R, Point B, int num, int dir, char[][] board) {
		num++;
		boolean priorityOfRed=true;
		boolean redGoal=false;
		boolean blueGoal=false;
		
		char[][] map = new char[n+1][m+1];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				map[i][j]=board[i][j];
			}
		}
		
		if(dir==0) {
			if(R.x>B.x)
				priorityOfRed=false;
		}else if(dir==1) {
			if(R.x<B.x)
				priorityOfRed=false;
			
		}else if(dir==2) {
			if(R.y>B.y)
				priorityOfRed=false;
		}else if(dir==3){
			if(R.y<B.y)
				priorityOfRed=false;
		}
		
		if(priorityOfRed) {
			while(true) {
				int cx = R.x+dx[dir];
				int cy = R.y+dy[dir];
				
				if(map[cx][cy]=='#')
					break;
				if(map[cx][cy]=='O') {
					map[R.x][R.y]='.';
					redGoal=true;
					R=null;
					break;
				}
				map[R.x][R.y]='.';
				map[cx][cy]='R';
				R = new Point(cx,cy);
			}
			
			while(true) {
				int cx = B.x+dx[dir];
				int cy = B.y+dy[dir];
				
				if(map[cx][cy]=='#' || map[cx][cy]=='R')
					break;
				if(map[cx][cy]=='O') {
					map[B.x][B.y]='.';
					blueGoal=true;
					B=null;
					break;
				}
				map[B.x][B.y]='.';
				map[cx][cy]='B';
				B = new Point(cx,cy);
			}
		}
		
		else {		
			while(true) {
				int cx = B.x+dx[dir];
				int cy = B.y+dy[dir];
				
				if(map[cx][cy]=='#')
					break;
				if(map[cx][cy]=='O') {
					map[B.x][B.y]='.';
					blueGoal=true;
					B=null;
					break;
				}
				map[B.x][B.y]='.';
				map[cx][cy]='B';
				B = new Point(cx,cy);
			}
			
			while(true) {
				int cx = R.x+dx[dir];
				int cy = R.y+dy[dir];
				
				if(map[cx][cy]=='#' || map[cx][cy]=='B')
					break;
				if(map[cx][cy]=='O') {
					map[R.x][R.y]='.';
					redGoal=true;
					R=null;
					break;
				}
				map[R.x][R.y]='.';
				map[cx][cy]='R';
				R = new Point(cx,cy);
			}	
		}
		
		if(num>10)
			return;
		if(redGoal && blueGoal)
			return;
		if(!redGoal && blueGoal)
			return;
		if(redGoal && !blueGoal) {
			ans = Math.min(num, ans);
			return;
		}
		
		for(int i=0; i<4; i++) {
			if(i==dir)
				continue;
			dfs(R,B,num,i,map);
		}
	
	}

}

class Point {
	int x, y;
	Point(int x, int y){
		this.x=x;
		this.y=y;
	}
}
