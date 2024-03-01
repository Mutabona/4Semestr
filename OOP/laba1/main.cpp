#include "CircularQueue.cpp"
#include "Penalty.cpp"
#include <string>

int summarizePenaltys(CircularQueue<Penalty>& queue);
void checkQueue();
void printMenu();
int getChoice();
void callFunctions(int choice);
void changeField();

const int size = 9;

CircularQueue<Penalty> queueMain(size);

int main() {
    int choice = 0;
    do {
        printMenu();
        choice = getChoice();
        callFunctions(choice);
    } while(choice);
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

void printMenu() {
    std::cout<<"\n";
    std::cout<<"0 - Exit"<<std::endl;
    std::cout<<"1 - Create obj"<<std::endl;
    std::cout<<"2 - Copy obj"<<std::endl;
    std::cout<<"3 - Print fields"<<std::endl;
    std::cout<<"4 - Change field"<<std::endl;
    std::cout<<"5 - Check queue"<<std::endl;
    std::cout<<"\n";
}

int getChoice() {
    std::string input = "0";
    int choice;
    try {
        std::cin>>input;
    }
    catch (...) {
        choice = 0;
    }
    try {
        choice = stoi(input);
    }
    catch (...) {
        choice = 0;
    }
    return choice;
}

void callFunctions(int choice) {
    switch(choice) {
        case 1:
            queueMain.enqueue(Penalty::createPenalty());
            break;
        case 2:
            queueMain.enqueue(*(queueMain.front()));
            break;
        case 3:
            std::cout<<"Queue main"<<std::endl;
            queueMain.print();
            break;
        case 4:
            changeField();
            break;
        case 5:
            checkQueue();
            break;
    }
}

void changeField() {
    std::cout<<"1 - Change first element amount 2 - change last element amount"<<std::endl;
    int choice = getChoice();
    switch (choice) {
        case 1:
            std::cin>>queueMain.front()->amount;
            break;
        case 2:
            std::cin>>queueMain.back()->amount;
    }
}

void checkQueue() {
    CircularQueue<Penalty> queue1(size);
    for (int i = 0; i < size; i++) {
        queue1.enqueue(i);
    }

    CircularQueue<Penalty> queue2 = queue1;

    queue1.print();
    queue2.print();

    std::cout<<summarizePenaltys(queue1)<<std::endl;
    std::cout<<summarizePenaltys(queue2)<<std::endl;
}