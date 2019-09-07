use std::io;
use std::collections::HashMap;
use rand::distributions::Uniform;
use rand::Rng;


struct Solution {
}

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {

    }
}

fn main() {
    use myio::Scanner;

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let n = scan.token::<usize>();

    for _ in 0..n {
        let N = scan.token::<i32>();
        let b_size = scan.token::<usize>();

        let blacklist = (0..b_size).map( |_| scan.token::<i32>()).collect();

        let sol = Solution::new(N, blacklist);

        let n_pick = scan.token::<i32>();

        for _ in 0..n_pick {
            print!("{} ", sol.pick());
        }
        println!("");
    }
}




