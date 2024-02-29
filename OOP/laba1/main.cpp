#include "CircularQueue.cpp"
#include "Penalty.cpp"

int summarizePenaltys(CircularQueue<Penalty>& queue);

const int size = 9;

int main() {
    CircularQueue<Penalty> queue(9);
    for (int i = 0; i < 100; i++) {
        queue.enqueue(Penalty(i));
    }

    CircularQueue<Penalty> queue2 = queue;

    queue.printQueue();
    queue2.printQueue();

    std::cout<<summarizePenaltys(queue)<<std::endl;
    std::cout<<summarizePenaltys(queue2)<<std::endl;
}

int summarizePenaltys(CircularQueue<Penalty>& queue) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += queue.front()->amount;
        std::cout<<"sum: "<<sum<<" amount: "<<queue.front()->amount<<std::endl;
        queue.dequeue();
    }
    return sum;
}