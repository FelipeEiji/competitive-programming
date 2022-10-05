#include <bits/stdc++.h>
using namespace std;

int main(){
    int L, A, S1, S2;
    float x, y;

    while((scanf("%d %d %d %d", &L, &A, &S1, &S2) != EOF) && (L != 0 || A !=0 || S1!=0 || S2 !=0)){
        if((S1+S2)<L){
            printf("DEFEITO\n");
            continue;
        }
        else if(L==0 || A == 0){
            printf("DEFEITO\n");
            continue;
        }else if((S1+S2)==L){
            printf("%d 0\n", S1);
            continue;
        }
        x = ((S1*S1)+(L*L)-(S2*S2))/(2.0*L);
        y = sqrt((S1*S1)*1.0-(x*x)*1.0);
        if((x>L || x<0) || (y>A || y<0) || isnan(y)){
            printf("DEFEITO\n");
            continue;
        };
        printf("%.0f %.0f\n", round(x), round(y));
    }
}