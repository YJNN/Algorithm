import java.util.Scanner;

public class BOJ_4948 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n;
		boolean[] isNotPrime = new boolean[246913];
		int[] cnt = new int[246913];
		isNotPrime[0]=true;
		isNotPrime[1]=true;
		isNotPrime[2]=false;
		
		for(int i=2; i<246913; i++) {
			if(isNotPrime[i])
				continue;
		
			for(int j=2*i; j<246913; j+=i) {
				isNotPrime[j]=true;
			}	
		}
		
		for(int i=2; i<246913; i++) {
			cnt[i] = cnt[i-1];
			if(!isNotPrime[i])
				cnt[i]++;
		}
		
		while(true) {
			n = scan.nextInt();
			if(n==0)
				break;
			System.out.println(cnt[n*2]-cnt[n]);
			
		}
	}

}
