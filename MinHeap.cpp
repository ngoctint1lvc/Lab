#include <iostream>
#include "MinHeap.h"
#include <climits>
#include <string>

int MinHeap::parent(int i){
    return (i - 1) / 2;
}

int MinHeap::leftChild(int i){
    return 2 * i + 1;
}

int MinHeap::rightChild(int i){
    return 2 * i + 2;
}

void MinHeap::swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

MinHeap::MinHeap(int capacity){
    this->capacity = capacity;
    if(capacity <= 0){
        std::cout << "Error: the capacity of heap cannot smaller than or equal 0" << std::endl; 
    }
    size = 0;
    data = new int[capacity];
}

void MinHeap::insert(int value){
    if(size == capacity){
        std::cout << "Error: heap overflows" << std::endl;
        return;
    }

    size++;
    data[size - 1] = value;
    reHeapUp(size - 1);
}

void MinHeap::reHeapUp(int i){
    while(i > 0 && data[i] < data[parent(i)]){
        swap(data[parent(i)], data[i]);
        i = parent(i);
    }
}

void MinHeap::reHeapDown(int i){
    while(leftChild(i) < size || rightChild(i) < size){
        // Find smallest element
        int smallest = i;
        if(leftChild(i) < size && data[leftChild(i)] < data[smallest]){
            smallest = leftChild(i);
        }
        if(rightChild(i) < size && data[rightChild(i) < data[smallest]]){
            smallest = rightChild(i);
        }

        // Swap element down
        if(smallest != i){
            swap(data[smallest], data[i]);
            i = smallest;
        }
        else break;
    }
}

int MinHeap::extractMin(){
    if(size == 0){
        std::cout << "Heap is already empty" << std::endl;
        return INT_MIN;
    }

    int min = data[0];
    data[0] = data[size - 1];
    size--;
    if(0 < size) reHeapDown(0);
    return min;
}

int MinHeap::getMin(){
    if(size == 0){
        std::cout << "Heap is empty" << std::endl;
        return INT_MIN;
    }
    return data[0];
}

void MinHeap::remove(int i){
    if(i < 0 || i >= size){
        std::cout << "Error: Index i is out of heap size" << std::endl;
        return;
    }
    if(size == 0){
        std::cout << "Error: Cannot remove! Heap is already empty" << std::endl;
        return;
    }
    data[i] = data[size - 1];
    size--;
    if(i < size) reHeapDown(i);
}

void MinHeap::setValue(int i, int newValue){
    if(i < 0 || i >= size){
        std::cout << "Error: Index i is out of heap size" << std::endl;
        return;
    }
    data[i] = newValue;
    if(data[i] < data[parent(i)]){
        reHeapUp(i);
    }
    else{
        reHeapDown(i);
    }
}

void MinHeap::printAsBinaryTree(int i, int depth){
    if(i >= size) return;
    // Create alignment string
    std::string alignment(depth, ' ');

    // Print to console
    std::cout << alignment << data[i] << std::endl;
    printAsBinaryTree(leftChild(i), depth + 3);
    printAsBinaryTree(rightChild(i), depth + 3);
}

void MinHeap::printAsBinaryTree(){
    printAsBinaryTree(0, 0);
}

void MinHeap::printAsArray(){
    for(int i = 0; i < size; i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}