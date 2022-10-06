#include <bits/stdc++.h>
using namespace std;

int main(){
    char magic[53][3];
    int N;

    while(scanf("%d", &N) && N){
        int index = 0;
        vector<int> indexes(N);
        iota(indexes.begin(), indexes.begin()+N, 0);
        char card[3];
        char word[23];
        for(int i = 0; i<N; i++){
            scanf("%s %s", card, word);
            index = (index+strlen(word)-1)%indexes.size();
            strcpy(magic[indexes[index]], card);
            indexes.erase(indexes.begin()+index);
        }
        printf("%s", magic[0]);
        for(int i = 1; i<N; i++) printf(" %s", magic[i]);
        printf("\n");
    }
    return 0;
}