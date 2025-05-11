#include<iostream>
using namespace std;
class InsufficientFundsException{
    public:
        string execption(){
            return "InsufficientFundsException - Deficit: ";
        }
};
template <typename T>
class BankAccount{
    T balance;
    public:
        BankAccount(T balance):balance(balance){}
        void withdraw(T amount){
            try{    
                if(amount>balance){
                    throw InsufficientFundsException();
                }
                balance-=amount;
                cout<<"$"<<amount<<" withdrawed successfully"<<endl;
            }
            catch(InsufficientFundsException funds){
                cout<<"Withdraw $"<<amount<<": "<<funds.execption()<<"$"<<amount-balance<<endl;
            }
        }
};
int main(){
    double balance,withdraw;
    char c;
    cout<<"Enter current balance: ";
    cin>>balance;
    BankAccount<double> account(balance);
    while(1){
        cout<<"Enter the amount which you want to withdraw: ";
        cin>>withdraw;
        account.withdraw(withdraw);
        cout<<"Do you want to withdraw again? If yes enter 'y' or 'Y' or else enter any character: ";
        cin>>c;
        if(c!='Y'&&c!='y'){
            break;
        }
    }
    return 0;
}