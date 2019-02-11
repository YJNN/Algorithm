import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13458 {
	static long n,leader,subLeader;
	static long[] room;
	static long ans=0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Long.parseLong(br.readLine());
		room = new long[1000001];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(long i=0; i<n; i++) {
			room[(int) i] = Long.parseLong(st.nextToken());
		}
		StringTokenizer s = new StringTokenizer(br.readLine());
		leader = Integer.parseInt(s.nextToken());
		subLeader = Integer.parseInt(s.nextToken());
		
		for(int i=0; i<n; i++) {
			if(room[i]-leader>=0) {
				ans++;
				room[i]=room[i]-leader;
			}else {
				ans++;
				room[i]=0;
			}		
		}
		
		for(int i=0; i<n; i++) {
			if(room[i]==0)
				continue;
			if(room[i]<subLeader) {
				ans++;
				continue;
			}else {
				if(room[i]%subLeader == 0) {
					ans = ans+room[i]/subLeader;
				}else {
					ans = ans+(room[i]/subLeader)+1;
				}
			}
		}	
		System.out.println(ans);
	}
}
