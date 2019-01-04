import java.util.ArrayList;
import java.util.Scanner;

public class BOJ_1978 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		ArrayList aList = new ArrayList();
		int n, cnt=0;
		n = scan.nextInt();
		
		for(int i=0; i<n; i++) {
			aList.add(scan.nextInt());
		}
		
		for(int i=0; i<aList.size(); i++) {
			if(aList.get(i).equals(1))
				continue;
			
			int num = Integer.parseInt(aList.get(i).toString());
			if(num==2) 
				cnt++;
			else {
				for(int j=2; j<num; j++) {
					if((num%j)==0) {
						cnt--;
						break;
					}
					
					
				}
				cnt++;
			}
			
		}
		
		System.out.println(cnt);
	}

}
