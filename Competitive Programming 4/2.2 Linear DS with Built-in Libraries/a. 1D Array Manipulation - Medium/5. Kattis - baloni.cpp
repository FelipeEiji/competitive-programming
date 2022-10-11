#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    vector<int> arrows(1000001,0);
    int count = 0;
    scanf("%d", &N);
    while(N--){
        int input;
        scanf("%d", &input);
        if(arrows[input] == 0){
            arrows[input-1]++;
        }else{
            arrows[input-1]++;
            arrows[input]--;
        }
    }

    for(int i = 0; i<1000000;i++){
        count += arrows[i];
    }

    printf("%d\n", count);
}