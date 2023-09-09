#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int result;
        int now;
        cin >> now;
        result = now;
        for(int j = 0; j < n - 1; j++){
            cin >> now;
            result ^= now;
        }
        if(result == 0){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
    return 0;
}