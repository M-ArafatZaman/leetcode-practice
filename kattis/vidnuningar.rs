#![allow(unused_parens)]

use std::io;

// https://open.kattis.com/problems/vidsnuningur
fn main() {
    let mut a = String::new();

    io::stdin().read_line(&mut a);

    let input = a.trim();
    let c: String = input.chars().rev().collect::<String>();

    println!("{}", c);
}