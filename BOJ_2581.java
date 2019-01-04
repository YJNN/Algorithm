import java.util.Scanner;

public class BOJ_2581 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int m,n,sum=0;
		int minNum = 10001;
		m = scan.nextInt();
		n = scan.nextInt();
		
		for(int i=m; i<=n; i++) {
			if(i==1)
				continue;
			if(i==2) {
				sum+=2;
				minNum = 2;
				continue;
			}
			
			sum+=i;
			int tmp = minNum;
			if(minNum>i)
				minNum=i;
			for(int j=2; j<i; j++) {
				if((i%j)==0) {
					sum-=i;
					minNum = tmp;
					break;
				}
			}	
		}
		
		if(minNum==10001)
			System.out.println("-1");
		else {
			System.out.println(sum);
			System.out.println(minNum);
		}

	}

}
