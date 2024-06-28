use std::collections::HashMap;
use std::cmp::max;

pub struct Solution;

// Problem: https://leetcode.com/problems/find-center-of-star-graph/
impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        let mut node_count: HashMap<i32, i32> = HashMap::new();
        let mut n = 0;
        let mut res = 0;
        
        // Build node count
        for edge in edges {
            let u = edge[0];
            let v = edge[1];
            n = max(n, u);
            n = max(n, v);
            
            *node_count.entry(u).or_insert(0) += 1;
            *node_count.entry(v).or_insert(0) += 1;
        }
        
        for (node, n_count) in node_count.iter() {
            if *n_count == (n-1) {
                res = *node;
            }
        }
        
        res
    }
}

fn main() {
    let edges = vec![vec![1,2], vec![2,3], vec![4,2]];
    let res = Solution::find_center(edges);
    println!("Center node: {}", res);
}