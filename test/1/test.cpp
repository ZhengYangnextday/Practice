#include <iostream>
using namespace std;
int main(){
    int a;
    a = 6740;//other data is allowed
    int b = a & 0XFF;
    int c = a & 0XFF00;
    c = c >> 8;
    b = b << 8;
    cout << b + c << endl;
    return 0;
}