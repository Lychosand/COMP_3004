#ifndef CLIENT_H
#define CLIENT_H
#include<string>
using std::string;

class Client
{
public:
    Client(string,string,string,string,string,string,string);
    string getName();
    string getUsername();
    string getPassword();
    string getPhoneNumber();
    string getAddress();
    string getPostalCode();
    string getProvince();

private:
    string name, address, postal_code, province, username, password,phone_number;
};

#endif // CLIENT_H
