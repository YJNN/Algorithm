import java.util.*;
class Solution {
     public static int solution(int[] priorities, int location) {
        int answer = 1;
        ArrayList<DocInfo> aList = new ArrayList<DocInfo>();
        for(int i=0; i<priorities.length; i++) aList.add(new DocInfo(i, priorities[i]));
        DocInfo firstPrinted = null;
        while(aList.size()!=1) {
        	firstPrinted = aList.get(0);
        	for(int i=1; i<aList.size(); i++) {
        		if(aList.get(i).prior > firstPrinted.prior) {
        			aList.add(firstPrinted);
        			aList.remove(0);
        			break;
        		}
        		if(i==aList.size()-1) {
        			if(location == firstPrinted.loc) return answer;
        			else {
        				++answer;
        				aList.remove(0);
        			}
        		}
        	}	
        }   
        return answer;       
    }
}
class DocInfo{
	int loc;
	int prior;
	
	public DocInfo(int loc, int prior) {
		this.loc = loc;
		this.prior = prior;
	}	
}