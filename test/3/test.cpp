#include <stdio.h>
#include <string.h>
int main(){
    char text1[100], text2[100];
    scanf_s("%s", text1, 99);
    scanf_s("%s", text2, 99);
    //读取字符串，最大长度为99
    int l1 = strlen(text1);
    int l2 = strlen(text2); 
    //识别字符串长度
    for(int i = 0; i < l1 && i < l2; i++){
        if(text1[i] == text2[i]){
            printf("%c", text1[i]);
        }
        //一旦相同就输出当前字符
    }//不超过字符串的最大长度
    return 0;
}