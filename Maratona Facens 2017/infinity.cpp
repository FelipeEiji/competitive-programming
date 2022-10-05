#include <bits/stdc++.h>
using namespace std;

map<int, map<int,int>> fights;

int main(){
    pair<int,int> stones[] = {
        {0, 200},
        {3, 200},
        {5, 170},
        {4, 170},
        {2, 160},
        {1, 160},
    };
    map<int, string> stonesName = {
        {0,"espaco"},
        {1,"mente"},
        {2,"alma"},
        {3,"realidade"},
        {4,"tempo"},
        {5,"poder"},
    };
    map<string,bool> takenStones = {
        {"espaco", false},
        {"mente", false},
        {"alma", false},
        {"realidade", false},
        {"tempo", false},
        {"poder", false},
    };

    int T0,T1,T2,T3;
    int A0,A1,A2,A3;
    int heros[6];
    int thanos;

    while((scanf("%d %d %d %d", &T0,&T1,&T2,&T3) != EOF) && (T0 !=-1 || T1 !=-1 || T2!=-1 || T3 !=-1)){
        vector<int> indexes = {0,1,2,3,4,5};
        thanos = T0 + T1 + T2 + T3;
        for(int i = 0; i<6; i++){
            scanf("%d %d %d %d", &A0,&A1,&A2,&A3);
            heros[i] = A0+A1+A2+A3;
        }

        vector<int> seq;

        while(indexes.size()!=0){
            bool victory = false;
            for(auto it = indexes.begin(); it!= indexes.end();it++){
                int result = thanos-heros[stones[*it].first];
                if(result>=0){
                    seq.push_back(stones[*it].first);
                    thanos+=stones[*it].second;
                    indexes.erase(it);
                    victory = true;
                    break;
                }
            }
            if(!victory){
                break;
            }
        }

        if(seq.size() <6){
            printf("Precisamos de mais poder antes dessa guerra!\n");
        }else{
            for(int i = 0; i<5; i++){
                printf("%s ", stonesName[seq[i]].c_str());
            }
            printf("%s\n", stonesName[seq[5]].c_str());
        }
    };
}