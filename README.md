# 0x1D. C - Binary Trees

## Description
This project introduces the concept of **Binary Trees** in C programming. A binary tree is a hierarchical data structure where each node has at most two children, known as the left and right child. You will:
- Implement basic binary tree operations
- Create functions for tree manipulation
- Understand tree traversal techniques

## Learning Objectives
By completing this project, you will:
- Understand binary tree data structures
- Implement tree creation and manipulation functions
- Learn different tree traversal methods (pre-order, in-order, post-order)
- Handle tree node insertions, deletions, and checks

---

## Requirements
| **Category**   | **Details**                                                                 |
|----------------|-----------------------------------------------------------------------------|
| **Editors**    | `vi`, `vim`, `emacs`                                                       |
| **Compiler**   | Ubuntu 20.04 LTS, `gcc`, `-Wall -Werror -Wextra -pedantic -std=gnu89`     |
| **Files**      | All files must end with a new line                                         |
| **README**     | A `README.md` file is mandatory                                            |
| **Style**      | Follow `Betty` coding style                                                |
| **Restrictions**| No global variables, max 5 functions per file                             |

---

## Tasks
 
| **Task #** | **Description**                                                            | **File**                        |
|------------|----------------------------------------------------------------------------|----------------------------------|
| **0**      | Create a binary tree node                                                  | `0-binary_tree_node.c`          |
| **1**      | Insert a node as the left child                                            | `1-binary_tree_insert_left.c`   |
| **2**      | Insert a node as the right child                                           | `2-binary_tree_insert_right.c`  |
| **3**      | Delete an entire binary tree                                               | `3-binary_tree_delete.c`        |
| **4**      | Check if a node is a leaf                                                  | `4-binary_tree_is_leaf.c`       |
| **5**      | Check if a node is a root                                                  | `5-binary_tree_is_root.c`       |
| **6**      | Perform pre-order tree traversal                                           | `6-binary_tree_preorder.c`      |
| **7**      | Perform in-order tree traversal                                            | `7-binary_tree_inorder.c`       |
| **8**      | Perform post-order tree traversal                                          | `8-binary_tree_postorder.c`     |
| **9**      | Measure the height of a binary tree                                        | `9-binary_tree_height.c`        |
| **10**     | Measure the depth of a node in a binary tree                               | `10-binary_tree_depth.c`        |
| **11**     | Measure the size of a binary tree                                              | `11-binary_tree_size.c`         |
| **12**     | Count the leaves in a binary tree                                              | `12-binary_tree_leaves.c`       |
| **13**     | Count the nodes with at least 1 child in a binary tree                         | `13-binary_tree_nodes.c`        |
| **14**     | Measure the balance factor of a binary tree                                    | `14-binary_tree_balance.c`      |
| **15**     | Check if a binary tree is full                                             | `15-binary_tree_is_full.c`      |
| **16**     | Check if a binary tree is perfect                                          | `16-binary_tree_is_perfect.c`   |
| **17**     | Find the sibling of a node                                                | `17-binary_tree_sibling.c`      |
| **18**     | Find the uncle of a node                                                  | `18-binary_tree_uncle.c`        |
| **19**     | Find the lowest common ancestor of two nodes                              | `100-binary_trees_ancestor.c`   |
| **20**     | Perform level-order tree traversal                        | `101-binary_tree_levelorder.c`   |
| **21**     | Check if a binary tree is complete                        | `102-binary_tree_is_complete.c`  |
| **22**     | Perform left rotation on a binary tree                    | `103-binary_tree_rotate_left.c`  |
| **23**     | Perform right rotation on a binary tree                   | `104-binary_tree_rotate_right.c` |
| **24**     | Check if a binary tree is a valid Binary Search Tree (BST) | `110-binary_tree_is_bst.c`       |
| **25**     | Insert a value into a Binary Search Tree                  | `111-bst_insert.c`               |
| **26**     | Convert an array to a Binary Search Tree (BST)                                 | `112-array_to_bst.c`             |
| **27**     | Search for a value in a Binary Search Tree (BST)                               | `113-bst_search.c`               |
| **28**     | Remove a node from a Binary Search Tree (BST)                                  | `114-bst_remove.c`               |
| **29**     | Document the Big O complexity for BST operations                               | `115-O`                          |
| **30**     | Check if a binary tree is a valid AVL Tree                                      | `120-binary_tree_is_avl.c`       |
| 31         | Write a function that inserts a value in an AVL Tree, ensuring the tree remains balanced.           | `121-avl_insert.c`                      |
| 32         | Build an AVL tree from an array, ignoring duplicate values in the array.                            | `122-array_to_avl.c`                    |
| 33         | Write a function to remove a node from an AVL tree and rebalance it after removal.                  | `123-avl_remove.c`                      |
| 34         | Create an AVL tree from a sorted array without performing any rotations.                            | `124-sorted_array_to_avl.c`             |
| 35         | Provide the average time complexities for operations (insert, remove, search) in an AVL Tree.       | `125-O`                                 |
| 36   | **Is Binary Heap** <br> Write a function `int binary_tree_is_heap(const binary_tree_t *tree);` to check if a binary tree is a valid Max Binary Heap. <br> - Return 1 if true, else 0.          | `130-binary_tree_is_heap.c`                                                                |
| 37   | **Heap - Insert** <br> Write a function `heap_t *heap_insert(heap_t **root, int value);` to insert a value into a Max Binary Heap. <br> - Return a pointer to the created node, or NULL.      | `131-heap_insert.c`, `0-binary_tree_node.c`                                                |
| 38   | **Heap - Array to Binary Heap** <br> Write a function `heap_t *array_to_heap(int *array, size_t size);` to build a Max Binary Heap from an array. <br> - Return the root node or NULL.        | `132-array_to_heap.c`, `131-heap_insert.c`, `0-binary_tree_node.c`                         |
| 39   | **Heap - Extract** <br> Write a function `int heap_extract(heap_t **root);` to extract the root node of a Max Binary Heap. <br> - Return the value of the root node or 0 on failure.          | `133-heap_extract.c`, `132-array_to_heap.c`, `131-heap_insert.c`, `3-binary_tree_delete.c` |
| 40   | **Heap - Sort** <br> Write a function `int *heap_to_sorted_array(heap_t *heap, size_t *size);` to convert a Max Binary Heap to a sorted array in descending order.                             | `134-heap_to_sorted_array.c`, `133-heap_extract.c`, `132-array_to_heap.c`, `131-heap_insert.c` | 
| **41**     | create_avl_tree - Recursively builds an AVL tree from a sorted array.  | `135-O`               |


## Header File
The project uses a `binary_trees.h` header file that defines the following data structure:

```c
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

---

## Repository Structure
```
binary_trees/
├── binary_trees.h
├── 0-binary_tree_node.c
├── 1-binary_tree_insert_left.c
├── 2-binary_tree_insert_right.c
├── 3-binary_tree_delete.c
├── 4-binary_tree_is_leaf.c
├── 5-binary_tree_is_root.c
├── 6-binary_tree_preorder.c
└── README.md
```

---

## Additional Notes
- Each function focuses on a specific binary tree operation
- The project uses a print function for tree visualization (not to be submitted)
- All functions handle edge cases like NULL pointers
## Developer

**Codename**: Achraf Sadeq

## Acknowledgments

This project was developed for educational purposes by Holberton School, in collaboration with the ALX Software Engineering Program.


