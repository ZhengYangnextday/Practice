#include <iostream>
#include <cstring>
using namespace std;
/*
本题本质上是一道最小生成树的题，利用prim算法解决
*/
int main(){
    int a, b;
    cin >> a >> b;
    int** matrix = new int*[b + 1];
    bool* visited = new bool[b + 1];
    memset(visited, 0, (b + 1) * sizeof(bool));
    for(int i = 0; i < b + 1; i++){
        matrix[i]  = new int[b + 1];
        memset(matrix[i], 0, sizeof(int) * (b + 1));
    }
    for(int i = 0; i < b + 1; i++){
        for (int j = 0; j < b + 1; j++){
            if(i == b || j == b){
                matrix[i][j] = a;
            }else{
                cin >> matrix[i][j];
                if(matrix[i][j] == 0){
                    matrix[i][j] = a;
                }
            }
        }
    }
    matrix[b][b] = 0;
    long long result = 0;
    int cnt = 0;
    int now = 0;
    visited[now] = true;
    cnt++;
    //利用prim算法，时间复杂度为O(n^3)
    while(cnt != b + 1){
        int search = 0;
        int from = -1;
        int to = -1;
        int min = 0XFFFFFF;
        for(int i = 0; i < b + 1; i ++){
            if(!visited[i]){
                continue;
            }
            for(int j = 0; j < b + 1; j ++){
                if(visited[j] || j == i){
                    continue;
                }
                if(matrix[i][j] < min){
                    from = i;
                    to = j;
                    min = matrix[i][j];
                }
            }
            search ++;
            if(search == cnt){
                result += matrix[from][to];
                visited[to] = true;
                cnt++;
                break;
            }
        }
    }
    cout << result;
    return 0;
}