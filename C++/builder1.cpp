#include<bits/stdc++.h>
using namespace std;

class Builder{
    public:
        string userName;
        string userId;
        string emailID;
        Builder* setUserName(string userName){
            this->userName = userName;
            return this;
        }
        Builder* setUserID(string userId){
            this->userId = userId;
            return this;
        }
        Builder* setEmailID(string emailID){
            this->emailID = emailID;
            return this;
        }
};

class User{
    string userName;
    string userId;
    string emailID;

    public : User(Builder obj){
        this->userName = obj.userName;
        this->userId = obj.userId;
        this->emailID = obj.emailID;
    }
    public : void print(){
        if(this->userName != "")cout<<this->userName<<" ";
        if(this->userId != "")cout<<this->userId<<" ";
        if(this->emailID != "")cout<<this->emailID<<" ";
        cout<<endl;
    }
};

int main()
{
    Builder builder = Builder();
    builder.setEmailID("adfa@gama.com")->setUserID("2323")->setEmailID("aka@gmil.com");
    // builder.setUserID("122");
    // builder.setUserName("aman");

    User user = User(builder);
    user.print();
}
