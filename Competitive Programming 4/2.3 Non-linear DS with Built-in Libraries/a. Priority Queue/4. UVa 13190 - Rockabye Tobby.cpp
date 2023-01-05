#include <bits/stdc++.h>
using namespace std;

#define tiis tuple<int,int,string>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k;
        scanf("%d %d", &n, &k);
        priority_queue<tiis, vector<tiis>,greater<tiis>> pq;
        unordered_map<int,int> drugs;
        for(int i = 0; i<n;i++){
            int a;
            char b[16];
            scanf("%s %d", b, &a);
            string bTemp = b;
            tiis temp(a,i,bTemp);
            drugs[i]=a;
            pq.push(temp);
        }
        while(k--){
            tiis top = pq.top();
            pq.pop();
            printf("%d %s\n", get<0>(top), get<2>(top).c_str());
            get<0>(top) = get<0>(top) + drugs[get<1>(top)];
            pq.push(top);
        }
    }
}