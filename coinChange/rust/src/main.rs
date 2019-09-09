use std::io;
use std::cmp::Ordering;

struct Solution {
}

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let mut dp = vec![0; (amount + 1) as usize];
        dp[0] = 1;

        for i in 1..(amount+1) {
            //println!("i: {}", i);
            for c in &coins {
                if i >= c {
                    dp[i as usize] += dp[(i - c) as usize] 
                }
            }
        }

        let res = dp[amount as usize];
        if res == 0 { -1 } else { res }
    }
}

fn main() {
    use myio::Scanner;

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




