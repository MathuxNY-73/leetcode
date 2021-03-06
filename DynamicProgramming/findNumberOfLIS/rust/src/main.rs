use std::io;

mod seg_tree;
mod seg_tree_max;
mod seg_tree_lis;

use seg_tree::SegmentTreeSum;
use seg_tree_max::SegmentTreeMax;
use seg_tree_lis::SegmentTreeLis;

struct Solution {
}

impl Solution {
    pub fn find_number_of_lis(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            0
        }
        else {
            let mut v: Vec<Vec<(i32, i32)>> = vec![vec!();nums.len() + 1];

            let mut lis = 0;
            for num in nums {
                let mut l = 0;
                let mut r = lis;

                while l < r {
                    let m = l + (r - l) / 2;
                    if v[m].last().unwrap().0 < num {
                        l = m + 1;
                    }
                    else {
                        r = m;
                    }
                }

                let mut possibilities = 1;

                if l > 0 {
                    let mut l1 = 0;
                    let mut r = v[l-1].len();

                    while l1 < r {
                        let m = l1 + (r - l1) / 2;
                        if v[l-1][m].0 < num {
                            r = m;
                        }
                        else {
                            l1 = m + 1;
                        }
                    }

                    possibilities = v[l-1].last().unwrap().1;
                    possibilities -= if l1 == 0 { 0 } else { v[l-1][l1-1].1 };
                }

                let pos = if let Some(p) = v[l].last() {
                    p.1 + possibilities
                }
                else {
                    possibilities
                };
                v[l].push((num, pos));

                if l == lis {
                    lis += 1;
                }

            }

            v[lis - 1].last().unwrap().1
        }
    }

    pub fn find_number_of_lis_seg_tree(&self, nums: Vec<i32>) -> (i32,i32) {
        if nums.len() == 0 {
            return (0,1)
        }

        let tr = SegmentTreeLis::build(&nums);
        //println!("Sum is: {:?}", tr.get(1,0,nums.len() - 1, 0, nums.len() - 1));
        //tr.update(1, 0, nums.len() - 1, 2, 100);
        //let s = tr.get(1, 0, nums.len() - 1, 0, nums.len() - 1);
        tr.root.val
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

        let nums = (0..nums_size).map( |_| scan.token::<i32>()).collect();
        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

        let res = Solution{}.find_number_of_lis_seg_tree(nums);
        println!("{:?}", res.1);
    }
}




