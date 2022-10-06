#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second>b.second);
}

int main(){
    int T, S;

    scanf("%d", &T);

    for(int i = 1; i<=T; i++){
        vector<pair<int,int>> friends(3);
        vector<vector<int>> problems(3);
        map<int, int> duplicates = {};
        for(int j = 1; j<=3; j++){
            int qt;
            scanf("%d", &qt);
            friends[j-1] = make_pair(j,qt);

            while(qt--){
                int problem;
                scanf("%d", &problem);
                problems[j-1].push_back(problem);
                if(duplicates.count(problem)==0) duplicates[problem] = 1;
                else duplicates[problem]++;
            }
        }

        for(int k = 0; k<3; k++){
            auto it = problems[k].begin();
            while(it != problems[k].end()){
                if(duplicates[*it]>1){
                    friends[k].second--;
                    it = problems[k].erase(it);
                }else{
                    it++;
                }
            }
        }

        
        stable_sort(friends.begin(),friends.end(),cmp);

        int max = friends[0].second;

        printf("Case #%d:\n", i);
        for(int j = 0; j<=2; j++){
            if(friends[j].second == max){
                printf("%d %d", friends[j].first, friends[j].second);
                sort(problems[friends[j].first-1].begin(), problems[friends[j].first-1].end());
                for(int k = 0; k<max; k++){
                    printf(" %d", problems[friends[j].first-1][k]);
                }
                printf("\n");
            }
        }
    }
}