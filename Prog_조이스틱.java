import java.util.*;
class Solution {
    public static int solution(String name) {
        int answer = 0;
        int minNum = name.length()-1;
        char[] nameArr = name.toCharArray();
        for(int i=0; i<nameArr.length; i++) {
        	if(nameArr[i]-'A' < 'Z'-nameArr[i]+1) answer+=nameArr[i]-'A';
        	else answer+='Z'-nameArr[i]+1;
        	int nextIdx = i+1;
        	int aCount = 0;
        	if(nameArr[i]=='A') {
        		while(true) {
        			if(nextIdx==nameArr.length) break;
        			if(nameArr[nextIdx]=='A') {
        				++nextIdx;
        				++aCount;
        			}else break;
        		}
        		int cursorNum = (i-1)*2 + nameArr.length-1-i-aCount;
        		minNum = Math.min(minNum, cursorNum);
        	}	
        }
        answer += minNum;
        return answer;
    }
}