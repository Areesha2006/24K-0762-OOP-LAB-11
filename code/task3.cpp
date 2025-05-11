#include<iostream>
#include<fstream>
#include<stdexcept>
using namespace std;
class FileExpcetion:public std::exception{
    public:
        virtual const char* what(){
            return "Expection found in file";
        }
};
class FileNotFoundExpcetion: public FileExpcetion{
    public:
        const char* what(){
            return "File not found";
        }
};
class PermissionDeniedExpcetion: public FileExpcetion{
    public:
        const char* what(){
            return "PermissionDeniedExpcetion - Access denied";
        }
};
void readFile(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        throw FileNotFoundExpcetion();
    }
    cout<<"Reading "<<filename<<".txt"<<endl;
    string line;
    while(1){
        getline(file,line);
        if(file.fail()){
            throw PermissionDeniedExpcetion();
        }
        cout<<line<<endl;
    }
}
int main(){
    string filename;
    cout<<"Enter the name pf the file: ";
    cin>>filename;
    try{
        readFile(filename);
    }
    catch(FileExpcetion &exception){
        cout<<"Reading "<<filename<<".txt: "<<exception.what()<<endl;
    }    
    catch(FileNotFoundExpcetion &notFound){
        cout<<notFound.what()<<endl;
    }
    catch(PermissionDeniedExpcetion &denied){
        cout<<"Reading "<<filename<<".txt: "<<denied.what()<<endl;
    }
    return 0;
}