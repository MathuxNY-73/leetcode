use std::io;
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
use myio::Scanner;
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
    fn canonize(root: &Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(tree) = root {
            let tree_n = tree.borrow();
            match (&(tree_n.left), &(tree_n.right)) {
                (Some(l), Some(r)) => {
                    let l_n = l.borrow();
                    let r_n = r.borrow();
                    if l_n.val < r_n.val {
                        let node = TreeNode {
                            val: tree_n.val,
                            left: Some(Rc::clone(l)),
                            right: Some(Rc::clone(r))
                        };
                        Some(Rc::new(RefCell::new(node)))
                    }
                    else {
                        let node = TreeNode {
                            val: tree_n.val,
                            left: Some(Rc::clone(r)),
                            right: Some(Rc::clone(l)),
                        };
                        Some(Rc::new(RefCell::new(node)))
                    }
                },
                (None, Some(r)) => {
                    let node = TreeNode {
                        val: tree_n.val,
                        left: None,
                        right: Some(Rc::clone(r)),
                    };
                    Some(Rc::new(RefCell::new(node)))
                },
                (Some(l), None) => {
                    let node = TreeNode {
                        val: tree_n.val,
                        left: None,
                        right: Some(Rc::clone(l)),
                    };
                    Some(Rc::new(RefCell::new(node)))
                },
                (None, None) => Some(Rc::new(RefCell::new(TreeNode::new(tree_n.val)))),
            }
        } else {
            None
        }
    }

    fn rec_flip_equiv(root1: &Option<Rc<RefCell<TreeNode>>>,
                      root2: &Option<Rc<RefCell<TreeNode>>>) -> bool {

        // Canonize the tree
        let can_root1 = Solution::canonize(root1);
        let can_root2 = Solution::canonize(root2);

        match (can_root1, can_root2) {
            (Some(r1), Some(r2)) => {
                let r1_n = r1.borrow();
                let r2_n = r2.borrow();

                if r1_n.val == r2_n.val {
                    Solution::rec_flip_equiv(&r1_n.left, &r2_n.left) &&
                        Solution::rec_flip_equiv(&r1_n.right, &r2_n.right)
                } else {
                    false
                }
          },
            (None, None) => true,
            (_, Some(_)) => false,
            (Some(_), _) => false,
        }
    }

    pub fn flip_equiv(root1: Option<Rc<RefCell<TreeNode>>>,
                      root2: Option<Rc<RefCell<TreeNode>>>) -> bool {

        Solution::rec_flip_equiv(&root1, &root2)
    }
}

fn read_b_tree<T: io::BufRead>(scan: &mut Scanner<T>, size: usize)
                               -> Result<Option<Rc<RefCell<TreeNode>>>, Box<dyn Error>> {
    if size == 0 {
        Ok(None)
    } else {

        let r = scan.token::<String>();
        println!("Token is {}", r);
        if r == "N" {
            Ok(None)
        } else {
            let mut q = VecDeque::new();
            let root = Rc::new(RefCell::new(TreeNode::new(r.parse::<i32>()?)));
            q.push_back(&root);

            let mut cnt: usize = 1;
            while cnt < size && !q.is_empty() {
                let node = match q.pop_front() {
                    Some(node) => Ok(node),
                    _ => Err("Queue should not be empty"),
                }?;

                let v = Rc::clone(node);

                let left = scan.token::<String>();
                let right = scan.token::<String>();

                if left != "N" {
                    let left_n = Rc::new(RefCell::new(TreeNode::new(left.parse::<i32>()?)));
                    v.borrow_mut().left = Some(Rc::clone(&left_n));
                    q.push_back(&left_n);
                }
                cnt += 1;

                if right != "N" {
                    let right_n = Rc::new(RefCell::new(TreeNode::new(right.parse::<i32>()?)));
                    v.borrow_mut().right = Some(Rc::clone(&right_n));
                    q.push_back(&right_n);
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
        //println!("New Test Case");
        let n = scan.token::<usize>();

        let root1 = match read_b_tree(&mut scan, n) {
            Ok(tree) => tree,
            Err(e) => panic!("Could not read tree because {}", e),
        };

        let m = scan.token::<usize>();
        let root2 = match read_b_tree(&mut scan, m) {
            Ok(tree) => tree,
            Err(e) => panic!("Could not read tree because {}", e),
        };

        let res = Solution::flip_equiv(root1, root2);
        println!("{}", res);
        /*for i in &nums {
            print!("{} ", i);
        }
        println!("");*/

        //println!("{:?}", res.1);
    }
}




