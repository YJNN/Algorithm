import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14499 {
	static int n,m,x,y,k;
	static int[][] map;
	static int[] rule;
	static int[] dice;
	static int[] dx = {0,0,0,-1,1};
	static int[] dy = {0,1,-1,0,0};
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		map = new int[n][m];
		rule = new int[k];
		dice = new int[6];
		for(int i=0; i<6; i++) {
			dice[i]=0;
		}
		
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());
			}
		}
		StringTokenizer s2 = new StringTokenizer(br.readLine());
		for(int i=0; i<k; i++) {
			rule[i] = Integer.parseInt(s2.nextToken());
		}
		
		for(int i=0; i<k; i++) {	
			int cx = x+dx[rule[i]];
			int cy = y+dy[rule[i]];
			
			if(cx<0 || cy<0 || cx>=n || cy>=m)
				continue;
			
			change(rule[i]);
			
			if(map[cx][cy]==0) {
				map[cx][cy]=dice[5];
			}else {
				dice[5]=map[cx][cy];
				map[cx][cy]=0;
			}
			
			x = cx;
			y = cy;
			
			System.out.println(dice[2]);
			
		}
	}
	
	private static void change(int command) {
		if(command==1) {
			swapNum(dice,2,1);
			swapNum(dice,3,5);
			swapNum(dice,1,3);
		}else if(command==2) {
			swapNum(dice,2,3);
			swapNum(dice,1,3);
			swapNum(dice,3,5);
			
		}else if(command==3) {
			swapNum(dice,0,2);
			swapNum(dice,2,4);
			swapNum(dice,4,5);
			
		}else if(command==4) {
			swapNum(dice,0,2);
			swapNum(dice,0,5);
			swapNum(dice,4,5);
		}
	}
	
	private static void swapNum(int[]arr, int a, int b) {
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
		
	}

}
