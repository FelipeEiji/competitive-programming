#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    stack<int> cards = {};
    scanf("%d", &N);
    int input;
    while(N--){
        scanf("%d", &input);
        if(cards.size()==0){
            cards.push(input);
            continue;
        }

        if(cards.top()+input+1 & 1){
            cards.pop();
        }else{
            cards.push(input);
        }
    }

    printf("%d\n", cards.size());
}