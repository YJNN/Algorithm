import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14890 {
	static int n,L;
	static int[][] map;
	static int[][] map2;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		
		map = new int[n][n];
		map2 = new int[n][n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer s = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				map[i][j] = Integer.parseInt(s.nextToken());
			}
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				map2[i][j] = map[n-j-1][i];
			}
		}
		
		int i,j;
		int ans=0;
		int cnt=0;
		for(i=0; i<n; i++) {
			cnt=1;
			for(j=0; j<n-1; j++) {
				if(map[i][j]==map[i][j+1])
					cnt++;
				else if(map[i][j]+1 == map[i][j+1] && cnt>=L) {//오르막 
					cnt=1;
				}
				else if(map[i][j] == map[i][j+1]+1 && cnt>=0) {//내리막 
					cnt=(1-L);
				}else {
					break;
				}
			
			}
			if(j==n-1 && cnt>=0)
				ans++;
		}
		
		for(i=0; i<n; i++) {
			cnt=1;
			for(j=0; j<n-1; j++) {
				if(map2[i][j]==map2[i][j+1])
					cnt++;
				else if(map2[i][j]+1 == map2[i][j+1] && cnt>=L) {//오르막 
					cnt=1;
				}
				else if(map2[i][j] == map2[i][j+1]+1 && cnt>=0) {//내리막 
					cnt=(1-L);
				}else {
					break;
				}
			
			}
			if(j==n-1 && cnt>=0)
				ans++;
		}

		
		System.out.println(ans);
		
	}

}
