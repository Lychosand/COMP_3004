#ifndef CLIENT_H
#define CLIENT_H
#include<string>
using std::string;

class Client
{
public:
    Client(string,string,string,string,string,string,string,int,int[]);
    string getName();
    string getUsername();
    string getPassword();
    string getPhoneNumber();
    string getAddress();
    string getPostalCode();
    string getProvince();
    int * getPreferences();
    int getDatabaseId();

private:
    string name, address, postal_code, province, username, password,phone_number;
    int client_id;
    int preferences [14];
};

#endif // CLIENT_H
