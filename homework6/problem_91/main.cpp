#include <iostream>
#include <regex>

using namespace std;

bool r1, r2, r3;

int main()
{
    string a;
    getline(cin, a);
    regex re1(R"xxx(\"username\" {0,}: {0,}\"([a-zA-Z][a-zA-Z0-9_]{3,14})\")xxx");
    regex re21("\"password\" {0,}: {0,}\"([a-zA-Z]{1,}[0-9]{1,}[a-zA-Z0-9]{0,})\"");
    regex re22("\"password\" {0,}: {0,}\"([0-9]{1,}[a-zA-Z]{1,}[a-zA-Z0-9]{0,})\"");
    regex re3(R"xxx(\"email\" {0,}: {0,}\"([a-zA-Z0-9_]+@[a-zA-Z0-9\._]+)\")xxx");
    
    string username;
    string password;
    string email;
    smatch sm1;
    smatch sm2;
    smatch sm3;
    if(regex_search(a, sm1, re1))
    {
        username = sm1[1];
        r1 = 1;
        // cout << username << endl;
        for(int i = 3; i < username.length(); i++)
            username[i] = '*';
    }
    if(regex_search(a, sm2, re21) || regex_search(a, sm2, re22))
    {
        password = sm2[1];
        int len = password.length();
        if(len >= 8 && len <= 20)
            r2 = 1;
    }
    if(regex_search(a, sm3, re3))
    {
        r3 = 1;
        email = sm3[1];
        for(int i = 0; i < email.length(); i++)
            if(email[i] !='@' && email[i] != '.')
                email[i] = '*';
    }
    if(!(r1 && r2 && r3))
    {
        cout << "Illegal " ;
        if(!r1)
            cout << "username";
        if(!r2)
        {
            if(!r1)
                cout << "," ;
            cout << "password";
        }
        if(!r3)
        {
            if((!r1) || (!r2))
                cout << ",";
            cout << "email";
        }
    }
    if(r1 && r2 && r3)
    {
        cout << "Successfully registered." << endl;
        cout << "username: " << username << endl;
        cout << "password: " ;
        for(int i = 0; i < password.length(); i++)
            cout << '*';
        cout << endl;
        cout << "email: "  << email;



    }

}