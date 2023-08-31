#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct point {
    double x;
    double y;
}point;
bool compare(const point& a, const point& b) {
    return a.x < b.x;
}
double distance(point* a, point* b) {
    double dx = a->x - b->x;
    double dy = a->y - b->y;
    return sqrt(dx * dx + dy * dy);
}
double min_distance(point* list, int num) {
    if (num == 1) {
        return 1e+30;
    }
    else {
        double left_min = 0;
        double right_min = 0;
        int middle = num / 2;
        left_min = min_distance(list, middle);
        right_min = min_distance(list + middle, num - middle);
        double min_dis = min(left_min, right_min);
        if (min_dis == -1) {
            min_dis = left_min;
        }
        int index = middle;
        double now_distance = 1e+30;
        while (1) {
            if (abs((list + index)->x - (list + middle - 1)->x) > min_dis || index >= num) {
                break;
            }
            for(int i = middle - 1; i >= 0; i--){
                now_distance = distance(list + i, list + index);
                if (now_distance < min_dis) {
                    min_dis = now_distance;
                }
                if((list + i) -> x != (list + middle - 1) -> x){
                    break;
                }
            }
            index++;
        }
        //先从左判断
        index = middle - 1;
        while (1) {
            if (abs((list + middle)->x - (list + index)->x) > min_dis || index < 0) {
                break;
            }
            for(int i = middle; i < num; i++){
                now_distance = distance(list + i, list + index);
                if (now_distance < min_dis) {
                    min_dis = now_distance;
                }
                if((list + i) -> x != (list + middle) -> x){
                    break;
                }
            }
            index--;
        }
        //再从右判断
        return min_dis;
    }
}
int main() {
    int n;
    cin >> n;
    point* list = new point[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i].x >> list[i].y;
    }
    sort(list, list + n, compare);
    //要注意这里排序，中心点可能会有相同的X值，需做额外的判定
    printf("%.4f", min_distance(list, n));
}