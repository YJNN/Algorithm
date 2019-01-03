import java.util.Scanner;

public class BOJ_6064_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t;
		t = scan.nextInt();
		
		for(int i=0; i<t; i++) {
			int m,n,x,y,tmp,ans = 0;

			m = scan.nextInt();
			n = scan.nextInt();
			x = scan.nextInt();
			y = scan.nextInt();
			
			ans = x % (m+1);
			tmp = x;
			
			for(int j=0; j<n; j++) {
				int tmpY;
				
				if((tmp%n)==0){
					tmpY = n;
				}else {
					tmpY = tmp%n;
				}

				
				if(tmpY==y)
					break;
				
				tmp = tmpY+m;
				ans = ans+m;
			}	
			

			if(ans>lcm(m,n)) {
				System.out.println("-1");
			}else {
				System.out.println(ans);
			}
		}
		
		
	}
	
	public static int gcd(int a, int b) {
	    while (b != 0) {
	        int r = a % b;
	        a = b;
	        b = r;
	    }
	    return a;
	}
	 
	public static int lcm(int a, int b) {
	    return a * b / gcd(a, b);
	}
}
