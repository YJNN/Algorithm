import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_15686 {
	static int n,m;
	static int[][] map;
	static ArrayList<Point> twoNums = new ArrayList<>();
	//static ArrayList<Integer> diff = new ArrayList<>();
	static ArrayList<Point> oneNums = new ArrayList<>();
	static boolean[] visited;
	static int ans = 987654321;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		map = new int[n][n];
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());
				if(map[i][j]==1) {
					Point point = new Point(i, j);
					oneNums.add(point);
					//diff.add(987654321);
				}else if(map[i][j]==2) {
					Point point = new Point(i, j);
					twoNums.add(point);
				}
						
			}
		}
		visited = new boolean[twoNums.size()];
		dfs(0,0);
		
		System.out.println(ans);
	}
	
	private static void dfs(int cnt, int start) {
		if(cnt==m) {	
			int distance = 0;
			for(int i=0; i<oneNums.size(); i++) {
				int minDis = 987654321;
				for(int j=0; j<twoNums.size(); j++) {
					if(visited[j]==true) {
						int dis = Math.abs(oneNums.get(i).x-twoNums.get(j).x)+Math.abs(oneNums.get(i).y-twoNums.get(j).y);
						if(minDis>dis)
							minDis=dis;
					}
				}
				distance += minDis;
			}
			
			if(ans>distance)
				ans=distance;
			
			return;
			
			/*
			for(int i=0; i<twoNums.size(); i++) {
				if(visited[i]==true) {
					int x = twoNums.get(i).x;
					int y = twoNums.get(i).y;
					
					for(int j=0; j<oneNums.size(); j++) {
						int oneX = oneNums.get(j).x;
						int oneY = oneNums.get(j).y;
						
						int num = Math.abs(x-oneX)+Math.abs(y-oneY);
						if(diff.get(j)>num) {
							diff.remove(j);
							diff.add(j, num);
						}
					}		
				}
			}	
			int sum=0;
			for(int i=0; i<diff.size(); i++) {
				sum += diff.get(i);
			}
			
			for(int i=0; i<diff.size(); i++) {
				diff.remove(i);
				diff.add(i, 987654321);
			}
			
			
			
			if(ans>sum)
				ans = sum;
	
			return;
			*/
		}
		
		for(int i=start; i<twoNums.size(); i++) {
			if(visited[i]==false) {
				visited[i]=true;
				dfs(cnt+1,i+1);
				visited[i]=false;
			}
		}
		
	}
}

class Point{
	int x,y;
	Point(int x, int y){
		this.x=x;
		this.y=y;
	}	
}

