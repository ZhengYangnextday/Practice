#include <iostream>
#include <math.h>
#include <cstring>
typedef struct node{
    int data;
    struct node* next;
}node;
using namespace std;
class Prime{
    public:
        void run(int up);
        Prime(int up){
            cnt = 0;
            up_limit = up;
            primes = new node[1];
            primes->data = 1;
            primes->next = NULL;
            run(up);
        }
        bool check(int num){
            node* now = primes;
            double sqrt_num = sqrt(num * 1.0);
            while(now->next){
                now = now->next;
                if(now->data > sqrt_num){
                    break;
                }//减少运算时间
                if(num % now->data == 0){
                    return false;
                }
            }
            return true;
        }
        void print_prime(bool text = true){
            node* now = primes;
            if(text){
                cout <<"In"<< up_limit <<", there are "<< cnt <<" prime numbers"<<endl;
            }
            while(now->next){
                now = now->next;
                cout << now->data << " ";
            }
        }
        int getCnt(){
            return cnt;
        }
        int* getPrimeDivide(int number){
            int* div = new int[cnt];
            memset(div, 0, cnt * sizeof(int));
            int index = 0;
            node* now = primes;
            while(now->next){
                now = now->next;
                while(number % (now->data) == 0){
                    number = number / (now->data);
                    div[index]++;
                }
                index++;
            }
            return div;
        }
        int* PrimeList(){
            int* prime_list = new int[cnt];
            int index = 0;
            node* now = primes;
            while(now->next){
                now = now->next;
                prime_list[index] = now->data;
                index++;
            }
            return prime_list;
        }
    private:
        node* primes;
        int cnt; 
        int up_limit;
};
void Prime::run(int up){
    node* now = primes;
    for(int i = 2; i < up; i++){
        if(check(i)){
            node* new_node = new node[1];
            new_node->data = i;
            new_node->next = NULL;
            now->next = new_node;
            now = new_node;
            cnt++;
        }
    }
}
int main(){
    Prime prime(10000);
    int prime_count = prime.getCnt();
    int x, y;
    cin >> x >> y;
    if(x > y || x < 0 || y < 0){
        cout << 0;
        return 0;
    }//最大公约数一定小于最小公倍数
    int* div_x = prime.getPrimeDivide(x);
    int* div_y = prime.getPrimeDivide(y);
    int cnt = 0;
    for(int i = 0; i < prime_count; i++){
        if(div_y[i] < div_x[i]){
            cout << 0;
            return 0;
        }//不存在最小公倍数不包括最大公约数的情况
        if(div_x[i] != div_y[i]){
            cnt++;
        }
    }
    long long result = 1;
    result = 1<<cnt;
    cout << result;
    return 0;
}