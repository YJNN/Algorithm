import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16234 {
	static int n,L,R;
	static int[][] map;
	static boolean[][] visited;
	static boolean[][] isPossible;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};
	static int cnt=0;
	static Queue<Point> q = new LinkedList<Point>();
	static boolean flag=false;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		
		map = new int[n][n];
		visited = new boolean[n][n];
		isPossible = new boolean[n][n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());	
			}
		}

		while(true) {
			
			flag=false;
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(visited[i][j]==false) {
						q.add(new Point(i,j));
						bfs();
						initPossible();
					}
				}
			}
			
			initPossible();
			initVisit();
		
			if(!flag)
				break;
			
			++cnt;
		}
		
		System.out.println(cnt);		
	}
	
	private static void initVisit() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				visited[i][j]=false;
			}
		}	
	}
	
	private static void initPossible() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				isPossible[i][j]=false;
			}
		}	
	}
	
	private static void bfs() {
		int sum=0;
		int bCnt=0;
		ArrayList<Point> aList = new ArrayList<Point>();
		
		while(!q.isEmpty()) {
			Point p = q.poll();
			int x = p.x;
			int y = p.y;
			
			for(int i=0; i<4; i++) {
				int cx = x+dx[i];
				int cy = y+dy[i];
				
				if(cx<0 || cy<0 || cx>=n || cy>=n || visited[cx][cy])
					continue;
				
				if(L<=Math.abs(map[x][y]-map[cx][cy]) && Math.abs(map[x][y]-map[cx][cy])<=R) {
					isPossible[cx][cy]=true;
					visited[cx][cy]=true;
					sum += map[cx][cy];
					bCnt++;
					aList.add(new Point(cx,cy));
					q.add(new Point(cx,cy));
				}	
			}	
		}	
		
		int tmpAns=0;
		if(bCnt!=0)
			tmpAns = sum/bCnt;
		if(aList.size()>0) {
			for(int i=0; i<aList.size(); i++) {
				int tmpX = aList.get(i).x;
				int tmpY = aList.get(i).y;
				flag=true;
				map[tmpX][tmpY]=tmpAns;
			}
		}
		/*
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(isPossible[i][j]==true) {
					flag=true;
					map[i][j]=tmpAns;
				}
			}
		}*/
	}
	
}
class Point{
	int x,y;
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
}
