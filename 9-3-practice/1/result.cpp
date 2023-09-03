#include <iostream>
#include <queue>
#define ll long long
typedef struct position{
    int x;
    int y;
}position;
using namespace std;
int main(){
    int n, m;
    int x, y;
    cin >> n >> m;
    cin >> x >> y;
    x--;
    y--;
    //读取数据，x和y需自减，方便操作
    ll** board = new ll*[n];
    for(int i = 0; i < n; i++){
        board[i] = new ll[m];
        for(int j = 0; j < m; j++){
            board[i][j] = -1;
        }
    }
    //创建棋盘，将所有值赋值为-1，表示未初始化
    queue<position> search_list;
    position* now = new position[1];
    now->x = x;
    now->y = y;
    int nx, ny;
    board[x][y] = 0;
    search_list.push(*now);
    int hx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int hy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    position* new_position;
    while(!search_list.empty()){
        now = &search_list.front();
        nx = now->x;
        ny = now->y;
        for(int i = 0; i < 8; i++){
            if(nx + hx[i] >= 0 && nx + hx[i] < n && ny + hy[i] >= 0 && ny + hy[i] < m){
                if(board[nx + hx[i]][ny + hy[i]] == -1){
                    board[nx + hx[i]][ny + hy[i]] = board[nx][ny] + 1;
                    new_position = new position[1];
                    new_position->x = nx + hx[i];
                    new_position->y = ny + hy[i];
                    search_list.push(*new_position);
                    delete new_position;
                }
            }
        }
        search_list.pop();
        //delete now; 这样子操作会让queue分配的空间释放掉
        //queue实现方法应该是有自己的内存管理
    }
    //bfs，基于队列思想
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%-5d",board[i][j]);
        }
        //这里-5代表左对齐，输出数值长度为5字符，去掉-为右对齐
        cout<<endl;
    }
}