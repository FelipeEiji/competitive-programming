#include <bits/stdc++.h>
using namespace std;

int main(){
    char beds[500001];
    while(scanf("%s", beds)!= EOF){
        int index = 0;
        int maxDist = 0;
        int lastBed = -1;
        while(beds[index]!= '\0'){
            if(beds[index]== 'X'){
                if(lastBed == -1){
                    maxDist = index-1;
                    lastBed = index;
                }else{
                    maxDist = max(maxDist, ((index-lastBed)/2)-1);
                    lastBed = index;
                }
            }
            index++;
        }
        maxDist = max(maxDist, index-2-lastBed);
        printf("%d\n", maxDist);
    }
}