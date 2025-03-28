# DataStructures-A2

This repository contains implementations of various data structures and their applications. The project is designed to demonstrate the functionality of data structures such as Binary Search Trees (BST), AVL Trees, and Heaps, along with their integration into a menu-driven program.

## Features

- **Binary Search Tree (BST):**
  - Insert, remove, and search for items.
  - Display items sorted by name or price in ascending/descending order.

- **AVL Tree:**
  - Self-balancing binary search tree.
  - Supports insertion, removal, and traversal (inorder, preorder, postorder).

- **Heap:**
  - Max-Heap and Min-Heap implementations.
  - Insert and remove elements.
  - Display heap elements sorted by custom comparison functions.

- **Item Class:**
  - Represents an item with attributes like name, category, and price.
  - Supports custom comparison functions for sorting.

## File Structure

- **Source Files:**
  - `main.cpp`: Entry point for the menu-driven program.
  - `BinarySearchTree.cpp` & `BinarySearchTree.hpp`: Implementation of the Binary Search Tree.
  - `AVL.cpp` & `AVL.hpp`: Implementation of the AVL Tree.
  - `Heap.cpp` & `heap.hpp`: Implementation of the Heap.
  - `item.cpp`: Defines the `item` class.
  - `Tree.hpp`: Abstract base class for tree structures.

- **Test Files:**
  - `test.cpp`: Test cases for the Binary Search Tree.
  - `HeapTest.cpp`: Test cases for the Heap.
  - `avlTest.cpp`: Test cases for the AVL Tree.

- **Configuration Files:**
  - `.gitignore`: Specifies files and directories to be ignored by Git.
  - `.idea/`: Contains IDE-specific configuration files.

## How to Run

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/DataStructures-A2.git
   cd DataStructures-A2
   ```

2. **Compile the Code:**
   Use a C++ compiler like `g++` to compile the desired source files. For example:

   ```bash
   g++ main.cpp -o main
   ```

3. **Run the Program:**
   Execute the compiled binary:

   ```bash
   ./main
   ```

4. **Follow the Menu:**
   The program provides a menu-driven interface to interact with the data structures.

## Dependencies

- C++17 or later.
- Standard Template Library (STL).

## Example Usage

### Binary Search Tree

```text
=== BST Menu ===
1. Add item
2. Remove item by name
3. Remove item by price
4. Display items sorted by name (ascending)
5. Display items sorted by name (descending)
6. Display items sorted by price (ascending)
7. Display items sorted by price (descending)
8. Search for an item by name
9. Return to Main Menu
```

### Heap

```text
=== Heap Menu ===
1. Add item
2. Remove root item
3. Display items sorted by name (ascending)
4. Display items sorted by price (ascending)
5. Return to Main Menu
```

### AVL Tree

```text
=== AVL Menu ===
1. Add item
2. Inorder traversal
5. Exit
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
