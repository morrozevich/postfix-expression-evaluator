//
//  main.cpp
//  ExamCpp
//
//  Created by Anastasia Marazevich on 05/06/2023.
//

#include <iostream>

class Vector{
    int capacity;
    int elements;
    int *mem;
public:
    Vector():
    capacity(10),
    elements(0),
    mem(new int[capacity])
    {}
    
    void push_back(int x){
        if (elements >= capacity){
            int *tmp = new int[capacity*2];
            for (int i=0; i<capacity; i++){
                tmp[i] = mem[i];
            }
            delete [] mem;
            mem = tmp;
            capacity+=5;
        }
        mem[elements++] = x;
    }
    
    bool empty(){
        return elements == 0;
    }
    
    int back(){
        if (empty()){
            throw std::runtime_error("back is called on an empty vector.\n");
        }
        return mem[elements-1];
    }
    
    void pop_back(){
        if (empty()){
            throw std::runtime_error("pop_back is called on an empty vector.\n");
        }
        elements--;
    }
    
    int &at(int x){
        if (elements < 0 || elements >= capacity){
            throw std::out_of_range("invalid index.\n");
        }
        return mem[x];
    }
    
    int size(){
        return elements;
    }
    
    int &operator[](int x){
        return mem[x];
    }
    
    Vector(const Vector &original):
    elements(original.elements),
    capacity(original.capacity),
    mem(new int[capacity])
    {
        for (int i=0; i<elements; i++){
            mem[i]=original.mem[i];
        }
    }
    
    Vector &operator=(Vector cpy){
        capacity = cpy.capacity;
        elements = cpy.elements;
        std::swap(mem, cpy.mem);
        return *this;
    }
    
    ~Vector(){
        delete [] mem;
    }
};

int evaluate(std::string tmp){
    Vector V;
    char Operator = ' ';
    int result;
    int a,b;
    
    for (int i=0; i<tmp.size(); i++){
            if (tmp[i] == 'p'){
                tmp[i] = Operator;
            }
        
        
            switch (tmp[i]) {
                case '1':
                    V.push_back(1);
                    break;
                case '2':
                    V.push_back(2);
                    break;
                case '3':
                    V.push_back(3);
                    break;
                case '4':
                    V.push_back(4);
                    break;
                case '5':
                    V.push_back(5);
                    break;
                case '6':
                    V.push_back(6);
                    break;
                case '7':
                    V.push_back(7);
                    break;
                case '8':
                    V.push_back(8);
                    break;
                case '9':
                    V.push_back(9);
                    break;
                case '0':
                    V.push_back(0);
                    break;
                    
                    
                case '+':
                    a = V.back();
                    V.pop_back();
                    b = V.back();
                    V.pop_back();
                    result = b + a;
                    V.push_back(result);
                    Operator = '+';
                    break;
                case '-':
                    a = V.back();
                    V.pop_back();
                    b = V.back();
                    V.pop_back();
                    result = b - a;
                    V.push_back(result);
                    Operator = '-';
                    break;
                case '*':
                    a = V.back();
                    V.pop_back();
                    b = V.back();
                    V.pop_back();
                    result = b * a;
                    V.push_back(result);
                    Operator = '*';
                    break;
                case '/':
                    a = V.back();
                    V.pop_back();
                    b = V.back();
                    V.pop_back();
                    result = b / a;
                    V.push_back(result);
                    Operator = '/';
                    break;
                    
                    
                default:
                    break;
            }
    }
        return V.back();
}

int main(int argc, const char * argv[]) {
    std::cout << evaluate("5 5 +") << std::endl;
    std::cout << evaluate("8 2 /") << std::endl;
    std::cout << evaluate("5 4 *") << std::endl;
    std::cout << evaluate("5 2 3 + *") << std::endl;
    
    std::cout << evaluate("5 2 + 3 *") << std::endl;
    std::cout << evaluate("1 2 3 4 + + +") << std::endl;
    std::cout << evaluate("1 2 + 3 + 4 +") << std::endl;
    std::cout << evaluate("1 2 + 3 p") << std::endl;
    std::cout << evaluate("5 4 3 2 1 + p * p") << std::endl;
    
    
    
    return 0;
}
