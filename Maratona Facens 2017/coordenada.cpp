#include <bits/stdc++.h>
using namespace std;

int main()
{
    int la, lb, lc, aa, ab, ac;
    char ld, ad;

    int n;

    float a,b;

    while(scanf("%d", &n) && n!=0){
        while(n--){
            scanf("%dg%dm%ds%c %dg%dm%ds%c", &la,&lb, &lc, &ld, &aa,&ab, &ac, &ad);
            a = (trunc((la+(lb/60.0)+(lc/3600.0)) * 100.0)/100) * (ld == 'S' ? -1:1);
            b = (trunc((aa+(ab/60.0)+(ac/3600.0)) * 100.0)/100) * (ad == 'W' ? -1:1);
            printf("%.2f %.2f\n", a,b);
        }
    }
}