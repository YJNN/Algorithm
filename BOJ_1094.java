import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_1094 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int x;
		x = scan.nextInt();
		
		int cnt=0;
		int sum=0;
		int length=64;
		
		if(x==64) {
			System.out.println("1");
			return;
		}
		
		while(x!=sum) {
			length = length/2;
			if(length+sum>x)
				continue;
			sum = sum+length;
			cnt++;
		}
		
		System.out.println(cnt);
	}
}
