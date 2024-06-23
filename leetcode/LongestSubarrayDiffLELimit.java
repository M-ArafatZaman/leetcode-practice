import java.util.HashMap;

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class LongestSubarrayDiffLELimit {
    public int[] nums;
    public int limit;
    public HashMap<String, Integer> cache;
    
    public static void main(String[] args) {
        LongestSubarrayDiffLELimit obj = new LongestSubarrayDiffLELimit();
        System.out.println(obj.longestSubarray(new int[]{8,2,4,7}, 4));
    }

    public int longestSubarray(int[] nums, int limit) {
        int longest = 0;
        this.nums = nums;
        this.limit = limit;
        cache = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            longest = Math.max(longest, dfs_helper(i, nums[i], nums[i], 1));
        }
        return longest;
    }
    
    public int dfs_helper(int i, int min, int max, int len) {
        // Check cache
        String key = String.format("%d,%d,%d", i, min, max);
        if (cache.containsKey(key)) return cache.get(key);
        
        if (max - min > limit) {
            cache.put(key, len-1);
            return len-1;
        }
        if (i == nums.length-1) {
            cache.put(key, len);
            return len;
        }
        int next_min = Math.min(min, nums[i+1]);
        int next_max = Math.max(max, nums[i+1]);
        int longest = Math.max(len, dfs_helper(i+1, next_min, next_max, len+1));
        cache.put(key, longest);
        return longest;
    }
}