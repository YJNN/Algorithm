import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ArrayList<Integer> tmpAns = new ArrayList<Integer>();
		if(l1==null && l2==null)
			return null;
		while(l1!=null || l2!=null) {
			if(l1!=null) {
				tmpAns.add(l1.val);
				l1 = l1.next;
			}	
			if(l2!=null) {
				tmpAns.add(l2.val);
				l2 = l2.next;
			}
		}
		Collections.sort(tmpAns);
		ListNode ans = new ListNode(tmpAns.get(0));
		ListNode rAns = ans;
		for(int i=1; i< tmpAns.size(); i++) {
			ans.next = new ListNode(tmpAns.get(i));
			ans = ans.next;
		}
		return rAns; 
    }
}
