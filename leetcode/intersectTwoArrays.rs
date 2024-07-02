// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
struct Solution;
impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut nums1 = nums1.to_vec();
        let mut nums2 = nums2.to_vec();
        nums1.sort(); nums2.sort();
        let mut res: Vec<i32> = Vec::new();
        let mut left = 0;
        let mut right = 0;
        
        while (left < nums1.len()) && (right < nums2.len()) {
            if nums1[left] < nums2[right] {
                left += 1;
            } else if nums1[left] > nums2[right] {
                right += 1;
            } else if nums1[left] == nums2[right] {
                res.push(nums1[left]);
                left += 1;
                right += 1;
            }
        }
        
        res
    }
}

fn main() {
    assert_eq!(Solution::intersect(vec![1,2,2,1], vec![2,2]), vec![2,2]);
}