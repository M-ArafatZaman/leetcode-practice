import java.lang.Math;

class Solution {
    public int[] getAverages(int[] nums, int k) {
        if (k == 0) return nums;

        int n = nums.length;
        int[] ans = new int[n];
        int len = 2*k + 1;

        // Build prefix
        long[] prefix = new long[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        for (int j = 0; j < n; j++) {
            if (j < k || j > (n-k-1)) {
                ans[j] = -1;
            } else {
                ans[j] = (int)Math.floorDiv((prefix[j+k] - (j == k ? 0 : prefix[j-k-1])), len);
            }
        }        

        return ans;
    }
}