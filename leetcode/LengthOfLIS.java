import java.util.HashMap;

// https://leetcode.com/problems/longest-increasing-subsequence/
class LengthofLIS {
    public HashMap<Integer, Integer> cache = new HashMap<>();

    public static void main(String[] args) {
        LengthofLIS lis = new LengthofLIS();
        System.out.println(lis.lengthOfLIS(new int[]{10,9,2,5,3,7,101,18}));
        System.out.println(lis.lengthOfLIS(new int[]{0,1,0,3,2,3}));
        System.out.println(lis.lengthOfLIS(new int[]{7,7,7,7,7,7,7}));
    }
    
    public int lengthOfLIS(int[] nums) {
        int lis = 0;
        
        for (int i = 0; i < nums.length; i++) {
            lis = Math.max(lis, dfs_helper(i, nums));
        }

        // Clear cache clean up
        cache.clear();
        return lis;
    }
    
    public int dfs_helper(int i, int[] nums) {
        // Check cache
        if (cache.containsKey(i)) {
            return cache.get(i);
        }
        
        // Get the next longest sequence and then add one
        int next_longest = 0;
        for (int j = i+1; j < nums.length; j++) {
            if (nums[i] < nums[j]) {
                // Include the next one
                next_longest = Math.max(next_longest, dfs_helper(j, nums));
            }    
        }
        
        // Update cache
        cache.put(i, next_longest+1);
        return next_longest + 1;
    }
}