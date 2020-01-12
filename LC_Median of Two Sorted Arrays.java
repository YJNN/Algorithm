import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
		double ans=0;
		ArrayList<Integer> tmpArr = new ArrayList<Integer>();
		
		for(int i=0; i<nums1.length; i++)
			tmpArr.add(nums1[i]);
		for(int i=0; i<nums2.length; i++)
			tmpArr.add(nums2[i]);
		Collections.sort(tmpArr);
		
		if(tmpArr.size()%2==0) {
			int firstNum = tmpArr.get(tmpArr.size()/2 -1);
			int secondNum = tmpArr.get(tmpArr.size()/2);
			ans = (double)(firstNum+secondNum)/2;
			
		}else{
			int num = tmpArr.get(tmpArr.size()/2);
			ans = (double)num;
		}
        return ans;
    }
}
