#include <iostream>

class Penalty {
    public:
    std::string number;
    std::string brand;
    int amount;

    void print() {
        std::cout<<"number: "<<number<<" brand: "<<brand<<" amount: "<<amount<<std::endl;
    }

    Penalty(int _amount = 0, std::string _number = "h666el", std::string _brand = "bugatti"): amount(_amount), number(_number), brand(_brand) {
        std::cout<<"Standart constructor penalty"<<std::endl;
    }

    Penalty(const Penalty& _penalty): number(_penalty.number), brand(_penalty.brand), amount(_penalty.amount) {
        std::cout<<"Copy constructor penalty"<<std::endl;
    }

    ~Penalty() {
        std::cout<<"Penalty destructor"<<std::endl;
    }

    static Penalty createPenalty() {
        std::string _number;
        std::string _brand;
        int _amount;
        std::cout<<"number: "; std::cin>>_number;
        std::cout<<"brand: "; std::cin>>_brand;
        std::cout<<"amount: "; std::cin>>_amount;
        Penalty newPenalty(_amount, _number, _brand);
        return newPenalty;
    }
};