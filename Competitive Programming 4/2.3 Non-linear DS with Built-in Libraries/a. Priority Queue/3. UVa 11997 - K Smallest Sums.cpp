#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int main(){
    int K;
    int L1[751], L2[751];
    while(scanf("%d", &K) != EOF){
        for(int i = 0; i<K;i++) scanf("%d", &L1[i]);
        sort(L1,L1+K);
        
        for(int i = 1; i<K;i++){
            for(int j = 0; j<K;j++) scanf("%d", &L2[j]);
            sort(L2,L2+K);

            priority_queue<pii, vector<pii>,greater<pii>> pq;
            for(int j = 0;j<K;j++) pq.push({L1[j]+L2[0],0});

            for(int j = 0;j<K;j++){
                pii top = pq.top();
                pq.pop();
                L1[j] = top.first;
                pq.push({top.first - L2[top.second] + L2[top.second+1], top.second+1});
            }
        }
        for(int i = 0; i<K-1;i++) printf("%d ", L1[i]);
        printf("%d\n", L1[K-1]);
    }
    return 0;
}