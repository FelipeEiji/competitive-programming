#include <bits/stdc++.h>
using namespace std;

int main(){
    char path[31];
    int H;
    unsigned int node = 1;

    scanf("%d %s", &H, path);

    for(int i = 0; path[i]!='\0';i++){
        if(path[i]=='L')node*=2;
        else if(path[i]=='R')node=(node*2)+1;
    }

    printf("%u", ((unsigned int)(pow(2,H+1))-node));
}