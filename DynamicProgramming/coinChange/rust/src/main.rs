extern crate input;

use std::io;
use std::cmp::min;

struct Solution {
}

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![-1; (amount + 1) as usize];
        dp[0] = 0;

        for c in coins {
            for i in 1..(amount+1) {
                //println!("i: {}", i);
                if i == c {
                    dp[i as usize] = 1;
                }
                else if i > c && dp[(i - c) as usize] > 0 {
                    if dp[i as usize] == -1 {
                        dp[i as usize] = dp[(i - c) as usize] + 1;
                    }
                    else {
                        dp[i as usize] = min(dp[i as usize], dp[(i - c) as usize] + 1);
                    }
                }
            }
        }

        let res = dp[amount as usize];
        res
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        let c_size = scan.token::<usize>();
        let amount = scan.token::<i32>();
        println!("c_size: {0}, amount: {1}", c_size, amount);

        let coins = (0..c_size).map( |_| scan.token::<i32>()).collect();

        let sol = Solution::coin_change(coins, amount);

        println!("{}", sol);
    }
}




