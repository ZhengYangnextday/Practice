#include <iostream>
#include <cstring>
using namespace std;
long long run(long long** board, long long a, long long b, long long x, long long y) {
    long long result = 0;
    if (a < 0 || b < 0) {
        return result;
    }
    if ((((1 << abs(a - x)) | (1 << abs(b - y))) == 6) || (a == x && b == y)) {
        result = 0;
    }
    else {
        if (board[a][b] != -1) {
            return board[a][b];
        }
        else {
            if (a == 0 && b == 0) {
                result = 1;
            }
            else {
                result = run(board, a - 1, b, x, y) + run(board, a, b - 1, x, y);
            }
        }
    }
    board[a][b] = result;
    return result;
}
int main() {
    long long a, b;
    long long x, y;
    cin >> a >> b >> x >> y;
    long long** board = new long long* [a + 1];
    for (long long i = 0; i < a + 1; i++) {
        board[i] = new long long[b + 1];
        for (long long j = 0; j < b + 1; j++) {
            board[i][j] = -1;
        }
    }
    cout << run(board, a, b, x, y) << endl;
    //for (long long i = 0; i < a + 1; i++) {
    //    for (long long j = 0; j < b + 1; j++) {
    //        cout << board[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    return 0;
}