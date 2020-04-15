use std::cmp::{min, max};

pub struct SegmentTreeSum {
    tree: Vec<i32>,
}

impl SegmentTreeSum {
    pub fn new(table: &Vec<i32>, debug: bool) -> SegmentTreeSum {
        let mut tree = vec![0;table.len() * 4];
        SegmentTreeSum::build_tree(table, &mut tree, 1, 0, table.len() - 1, 0, debug);

        SegmentTreeSum { tree }
    }

    fn build_tree(nums: &Vec<i32>, t: &mut Vec<i32>, v: usize, tl: usize, tr: usize, l: usize, debug: bool) -> () {
        if tl == tr {
            t[v] = nums[tl];
        }
        else {
            let tm: usize = (tl + tr) / 2;
            let space = "  ".repeat(l);

            if debug {
                print!("{}", space);
                println!("v={}, tl={} and tr={}", v, tl, tr);
                print!("{}", space);
                SegmentTreeSum::print_tree(t);
            }
            SegmentTreeSum::build_tree(nums, t, v * 2, tl, tm, l + 1, debug);

            if debug {
                print!("{}", space);
                println!("End of build left");
                print!("{}", space);
                SegmentTreeSum::print_tree(t);
            }
            SegmentTreeSum::build_tree(nums, t, v * 2 + 1, tm + 1, tr, l + 1, debug);

            if debug {
                print!("{}", space);
                println!("End of build right");
                print!("{}", space);
                SegmentTreeSum::print_tree(t);
            }

            t[v] = t[v*2] + t[v*2 + 1];
        }
    }

    fn print_tree(t: &Vec<i32>) -> () {
        for n in t.iter() {
            print!("{} ", n);
        }
        println!("")
    }

    pub fn update(&mut self, v: usize, tl: usize, tr: usize, pos: usize, new_val: i32) -> () {
        if tl == tr {
            self.tree[v] = new_val;
        }
        else {
            let tm: usize = (tl + tr) /2;
            if pos <= tm {
                self.update(v*2, tl, tm, pos, new_val);
            }
            else {
                self.update(v*2 + 1, tm + 1, tr, pos, new_val);
            }
            self.tree[v] = self.tree[v*2] + self.tree[v*2 + 1];
        }
    }

    pub fn sum(&self, v: usize, tl: usize, tr: usize, l: usize, r: usize) -> i32 {
        if l > r {
            0
        }
        else if l == tl && r == tr {
            self.tree[v]
        }
        else {
            let tm: usize = (tl + tr) / 2;
            self.sum(v*2, tl, tm, l, min(tm, r)) + self.sum(v*2 + 1, tm + 1, tr, max(tm + 1, l), r)
        }
    }
}
