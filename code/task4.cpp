#include <iostream>
#include <typeinfo>
#include <cmath>
using namespace std;
class NegativeNumberException {
public:
    void exception() {
        cout << "NegativeNumberException - Input must be non-negative!" << endl;
    }
};
class InvalidTypeException {
public:
    void exception() {
        cout << "InvalidTypeException - Non-numeric type detected!" << endl;
    }
};
template <typename T>
void compute_sqrt(T num) {
    try{
        cout<<"sqrt("<<num<<"): ";
        if(typeid(num)!=typeid(int)&&typeid(num)!=typeid(float)&&typeid(num)!=typeid(double)){
            throw InvalidTypeException()
            return;
        }
        cout<<sqrt(static_cast<double>(num)) << endl;
    }
    catch(InvalidTypeException invalid){
        invalid.exception();
    }
    try{
        cout<<"sqrt("<<num<<"): ";
        if(num<0){
            throw NegativeNumberException()
            return;
        }
        cout<<sqrt(static_cast<double>(num)) << endl;
    }
    catch(NegativeNumberException negative){
        negative.exception();
    }
}   
int main() {
    cout<<"Finding square root of 5"<<endl;
    compute_sqrt(5);    
    cout<<endl<<"Finding square root of 6.25"<<endl;
    compute_sqrt(6.25);      
    cout<<endl<<"Finding square root of 0"<<endl;
    compute_sqrt(0);         
    cout<<endl<<"Finding square root of -6"<<endl;
    compute_sqrt(-6);        
    cout<<endl<<"Finding square root of -9.4"<<endl;
    compute_sqrt(-9.4); 
    cout<<endl<<"Finding square root of 'a'"<<endl;
    compute_sqrt('a');       
    cout<<endl<<"Finding square root of 'Hello'"<<endl;
    compute_sqrt("hello");   
    return 0;
}