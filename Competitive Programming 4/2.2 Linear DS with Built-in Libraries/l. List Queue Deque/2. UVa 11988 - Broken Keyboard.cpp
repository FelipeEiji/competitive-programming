#include <bits/stdc++.h>
using namespace std;

int main(){
    char text[100001];
    while(scanf("%s", text) != EOF){
        list<char> beijuText;
        auto itText = beijuText.begin();
        int size = strlen(text);
        for(int i = 0; i<size;i++){
            if(text[i] == '['){
                itText = beijuText.begin();
                continue;
            }
            if(text[i] == ']'){
                itText = beijuText.end();
                continue;
            }
            beijuText.insert(itText, text[i]);        
        }
        for(auto it = beijuText.begin();it!=beijuText.end();it++) printf("%c", *it);
        printf("\n");
    }
}