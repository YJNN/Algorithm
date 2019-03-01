import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_14891 {
	static ArrayList<Integer> top1 = new ArrayList<Integer>();
	static ArrayList<Integer> top2 = new ArrayList<Integer>();
	static ArrayList<Integer> top3 = new ArrayList<Integer>();
	static ArrayList<Integer> top4 = new ArrayList<Integer>();
	static int k;
	static int[][] topRule;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String st1 = new String(br.readLine());
		String st2 = new String(br.readLine());
		String st3 = new String(br.readLine());
		String st4 = new String(br.readLine());
	
		for(int i=0; i<8; i++) {
			top1.add(Integer.parseInt(st1.charAt(i)+""));
		}
		for(int i=0; i<8; i++) {
			top2.add(Integer.parseInt(st2.charAt(i)+""));
		}
		for(int i=0; i<8; i++) {
			top3.add(Integer.parseInt(st3.charAt(i)+""));
		}
		for(int i=0; i<8; i++) {
			top4.add(Integer.parseInt(st4.charAt(i)+""));
		}
		
		k = Integer.parseInt(br.readLine());
		topRule = new int[k][2];
		for(int i=0; i<k; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<2; j++) {
				topRule[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		
		
		for(int i=0; i<k; i++) {
			ArrayList<Integer> tmp1 = new ArrayList<Integer>();
			ArrayList<Integer> tmp2 = new ArrayList<Integer>();
			ArrayList<Integer> tmp3 = new ArrayList<Integer>();
			ArrayList<Integer> tmp4 = new ArrayList<Integer>();
			for(int j=0; j<8; j++) {
				tmp1.add(top1.get(j));
				tmp2.add(top2.get(j));
				tmp3.add(top3.get(j));
				tmp4.add(top4.get(j));	
			}
		
			if(topRule[i][0]-1 == 0) {
				if(top1.get(2)!=top2.get(6)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp1.get(7);
						tmp1.remove(7);
						tmp1.add(0, tmpNum);
						
						tmpNum = tmp2.get(0);
						tmp2.remove(0);
						tmp2.add(tmpNum);	
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp1.get(0);
						tmp1.remove(0);
						tmp1.add(tmpNum);
						
						tmpNum = tmp2.get(7);;
						tmp2.remove(7);
						tmp2.add(0, tmpNum);
					}
					
					if(top2.get(2)!=top3.get(6)) {
						if(topRule[i][1]==1) {
							int tmpNum = tmp3.get(7);
							tmp3.remove(7);
							tmp3.add(0, tmpNum);
						}else if(topRule[i][1]==-1) {
							int tmpNum = tmp3.get(0);
							tmp3.remove(0);
							tmp3.add(tmpNum);
						}
						
						if(top3.get(2)!=top4.get(6)) {
							if(topRule[i][1]==1) {
								int tmpNum = tmp4.get(0);
								tmp4.remove(0);
								tmp4.add(tmpNum);
							}else if(topRule[i][1]==-1) {
								int tmpNum = tmp4.get(7);
								tmp4.remove(7);
								tmp4.add(0, tmpNum);
							}
						}

					}
				}
				
				else {
					if(topRule[i][1]==1) {
						int tmpNum = tmp1.get(7);
						tmp1.remove(7);
						tmp1.add(0, tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp1.get(0);
						tmp1.remove(0);
						tmp1.add(tmpNum);
					}
				}
				top1.clear();
				top2.clear();
				top3.clear();
				top4.clear();
				for(int j=0; j<8; j++) {
					top1.add(tmp1.get(j));
					top2.add(tmp2.get(j));
					top3.add(tmp3.get(j));
					top4.add(tmp4.get(j));
				}
			}else if(topRule[i][0]-1 == 1) {
				if(top1.get(2)!=top2.get(6)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp2.get(7);
						tmp2.remove(7);
						tmp2.add(0, tmpNum);
						
						tmpNum = tmp1.get(0);
						tmp1.remove(0);
						tmp1.add(tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp2.get(0);
						tmp2.remove(0);
						tmp2.add(tmpNum);
						
						tmpNum = tmp1.get(7);
						tmp1.remove(7);
						tmp1.add(0, tmpNum);
					}
				}else {
					if(topRule[i][1]==1) {
						int tmpNum = tmp2.get(7);
						tmp2.remove(7);
						tmp2.add(0, tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp2.get(0);
						tmp2.remove(0);
						tmp2.add(tmpNum);
					}
				}
				
				if(top2.get(2)!=top3.get(6)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp3.get(0);
						tmp3.remove(0);
						tmp3.add(tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp3.get(7);
						tmp3.remove(7);
						tmp3.add(0, tmpNum);
					}
					
					if(top3.get(2)!=top4.get(6)) {
						if(topRule[i][1]==1) {
							int tmpNum = tmp4.get(7);
							tmp4.remove(7);
							tmp4.add(0, tmpNum);
						}else if(topRule[i][1]==-1) {
							int tmpNum = tmp4.get(0);
							tmp4.remove(0);
							tmp4.add(tmpNum);
						}
						
					}
				}
				top1.clear();
				top2.clear();
				top3.clear();
				top4.clear();
				for(int j=0; j<8; j++) {
					top1.add(tmp1.get(j));
					top2.add(tmp2.get(j));
					top3.add(tmp3.get(j));
					top4.add(tmp4.get(j));
				}
			}else if(topRule[i][0]-1 == 2) {
				if(top3.get(2)!=top4.get(6)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp3.get(7);
						tmp3.remove(7);
						tmp3.add(0, tmpNum);
						
						tmpNum = tmp4.get(0);
						tmp4.remove(0);
						tmp4.add(tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp3.get(0);
						tmp3.remove(0);
						tmp3.add(tmpNum);
						
						tmpNum = tmp4.get(7);
						tmp4.remove(7);
						tmp4.add(0, tmpNum);
					}
				}else {
					if(topRule[i][1]==1) {
						int tmpNum = tmp3.get(7);
						tmp3.remove(7);;
						tmp3.add(0, tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp3.get(0);
						tmp3.remove(0);
						tmp3.add(tmpNum);
					}	
				}
				
				if(top2.get(2)!=top3.get(6)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp2.get(0);
						tmp2.remove(0);
						tmp2.add(tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp2.get(7);
						tmp2.remove(7);
						tmp2.add(0, tmpNum);
					}
					
					if(top1.get(2)!=top2.get(6)) {
						if(topRule[i][1]==1) {
							int tmpNum = tmp1.get(7);
							tmp1.remove(7);
							tmp1.add(0, tmpNum);
						}else if(topRule[i][1]==-1) {
							int tmpNum = tmp1.get(0);
							tmp1.remove(0);
							tmp1.add(tmpNum);
						}			
					}	
				}
				top1.clear();
				top2.clear();
				top3.clear();
				top4.clear();
				for(int j=0; j<8; j++) {
					top1.add(tmp1.get(j));
					top2.add(tmp2.get(j));
					top3.add(tmp3.get(j));
					top4.add(tmp4.get(j));
				}

			}else if(topRule[i][0]-1 == 3) {
				if(top4.get(6)!=top3.get(2)) {
					if(topRule[i][1]==1) {
						int tmpNum = tmp4.get(7);
						tmp4.remove(7);
						tmp4.add(0, tmpNum);
						
						tmpNum = tmp3.get(0);
						tmp3.remove(0);
						tmp3.add(tmpNum);
					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp4.get(0);
						tmp4.remove(0);
						tmp4.add(tmpNum);
						
						tmpNum = tmp3.get(7);
						tmp3.remove(7);
						tmp3.add(0, tmpNum);
					}
					
					if(top2.get(2)!=top3.get(6)) {
						if(topRule[i][1]==1) {
							int tmpNum = tmp2.get(7);
							tmp2.remove(7);
							tmp2.add(0, tmpNum);
						}else if(topRule[i][1]==-1) {
							int tmpNum = tmp2.get(0);
							tmp2.remove(0);
							tmp2.add(tmpNum);
						}
						
						if(top1.get(2)!=top2.get(6)) {
							if(topRule[i][1]==1) {
								int tmpNum = tmp1.get(0);
								tmp1.remove(0);
								tmp1.add(tmpNum);
							}else if(topRule[i][1]==-1) {
								int tmpNum = tmp1.get(7);
								tmp1.remove(7);
								tmp1.add(0, tmpNum);
							}
						}
						
					}
				
				}else {
					if(topRule[i][1]==1) {
						int tmpNum = tmp4.get(7);
						tmp4.remove(7);
						tmp4.add(0, tmpNum);

					}else if(topRule[i][1]==-1) {
						int tmpNum = tmp4.get(0);
						tmp4.remove(0);
						tmp4.add(tmpNum);
					}
			
				}	
				top1.clear();
				top2.clear();
				top3.clear();
				top4.clear();
				for(int j=0; j<8; j++) {
					top1.add(tmp1.get(j));
					top2.add(tmp2.get(j));
					top3.add(tmp3.get(j));
					top4.add(tmp4.get(j));
				}
			}
		}		
		int sum=0;
		
		if(top1.get(0)==1)
			sum += 1;
		if(top2.get(0)==1)
			sum += 2;
		if(top3.get(0)==1)
			sum += 4;
		if(top4.get(0)==1)
			sum += 8;
		
		System.out.println(sum);
	}
}
