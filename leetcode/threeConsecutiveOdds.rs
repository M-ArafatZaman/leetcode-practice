// https://leetcode.com/problems/three-consecutive-odds/
struct Solution;
impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let bin_arr = arr.into_iter().map(|x| x % 2).collect::<Vec<i32>>();
        let mut cons = 0;
        
        for n in bin_arr {
            if n == 1 {
                cons += 1;
            } else {
                cons = 0;
            }
            
            if cons == 3 {
                return true;
            }
        }
        
        false
    }
}

fn main() {
    assert_eq!(Solution::three_consecutive_odds(vec![1,2,34,3,4,5,7,23,12]), true);
    assert_eq!(Solution::three_consecutive_odds(vec![2,6,4,1]), false);
}