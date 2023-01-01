#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int main(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    unordered_map<int,int> processes;
    char input[10];
    while(scanf("%s", input) && input[0] != '#'){
        pii input;
        scanf("%d %d", &input.second, &input.first);
        processes[input.second] = input.first;
        pq.push(input);
    }
    int k;
    scanf("%d", &k);
    while(k--){
        pii top = pq.top();
        pq.pop();
        printf("%d\n", top.second);
        top.first += processes[top.second];
        pq.push(top);
    }

    return 0;
}