import java.io.*;
import java.util.*;
class Solution {
    public static int[] solution(int N, int[] stages) {
        int[] answer = {};
        ArrayList<Integer> aList = new ArrayList<Integer>();
        HashMap<Integer, Double> map = new HashMap<Integer, Double>();
        for(int i=0; i<stages.length; i++) aList.add(stages[i]);
        for(int i=1; i<=N; i++) {
     		int userNum = aList.size();
    		int failNum = 0;
        	for(int j=0; j<aList.size(); j++) {
        		if(aList.get(j)==i) {
        			++failNum;
            		aList.remove(j);
            		j = j-1;
        		}
        	}
            if(userNum==0) map.put(i, 0.0);
            else map.put(i, ((double)failNum/userNum)); 	
        }
        List<Integer> keySetList = new ArrayList<>(map.keySet());
        Collections.sort(keySetList, (o1,o2) ->  (map.get(o2).compareTo(map.get(o1))));
        answer = new int[keySetList.size()];
        for(int i=0; i<keySetList.size(); i++) answer[i] = keySetList.get(i);
        return answer;
    }	
}