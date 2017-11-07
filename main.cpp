#include <iostream>
#include "MinHeap.h"
#include <cstdlib>

int main(){
    MinHeap heap(11);
    heap.printAsBinaryTree();
    heap.remove(0);

    heap.insert(45);
    heap.insert(15);
    heap.insert(30);
    heap.insert(2);
    heap.insert(1);
    heap.insert(3);
    heap.insert(17);
    heap.insert(0);
    heap.insert(4);

    heap.printAsBinaryTree();

    heap.remove(5);
    heap.printAsBinaryTree();

    heap.setValue(4, 20);
    heap.printAsBinaryTree();

    return 0;
}