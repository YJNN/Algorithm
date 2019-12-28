import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class example{
	static Queue<Pos> q = new LinkedList<Pos>();
    public static void main(String[] args) {
    	Pos p = new Pos(0,0);
    	q.add(p);
    	System.out.println(q.size());
    	
    	
    	p=new Pos(p.x+1,p.y+1);
    	q.add(p);
    	System.out.println(q.size());
    	
    	
    	p=new Pos(p.x+1,p.y+1);
    	q.add(p);
    	System.out.println(q.size());
    	
    	
    	Pos s = q.poll();
    	System.out.println(s.x+ " "+s.y);
	}
}
class Pos{
	int x, y;
	Pos(int x, int y){
		this.x=x;
		this.y=y;
	}
}