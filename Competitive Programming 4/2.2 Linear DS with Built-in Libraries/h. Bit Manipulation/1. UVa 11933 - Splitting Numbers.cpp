#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) && N){
        int A = 0, B = 0;
        bool isA = true;
        for(int i = 0; N != 0; N = (N >> 1), i++){
            if(N & 1){
                if(isA) {
                    A |= (1 << i);
                    isA = false;
                }else{
                    B |= (1 << i);
                    isA = true;
                }
            }
        }
        printf("%d %d\n", A, B);
    }
}