use std::collections::HashMap;
use std::collections::BinaryHeap;

pub struct Solution;
// https://leetcode.com/problems/maximum-total-importance-of-roads/
impl Solution {
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        let mut node_count: HashMap<i32, i32> = HashMap::new();
        let mut max_heap: BinaryHeap<(i32, i32)> = BinaryHeap::new();
        let mut impt: HashMap<i32, i32> = HashMap::new();
        let mut n = n;
        let mut sum: i64 = 0;
        
        for edge in &roads {
            *node_count.entry(edge[0]).or_insert(0) += 1;
            *node_count.entry(edge[1]).or_insert(0) += 1;
        }
        
        for (&node, &count) in node_count.iter() {
            max_heap.push((count, node));
        }
        
        while let Some((_, node)) = max_heap.pop() {
            impt.insert(node, n);
            n -= 1;
        }
        
        for edge in &roads {
            sum += i64::from(impt[&edge[0]]) + i64::from(impt[&edge[1]]);
        }
        
        sum 
    }
}

fn main() {
    let n = 5;
    let roads = vec![vec![0, 1], vec![1,2], vec![2,3], vec![0, 2], vec![1,3], vec![2,4]];
    let result = Solution::maximum_importance(n, roads);
    println!("Result: {}", result);
}