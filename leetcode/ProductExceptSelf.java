public class ProductExceptSelf {
    // https://leetcode.com/problems/product-of-array-except-self/submissions/
    
    public int[] productExceptSelf(int[] nums) {
        int N = nums.length;
        int[] prefix = new int[N];
        int[] suffix = new int[N];
        prefix[0] = nums[0];
        suffix[N-1] = nums[N-1];
        // Calculate the prefix
        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        };

        // Calculate the suffix
        for (int j = N-2; j >= 0; j--) {
            suffix[j] = suffix[j+1] * nums[j];
        };

        int[] res = new int[N];
        for (int k = 0; k < N; k++) {
            if (k == 0) {
                res[k] = suffix[1];
            } else if (k == N-1) {
                res[k] = prefix[k-1];
            } else {
                res[k] = prefix[k-1] * suffix[k+1];
            }
        }

        return res;
    }
}