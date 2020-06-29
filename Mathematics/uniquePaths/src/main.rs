extern crate input;

use std::io;
use std::collections::HashMap;
use input::Scanner;

struct Solution {
}


impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let num: i64 = (n..=(m + n - 2)).fold(1, |a , b| (a as i64) * (b as i64));
        let den: i64 = (1..=(m - 1)).fold(1, |a , b| (a as i64) * (b as i64));

        (num / den) as i32
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




