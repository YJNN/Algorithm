import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class BOJ_1011 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader in  = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int dist, t;
		StringBuilder ans = new StringBuilder();
		String xy[];
		t = Integer.parseInt(in.readLine());
		
		for(int i=0; i<t; i++) {
			xy = in.readLine().split(" ");
			dist = Integer.parseInt(xy[1])-Integer.parseInt(xy[0]);
		
			for(int j=1; ; j++) {
				int minNum = j*j-j+1;
				int maxNum = j*j+j;
				int ret=0;
				
				if(dist>=minNum && dist<=maxNum) {
					if(dist>=minNum && dist<=j*j) {
						ret = (j<<1)-1;
						ans.append(ret+"\n");
						break;
					}else {
						ret = (j<<1);
						ans.append(ret+"\n");
						break;
					}
				}
			}		
		}
		out.write(ans.toString());
		out.close();
		in.close();
	}
}
