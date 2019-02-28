#include "Client.h"
using namespace std;

Client::Client(string c_name, string c_username, string c_password, int c_phone_number, string c_address, string c_postal_code, string c_province)
{
    name = c_name;
    username = c_username;
    password = c_password;
    phone_number = c_phone_number;
    address = c_address;
    postal_code = c_postal_code;
    province = c_province;
}

string Client::getName()
{
    return name;
}

string Client::getUsername()
{
    return username;
}

string Client::getPassword()
{
    return password;
}

int Client::getPhoneNumber()
{
    return phone_number;
}

string Client::getAddress()
{
    return address;
}

string Client::getPostalCode()
{
    return postal_code;
}

string Client::getProvince()
{
    return province;
}
