
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int a = 0, b = numbers.length-1;

        while ((numbers[a] + numbers[b]) != target && a < b) {
            if (numbers[a] + numbers[b] > target) {
                b -=1;
            } else {
                a += 1;
            }
        }

        int[] res = {a+1, b+1};

        return res;
    }
}