import java.math.BigInteger;
import java.util.Scanner;

public class BOJ_1914 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int n;
		n = scan.nextInt();
		
		BigInteger ans = new BigInteger("1");
		if(n==1)
			System.out.println("1");
		else {
			for(int i=0; i<n; i++) {
				ans = ans.multiply(new BigInteger("2"));
			}
			ans = ans.subtract(new BigInteger("1"));
			System.out.println(ans);
		}
		if(n<=20) {
			hanoi(n,'1','2','3');
		}
	}
	
	private static void hanoi(int num, char src, char mid, char des) {
		if(num==1) {
			System.out.println(src+" "+des);
			return;
		}else {
			hanoi(num-1,src,des,mid);
			System.out.println(src+" "+des);
			hanoi(num-1,mid,src,des);
		}
	}

}
