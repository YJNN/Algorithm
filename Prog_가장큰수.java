import java.io.*;
import java.util.*;
class Solution {
    public static String solution(int[] numbers) {
        String answer = "";
        String[] tmpNumList = new String[numbers.length];
        for(int i=0; i<numbers.length; i++) tmpNumList[i] = numbers[i]+"";
        Arrays.sort(tmpNumList, (o1,o2) -> (o2+o1).compareTo(o1+o2));
        if(tmpNumList[0].equals("0")) return "0";     
        for(int i=0; i<tmpNumList.length; i++) answer += tmpNumList[i];    
        return answer;
    }
}