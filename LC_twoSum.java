
public class Solution {
	public int[] twoSum(int[] nums, int target) {
        int[] ret = null;
		boolean flag = true;
		
		for(int i=0; i<nums.length; i++) {
			for(int j=i+1; j<nums.length; j++) {
				if((nums[i]+nums[j])==target) {
					int[] tmp = {i,j};
					ret = tmp;
					flag = false;
					break;
				}
				else {
					continue;
				}
			}
			if(flag==false)
				break;
		}
	    return ret;     
    }
}
