
public class Solution {
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode ret = null;
		ListNode nextNode = null;
		int carry = 0;
		
		while(l1!=null || l2!=null || carry==1) {
			int val1;
			int val2;
			if(l1==null)
				val1 = 0;
			else
				val1 = l1.val;
			if(l2==null)
				val2 = 0;
			else
				val2 = l2.val;
			
			int sumResult = val1+val2+carry;
			carry = 0;
			
			if(sumResult >= 10) {
				carry = 1;
				sumResult = sumResult - 10;
			}
			if(ret==null) {
				ret = new ListNode(sumResult);
				nextNode = ret;
			}
			else {
				//ret.next = new ListNode(sumResult);
				//ret = ret.next;
				nextNode.next = new ListNode(sumResult);
				nextNode = nextNode.next;
			}

			if(l1!=null)
				l1 = l1.next;
			if(l2!=null)
				l2 = l2.next;
		}
	    return ret;
	}
}
