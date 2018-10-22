import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String tmp = n+"";
		int setNum=0;
		int sixNum=0;
		int nineNum=0;
		
		
		ArrayList<Integer> arr = new ArrayList<>();
		for(int i=0; i<tmp.length(); i++) {
			arr.add(Integer.parseInt(String.valueOf(tmp.charAt(i))));
		}
		
		for(int i=0; i<arr.size(); i++) {
			if(arr.get(i)==6)
				sixNum++;
			else if(arr.get(i)==9)
				nineNum++;
		}

		int tmpNum = (sixNum+nineNum)/2;
		if(sixNum!=nineNum && Math.abs(sixNum-nineNum)>=2) {
			if(sixNum>nineNum) {
				int rNum = tmpNum-nineNum;
				while(rNum!=0) {
					for(int i=0; i<arr.size(); i++) {
						if(arr.get(i)==6) {
							arr.set(i, 9);
							rNum--;
							break;
						}
					}	
				}
			}else {
				int roNum = tmpNum-sixNum;
				while(roNum!=0) {
					for(int i=0; i<arr.size(); i++) {
						if(arr.get(i)==9) {
							arr.set(i, 6);
							roNum--;
							break;
						}
					}
				}
			}
		}
		
		
		while(!arr.isEmpty()) {
			for(int i=0; i<=9; i++) {
				for(int j=0; j<arr.size(); j++) {
					if(arr.get(j)==i) {
						arr.remove(j);
						break;
					}
				}
			}

			setNum++;	
		}
		
		System.out.println(setNum);
		

	}

}
