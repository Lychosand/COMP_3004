#ifndef CLIENT_H
#define CLIENT_H
#include<string>
using std::string;

class Client
{
public:
    Client(string,string,string,int,string,string,string);
    string getName();
    string getUsername();
    string getPassword();
    int getPhoneNumber();
    string getAddress();
    string getPostalCode();
    string getProvince();

private:
    string name, address, postal_code, province, username, password;
    int phone_number;
};

#endif // CLIENT_H
