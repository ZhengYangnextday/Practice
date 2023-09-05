#include <iostream>
#include <cstring>
using namespace std;
inline int log2_int(register int x) {
    register int ans = 0;
    while ((x >>= 1)) ++ans;
    return ans;
}
#define ll long long
typedef struct node {
    ll left, right, value, lazy;
    bool visited;
    //方便建树
}node;
ll build(node* tree, int total_num, int index, int num) {
    if (index >= total_num) {
        return 0;
    }
    else if (tree[index].visited) {
        return tree[index].value;
    }
    else {
        tree[index].value = build(tree, total_num, index * 2 + 1, num) + build(tree, total_num, index * 2 + 2, num);
        if (index * 2 + 1 < total_num) {
            tree[index].left = tree[index * 2 + 1].left;
        }
        else {
            tree[index].left = index * 2 - num + 2;
        }
        if (index * 2 + 2 < total_num) {
            tree[index].right = tree[index * 2 + 2].right;
        }
        else {
            tree[index].right = index * 2 - num + 3;
        }
        tree[index].lazy = 0;
        tree[index].visited = true;
        return tree[index].value;
    }
}
bool in(int al, int ar, int bl, int br) {
    if (al <= br && bl <= ar) {
        return true;
    }
    else {
        return false;
    }
}//判断两个区间是否相交
ll search(node* tree, int total_num, int index, int left, int right, ll lazy) {
    ll result = 0;
    if (index >= total_num) {
        return 0;
    }
    //if (!in(tree[index].left, tree[index].right, left, right)) {
    //    return 0;
    //}
    if (left < tree[index].left) {
        left = tree[index].left;
    }
    if (right > tree[index].right) {
        right = tree[index].right;
    }//如果搜索范围比当前划分范围大，缩小搜索范围
    tree[index].value += (tree[index].right - tree[index].left + 1) * lazy;
    tree[index].lazy += lazy;
    if (!in(tree[index].left, tree[index].right, left, right)) {
        return 0;
    }
    //保存上层传来的lazy值，同时更新value，
    //这样处理会导致最后一层lazy堆积，不过因为lazy只会向下传递，所以问题不大
    if (left == tree[index].left && right == tree[index].right) {
        return tree[index].value;
    }
    //完美闭包，不涉及lazy值的向下传递
    else {
        result += search(tree, total_num, 2 * index + 1, left, right, tree[index].lazy);
        result += search(tree, total_num, 2 * index + 2, left, right, tree[index].lazy);
        tree[index].lazy = 0;
        return result;
    }
}
void changenum(node* tree, int total_num, int index, int left, int right, ll change) {
    if (index >= total_num) {
        return;
    }
    if (!in(tree[index].left, tree[index].right, left, right)) {
        return;
    }
    if (left < tree[index].left) {
        left = tree[index].left;
    }
    if (right > tree[index].right) {
        right = tree[index].right;
    }//如果修改范围比当前划分范围大，缩小搜索范围
    if (left == tree[index].left && right == tree[index].right) {
        tree[index].value += change * (right - left + 1);
        tree[index].lazy += change;
        return;
    }
    else {
        tree[index].value += change * (right - left + 1);
        changenum(tree, total_num, 2 * index + 1, left, right, change);
        changenum(tree, total_num, 2 * index + 2, left, right, change);
    }//只修改到完全闭包的lazy值
}
// int main(){
//     cout << in(4,6,5,6)<<endl;
//     cout << in(5,6,5,6)<<endl;
//     cout << in(6,6,6,6)<<endl;
//     cout << in(1,6,2,3)<<endl;
//     cout << in(2,3,3,4)<<endl;
//     cout << in(3,3,3,4)<<endl;
//     cout << in(1,1,2,3)<<endl;
// }
// 测试代码，用于测试函数in的功能
int main() {
    int n, m;
    cin >> n >> m;
    int level = log2_int(n);
    int num = 1 << level;
    //数据子节点的起始地址
    node* tree;
    int total_num;
    if (n == num) {
        num--;
        level = level + 1;
        total_num = (1 << level) - 1;
    }
    else {
        num--;
        num += 1 << level;
        level = level + 2;
        total_num = (1 << (level - 1)) + n - 1;
    }
    //说明需要的层数, 
    // level + 1是因为需要包含第一层，刚好形成完全二叉树，
    // level + 2是因为数据长度为非完全二叉树
    // 数据从0开始编号，
    // num为数据存入时的第一个值
    // level为线段树的层数
    // total_num为总共需要分配的空间
    tree = new node[total_num];
    memset(tree, 0, total_num * sizeof(node));
    for (int i = num; i < total_num; i++) {
        tree[i].left = i - num + 1;
        tree[i].right = i - num + 1;
        cin >> tree[i].value;
        tree[i].lazy = 0;
        tree[i].visited = true;
    }
    build(tree, total_num, 0, num);
    //从0开始建立线段树
    int choose, x, y;
    ll k;
    for (int i = 0; i < m; i++) {
        cin >> choose;
        switch (choose) {
        case 1:
            cin >> x >> y >> k;
            changenum(tree, total_num, 0, x, y, k);
            break;
        case 2:
            cin >> x >> y;
            cout << search(tree, total_num, 0, x, y, 0) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}