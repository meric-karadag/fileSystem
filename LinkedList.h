#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &rhs);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);
    void mergeNodes(int sourceIndex, int destIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    // My addition to get rid of the error
    void swapWithRight(Node<T> *node);
    void swapWithLeft(Node<T> *node);
    /* TODO */

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    // Complete
    size = 0;
    head = new Node<T>(T());
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
{
    /* TODO */
    // Complete
    // Copy all nodes from rhs to this
    // Do not need to delete existing nodes this is copy constructor
    head = new Node<T>(T());
    Node<T> *current = rhs.head->next;
    size = 0;
    while (current != nullptr)
    {
        this->append(current->data);
        current = current->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    // Complete
    // Delete all nodes
    Node<T> *current = head->next;
    delete head;
    Node<T> *temp = current;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    // Complete
    // First delete existing nodes except dummy head
    // If try to assign to itself return itself
    if (this == &rhs)
    {
        return *this;
    }
    this->removeAllNodes();
    // Copy all nodes from rhs to this
    Node<T> *current = rhs.head->next;
    while (current != nullptr)
    {
        this->append(current->data);
        current = current->next;
    }
    return *this;
}

template <class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    // Complete
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    // Complete
    return size == 0;
}

template <class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    // Complete
    if (node == nullptr)
    {
        return false;
    }
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current == node)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    // Complete
    if (size == 0)
    {
        return nullptr;
    }
    return head->next;
}

template <class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    // Complete
    // if size 0 return nullptr
    if (size == 0)
    {
        return nullptr;
    }
    // else traverse the list to reach the last node
    Node<T> *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    return current;
}

template <class T>
Node<T>* LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    // Complete
    // if size 0 return nullptr
    if (size == 0)
    {
        return nullptr;
    }
    // else traverse the list to reach the node with the data
    Node<T> *current = head->next;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    // if not found return nullptr
    return nullptr;
}

template <class T>
Node<T>* LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    // Complete
    // Check if index is valid if not return nullptr
    if (index >= size || index < 0)
    {
        return nullptr;
    }
    // find the valid node and return it
    else
    {
        Node<T> *current = head->next;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current;
    }
}

template <class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */
    // Complete
    // Get the last node and add a new node after it
    if (size == 0)
    {
        head->next = new Node<T>(data, head, nullptr);
    }
    else
    {
        Node<T> *last = this->getLastNode();
        last->next = new Node<T>(data, last, nullptr);
    }
    // Increase size
    size++;
}

template <class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    // Complete
    if (size == 0)
    {
        head->next = new Node<T>(data, head, nullptr);
    }
    else
    {
        Node<T> *first = head->next;
        head->next = new Node<T>(data, head, first);
        first->prev = head->next;
    }
    size++;
}

template <class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    // Complete
    // if node is null or size is 0 or node is not in the list return
    if (node == nullptr || size == 0 || !this->containsNode(node))
    {
        return;
    }
    else
    {
        // Find the given node
        Node<T> *current = head->next;
        while (current != nullptr)
        {
            if (current == node)
            {
                break;
            }
            current = current->next;
        }
        // Create and initialize new node
        Node<T> *new_node = new Node<T>(data, current, current->next);
        // Correct the links
        current->next = new_node;
        if (new_node->next != nullptr)
        {
            new_node->next->prev = new_node;
        }
        // Increase size
        size++;
    }
}

template <class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    // Complete
    // Check if index is within bounds
    if (index >= size || index < 0)
    {
        return;
    }
    // if index == 0 call prepend
    else if (index == 0)
    {
        this->prepend(data);
        return;
    }
    // Else find node at index and do links
    else
    {
        Node<T> *current = this->getNodeAtIndex(index);
        // Create and initialize new node
        Node<T> *new_node = new Node<T>(data, current->prev, current);
        // Correct the links
        current->prev->next = new_node;
        current->prev = new_node;
        size++;
        return;
    }
}

template <class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    Node<T> *current = head->next;
    int index = 0;
    // Traverse the list to find the node
    while (current != nullptr)
    {
        if (current == node)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    // If not found
    return -1;
}

template <class T>
void LinkedList<T>::swapWithLeft(Node<T> *node)
{
    /* TODO */
}

template <class T>
void LinkedList<T>::swapWithRight(Node<T> *node)
{
    /* TODO */
}

template <class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    // Complete but unsure
    // Check if currentIndex is valid
    if (currentIndex == newIndex)
    {
        return;
    }
    if (currentIndex >= size || currentIndex < 0)
    {
        return;
    }
    // Check if newIndex is valid
    if (newIndex < 0)
    {
        return;
    }
    // If newIndex is greater than size, set it to size
    bool to_end = false;
    if (newIndex >= size - 1)
    {
        newIndex = size - 1;
        to_end = true;
    }
    if (!to_end) // If not moving to end and carrying from left to right
    {
        if (currentIndex < newIndex)
        {
            newIndex++;
        }
    }
    Node<T> *current = this->getNodeAtIndex(currentIndex);
    Node<T> *current_prev = current->prev;
    Node<T> *current_next = current->next;
    // Get the node at newIndex
    Node<T> *target_node = this->getNodeAtIndex(newIndex);
    Node<T> *target_prev = target_node->prev;
    // Correct the links with current node
    current_prev->next = current_next; // Set the previous node's next to current's next. Current_prev Cant be nullptr
    if (current_next != nullptr)       // If current is not the last node
    {
        current_next->prev = current_prev;
    }
    if (to_end)
    {
        current->next = nullptr;
        current->prev = target_node;
        target_node->next = current;
    }
    else
    {
        current->next = target_node; // Set current's next to target
        current->prev = target_prev;
        // Correct the links with target node
        target_prev->next = current; // Target prev cant be nullptr because of dummy head
    }
}

template <class T>
void LinkedList<T>::mergeNodes(int sourceIndex, int destIndex)
{
    /* TODO */
    // Complete
    // Check if sourceIndex and destIndex are valid
    if (sourceIndex < 0 || sourceIndex > size - 1 || destIndex < 0 || destIndex > size - 1)
    {
        return;
    }
    // Get the nodes at sourceIndex and destIndex
    Node<T> *source = this->getNodeAtIndex(sourceIndex);
    Node<T> *source_prev = source->prev;
    Node<T> *source_next = source->next;
    Node<T> *dest = this->getNodeAtIndex(destIndex);
    // Do the merging operation
    dest->data = dest->data + source->data;
    // Correct the links
    source_prev->next = source_next;
    if (source_next != nullptr)
    {
        source_next->prev = source_prev;
    }
    size--;
    delete source;
}

template <class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    // Check if node is nullptr or size is 0 or node is not in the list return
    if (node == nullptr || size == 0 || !this->containsNode(node))
    {
        return;
    }
    else
    {
        // Find the given node
        Node<T> *current = head->next;
        while (current != nullptr)
        {
            if (current == node)
            {
                break;
            }
            current = current->next;
        }
        // Correct the links
        current->prev->next = current->next;
        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        delete current;
        size--;
    }
}

template <class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    // Complete
    // Remove all nodes with given data
    Node<T> *current = this->getNode(data);
    while(current)
    {
        this->removeNode(current);
        current = this->getNode(data);
    }
}

template <class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    // Complete
    Node<T> *current = getNodeAtIndex(index);
    if (current == nullptr)
    {
        return;
    }
    else
    {
        this->removeNode(current);
    }
}

template <class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    // Complete
    // Delete all nodes except dummy head
    Node<T> *current = head->next;
    Node<T> *temp;
    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
    head->next = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty())
    {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    while (node)
    {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

#endif // LINKEDLIST_H
