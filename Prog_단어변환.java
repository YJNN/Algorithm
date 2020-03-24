import java.util.*;
class Solution {
	   static int minNum = 987654321;
	   static boolean[] isVisited;
	   public static int solution(String begin, String target, String[] words) {
	        int tmpCnt = 0;
	        isVisited = new boolean[words.length];
	        for(int i=0; i<words.length; i++) {
	        	if(words[i].equals(target)) {
	        		++tmpCnt;
	        		break;
	        	}
	        }
	        if(tmpCnt==0) return 0;
	        String nowStr = begin;
	        dfs(target, nowStr, words, 0);

	        return minNum;
	    }
	   
	   public static void dfs(String target, String nowStr, String[] words, int cnt) {	   
		   if(nowStr.equals(target)) {
			   minNum = Math.min(minNum, cnt);
			   return;
		   }
		   
		   for(int i=0; i<words.length; i++) {
			   if(isVisited[i]) continue;
			   if(isPossible(words[i],nowStr)) {
				   isVisited[i] = true;
				   dfs(target,words[i],words,cnt+1);
				   isVisited[i] = false;
			   }   
		   }   
	   }
	   
	   public static boolean isPossible(String word, String nowStr) {
		   int tmpCnt = 0;
		   for(int i=0; i<word.length(); i++) {
			   if(word.charAt(i)!=nowStr.charAt(i)) ++tmpCnt;
		   }
		   if(tmpCnt != 1) return false;
		   else return true;
	   }
}
