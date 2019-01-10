import java.util.Scanner;

public class BOJ_1547 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int m, x, y;
		int[] ball = {0,1,0,0};
		boolean isFound = false;
		m = scan.nextInt();
		
		for(int i=0; i<m; i++) {
			x = scan.nextInt();
			y = scan.nextInt();
			
			int tmp = ball[x];
			ball[x] = ball[y];
			ball[y] = tmp;
		}
		
		for(int i=1; i<=3; i++) {
			if(ball[i]==1) {
				System.out.println(i);
				isFound=true;
				break;
			}
		}
		
		if(isFound==false) {
			System.out.println("-1");
			return;
		}
		
	}

}
