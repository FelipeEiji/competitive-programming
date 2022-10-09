#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) && N){
        while(true){
            stack<int> station = {};
            int order[1001];
            int input;

            scanf("%d", &order[0]);

            if(order[0] == 0) break;

            for(int i = 1; i<N; i++){
                scanf("%d", &order[i]);
            }

            int currentCoach = 1;
            bool failed = false;
            for(int i = 0; i<N; i++){
                if(order[i] == currentCoach){
                    currentCoach++;
                    continue;
                }
                if(station.size() != 0 && station.top() == order[i]){
                    station.pop();
                    continue;
                }
                if(currentCoach > N){
                    failed = true;
                    break;
                }
                station.push(currentCoach);
                currentCoach++;
                i--;
            }

            if(failed) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }
}