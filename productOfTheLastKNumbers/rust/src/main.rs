use std::io;
use std::vec::Vec;

struct ProductOfNumbers {
    tree: Vec<i32>,
    n: usize,
}

impl ProductOfNumbers {

    fn new() -> ProductOfNumbers {
        ProductOfNumbers {
            tree: Vec::new(),
            n: 0
        }
    }

    fn add(&mut self, num: i32) -> () {
        self.tree.push(1);
        self.add_priv(self.n as i32, num);
        self.n = self.n + 1;
    }

    fn add_priv(&mut self, idx: i32, num: i32) {
        let mut i = idx;
        while i >= 0 {
            //println!("Tree[{}]={}", i, self.tree[i as usize]);
            self.tree[i as usize] *= num;
            i = (i & (i + 1)) - 1;
        }
    }

    fn get_product(&self, k: i32) -> i32 {
        let mut res = 1;
        let mut i = self.n - k as usize;

        while i < self.n {
            res *= self.tree[i];
            i |= i + 1;
        }
        res
    }
}

fn main() {
    use myio::Scanner;

    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        //println!("New Test Case");
        let nums_size = scan.token::<usize>();
        let mut pon = ProductOfNumbers::new();

        for _ in 0..nums_size {
            let c = scan.token::<String>();
            if c == "f" {
                let k = scan.token::<i32>();
                println!("{}", pon.get_product(k));
            } else {
                let num = c.parse::<i32>().unwrap();
                //println!("Number is {}", num);
                pon.add(c.parse::<i32>().unwrap());
            }
        }
        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

    }
}




