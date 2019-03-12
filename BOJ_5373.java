import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_5373 {
	static int n;
	static int t;
	static String[] rule; 
	//static char[] map;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());
		
		for(int i=0; i<t; i++) {
			
			n = Integer.parseInt(br.readLine());
			rule = new String[n];
			char map[] = {'w','w','w','w','w','w','w','w','w',
					'r','r','r','r','r','r','r','r','r',
					'g','g','g','g','g','g','g','g','g',
					'b','b','b','b','b','b','b','b','b',
					'y','y','y','y','y','y','y','y','y',
					'o','o','o','o','o','o','o','o','o',};
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				rule[j] = st.nextToken().toString();
			}
			for(int j=0; j<n; j++) {
				changeMap(rule[j],map);
			}
			int cnt=0;
			//System.out.println();
			for(int j=0; j<9; j++) {
				System.out.print(map[j]);
				++cnt;
				if(cnt==3) {
					System.out.println();
					cnt=0;
				}
				
			}
		}	
	}
	
	private static void changeMap(String rules, char[] mapp) {
		if(rules.equals("U+")) {
			swap(mapp, 51, 20);
			swap(mapp, 52, 19);
			swap(mapp, 53, 18);
			swap(mapp, 18, 9);
			swap(mapp, 19, 10);
			swap(mapp, 20, 11);
			swap(mapp, 9, 27);
			swap(mapp, 10, 28);
			swap(mapp, 11, 29);
			
			swap(mapp, 6, 0);
			swap(mapp, 2, 6);
			swap(mapp, 6, 8);
			swap(mapp, 1, 3);
			swap(mapp, 3, 5);
			swap(mapp, 3, 7);
			
		}else if(rules.equals("U-")) {
			swap(mapp, 51, 29);
			swap(mapp, 52, 28);
			swap(mapp, 53, 27);
			swap(mapp, 9, 27);
			swap(mapp, 10, 28);
			swap(mapp, 11, 29);
			swap(mapp, 18, 9);
			swap(mapp, 19, 10);
			swap(mapp, 20, 11);
			
			swap(mapp, 0, 2);
			swap(mapp, 2, 6);
			swap(mapp, 2, 8);
			swap(mapp, 1, 3);
			swap(mapp, 1, 7);
			swap(mapp, 1, 5);

		}else if(rules.equals("D+")) {
			swap(mapp, 15, 24);
			swap(mapp, 16, 25);
			swap(mapp, 17, 26);
			swap(mapp, 26, 45);
			swap(mapp, 25, 46);
			swap(mapp, 24, 47);
			swap(mapp, 45, 35);
			swap(mapp, 46, 34);
			swap(mapp, 47, 33);
			
			swap(mapp, 36, 42);
			swap(mapp, 42, 44);
			swap(mapp, 44, 38);
			swap(mapp, 43, 39);
			swap(mapp, 43, 41);
			swap(mapp, 37, 41);
	
		}else if(rules.equals("D-")) {
			swap(mapp, 15, 33);
			swap(mapp, 16, 34);
			swap(mapp, 17, 35);
			swap(mapp, 35, 45);
			swap(mapp, 34, 46);
			swap(mapp, 33, 47);
			swap(mapp, 45, 26);
			swap(mapp, 46, 25);
			swap(mapp, 47, 24);
			
			swap(mapp, 38, 36);
			swap(mapp, 38, 42);
			swap(mapp, 38, 44);
			swap(mapp, 37, 39);
			swap(mapp, 37, 43);
			swap(mapp, 37, 41);
	
		}else if(rules.equals("F+")) {
			swap(mapp, 6, 26);
			swap(mapp, 7, 23);
			swap(mapp, 8, 20);
			swap(mapp, 26, 38);
			swap(mapp, 23, 37);
			swap(mapp, 20, 36);
			swap(mapp, 36, 33);
			swap(mapp, 37, 30);
			swap(mapp, 38, 27);
			
			swap(mapp, 9, 15);
			swap(mapp, 15, 17);
			swap(mapp, 11, 17);
			swap(mapp, 16, 12);
			swap(mapp, 16, 14);
			swap(mapp, 10, 14);
	
		}else if(rules.equals("F-")) {
			swap(mapp, 6, 27);
			swap(mapp, 7, 30);
			swap(mapp, 8, 33);
			swap(mapp, 33, 36);
			swap(mapp, 30, 37);
			swap(mapp, 27, 38);
			swap(mapp, 36, 20);
			swap(mapp, 37, 23);
			swap(mapp, 38, 26);
			
			swap(mapp, 9, 11);
			swap(mapp, 11, 15);
			swap(mapp, 11, 17);
			swap(mapp, 12, 10);
			swap(mapp, 10, 14);
			swap(mapp, 14, 16);
		}else if(rules.equals("B+")) {
			swap(mapp, 35, 42);
			swap(mapp, 32, 43);
			swap(mapp, 29, 44);
			swap(mapp, 42, 18);
			swap(mapp, 43, 21);
			swap(mapp, 44, 24);
			swap(mapp, 24, 0);
			swap(mapp, 21, 1);
			swap(mapp, 18, 2);
			
			swap(mapp, 53, 47);
			swap(mapp, 47, 45);
			swap(mapp, 45, 51);
			swap(mapp, 46, 50);
			swap(mapp, 46, 52);
			swap(mapp, 46, 48);
		
		}else if(rules.equals("B-")) {
			swap(mapp, 42, 35);
			swap(mapp, 43, 32);
			swap(mapp, 44, 29);
			swap(mapp, 35, 2);
			swap(mapp, 32, 1);
			swap(mapp, 29, 0);
			swap(mapp, 0, 24);
			swap(mapp, 1, 21);
			swap(mapp, 2, 18);
			
			swap(mapp, 51, 53);
			swap(mapp, 51, 47);
			swap(mapp, 51, 45);
			swap(mapp, 52, 50);
			swap(mapp, 52, 48);
			swap(mapp, 48, 46);
					
		}else if(rules.equals("L+")) {
			swap(mapp, 0, 45);
			swap(mapp, 3, 48);
			swap(mapp, 6, 51);
			swap(mapp, 51, 42);
			swap(mapp, 48, 39);
			swap(mapp, 45, 36);
			swap(mapp, 42, 15);
			swap(mapp, 39, 12);
			swap(mapp, 36, 9);
			
			swap(mapp, 18, 24);
			swap(mapp, 24, 26);
			swap(mapp, 26, 20);
			swap(mapp, 25, 21);
			swap(mapp, 25, 23);
			swap(mapp, 19, 23);
		
		}else if(rules.equals("L-")) {
			swap(mapp, 0, 9);
			swap(mapp, 3, 12);
			swap(mapp, 6, 15);
			swap(mapp, 15, 42);
			swap(mapp, 12, 39);
			swap(mapp, 9, 36);
			swap(mapp, 42, 51);
			swap(mapp, 39, 48);
			swap(mapp, 36, 45);
			
			swap(mapp, 20, 18);
			swap(mapp, 20, 24);
			swap(mapp, 20, 26);
			swap(mapp, 19, 21);
			swap(mapp, 19, 23);
			swap(mapp, 23, 25);
		}else if(rules.equals("R+")) {
			swap(mapp, 8, 17);
			swap(mapp, 5, 14);
			swap(mapp, 2, 11);
			swap(mapp, 11, 38);
			swap(mapp, 14, 41);
			swap(mapp, 17, 44);
			swap(mapp, 38, 47);
			swap(mapp, 41, 50);
			swap(mapp, 44, 53);
			
			swap(mapp, 27, 33);
			swap(mapp, 33, 35);
			swap(mapp, 35, 29);
			swap(mapp, 30, 28);
			swap(mapp, 30, 34);
			swap(mapp, 32, 34);
			
		}else if(rules.equals("R-")) {
			swap(mapp, 8, 53);
			swap(mapp, 5, 50);
			swap(mapp, 2, 47);
			swap(mapp, 47, 38);
			swap(mapp, 50, 41);
			swap(mapp, 53, 44);
			swap(mapp, 38, 11);
			swap(mapp, 41, 14);
			swap(mapp, 44, 17);
			
			swap(mapp, 27, 29);
			swap(mapp, 29, 33);
			swap(mapp, 29, 35);
			swap(mapp, 28, 30);
			swap(mapp, 28, 32);
			swap(mapp, 32, 34);
		}
	
	}
	
	private static void swap(char a[], int idx1, int idx2) {
		char tmp;
		tmp = a[idx1];
		a[idx1]=a[idx2];
		a[idx2]=tmp;	
	}
	
}


