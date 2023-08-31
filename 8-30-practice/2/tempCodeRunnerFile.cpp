#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string formula(int num, int upnum, bool first = false){
    if(upnum != 0){
        if(num == 0){
            return "";
        }else if(num == 1){
            string result = "x^" + to_string(upnum);
            if(first == false){
                return "+" + result;
            }else{
                return result;
            }
        }else if(num == -1)
        {
            string result = "x^" + to_string(upnum);
            return "-" + result;
        }else{
            if(num > 0){
                string result = "x^" + to_string(upnum);
                if(first == false){
                    return "+" + to_string(num) + result;
                }else{
                    return to_string(num) + result;
                }
            }else{
                string result = "x^" + to_string(upnum);
                return to_string(num) + result;
            }
        }
    }else{
        if(num == 0){
            return "";
        }else{
            if(num > 0){
                if(first == false){
                    return "+" + to_string(num);
                }else{
                    return to_string(num);
                }
            }else{
                return to_string(num);
            }
        }
    }
}
int main(){
    int n = 0;
    string result = "";
    cin >> n;
    int num = 0;
    for(int i = n; i >= 0; i--){
        cin >> num;
        if(i == n){
            result += formula(num, i, true);
        }else{
            result += formula(num, i, false);
        }
    }
    cout << result;
}