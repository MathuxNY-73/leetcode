use std::cmp::{min, max};
use std::cell::RefCell;
use std::rc::Rc;
use std::ops::DerefMut;
use std::ops::Deref;

pub struct TreeNode {
    start: i32,
    end: i32,
    right: Option<Rc<RefCell<TreeNode>>>,
    left: Option<Rc<RefCell<TreeNode>>>,
    pub val: (i32, i32),
}

impl TreeNode {
    fn new(start: i32, end: i32) -> TreeNode {
        TreeNode {
            start,
            end,
            right: None,
            left: None,
            val: (0,1)
        }
    }

    fn get_right(&mut self) -> &Option<Rc<RefCell<TreeNode>>> {
        if self.right.is_none() {
            let new_s = ((self.start + self.end) as f64 / 2f64).floor() as i32 + 1;
            //println!("Generate right with [{},{}]", new_s, self.end);
            let right_box = Rc::new(RefCell::new(TreeNode::new(new_s, self.end)));
            self.right = Some(right_box);
        }
        &self.right
    }

    fn get_left(&mut self) -> &Option<Rc<RefCell<TreeNode>>> {
        if self.left.is_none() {
            let new_e = ((self.start + self.end) as f64 / 2f64).floor() as i32;
            //println!("Generate left with [{},{}]", self.start, new_e);
            let left_box = Rc::new(RefCell::new(TreeNode::new(self.start, new_e)));
            self.left = Some(left_box);
        }
        &self.left
    }
}

pub struct SegmentTreeLis {
    pub root: TreeNode,
}

impl SegmentTreeLis {
    pub fn new(start: i32, end: i32) -> SegmentTreeLis {
        SegmentTreeLis {
            root: TreeNode::new(start, end)
        }
    }

    pub fn build(nums: &Vec<i32>) -> SegmentTreeLis {
        let end = nums.iter().cloned().fold(None, |max, x| match max {
            None => Some(x),
            Some(y) => Some(i32::max(x, y))
        }).unwrap();
        let start = nums.iter().cloned().fold(None, |min, x| match min {
            None => Some(x),
            Some(y) => Some(i32::min(x,y))
        }).unwrap();
        let root = TreeNode::new(start, end);
        let root_cell = Some(Rc::new(RefCell::new(root)));

        for el in nums.iter() {
            let val = SegmentTreeLis::get(&root_cell, el - 1);
            //println!("For {} found {:?}", el, val);
            SegmentTreeLis::add(&root_cell, (val.0 + 1, val.1), *el, 10);
        }

        SegmentTreeLis {
            root: root_cell.unwrap().replace(TreeNode::new(0,0))
        }
    }

    pub fn get(v: &Option<Rc<RefCell<TreeNode>>>, key: i32) -> (i32, i32) {
        match v {
            Some(v_rc) => {
                let mut v_node = v_rc.borrow_mut();

                if key >= v_node.end {
                    v_node.val
                }
                else if key < v_node.start {
                    (0, 1)
                }
                else {
                    SegmentTreeLis::combine(
                        SegmentTreeLis::get(v_node.get_left(), key),
                        SegmentTreeLis::get(v_node.get_right(), key)
                    )
                }
            },
            _ => (0, 1),
        }
    }

    pub fn combine(l: (i32, i32), r: (i32, i32)) -> (i32, i32) {
        if l.0 > r.0 {
            l
        }
        else if l.0 < r.0 {
            r
        }
        else {
            if l.0 != 0 {
                (l.0, l.1 + r.1)
            } else {
                (0, 1)
            }
        }
    }

    pub fn add(v: &Option<Rc<RefCell<TreeNode>>>, val: (i32, i32), key: i32, lvl: i32) -> () {
        if let Some(v_rc) = v {
            let mut v_node = v_rc.borrow_mut();
            //println!("On [{}, {}] with lvl={}", v_node.start, v_node.end, lvl);
            //if lvl == 0 {
            //    panic!("Max depth reached");
            //}

            if v_node.start == v_node.end {
                v_node.val = SegmentTreeLis::combine(
                    v_node.val, val
                );
            }
            else {
                let m: i32 = ((v_node.start + v_node.end) as f64 / 2f64).floor() as i32;
                if key <= m {
                    //println!("Test hello 1");
                    SegmentTreeLis::add(v_node.get_left(), val, key, lvl - 1);
                }
                else {
                    //println!("Test hello 2");
                    SegmentTreeLis::add(v_node.get_right(), val, key, lvl - 1);
                }

                let left = {v_node.get_left().as_ref().unwrap().borrow().val};
                let right = {v_node.get_right().as_ref().unwrap().borrow().val};
                //println!("On [{},{}] left: {:?} right: {:?}", v_node.start, v_node.end, left, right);

                v_node.val = SegmentTreeLis::combine(left, right);
            }
        }
    }
}
