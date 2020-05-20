extern crate input;

use std::io;

struct StockSpanner {
    stack: Vec<(i32, i32)>
}

impl StockSpanner {

    fn new() -> Self {
        StockSpanner {
            stack: Vec::<(i32,i32)>::new()
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut cnt = 1;
        while let Some((p, c)) = self.stack.last() {
            if p <= &price {
                cnt += c;
                self.stack.pop();
            }
            else {
                break;
            }
        }
        self.stack.push((price, cnt));

        cnt
    }
}

fn main() {
    use input::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<i32>();

    for i in 1..=t {
        print!("Case #{}:", i);
        let n = scan.token::<usize>();
        let mut stock_spanner = StockSpanner::new();

        for _ in 0..n {
            let num = scan.token::<i32>();

            let res = stock_spanner.next(num);
            print!(" {}", res);
        }
        println!()
    }
}
