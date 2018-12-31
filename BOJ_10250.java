import java.util.Scanner;

public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int t;
		t = scan.nextInt();
		for(int i=0; i<t; i++) {
			int h, w, n;
			String ans="";
			h = scan.nextInt();
			w = scan.nextInt();
			n = scan.nextInt();
			
			int stair, room;
			stair = (n%h);
			room = (n/h)+1;
			
			if(stair==0) {
				room -= 1;
				stair=h;
			}
			
			if(room<10) {
				ans = stair + "0" + room;
			}
			else
				ans = stair + "" + room;
			
			System.out.println(ans);
			
		}
	}

}
