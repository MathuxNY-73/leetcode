impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut f1 = 0; let mut f2=1; let mut f3 = 1;
        if n == 0 { 0 }
        else if n <= 2 { 1 }
        else {
            for i in (2..n) {
                f1 = f2;
                f2 = f3;
                f3 = f1 + f2;
            }
            f3
        }
    }
}
