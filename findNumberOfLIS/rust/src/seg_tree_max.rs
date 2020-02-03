use std::cmp::{min, max};

pub struct SegmentTreeMax {
    tree: Vec<(i32,i32)>,
}

impl SegmentTreeMax {
    pub fn new(table: &Vec<i32>, debug: bool) -> SegmentTreeMax {
        let mut tree = vec![(0,0);table.len() * 4];
        SegmentTreeMax::build_tree(table, &mut tree, 1, 0, table.len() - 1, 0, debug);

        SegmentTreeMax { tree }
    }

    fn combine_tuple(l: (i32, i32), r: (i32,i32)) -> (i32,i32) {
        if l.0 > r.0 {
            l
        }
        else if l.0 < r.0 {
            r
        }
        else {
            (l.0, l.1 + r.1)
        }
    }

    fn build_tree(nums: &Vec<i32>, t: &mut Vec<(i32,i32)>, v: usize, tl: usize, tr: usize, l: usize, debug: bool) -> () {
        if tl == tr {
            t[v] = (nums[tl], 1);
        }
        else {
            let tm: usize = (tl + tr) / 2;
            let space = "  ".repeat(l);

            if debug {
                print!("{}", space);
                println!("v={}, tl={} and tr={}", v, tl, tr);
                print!("{}", space);
                SegmentTreeMax::print_tree(t);
            }
            SegmentTreeMax::build_tree(nums, t, v * 2, tl, tm, l + 1, debug);

            if debug {
                print!("{}", space);
                println!("End of build left");
                print!("{}", space);
                SegmentTreeMax::print_tree(t);
            }
            SegmentTreeMax::build_tree(nums, t, v * 2 + 1, tm + 1, tr, l + 1, debug);

            if debug {
                print!("{}", space);
                println!("End of build right");
                print!("{}", space);
                SegmentTreeMax::print_tree(t);
            }

            t[v] = SegmentTreeMax::combine_tuple(t[v*2], t[v*2 + 1]);
        }
    }

    fn print_tree(t: &Vec<(i32, i32)>) -> () {
        for (m, n) in t.iter() {
            print!("({}, {}) ", m, n);
        }
        println!("")
    }

    pub fn update(&mut self, v: usize, tl: usize, tr: usize, pos: usize, new_val: i32) -> () {
        if tl == tr {
            self.tree[v] = (new_val, 1);
        }
        else {
            let tm: usize = (tl + tr) /2;
            if pos <= tm {
                self.update(v*2, tl, tm, pos, new_val);
            }
            else {
                self.update(v*2 + 1, tm + 1, tr, pos, new_val);
            }
            self.tree[v] = SegmentTreeMax::combine_tuple(self.tree[v*2], self.tree[v*2 + 1]);
        }
    }

    pub fn get(&self, v: usize, tl: usize, tr: usize, l: usize, r: usize) -> (i32, i32) {
        if l > r {
            (0, 1)
        }
        else if l == tl && r == tr {
            self.tree[v]
        }
        else {
            let tm: usize = (tl + tr) / 2;
            SegmentTreeMax::combine_tuple(self.get(v*2, tl, tm, l, min(tm, r)), self.get(v*2 + 1, tm + 1, tr, max(tm + 1, l), r))
        }
    }
}
