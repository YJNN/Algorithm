import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1953 {
	static int n;
	static int[] team;
	static int[][] teamMap;
	static Queue<Integer> q = new LinkedList<Integer>();
	static int blueTeam, whiteTeam;
		
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(br.readLine());
		team = new int[n+1];
		teamMap = new int[n+1][n+1];
		
		for(int i=1; i<=n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			for(int j=0; j<num; j++) {
				int one = Integer.parseInt(st.nextToken());
				teamMap[i][one] = 1;
				teamMap[one][i] = 1;
			}
		}
		
		for(int i=1; i<=n; i++) {
			if(team[i]!=0)
				continue;
			
			q.add(i);
			team[i]=1;
			
			while(!q.isEmpty()) {
				int now = q.poll();
				
				for(int j=1; j<=n; j++) {
					if(team[j]!=0)
						continue;
					if(teamMap[now][j]==1) {
						team[j] = team[now]*-1;
						q.add(j);
					}
				}
				
			}	
		}
		
		for(int i=1; i<=n; i++) {
			if(team[i]==1) {
				blueTeam++;
			}else {
				whiteTeam++;
			}
		}
		System.out.println(blueTeam);
		for(int i=1; i<=n; i++) {
			if(team[i]==1)
				System.out.print(i+" ");
		}
		System.out.println();
		System.out.println(whiteTeam);
		for(int i=1; i<=n; i++) {
			if(team[i]!=1)
				System.out.print(i+" ");
		}
		System.out.println();
	}

}
