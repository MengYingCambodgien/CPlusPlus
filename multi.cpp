#include<iostream>

using namespace std;

class People{
    protected:
        string id, name, gender, address;
    public:
        People(string id, string name, string gender, string address){
            this->id = id;
            this->name = name;
            this->gender = gender;
            this->address = address;
        }  
        void setData(string id, string name, string gender, string address){
            this->id = id;
            this->name = name;
            this->gender = gender;
            this->address = address;
        }
        void setId(string id){
            this->id = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setGender(string gender){
            this->gender = gender;
        }
        void setAddress(string address){
            this->address = address;
        }
        string getId(){
            return id;
        }
        string getName(){
            return name;
        }
        string getGender(){
            return gender;
        }
        string getAddress(){
            return address;
        }
};

class Acleda{
    protected:
        string accid;
        float balance;
    public:
        Acleda(string accid, float balance){
            this->accid = accid;
            this->balance = balance;
        }
        void setData(string accid, float balance){
            this->accid = accid;
            this->balance = balance;
        }
        void setAccId(string accid){
            this->accid = accid;
        }
        void setBalance(float balance){
            this->balance = balance;
        }
        string getAccId(){
            return accid;
        }
        float getBalance(){
            return balance;
        }
};
class ATM: public People, public Acleda{
    private:
        string password;
    public:
        void setData(string id, string name, string gender, string address, string accid, float balance, string password){
            People::setData(id, name, gender, address);
            Acleda::setData(accid, balance);
            this->password = password;
        }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}