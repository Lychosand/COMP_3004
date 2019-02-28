#include "ClientArray.h"
using namespace std;

void ClientArray::addClient(Client *c)
{
    array[num_clients] = c;
    num_clients += 1;
}

void ClientArray::deleteList()
{
    for(int i=0; i<num_clients; i++)
    {
        delete array[i];
    }

    num_clients = 0;
}

ClientArray::~ClientArray()
{
    for(int i=0; i<num_clients; i++)
    {
        delete array[i];
    }
}

int ClientArray::getNumClients()
{
    return num_clients;
}

string ClientArray::getClientName(int a)
{
    return array[a]->getName();
}

string ClientArray::getClientUsername(int a)
{
    return array[a]->getUsername();
}

string ClientArray::getClientPassword(int a)
{
    return array[a]->getPassword();
}

int ClientArray::getClientPhoneNumber(int a)
{
    return array[a]->getPhoneNumber();
}
string ClientArray::getClientAddress(int a)
{
    return array[a]->getAddress();
}

string ClientArray::getClientPostalCode(int a)
{
    return array[a]->getPostalCode();
}

string ClientArray::getClientProvince(int a)
{
    return array[a]->getProvince();
}

