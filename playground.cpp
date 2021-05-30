#include <iostream>
using namespace std;
int main() {
    int a = INT32_MIN;
    cout << (-a & a) << endl;
    cout << a << endl;
    cout << INT32_MAX << endl;
    cout << (3 ^ 4) << endl;
    return 0;
}