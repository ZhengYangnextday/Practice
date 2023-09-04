#include <iostream>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;
int dp(vector<int>* tree, int* beauty, int* value, bool* visited, int father, int index){
    if(visited[index] == true){
        return value[index];
        //记忆机制，加快搜索速度
    }else{
        visited[index] = true;
        int now_value = beauty[index];
        for(int i = 0; i < tree[index].size(); i++){
            if(tree[index][i] != father){
                now_value += max(0, dp(tree, beauty, value, visited, index, tree[index][i]));
            }//跳过父节点
        }
        value[index] = now_value;
        //存储计算结果，避免反复调用
        return now_value;
    }
}
int main(){
    int n;
    cin >> n;
    int* beauty = new int[n];
    int max = -1;
    int max_index = 0;
    for(int i = 0; i < n; i++){
        cin >> beauty[i];
        if(beauty[i] > max){
            max = beauty[i];
            max_index = i;
        }
    }
    //存储美丽值
    int* value = new int[n];
    //建立每个节点对应的最大值
    bool* visited = new bool[n];
    memset(visited, 0, n * sizeof(bool));
    //判断节点是否访问过
    vector<int>* tree = new vector<int>[n];
    //利用逆邻接表，存储树
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //无向图
    dp(tree, beauty, value, visited, -1, max_index);
    max = value[0];
    for(int i = 1; i < n; i++){
        if(value[i] > max){
            max = value[i]; 
        }
    }
    cout << max;
    return 0;
}