#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a, b;
    bitset<3001> jumpers;
    while(scanf("%d", &n) != EOF){
        jumpers.reset();
        scanf("%d", &a);
        for(int i = 1; i<n; i++){
            scanf("%d", &b);
            jumpers.set(abs(a-b));
            a = b;
        }
        bool isJolly = true;
        for(int i = 1; i<=n-1;i++){
            if(!jumpers[i]){
                isJolly = false;
                break;
            }
        }
        if(isJolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }
}