#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int sum[32769] = {};
        int input;
        for(int i = 0; i< (1 << N); i++){
            scanf("%d", &input);
            for(int j = 0; j<N;j++){
                sum[i^(1<<j)] += input;
            }
        }

        int maxSum = 0;

        for(int i = 0; i<(1 << N);i++){
            int origin = sum[i];
            for(int j = 0; j<N;j++){
                maxSum = max(maxSum, sum[i^(1<<j)] + origin);
            }
        }

        printf("%d\n", maxSum);
    }
}