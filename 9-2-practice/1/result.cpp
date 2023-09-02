#include <iostream>
#include <cstring>
using namespace std;
// int run(int* time, int* value, int num, int total_time){
//     if(num <= 0){
//         return 0;
//     }
//     if(time[0] <= total_time){
//         return max(run(time + 1, value + 1, num - 1, total_time), value[0] + run(time + 1, value + 1, num - 1, total_time - time[0]));
//     }else{
//         return run(time + 1, value + 1, num - 1, total_time);
//     }
// }
//直接递归作法容易TLE，需要在执行过程中保存信息，采用二维数组
int run(int* time, int* value, int num, int total_time, int** matrix){
    if(num < 1 || total_time < 1){
        return 0;
    }
    if(matrix[num - 1][total_time - 1] != 0){
        return matrix[num - 1][total_time - 1];
    }else{
        if(total_time >= time[num - 1]){
            matrix[num - 1][total_time - 1] = max(run(time, value, num - 1, total_time, matrix), value[num - 1] + run(time, value, num - 1, total_time - time[num - 1], matrix));
            return matrix[num - 1][total_time - 1];
        }else{
            matrix[num - 1][total_time - 1] = run(time, value, num - 1, total_time, matrix);
            return matrix[num - 1][total_time - 1];
        }
    }
}
int main(){
    int t, m;
    cin >> t >> m;
    int* time = new int[m];
    int* value = new int[m];
    for(int i = 0; i < m; i++){
        cin >> time[i] >> value[i];
    }
    int** matrix = new int*[m];
    for(int i = 0; i < m; i++){
        matrix[i] = new int[t];
        memset(matrix[i], 0, t * sizeof(int));
    }
    cout << run(time, value, m, t, matrix);
}