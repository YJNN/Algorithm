import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_14888 {
	static int n;
	static int[] num;
	static long tmpNum;
	static long minNum = 1000000000;
	static long maxNum = -1000000000;
	static int[] calNum;
	static int[] calculateRotation;
	static boolean[] visited;
	static ArrayList<Integer> aList = new ArrayList<>();
	static ArrayList<Integer> tmp = new ArrayList<>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		
		num = new int[n];
		calNum = new int[n-1];
		calculateRotation = new int[4];
		visited = new boolean[n-1];
		
		for(int i=0; i<n; i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<4; i++) {
			calculateRotation[i] = Integer.parseInt(st2.nextToken());
			for(int j=0; j<calculateRotation[i]; j++) {
				aList.add(i);
			}
		}
		
		for(int i=0; i<aList.size(); i++) {
			//visited[i]=true;
			tmp.add(aList.get(i));
			int tmpp = tmp.size();
			visited[i]=true;
			dfs(i,1);
			tmp.remove(tmpp-1);
			visited[i]=false;
			//visited[i]=false;
		}
		System.out.println(maxNum);
		System.out.println(minNum);
		

	}
	
	private static void dfs(int node, int cnt) {
		if(cnt == n-1) {
			for(int i=0; i<tmp.size(); i++) {
				if(i==0) {
					if(tmp.get(i)==0) {
						tmpNum = num[i]+num[i+1];
					}else if(tmp.get(i)==1) {
						tmpNum = num[i]-num[i+1];
					}else if(tmp.get(i)==2) {
						tmpNum = num[i]*num[i+1];
					}else {
						tmpNum = num[i]/num[i+1];
					}
					
				}else {
					if(tmp.get(i)==0) {
						tmpNum = tmpNum+num[i+1];
					}else if(tmp.get(i)==1) {
						tmpNum = tmpNum-num[i+1];
					}else if(tmp.get(i)==2) {
						tmpNum = tmpNum*num[i+1];
					}else {
						if(tmpNum<0) {
							tmpNum *= -1;
							tmpNum = tmpNum/num[i+1];
							tmpNum *= -1;
						}else {
							tmpNum = tmpNum/num[i+1];
						}
							
					}
					
				}
			}
			
			if(tmpNum>maxNum)
				maxNum=tmpNum;
			if(tmpNum<minNum)
				minNum=tmpNum;

			return;
		}
	
		//visited[node]=true;
		for(int i=0; i<n-1; i++) {
			if(visited[i])
				continue;
			visited[i]=true;
			tmp.add(aList.get(i));
			int tmpp = tmp.size();
			dfs(i,cnt+1);
			tmp.remove(tmpp-1);
			visited[i]=false;
			
		}
		//visited[node]=false;
	}

}
