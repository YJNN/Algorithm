import java.util.Scanner;

public class BOJ_6064 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t, ans;
		t = scan.nextInt();
		
		for(int i=0; i<t; i++) {
			int m,n,firstX,firstY,x,y;
			ans = 0;

			boolean isTrue;
			m = scan.nextInt();
			n = scan.nextInt();
			firstX = scan.nextInt();
			firstY = scan.nextInt();
			
			x = firstX;
			y = firstY;
			
			while(true) {
				if(x<m)
					x = x+1;
				else
					x = 1;
				if(y<n)
					y = y+1;
				else
					y = 1;
				
				if(x==m && y==n) {
					isTrue=true;
					break;
				}
					
				else if(x==firstX && y==firstY) {
					isTrue=false;
					break;
				}
			}
			ans=0;
			if(isTrue) {
				x = 1;
				y = 1;
				
				while(true) {
					if(firstX==1 && firstY==1) {
						break;
					}
					
					
					if(x<m)
						x = x+1;
					else
						x = 1;
					if(y<n)
						y = y+1;
					else
						y = 1;
					
					ans++;

					if(x==firstX && y==firstY)
						break;
				}
				System.out.println(ans+1);
				
			}
			
			else
				System.out.println("-1");
		}
	}
}
