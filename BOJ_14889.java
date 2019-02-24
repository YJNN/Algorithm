import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_14889 {
	static int n;
	static int[][] map;
	static boolean[] visited;
	static boolean[] isVisited;
	static boolean[] isVisited2;
	static int minNum = 987654321;
	static int[] aTeam;
	static int[] bTeam;
	static int ans=-1;
	static int sumA=0;
	static int sumB=0;
	static ArrayList<Integer> aList = new ArrayList<Integer>();
	static ArrayList<Integer> bList = new ArrayList<Integer>();
	
	static ArrayList<Integer> teamA = new ArrayList<>();
	static ArrayList<Integer> teamB = new ArrayList<>();
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		map = new int[n][n];
		visited = new boolean[n];
		
		aTeam = new int[n/2];
		bTeam = new int[n/2];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i=0; i<n; i++) {
			visited[i]=true;
			aList.add(i);
			int tmp = aList.size()-1;
			dfs(i,1);
			aList.remove(tmp);
			visited[i]=false;
		}
		
		System.out.println(minNum);
		
	}
	
	private static void dfsSum(int v, int num) {
		if(num==2) {
			ArrayList<Integer> tmppA = new ArrayList<Integer>();
			ArrayList<Integer> tmppB = new ArrayList<Integer>();
			for(int i=0; i<teamA.size(); i++) {
				if(isVisited[i]) {
					tmppA.add(teamA.get(i));
					//System.out.print(tmppA.get(i));
				}
			}
			for(int i=0; i<teamB.size(); i++) {
				if(isVisited[i]) {
					tmppB.add(teamB.get(i));
				}
			}
	
			sumA += map[tmppA.get(0)][tmppA.get(1)];
			sumA += map[tmppA.get(1)][tmppA.get(0)];
			
			sumB += map[tmppB.get(0)][tmppB.get(1)];
			sumB += map[tmppB.get(1)][tmppB.get(0)];
			
			tmppA.clear();
			tmppB.clear();
			return;
		}
		
		for(int i=v+1; i<n/2; i++) {
			if(isVisited[i])
				continue;
			isVisited[i]=true;
			dfsSum(i,num+1);
			isVisited[i]=false;
		}	
	}
	
	private static void dfs(int node, int cnt) {
		if(cnt == n/2) {
			//System.out.println(aList.size());
			
			for(int i=0; i<n/2; i++) {
				aTeam[i]=-1;
				bTeam[i]=-1;
			}
			boolean tmpList[] = new boolean[n];

			for(int i=0; i<aList.size(); i++) {
				if(aList.get(i)!=null) {
					aTeam[i] = aList.get(i);
					tmpList[aTeam[i]] = true;
				}
			}
			ArrayList<Integer> tmpB = new ArrayList<Integer>();
			for(int i=0; i<n; i++) {
				if(!tmpList[i]) {
					tmpB.add(i);
				}
			}
			for(int i=0; i<tmpB.size(); i++)
				bTeam[i]=tmpB.get(i);
			
			
			isVisited = new boolean[n/2];
			//isVisited2 = new boolean[n/2];
			for(int i=0; i<n/2; i++) {
				teamA.add(aTeam[i]);
				teamB.add(bTeam[i]);
			}
			
			for(int i=0; i<teamA.size(); i++) {
				isVisited[i]=true;
				dfsSum(i,1);
				isVisited[i]=false;
			}
			/*
			for(int i=0; i<teamB.size(); i++) {
				isVisited2[i]=true;
				dfsSum2(i,1);
				isVisited2[i]=false;
			}
			*/
			
			teamA.clear();
			teamB.clear();
			ans = Math.abs(sumA-sumB);
			if(ans<minNum)
				minNum = ans;
			sumA=0;
			sumB=0;

			return;
		}
		
		for(int i=node+1; i<n; i++) {
			if(visited[i])
				continue;
			visited[i]=true;
			aList.add(i);
			int tmpp = aList.size()-1;
			dfs(i,cnt+1);
			aList.remove(tmpp);
			visited[i]=false;
		}
	}

}
