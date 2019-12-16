
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

int main() {
    Json::Reader reader;
    Json::Value obj;
    reader.parse(cin, obj); // reader can also read strings

    cout << obj;
    return 0;
}
