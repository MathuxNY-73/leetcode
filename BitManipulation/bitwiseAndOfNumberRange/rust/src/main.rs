extern crate input;

use std::io;

struct Solution {
}

impl Solution {
    pub fn range_bitwise_and(m: i32, n: i32) -> i32 {
        let mut n_mut = n;

        while n_mut > m {
            n_mut &= n_mut - 1;
        }
        m & n_mut
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let n = scan.token::<usize>();

    for _ in 0..n {
        let m = scan.token::<i32>();
        let n = scan.token::<i32>();

        let res = Solution::range_bitwise_and(m, n);
        println!("{}", res);
    }
}
