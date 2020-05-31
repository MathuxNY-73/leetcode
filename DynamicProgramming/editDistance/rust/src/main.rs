extern crate input;

use std::io;
use std::vec::Vec;
use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::{max, min};

struct Solution {}

impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let n = word1.len();
        let m = word2.len();
        if n == 0 || m == 0 {
            max(m as i32, n as i32)
        }
        else {

            let mut dp: Vec<usize> = (0..=m).collect();

            for (i, c1) in word1.chars().enumerate() {
                let mut diag = dp[0];
                dp[0] = i + 1;

                for (j, c2) in word2.chars().enumerate() {
                    let tmp = dp[j + 1];
                    if c1 == c2 {
                        dp[j+1] = diag;
                    }
                    else {
                        dp[j + 1] = min(dp[j], min(diag, tmp)) + 1;
                    }
                    diag = tmp;
                }
            }

            dp[m] as i32
        }
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        //println!("New Test Case");
        let word1 = scan.token::<String>();
        let word2 = scan.token::<String>();

        let res = Solution::min_distance(word1, word2);

        println!("{}", res);
    }

}
