#include <iostream>
#include <cstring>
using namespace std;
double f[1251][1251];
double run(int n){
    double result = 1.0;
    for(int i = 1; i <= n-1; i++){
        result = result * (n - 1 + i) / (i * 4);
    }
    return result;
}
int main(){
    int n,i,j;
    cin >> n;
    n >>= 1;
    printf("%.4lf", 1 - run(n));
    return 0;
}