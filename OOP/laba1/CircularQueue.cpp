#include <iostream>

template <typename T>
class CircularQueue {
    private:
    std::size_t size;
    std::size_t head;
    std::size_t tail;
    T** queue;

    public:
    void enqueue(T element);
    void dequeue();
    T* front();
    T* back();
    void printQueue();

    CircularQueue(size_t _size): size(_size) {
        head = 0;
        tail = -1;
        queue = new T*[size];
    }

    CircularQueue(const CircularQueue& _queue): size(_queue.size), head(_queue.head), tail(_queue.tail) {
        queue = new T*[size];
        for (int i = 0; i < size; i++) {
            queue[i] = new T(*(_queue.queue[i]));
        }
    }

    ~CircularQueue() {
        for (int i = 0; i < size; i++)
            free(queue[i]);
    }
};

template <typename T>
void CircularQueue<T>::enqueue(T element) {   
    if (tail == size-1) {
        tail = 0;
        free(queue[tail]);
    }
    else {
        tail++;
    }
    queue[tail] = new T(element);
}

template <typename T>
void CircularQueue<T>::dequeue() { 
    if (tail < 0) return;
    if (queue[head] == NULL) return;
    free(queue[head]);  
    queue[head++] = NULL;
    if (head == size) {
        head = 0;
    }
}

template <typename T>
T* CircularQueue<T>::front() {
    if (head < 0) return NULL;
    return queue[head];
}

template <typename T>
T* CircularQueue<T>::back() {
    if (tail < 0) return NULL;
    return queue[tail];
}

template <typename T>
void CircularQueue<T>::printQueue() {
    for (int i = head, j = 0; queue[i] != NULL && j < size; i < size-1 ? i++ : i=0, j++) {
        queue[i]->print();
    }
}