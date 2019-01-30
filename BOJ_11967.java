import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_11967 {
	static int n,m;
	static boolean[][] isVisited;
	static boolean[][] isTurned;
	//static boolean[][] isPossibleLight;
	static ArrayList<Integer>[] map;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int cnt = 1;
	static Queue<Integer> q = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		isVisited = new boolean[n][n];
		isTurned = new boolean[n][n];
		map = new ArrayList[n*n];
		for(int i=0; i<n*n; i++) {
			map[i] = new ArrayList<Integer>();
		}
		
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken())-1;
			int y = Integer.parseInt(st.nextToken())-1;
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			
			map[x*n+y].add(a*n+b);
		}
		isVisited[0][0]=true;
		isTurned[0][0]=true;
		q.add(0);
		
		while(!q.isEmpty()) {
			int now = q.poll();
			int x = now/n;
			int y = now%n;
			turnLight(now);
			
			for(int i=0; i<4; i++) {
				int cx = x+dx[i];
				int cy = y+dy[i];
				
				if(cx<0 || cy<0 || cx>=n || cy>=n || isVisited[cx][cy] || !isTurned[cx][cy])
					continue;
				
				isVisited[cx][cy]=true;
				q.add(cx*n+cy);	
			}
		}
		
		System.out.println(cnt);
	}
	
	private static void turnLight(int xy) {
		for(int i=0; i<map[xy].size(); i++) {
			int now = map[xy].get(i);
			int x = now/n;
			int y = now%n;
			
			if(isTurned[x][y])
				continue;
			isTurned[x][y]=true;
			cnt++;
			
			for(int j=0; j<4; j++) {
				int cx = x+dx[j];
				int cy = y+dy[j];
				
				if(cx<0 || cy<0 || cx>=n || cy>=n)
					continue;
				if(isVisited[cx][cy]) {
					q.add(cx*n+cy);
					break;
				}	
			}	
		}	
	}
	
	

}
