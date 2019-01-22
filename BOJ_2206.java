import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class BOJ_2206 {
	static int n,m;
	static int[][] map = new int[1001][1001];
	static boolean[][][] isVisited = new boolean[1001][1001][2];
	static final int[] dx = {-1,1,0,0};
	static final int[] dy = {0,0,1,-1};

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<n; i++) {
			String str = br.readLine();
			for(int j=0; j<m; j++) {
				map[i][j] = str.charAt(j)-'0';
			}
		}
		
		int cnt=0;
		Queue<Node> queue = new LinkedList<Node>();
		queue.add(new Node(0,0,0));
		isVisited[0][0][0] = true; //벽 x
		isVisited[0][0][1] = true; //벽 o
		boolean isTrue = false;
		
		while(!queue.isEmpty() && !isTrue) {
			int size = queue.size();
			cnt++;
			
			for(int i=0; i<size; i++) {
				Node node = queue.poll();
				
				if(node.x == n-1 && node.y == m-1) {
					isTrue = true;
					break;
				}
				
				for(int j=0; j<4; j++) {
					int cx = node.x+dx[j];
					int cy = node.y+dy[j];
					
					if(cx<0 || cy<0 || cx>=n || cy>=m)
						continue;
					if(map[cx][cy]==1) {
						if(isVisited[cx][cy][1]==false && node.change==0) {
							isVisited[cx][cy][1]=true;
							queue.add(new Node(cx, cy, 1));
						}						
					}
					
					else {
						if(isVisited[cx][cy][node.change]==false) {
							isVisited[cx][cy][node.change]=true;
							queue.add(new Node(cx, cy, node.change));
						}
					}	
				}	
			}	
		}
		
		if(isTrue)
			System.out.println(cnt);
		else
			System.out.println("-1");
	}

}

class Node{
	int x,y,change;
	
	Node(int x, int y, int change){
		this.x = x;
		this.y = y;
		this.change = change;
	}
}
