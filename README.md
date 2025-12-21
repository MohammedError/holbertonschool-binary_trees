# holbertonschool-binary_trees

## Description
This project focuses on understanding and implementing different types of binary trees in C, 
including basic binary trees, Binary Search Trees (BST), AVL trees, and Max Binary Heaps. 
It also introduces tree traversal methods, tree properties (height, depth, size), and 
time complexity analysis for tree operations.

---

## Table of Contents
- [Description](#description)
- [What We Learned From This Project](#what-we-learned-from-this-project)
- [Requirements](#requirements)
- [File Overview](#file-overview)
- [Examples](#examples)
- [Output](#output)
- [Compilation](#compilation)
- [Testing](#testing)
- [Contributors](#contributors)

---

## What We Learned From This Project

- How binary trees work  
- Differences between Binary Trees and Binary Search Trees (BST)  
- Depth, height, size, and properties of binary trees  
- Tree traversal methods: pre-order, in-order, post-order, level-order  
- How to check for complete, full, perfect, and balanced trees  
- How to implement BST and AVL tree operations  
- Writing clean and readable C code following the Betty style  

---

## Requirements

- Ubuntu 20.04 LTS  
- GCC compiler  
- Compilation flags:
```bash
-Wall -Werror -Wextra -pedantic -std=gnu89
```
- Betty coding style
- No global variables
- Include guards in all header files

---
## File Overview

| File | Description |
|------|-------------|
| `README.md` | Project documentation |
| `binary_trees.h` | Header file with all function prototypes and data structures |
| `print_tree.c` | Function to visualize a binary tree (for testing) |
| `0-binary_tree_node.c` | Create a binary tree node |
| `1-binary_tree_insert_left.c` | Insert a node as the left child |
| `2-binary_tree_insert_right.c` | Insert a node as the right child |
| `3-binary_tree_delete.c` | Delete an entire binary tree |
| `4-binary_tree_is_leaf.c` | Check if a node is a leaf |
| `5-binary_tree_is_root.c` | Check if a node is a root |
| `6-binary_tree_preorder.c` | Pre-order traversal |
| `7-binary_tree_inorder.c` | In-order traversal |
| `8-binary_tree_postorder.c` | Post-order traversal |
| `9-binary_tree_height.c` | Compute tree height |
| `10-binary_tree_depth.c` | Compute node depth |
| `11-binary_tree_size.c` | Compute tree size |
| `12-binary_tree_leaves.c` | Count leaves |
| `13-binary_tree_nodes.c` | Count nodes with at least one child |
| `14-binary_tree_balance.c` | Measure balance factor |
| `15-binary_tree_is_full.c` | Check if tree is full |
| `16-binary_tree_is_perfect.c` | Check if tree is perfect |
| `17-binary_tree_sibling.c` | Find sibling of a node |
| `18-binary_tree_uncle.c` | Find uncle of a node |
| `100-binary_trees_ancestor.c` | Find lowest common ancestor |
| `101-binary_tree_levelorder.c` | Level-order traversal |
| `102-binary_tree_is_complete.c` | Check if tree is complete |
| `103-binary_tree_rotate_left.c` | Rotate tree left |
| `104-binary_tree_rotate_right.c` | Rotate tree right |
| `110-binary_tree_is_bst.c` | Check if tree is a BST |
| `111-bst_insert.c` | Insert value into BST |
| `112-array_to_bst.c` | Build BST from array |
| `113-bst_search.c` | Search value in BST |
| `114-bst_remove.c` | Remove node from BST |
| `120-binary_tree_is_avl.c` | Check if tree is AVL |
| `121-avl_insert.c` | Insert node into AVL |
| `122-array_to_avl.c` | Build AVL from array |
| `123-avl_remove.c` | Remove node from AVL |
| `124-sorted_array_to_avl.c` | Build AVL from sorted array |
| `130-binary_tree_is_heap.c` | Check if tree is a Max Binary Heap |
| `131-heap_insert.c` | Insert value into Max Binary Heap |
| `132-array_to_heap.c` | Build Max Binary Heap from array |
| `133-heap_extract.c` | Extract root from Max Binary Heap |
| `134-heap_to_sorted_array.c` | Convert Max Binary Heap to sorted array |

---