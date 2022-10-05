#include <bits/stdc++.h>
using namespace std;

int main(){
    int S, B;
    int R, L;
    int right[100002], left[100002];
    int tempR, tempL;

    while(scanf("%d %d", &S, &B) && (S || B)){
        for(int i = 0; i<=S; i++){
            left[i] = i-1;
            right[i] = i+1;
        }

        while(B--){
            scanf("%d %d", &L, &R);
            tempL = left[L];
            tempR = right[R];
            tempL <= 0?printf("* "):printf("%d ", tempL);
            tempR > S?printf("*\n"):printf("%d\n", tempR);
            left[right[R]] = tempL;
            right[left[L]] = tempR;
        }
        printf("-\n");
    }
}