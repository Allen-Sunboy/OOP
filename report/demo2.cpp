#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using nlohmann::json;

int main()
{
    ifstream fin;
    fin.open("tasks.json");
    json j;
    fin >> j;
    cout << j["tasks"][0]["type"] << endl; //"cppbuild"
    return 0;
}