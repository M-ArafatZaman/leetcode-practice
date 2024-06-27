use std::cmp::{max};

pub struct Solution;

impl Solution {
    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, worker: Vec<i32>) -> i32 {
        let n = difficulty.len();
        let mut diff_profits: Vec<Vec<i32>> = Vec::new();
        let mut max_profits: Vec<i32> = Vec::new();
        
        // Combine profit and difficulty into a singular array
        for i in 0..n {
            diff_profits.push(vec![difficulty[i], profit[i]]);
        }
        
        // Sort by difficulty
        diff_profits.sort_by(|a, b| a[0].cmp(&b[0]));
        
        let mut curr_max = diff_profits[0][1];
        // Extract profits
        diff_profits.iter().flatten().skip(1).step_by(2).for_each(|x| {
            curr_max = max(curr_max, *x);
            max_profits.push(curr_max);
        });
        
        // Binary Search for every worker
        let mut left: usize; 
        let mut right: usize; 
        let mut mid: usize; 
        let mut hit: usize;
        let mut max_prof: i32 = 0;
        
        for i in 0..worker.len() {
            left = 0;
            right = n as usize;
            mid = 0;
            hit = 0;
            // Binary search
            while left < right {
                mid = (left + right)/2 as usize;
                if diff_profits[mid][0] <= worker[i] {
                    left = mid + 1;
                    hit = mid;
                } else {
                    right = mid;
                    hit = if mid == 0 { mid } else { mid - 1 };
                }
            }
            
            if diff_profits[hit][0] <= worker[i] {
                max_prof += max_profits[hit];
            }
        }
        
        max_prof
    }
}

// https://leetcode.com/problems/most-profit-assigning-work/
fn main() {
    let result = Solution::max_profit_assignment(vec![2,4,6,8,10], vec![10, 20, 30, 40, 50], vec![4, 5, 6, 7]);
    println!("Result: {}", result);

}
