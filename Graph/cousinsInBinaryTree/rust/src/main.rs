extern crate input;

use std::io;
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
use input::Scanner;
use std::error::Error;

#[derive(Debug, PartialEq, Eq)]
 pub struct TreeNode {
   pub val: i32,
   pub left: Option<Rc<RefCell<TreeNode>>>,
   pub right: Option<Rc<RefCell<TreeNode>>>,
 }

 impl TreeNode {
   #[inline]
   pub fn new(val: i32) -> Self {
     TreeNode {
       val,
       left: None,
       right: None
     }
   }
}

struct Solution {
}

impl Solution {
    pub fn is_cousins(root: Option<Rc<RefCell<TreeNode>>>, x: i32, y: i32) -> bool {
        let mut q = VecDeque::new();
        q.push_back(root);

        while !q.is_empty() {
            let len = q.len();
            let mut sibling = false;
            let mut cousin = false;

            for _i in 0..len {

                if let Some(node_opt) = q.pop_front() {
                match node_opt {
                    Some(node) => {
                        let n = node.borrow();
                        if n.val == x || n.val == y {
                            if !cousin {
                                cousin = true;
                                sibling = true;
                            }
                            else {
                                return !sibling;
                            }
                        }
                        if let Some(left) = &n.left {
                            q.push_back(Some(Rc::clone(&left)));
                        }
                        if let Some(right) = &n.right {
                            q.push_back(Some(Rc::clone(&right)));
                        }
                        q.push_back(None);
                    },
                    None => {
                        sibling = false;
                    },
                }
                }

            }

            if cousin {
                return false;
            }
        }

        false
    }
}

fn read_b_tree<T: io::BufRead>(scan: &mut Scanner<T>, size: usize)
                               -> Result<Option<Rc<RefCell<TreeNode>>>, Box<dyn Error>> {
    if size == 0 {
        Ok(None)
    } else {

        let r = scan.token::<String>();
        if r == "N" {
            Ok(None)
        } else {
            let mut q = VecDeque::new();
            let root = Rc::new(RefCell::new(TreeNode::new(r.parse::<i32>()?)));
            q.push_back(Rc::clone(&root));

            let mut cnt: usize = 1;
            while cnt < size && !q.is_empty() {
                let node = match q.pop_front() {
                    Some(node) => Ok(node),
                    _ => Err("Queue should not be empty"),
                }?;

                let left = scan.token::<String>();
                let right = scan.token::<String>();

                if left != "N" {
                    let left_n = Rc::new(RefCell::new(TreeNode::new(left.parse::<i32>()?)));
                    node.borrow_mut().left = Some(Rc::clone(&left_n));
                    q.push_back(Rc::clone(&left_n));
                }
                cnt += 1;

                if right != "N" {
                    let right_n = Rc::new(RefCell::new(TreeNode::new(right.parse::<i32>()?)));
                    node.borrow_mut().right = Some(Rc::clone(&right_n));
                    q.push_back(Rc::clone(&right_n));
                }
                cnt += 1;
            }
            Ok(Some(root))
        }
    }
}

fn main() {
    let (stdin, _stdout) = (io::stdin(), io::stdout());
    let mut scan = Scanner::new(stdin.lock());

    let t = scan.token::<usize>();

    for _ in 0..t {
        println!("New Test Case");
        let n = scan.token::<usize>();
        let x = scan.token::<i32>();
        let y = scan.token::<i32>();

        println!("n={}, x={}, y={}", n, x, y);
        let root1 = match read_b_tree(&mut scan, n) {
            Ok(tree) => tree,
            Err(e) => panic!("Could not read tree because {}", e),
        };

        let res = Solution::is_cousins(root1, x, y);
        println!("{}", res);
        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

        //println!("{:?}", res.1);
    }
}




