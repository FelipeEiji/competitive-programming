#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    

    while(scanf("%d", &N) && N!=0){
        int E[101][101];
        vector<int> dist(N, INT_MAX);
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i<N;i++){
            for(int j = 0; j<N;j++){
                scanf("%d", &E[i][j]);
            }
        }

        pq.push({0,0});
        dist[0] = 0;

        while(pq.size()>0){
            int v = pq.top().first;
            int w = pq.top().second;

            pq.pop();

            if(w!=dist[v])continue;

            for(int i = 0; i<N ;i++){
                if(E[v][i] == 0) continue;
                int cost = E[v][i];
                if(dist[i]>dist[v]+cost){
                    dist[i] = dist[v]+cost;
                    pq.push({i,dist[i]});
                }
            }
        }

        if(dist[N-1] == INT_MAX){
            printf("CAMINHO INEXISTENTE\n");
        }else{
            printf("%d\n",dist[N-1]);
        }
    }
}