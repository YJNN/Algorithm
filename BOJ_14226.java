import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_14226 {
	static int s;
	static Queue<Node> queue;
	static boolean[][] isVisted = new boolean[2001][2001];
	static int minNum;

	public static void main(String[] args) throws Exception, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = Integer.parseInt(br.readLine());
		
		queue = new LinkedList<>();
		queue.add(new Node(1,0,0));
		isVisted[1][0]=true;
		
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			
			if(node.curNum==s) {
				minNum = node.cnt;
				break;
			}
			
			queue.add(new Node(node.curNum, node.curNum, node.cnt+1));
			
			if(node.clipBoard !=0 && !isVisted[node.curNum+node.clipBoard][node.clipBoard] 
					&& node.curNum+node.clipBoard<=1000) {
				isVisted[node.curNum+node.clipBoard][node.clipBoard]=true;
				queue.add(new Node(node.curNum+node.clipBoard, node.clipBoard, node.cnt+1));
			}
			
			if(node.curNum>0 && !isVisted[node.curNum-1][node.clipBoard] && node.curNum-1<=1000) {
				isVisted[node.curNum-1][node.clipBoard]=true;
				queue.add(new Node(node.curNum-1, node.clipBoard, node.cnt+1));
			}
		}
		
		System.out.println(minNum);
	}
}

class Node{
	int curNum;
	int clipBoard;
	int cnt;
	
	Node(int curNum, int clipBoard, int cnt){
		this.curNum=curNum;
		this.clipBoard=clipBoard;
		this.cnt=cnt;
	}
}
