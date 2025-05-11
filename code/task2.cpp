#include<iostream>
#include<stdexcept>
using namespace std;
class StackOverFlowException: public std::exception{
    public:
        const char* what(){
            return "Pushing to a full stack: StackOverflowException - Stack is full!";
        }
};
class StackUnderFlowException: public std::exception{
    public:
        const char* what(){
            return "Popping from an empty stack: StackUnderflowException - Stack is empty! ";
        }
};
template <typename T>
class Stack{
    const int capacity;
    T *data;
    int pos;
    public:
        Stack(int cap):capacity(cap),pos(-1),data(new T[capacity]){}
        void push(T value){
            try{
                if(pos>=capacity-1){
                    throw StackOverFlowException();
                }
                data[++pos]=value;
                cout<<"Value pushed successfully"<<endl;
            }
            catch(StackOverFlowException &overflow){
                cout<<overflow.what()<<endl;
            }
        }
        void pop(){
            try{
                if(pos<0){
                    throw StackUnderFlowException();                    
                }
                data[pos--]=T();
                cout<<"Value popped successfully"<<endl;
            }
            catch(StackUnderFlowException &underflow){
                cout<<underflow.what()<<endl;
            }
        }
        ~Stack(){
            delete[] data;
        }
};
int main(){
    int capacity,value,choice;
    cout<<"Enter the capacity: ";
    cin>>capacity;
    Stack<int> stack(capacity);
    do{
        cout<<"Enter the appropriate key according to the function you want to perform\n1.Push value in the stack\n2.Pop value from the stack\nAn other key to exit\nEnter: ";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter the value which you want to push: ";
                cin>>value;
                stack.push(value);
                break;    
            case 2:
                stack.pop();
                break;
            default:
                cout<<"Exited successfully";
        }
        cout<<endl;
    }while(choice==1||choice==2);
    return 0;
}