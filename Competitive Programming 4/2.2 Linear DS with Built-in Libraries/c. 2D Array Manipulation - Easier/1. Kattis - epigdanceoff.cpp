#include <bits/stdc++.h>
using namespace std;

char danceInput[2002][2002];

int main(){    
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF){
        int steps = 0;
        for(int i = 0; i<N; i++){
            scanf("%s", danceInput[i]);
        }
        bool dancing = false;
        for(int i = 0; i<M; i++){
            for(int j = 0; j<N; j++){
                if(danceInput[j][i] == '$'){
                    dancing = true;
                    break;
                }

                if((j==(N-1)) && (danceInput[j][i] == '_') && dancing){
                    steps++;
                    dancing = false;
                }
            }
        }
        if(dancing) steps++;

        printf("%d", steps);
    }
}