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
        int getMaxPrimeDivideNumber(long long number){
            int* div = new int[cnt];
            memset(div, 0, cnt * sizeof(int));
            int max = -1;
            int index = 0;
            node* now = primes;
            while(now->next){
                now = now->next;
                while(number % (now->data) == 0){
                    number = number / (now->data);
                    div[index]++;
                    if(now->data > max){
                        max = now->data;
                        return max;
                    }
                }
                index++;
            }
            return max;
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
    Prime prime(2000000);
    long long number;
    cin >> number;
    long long result;
    result = prime.getMaxPrimeDivideNumber(number);
    if(result == -1){
        cout << number;
        return 0;
    }else{
        cout << number / result;
        return 0;
    }
}