#include <iostream>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace std;

int main()
{
    json j1 = { {"name", "yang"}, {"age", 19} };
    json j2 = R"(
        {
            "name": "yang",
            "age": 19
        }
    )"_json;  //raw string 双引号后紧跟着_json是用于识别读取
    cout << j1 << endl; // {"age":19,"name":"yang"}
    cout << j2.dump(4) << endl;
    /*
{
    "age": 19,
    "name": "yang"
}
    */
    
    j1["name"] = "yangnan";
    j1.at("age") = 20;
    cout << j1.at("name") << endl; //"yangnan"
    cout << j1["age"] << endl; //20
    return 0;
}

