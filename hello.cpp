#include <iostream>
#include <string>
using namespace std;

int main() {
    string names[] = {"Yathish", "Maxim", "Lokesh"};
    int ages[] = {24, 31, 25};

    for (int i = 0; i < sizeof(names); ++i) {
        cout << "Hello, my name is " << names[i] << " and I am " << ages[i] << " years old." << endl;
    }

    return 0;
}
