import java.util.*;
class Solution {
    public static String[] solution(String[][] tickets) {
        String[] answer = {};
        ArrayList<Airport> airportList = new ArrayList<>();
        for(int i=0; i<tickets.length; i++) airportList.add(new Airport(tickets[i][0], tickets[i][1]));
        Collections.sort(airportList, (air1, air2) -> air1.start.compareTo(air2.start)==0 ? 
        		air1.end.compareTo(air2.end) : air1.start.compareTo(air2.start));
        
        ArrayList<Airport> startAir = new ArrayList<Airport>();
        for(int i=0; i<airportList.size(); i++) {
        	if(airportList.get(i).start.equals("ICN")) startAir.add(airportList.get(i));
        }
        
        for(int i=0; i<startAir.size(); i++) {
        	startAir.get(i).isVisited = 0;
        	if(dfs(airportList, startAir.get(i), 1)) break;
        }
        
        Collections.sort(airportList, (air1, air2) -> air1.isVisited > air2.isVisited ? 1 : -1);
        answer = new String[airportList.size()+1];
        answer[0] = airportList.get(0).start;
        answer[1] = airportList.get(0).end;
        for(int i=1; i<airportList.size(); i++) {
        	answer[i+1] = airportList.get(i).end;
        }      
        return answer;
    }
    
    public static boolean dfs(ArrayList<Airport> airportList, Airport startAir, int cnt) {
    	boolean flag = false;
    	if(airportList.size()==cnt) return true;
  
    	for(int i=0; i<airportList.size(); i++) {
    		if(airportList.get(i).isVisited==-1 && startAir.isPossible(airportList.get(i))) {
    			airportList.get(i).isVisited = cnt;
    			if(flag=(dfs(airportList,airportList.get(i),cnt+1))) break;
    		}
    	}
    	if(!flag) startAir.isVisited = -1;
    	
    	return flag;
    }
}
class Airport{
	public String start;
	public String end;
	public int isVisited = -1;
	
	public Airport(String start, String end) {
		this.start = start;
		this.end = end;
	}
	
	public boolean isPossible(Airport nextAir) {
		return this.end.equals(nextAir.start);
	}
}