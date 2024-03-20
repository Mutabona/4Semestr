#include <iostream>

template <typename T>
class CircularQueue {
    private:
    std::size_t size;
    std::size_t head;
    std::size_t tail;
    T** queue;

    public:
    void enqueue(const T& element);
    void dequeue();
    T* front();
    T* back();
    void print();

    CircularQueue(size_t _size): size(_size) {
        std::cout<<"Standart constructor queue"<<std::endl;
        head = 0;
        tail = -1;
        queue = new T*[size];
        for (int i = 0; i < size; i++) {
            queue[i] = NULL;
        }
    }

    CircularQueue(const CircularQueue& _queue): size(_queue.size), head(_queue.head), tail(_queue.tail) {
        std::cout<<"Copy constructor queue"<<std::endl;
        queue = new T*[size];
        for (int i = 0; i < size; i++) {
            queue[i] = new T(*(_queue.queue[i]));
        }
    }

    ~CircularQueue() {
        for (int i = 0; i < size; i++)
            delete queue[i];
        delete[] queue;
        std::cout<<"Queue destructor"<<std::endl;
    }
};

template <typename T>
void CircularQueue<T>::enqueue(const T& element) {   
    if (tail == size-1) {
        tail = 0;
        delete queue[tail];
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
    delete queue[head];  
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
void CircularQueue<T>::print() {
    for (int i = head, j = 0; queue[i] != NULL && j < size; i < size-1 ? i++ : i=0, j++) {
        if (queue[i] != NULL) queue[i]->print();
    }
}

