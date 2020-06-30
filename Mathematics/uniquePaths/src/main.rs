extern crate input;

use std::io;
use std::collections::HashMap;
use input::Scanner;

struct Solution {
}


impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        if n == 0 {
            0
        }
        else {
            let mut dp = vec![1;(n + 1) as usize];

            dp[0] = 0;
            for _ in 1..m {
                for j in 2..=n {
                    dp[j as usize] += dp[(j - 1) as usize];
                }
            }

            dp[n as usize]
        }
    }
}

fn main() {
    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        println!("New Test Case");
        let n = scan.token::<i32>();
        let m = scan.token::<i32>();

        let res = Solution::unique_paths(m, n);

        println!("{}", res);

    }
}




