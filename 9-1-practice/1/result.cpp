#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct line{
    int x;
    int y;
    int length;
    bool available;
}line;
bool compare(const line& line1, const line& line2){
    return line1.length < line2.length;
}
class Set{
    public:
        Set(int number){
            num = number;
            list = new int[num];
            for(int i = 0; i < num; i++){
                list[i] = -1;
            }
            cnt = 0;
        }
        bool judge(int a, int b){
            if(a < 0 || a >= num || b < 0 || b >= num){
                return false;
            }else{
                int set_a = search(a);
                int set_b = search(b);
                if(set_a == set_b){
                    return true;
                }else{
                    return false;
                }
            }
        }
        void merge(int a, int b){
            int set_a = search(a);
            int set_b = search(b);
            if(set_a < set_b){
                list[set_b] = set_a;
            }else{
                list[set_a] = set_b;
            }
            cnt--;
        }
        int search(int search_index){
            int now_num = search_index;
            if(list[now_num] == -1){
                list[now_num] = now_num;
                cnt += 1;
                return search_index;
            }
            while(list[now_num] != now_num){
                list[now_num] = list[list[now_num]];
                now_num = list[now_num];
            }
            return now_num;
        }
        int get_cnt(){
            return cnt;
        }
    private:
        int* list;
        int num;
        int cnt;
};
int main(){
    int n, m;
    cin >> n >> m;
    //int** matrix = new int*[n];
    line* list = new line[m];
    bool* visited = new bool[n];//用于确定孤立点
    // for(int i = 0; i < n; i++){
    //     matrix[i] = new int[n];
    //     memset(matrix[i], 0, n * sizeof(int));
    // }
    // int x,y,z;
    // for(int i = 0; i < m; i++){
    //     cin >> x >> y >> z;
    //     visited[x - 1] = true;
    //     visited[y - 1] = true;
    //     matrix[x - 1][y - 1] = z;
    // }
    // for(int i = 0; i < n; i++){
    //     if(visited[i] == false){
    //         cout << "orz";
    //         return -1;
    //     }else{
    //         visited[i] = false;
    //     }
    // }
    // int now_index = 0;
    // int new_index = 0;
    // long long result = 0;
    // int cnt = 1;
    // visited[0] = true;
    // while(cnt != n){
    //     int min = 0xffffff;
    //     for(int i = 0; i < n; i++){
    //         if(visited[i] == false && matrix[now_index][i] != 0){
    //             if(matrix[now_index][i] < min){
    //                 min = matrix[now_index][i];
    //                 new_index = i
    //             }
    //         }
    //     }
    // }
    //这里想用prim算法时间复杂度较高，采用kruscal算法
    int x, y, z;
    for(int i = 0; i < m; i++){
        cin >> x >> y>> z;
        list[i].x = x - 1;
        list[i].y = y - 1;
        list[i].length = z;
        list[i].available = true;
        visited[x - 1] = true;
        visited[y - 1] = true; 
    }
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            cout << "orz";
            return -1;
        }else{
            visited[i] = false;
        }
    }//首先排除孤立点的存在
    sort(list, list + m, compare);
    long long result = 0;
    int cnt = 0;
    Set pset(n);
    while (cnt != n)
    {
        for(int i = 0; i < m; i++){
            if(list[i].available == true){
                x = list[i].x;
                y = list[i].y;
                z = list[i].length;
                if(pset.judge(x, y)){
                    list[i].available = false;
                    continue;
                }else{
                    if(visited[x] && visited[y]){
                        cnt += 0;
                    }else if(!visited[x] && !visited[y]){
                        cnt += 2;
                    }else{
                        cnt += 1;
                    }
                    pset.merge(x, y);
                    result += z;
                    visited[x] = true;
                    visited[y] = true;
                    list[i].available = false;
                    break;
                }
            }
        }
    }
    
    // while(cnt != n){
    //     for(int i = 0; i < m; i++){
    //         if(list[i].available == true){
    //             x = list[i].x;
    //             y = list[i].y;
    //             z = list[i].length;
    //             if(visited[x] && visited[y]){
    //                 list[i].available = false;
    //                 continue;
    //             }else if(!visited[x] && !visited[y]){
    //                 cnt += 2;
    //                 result += z;
    //                 visited[x] = true;
    //                 visited[y] = true;
    //                 list[i].available = false;
    //                 break;
    //             }else{
    //                 cnt += 1;
    //                 result += z;
    //                 visited[x] = true;
    //                 visited[y] = true;
    //                 list[i].available = false;
    //                 break;
    //             }
    //         }
    //     }
    // }
    if(pset.get_cnt() != 1){
        cout << "orz";
        return 0;
    }
    cout << result;
    return 0;
}
/*
使用kruscal算法，还需使用并查集的思想来检测是否处于环中
*/