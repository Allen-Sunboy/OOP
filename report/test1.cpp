#include <iostream>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace std;
int main()
{
    json j = {{"name","yang"}};
    j.push_back({"sex","male"});
    cout << j << endl; //{"name":"yang","sex":"male"}
    j += {"age", 20};
    cout << j << endl; //{"age":20,"name":"yang","sex":"male"}
    return 0;
}


