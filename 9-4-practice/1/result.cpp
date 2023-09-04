#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
ld fun(double a, double b, double c, double d, double x){
    return d + x * (c + x * (b + x * a));
}
ld funs(double a, double b, double c, double d, double x){
    return d + x * (c + x * (b + x * a));
}
double search(double a, double b, double c, double d, double x){
    double length = 1;
    double now = x;
    ld result_right = funs(a, b, c, d, now);
    ld result_middle = 0;
    while(length >= 0.001){
        length = length / 2;
        result_middle = funs(a, b, c, d, now - length);
        if(result_middle == 0){
            return now - length;
        }
        if((result_middle >= 0 && result_right <= 0) || 
        (result_middle <= 0 && result_right >= 0)){
            continue;
        }//在右区间
        else{
            result_right = result_middle;
            now = now - length;
        }
    }
    return now;
}
int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    ld* result = new ld[201];
    vector<double> ans;
    result[0] = fun(a, b, c, d, -100);
    if(result[0] == 0){
        ans.push_back(0);
    }
    for(int i = -99; i <= 100; i++){
        result[i + 100] = fun(a, b, c, d, i);
        if((result[i + 100] > 0 && result[i + 99] < 0) || 
        (result[i + 100] < 0 && result[i + 99] > 0)||
        (result[i + 100] == 0)){
            ans.push_back(i);
        }
        if(ans.size() == 3){
            break;
        }
    }
    //这里保证了输出区间一定是在(ans[i] - 1, ans[i]]内
    for(int i = 0; i < ans.size(); i++){
        if(funs(a, b, c, d, ans[i]) == 0){
            printf("%.2lf ", ans[i]);
        }else{
            printf("%.2lf ", search(a, b, c, d, ans[i]));
        }
    }
    return 0;
}