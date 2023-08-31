#include <iostream>
using namespace std;
inline bool check(int a, int b, int g, int k, int x, int y){
    if(x >= a && x <= a + g && y >= b && y <= b + k){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n = 0;
    cin >> n;
    int* pos_x = new int[n]; 
    int* pos_y = new int[n]; 
    int* pos_a = new int[n]; 
    int* pos_b = new int[n];
    for(int i = 0; i < n; i++){
        cin >> pos_x[i] >> pos_y[i] >> pos_a[i] >> pos_b[i];
    } 
    int x = 0, y = 0;
    cin >> x >> y;
    int index = -1;
    for(int i = 0; i < n; i++){
        if(check(pos_x[i], pos_y[i], pos_a[i], pos_b[i], x, y)){
            index = i + 1;
        }
    }
    cout << index;
}