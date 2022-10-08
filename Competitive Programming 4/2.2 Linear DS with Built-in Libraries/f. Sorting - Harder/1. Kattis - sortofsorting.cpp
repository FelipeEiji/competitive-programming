#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a,const string& b){
    string as = a.substr(0,2);
    string bs = b.substr(0,2);
    return as.compare(bs) < 0;
}

int main(){
    int N;
    vector<string> names(201);
    char name[21];
    while(scanf("%d", &N) && N){
        for(int i = 0; i<N;i++){
            scanf("%s", name);
            string a = name;
            names[i]=a;
        }

        stable_sort(names.begin(), names.begin()+N, cmp);

        for(int i = 0; i<N;i++){
            printf("%s\n", names[i].c_str());
        }
        printf("\n");
    }
}