#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

#include<iostream>
using namespace std;

template <class T>
class myQueue {
public:
	myQueue(int maxSz);
	~myQueue();
	void enqueue(T item);
	T dequeue();
    int currentSize();
    bool isEmpty();
    bool isFull();

private:
	T *contents; /*Dynamic initiate (C++ keyword new) the holder array*/
	int front,rear;  /*Index in the array of the front and rear element*/
	int arrayLength;  /*The length of the contents holder array*/
		/* Keep in mind that the Queue will only hold up to (arrayLength - 1) elements*/
};

template <class T>
myQueue<T>::myQueue(int maxSz) {
    arrayLength = maxSz + 1;
    contents = new T[arrayLength];
    front = -1;
    rear = -1;
}

template <class T>
myQueue<T>::~myQueue() {
    delete [] contents;
}

template <class T>
void myQueue<T>::enqueue(T item) {
    if(isFull())
        cout << "The queue is full" << endl;
    else {
        rear = (rear + 1) % arrayLength;
        contents[rear] = item;
    }
 
}

template <class T>
T myQueue<T>::dequeue() {
	if(isEmpty())
        cout << "This queue is empty";
    else{
        front = (front + 1) % arrayLength;
        return contents[front];
    }
}

template <class T>
int myQueue<T>::currentSize() {
    return rear + 1;
}

template <class T>
bool myQueue<T>::isEmpty() {
	if(front == currentSize() - 1)
        return true;
    return false;
}

template <class T>
bool myQueue<T>::isFull() {
	if(currentSize() == arrayLength - 1)
        return true;
    return false;
}

#endif
