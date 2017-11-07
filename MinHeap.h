#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap{
    int* data;
    int size;
    int capacity;

    static int parent(int i);

    static int leftChild(int i);

    static int rightChild(int i);

    static void swap(int& x, int& y);

    void reHeapUp(int i);
    
    void reHeapDown(int i);

    void printAsBinaryTree(int i, int depth);

public:
    MinHeap(int capacity);

    void insert(int value);

    int extractMin();

    int getMin();

    void remove(int i);

    void setValue(int i, int newValue);

    void printAsBinaryTree();

    void printAsArray();
};

#endif