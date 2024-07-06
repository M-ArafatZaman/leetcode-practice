// https://leetcode.com/problems/pass-the-pillow/
struct Solution;
impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let q = time / (n-1);
        let m = time % (n-1);
        
        if (q % 2) == 0 {
            1 + m
        } else {
            n - m
        }
    }
}

fn main() {
    assert_eq!(Solution::pass_the_pillow(4, 5), 2);
}