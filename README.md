File System with Linked Lists
===================================

Overview
--------

This C++ project involves implementation of a doubly linked list with a dummy head node and using it to create a simplified file system. The file system consists of a single directory with multiple files, and the implementation includes classes for linked lists, nodes, blocks, files, and directories.

Linked List Implementation
--------------------------

### LinkedList Class

The `LinkedList` class is a template class representing a doubly linked list with a dummy head node. It has the following key functionalities:

*   **Constructors and Destructor:**
    
    *   `LinkedList()`: Default constructor for initializing an empty doubly linked list.
    *   `LinkedList(const LinkedList &rhs)`: Copy constructor for deep copying linked lists.
    *   `~LinkedList()`: Destructor for deallocating memory.
*   **Assignment and Information Functions:**
    
    *   `LinkedList<T> &operator=(const LinkedList &rhs)`: Overloaded assignment operator.
    *   `int getSize() const`: Returns the number of nodes in the linked list (excluding the dummy node).
    *   `bool isEmpty() const`: Returns true if the linked list is empty; otherwise, false.
    *   `bool containsNode(Node<T> *node) const`: Returns true if the linked list contains the given node.
*   **Node Access Functions:**
    
    *   `int getIndex(Node<T> *node) const`: Returns the index of the given node in the linked list.
    *   `Node<T> *getFirstNode() const`: Returns a pointer to the first node in the linked list.
    *   `Node<T> *getLastNode() const`: Returns a pointer to the last node in the linked list.
    *   `Node<T> *getNode(const T &data) const`: Returns a pointer to the node with the given data.
*   **Node Manipulation Functions:**
    
    *   `void append(const T &data)`: Adds a new node with the given data at the end of the linked list.
    *   `void prepend(const T &data)`: Adds a new node with the given data at the front of the linked list.
    *   `void insertAfterNode(const T &data, Node<T> *node)`: Inserts a new node with the given data after the specified node.
    *   `void insertAtIndex(const T &data, int index)`: Inserts a new node with the given data at the specified index.
*   **Node Removal Functions:**
    
    *   `void removeNode(Node<T> *node)`: Removes the given node from the linked list.
    *   `void removeNode(const T &data)`: Removes the node with the given data from the linked list.
    *   `void removeNodeAtIndex(int index)`: Removes the node at the specified index from the linked list.
*   **Other Node Operations:**
    
    *   `void moveToIndex(int currentIndex, int newIndex)`: Moves the node at the currentIndex to newIndex.
    *   `void mergeNodes(int sourceIndex, int destIndex)`: Merges nodes by adding content and deleting the source node.
    *   `void removeAllNodes()`: Removes all nodes (excluding the dummy node) in the linked list.
    *   `void print() const`: Prints the linked list to the standard output.

File System Implementation
--------------------------

### Block Class

The `Block` class represents a variable-sized block in memory. It contains a string `content` and a size variable. The class has the following key functionality:

*   `Block &operator+(const Block &rhs)`: Appends the content of another block to the current block.

### File Class

The `File` class represents a file in the directory. It contains a linked list of blocks. Key functionalities include:

*   `size_t fileSize() const`: Returns the cumulative size of blocks in the file.
*   `int numBlocks() const`: Returns the number of blocks in the file.
*   `bool isEmpty() const`: Returns true if the file is empty; otherwise, false.
*   `bool operator==(const File &rhs) const`: Checks equality based on content and block count.
*   `void newBlock(const Block &block)`: Adds a new block at the end of the file.
*   `void removeBlock(int index)`: Removes the block at the specified index.
*   `void mergeBlocks(int sourceIndex, int destIndex)`: Merges blocks by appending and deleting the source block.
*   `void printContents() const`: Prints the contents of the file with its size to the standard output.

### Directory Class

The `Directory` class implements a simple directory structure with a vector of files. Key functionalities include:

*   `File getFile(int index) const`: Returns the file at the specified index.
*   `size_t directorySize() const`: Returns the cumulative size of files in the directory.
*   `bool isEmpty() const`: Returns true if the directory is empty; otherwise, false.
*   `size_t numFiles() const`: Returns the number of files in the directory.
*   `void newFile(const File &file)`: Adds a new file at the end of the directory.
*   `void removeFile(int index)`: Removes the file at the specified index.
*   `void removeFile(const File &file)`: Removes the first occurrence of the specified file.
*   `void removeBiggestFile()`: Finds and removes the biggest file from the directory.
