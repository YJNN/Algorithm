import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_3190 {
	static int n,k,L;
	static int[][] board;
	static boolean[][] isVisited;
	static String[] s = new String[10001];
	static int ans=1;
	static int num=1;
	static int tail=0;
	static int[] dx = {-1,1,0,0}; 
	static int[] dy = {0,0,-1,1};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		k = Integer.parseInt(br.readLine());
		
		board = new int[n][n];
		isVisited = new boolean[n][n];
		
		for(int i=0; i<k; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			board[x-1][y-1]=1;
		}
		
		L = Integer.parseInt(br.readLine());
		
		for(int i=0; i<L; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			String c = st.nextToken();
			
			s[cnt]=c;
		}

		isVisited[0][0]=true;
		move(3,0,0,num);
	
		System.out.println(ans);
	}
	
	
	private static void move(int dir, int x, int y, int num) {
		if(dir==0) { //위 		
			if(s[num]!=null) {
				if(s[num].equals("D")) {
					int cy = y+1;
					if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
						return;
					if(board[x][cy]==1) {
						isVisited[x][cy]=true;
						board[x][cy]=0;
						ans++;
						move(3,x,cy,num+1);	
					}else {
						isVisited[x][y]=false;
						isVisited[x][cy]=true;
						ans++;
						move(3,x,cy,num+1);
					}
					
				}else if(s[num].equals("L")) {
					int cy = y-1;
					if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
						return;
					if(board[x][cy]==1) {
						isVisited[x][cy]=true;
						board[x][cy]=0;
						ans++;
						move(2,x,cy,num+1);
					}else {
						isVisited[x][y]=false;
						isVisited[x][cy]=true;
						ans++;
						move(2,x,cy,num+1);
					}
					
				}
			}else {
				int cx = x-1;
				if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y])
					return;
				if(board[cx][y]==1) {
					isVisited[cx][y]=true;
					board[cx][y]=0;
					ans++;
					move(0,cx,y,num+1);
				}else {
					isVisited[x][y]=false;
					isVisited[cx][y]=true;
					ans++;
					move(0,cx,y,num+1);
				}
			
			}
	
		}else if(dir==1) { //아래 
			if(s[num]!=null) {
				if(s[num].equals("D")) {
					int cy = y-1;
					if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
						return;
					if(board[x][cy]==1) {
						isVisited[x][cy]=true;
						board[x][cy]=0;
						ans++;
						move(2,x,cy,num+1);	
					}else {
						isVisited[x][y]=false;
						isVisited[x][cy]=true;
						ans++;
						move(2,x,cy,num+1);
					}
					
				}else if(s[num].equals("L")) {
					int cy = y+1;
					if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
						return;
					if(board[x][cy]==1) {
						isVisited[x][cy]=true;
						board[x][cy]=0;
						ans++;
						move(3,x,cy,num+1);
					}else {
						isVisited[x][y]=false;
						isVisited[x][cy]=true;
						ans++;
						move(3,x,cy,num+1);
					}
					
				}
			}else {
				int cx = x+1;
				if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y])
					return;
				if(board[cx][y]==1) {
					isVisited[cx][y]=true;
					board[cx][y]=0;
					ans++;
					move(1,cx,y,num+1);
				}else {
					isVisited[x][y]=false;
					isVisited[cx][y]=true;
					ans++;
					move(1,cx,y,num+1);
				}
			
			}
	
		}else if(dir==2) { //왼 
			if(s[num]!=null) {
				if(s[num].equals("D")) {
					int cx = x-1;
					if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y])
						return;
					if(board[cx][y]==1) {
						isVisited[cx][y]=true;
						board[cx][y]=0;
						ans++;
						move(0,cx,y,num+1);	
					}else {
						isVisited[x][y]=false;
						isVisited[cx][y]=true;
						ans++;
						move(0,cx,y,num+1);
					}
					
				}else if(s[num].equals("L")) {
					int cx = x+1;
					if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y])
						return;
					if(board[cx][y]==1) {
						isVisited[cx][y]=true;
						board[cx][y]=0;
						ans++;
						move(1,cx,y,num+1);
					}else {
						isVisited[x][y]=false;
						isVisited[cx][y]=true;
						ans++;
						move(1,cx,y,num+1);
					}
					
				}
			}else {
				int cy = y-1;
				if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
					return;
				if(board[x][cy]==1) {
					isVisited[x][cy]=true;
					board[x][cy]=0;
					ans++;
					move(2,x,cy,num+1);
				}else {
					isVisited[x][y]=false;
					isVisited[x][cy]=true;
					ans++;
					move(2,x,cy,num+1);
				}
			}
				
		}else if(dir==3) { //오 
			if(s[num]!=null) {
				if(s[num].equals("D")) {
					int cx = x+1;
					if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y]) {
						System.exit(0);
					}
					if(board[cx][y]==1) {
						isVisited[cx][y]=true;
						board[cx][y]=0;
						ans++;
						move(1,cx,y,num+1);
					}else {
						isVisited[x][y]=false;
						isVisited[cx][y]=true;
						ans++;
						move(1,cx,y,num+1);
					}
					
					
				}else if(s[num].equals("L")) {
					int cx = x-1;
					if(cx<0 || y<0 || cx>=n || y>=n || isVisited[cx][y])
						System.exit(0);
					if(board[cx][y]==1) {
						isVisited[cx][y]=true;
						board[cx][y]=0;
						ans++;
						move(0,cx,y,num+1);
					}else {
						isVisited[x][y]=false;
						isVisited[cx][y]=true;
						ans++;
						move(0,cx,y,num+1);
					}
					
					
				}
			}else {
				int cy = y+1;
				if(x<0 || cy<0 || x>=n || cy>=n || isVisited[x][cy])
					return;
				if(board[x][cy]==1) {
					isVisited[x][cy]=true;
					board[x][cy]=0;
					ans++;
					move(3,x,cy,num+1);
				}else {
					isVisited[x][y]=false;
					isVisited[x][cy]=true;
					ans++;
					move(3,x,cy,num+1);
				}
			}		
		}
	}

}
