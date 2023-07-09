#include <iostream>
#include <regex>
#include <algorithm>
#include <vector>
using namespace std;


struct student{
    string name;
    string birth;
    string num;
    string email;
};

vector<student> list;

void check(string &a)
{
    if(a[6] == '-' || a[6] == '.')
        a.insert(5,"0");
    if(a[4] == '-')
        a[4] = '.';
    if(a[7] == '-')
        a[7] = '.';
    if(a.length() == 9)
        a.insert(8, "0");
}

int year(string a)
{
    int y = 1000 * (a[0] - '0') + 100 * (a[1] - '0') + 10 * (a[2] - '0') + (a[3] - '0');
    return y;
}

int month(string a)
{
    int m = 0;
    if(a[7] == '-' || a[7] == '.')
        m = a[6] - '0' + 10 * (a[5] - '0');
    if(a[6] == '-' || a[6] == '.')
        m = a[5] -'0';
    return m;
}

int day(string a)
{
    int len = a.length();
    // cout << len << endl; //test
    int digit = 1;
    int d = 0;
    for(int i = len-1; a[i] != '-' && a[i] != '.'; i--)
    {
        d += digit * (a[i] - '0');
        digit *= 10;
    }
    return d;

}

bool comp(student &a, student &b)
{
    string b1 = a.birth;
    string b2 = b.birth;
    int y1 = year(b1);
    int y2 = year(b2);
    if(y1 < y2)
        return 1;
    if(y1 > y2)
        return 0;
    int m1 = month(b1);
    int m2 = month(b2);
    if(m1 < m2)
        return 1;
    if(m1 > m2)
        return 0;
    int d1 = day(b1);
    int d2 = day(b2);
    if(d1 < d2)
        return 1;
    return 0;
}

int n;

regex getname(R"xxx((?:I am |My name is )([a-zA-Z]*))xxx");
regex getbirth(R"xxxx(([0-9]{4}-[0-9]{1,2}-[0-9]{1,2}|[0-9]{4}\.[0-9]{1,2}\.[0-9]{1,2}))xxxx");
regex getnum("([0-9]{11})");
regex getemail(R"xxx(([0-9a-zA-Z\.]{1,}@.+\.com|[0-9a-zA-Z\.]{1,}@.+\.net|[0-9a-zA-Z\.]{1,}@.+\.cn).)xxx");
// smatch sm1;
// smatch sm2;
// smatch sm3;
// smatch sm4;


int main()
{
    cin >> n;
    string str = "\n";
    getline(cin, str);

    while(n--)
    {
        // cout << n << endl;
        string a;
        getline(cin, a);
        string b1, b2, b3, b4;
        smatch sm1;
        if(regex_search(a, sm1, getname))
            b1 = sm1[1];
        smatch sm2;
        if(regex_search(a, sm2, getbirth))
            b2 = sm2[1];
        check(b2);
        smatch sm3;
        if(regex_search(a, sm3, getnum))
            b3 = sm3[1];
        smatch sm4;
        if(regex_search(a, sm4, getemail))
            b4 = sm4[1];
        list.push_back({b1,b2,b3,b4});
    }

    // cout << list[0].birth << endl;
    // cout << list[1].birth << endl;

    sort(list.begin(), list.end(), comp);
    for(auto i : list)
    {
        cout << i.name << "-" << i.birth << "-" << i.num << "-" << i.email << endl;

    }


}