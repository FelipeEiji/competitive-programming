#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int a,b;

    while(scanf("%d", &N) && N){
        int cars[10001] =  {};
        int valid = true;
        for(int i = 0; i<N; i++){
            scanf("%d %d", &a, &b);
            if(i+b < 0 || i+b >= N) valid = false;
            if(valid && cars[i+b]) valid = false;
            if(!valid) continue;
            cars[i+b] = a;
        }

        if(!valid) {
            printf("-1\n");
            continue;
        }

        printf("%d", cars[0]);
        for(int i = 1; i<N;i++){
            printf(" %d", cars[i]);
        }
        printf("\n");
    }

    return 0;
}