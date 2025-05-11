#include<iostream>
#include<stdexcept>
using namespace std;
class InvalidValueExpcetion: public std::exception{
    const char* what() const noexcept override{
        return "Error: InvalidValueExpcetion - Age cannot be negative or exceed 120";
    }
    public:
        void validateAge(int age){
            try{
                if(age<0||age>120){
                    throw *this;
                }
                cout<<"The age "<<age<<" is valid"<<endl;
            }
            catch(InvalidValueExpcetion &invalid){
                cout<<invalid.what()<<endl;
            }
        }
};
int main(){
    int age;
    InvalidValueExpcetion value1,value2,value3;
    cout<<"Enter the age for value 1: ";
    cin>>age;
    value1.validateAge(age);
    cout<<"Enter the age for value 2: ";
    cin>>age;
    value2.validateAge(age);
    cout<<"Enter the age for value 3: ";
    cin>>age;
    value3.validateAge(age);
    return 0;
}