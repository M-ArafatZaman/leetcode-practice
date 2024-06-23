import java.util.PriorityQueue;

// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
class LongestSubarrayDiffLELimit {
    public static void main(String[] args) {
        LongestSubarrayDiffLELimit obj = new LongestSubarrayDiffLELimit();
        System.out.println(obj.longestSubarray(new int[]{8,2,4,7}, 4));
    }

    public int longestSubarray(int[] nums, int limit) {
        int longest = 0, left = 0, right = 0;
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((int a[], int b[]) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((int a[], int b[]) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return b[0] - a[0];
        });
        
        while (right < nums.length) {
            minHeap.add(new int[]{nums[right], right});
            maxHeap.add(new int[]{nums[right], right});

            while (maxHeap.peek()[0] - minHeap.peek()[0] > limit) {
                left++;
                // Get rid of min from heap that are not in window
                while (minHeap.peek()[1] < left) {
                    minHeap.remove();
                }
                
                // Get rid of max from heap that are not in window
                while (maxHeap.peek()[1] < left) {
                    maxHeap.remove();
                }    
            } 
            right++;
            longest = Math.max(longest, right-left);
        }
        
        return longest;
    }
}