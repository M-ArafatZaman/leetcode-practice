use std::io;

// https://open.kattis.com/problems/metronome
fn main() {
    let mut a = String::new();

    io::stdin()
        .read_line(&mut a)
        .expect("Can not read number");

    let b: f32 = a.trim().parse::<f32>().unwrap();
    let c: f32 = (b/4.0) as f32; 
    println!("{}", c);

}