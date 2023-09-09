#include <iostream>
#include <cstring>
using namespace std;
bool run_turn(bool* list){
    int cnt = 0;
    bool on = false;
    int result = 0;
    for(int i = 0; i < 20; i++){
        if(list[i] == 0){
            if(on == true){
                on = false;
            }
            cnt++;
        }
    }
}
//阶梯Nim
int main(){
    int t;
    cin >> t;
    int n;
    bool* list = new bool[20];
    int index;
    int result = 0;
    for(int i = 0; i < t; i++){
        cin >> n;
        result = false;
        for(int j = 0; j < n; j++){
            memset(list, 0, sizeof(bool) * 20);
            int num;
            cin >> num;
            for(int k = 0; k < num; k++){
                cin >> index;
                index--;
                list[index] = true;
            }
            result ^= run_turn(list);
        }
        if(result){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}