#include <iostream>

class Penalty {
    public:
    std::string number;
    std::string brand;
    int amount;

    void print() {
        std::cout<<"number: "<<number<<" brand: "<<brand<<" amount: "<<amount<<std::endl;
    }

    Penalty (int _amount = 0, std::string _number = "h666el", std::string _brand = "bugatti"): amount(_amount), number(_number), brand(_brand) {}
    Penalty (const Penalty& _penalty): number(_penalty.number), brand(_penalty.brand), amount(_penalty.amount) {}
};