#include <bits/stdc++.h>
using namespace std;

int main(){
    char students[101][4];
    int N;

    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf(" %s", students[i]);
    }

    int Q;

    scanf("%d", &Q);

    char left[4];
    int leftDist;
    char right[4];
    int rightDist;

    int pos;

    while(Q--){
        scanf("%d", &pos);
        int tempPos = pos-1;

        if(students[tempPos][0] != '?'){
            printf("%s\n", students[tempPos]);
            continue;
        }
        leftDist = tempPos - 1;
        rightDist = tempPos + 1;

        bool leftFound = false;
        bool rightFound = false;

        while(leftDist >= 0){
            if(students[leftDist][0] != '?') {
                strcpy(left,students[leftDist]);
                leftFound = true;
                break;
            }
            leftDist--;
        }

        while(rightDist < N){
            if(students[rightDist][0] != '?'){
                strcpy(right,students[rightDist]);
                rightFound = true;
                break;
            } 
            rightDist++;
        }

        if(leftFound && rightFound && ((tempPos - leftDist) == (rightDist - tempPos))){
            printf("middle of %s and %s\n", left, right);
        }else if((leftFound && ((tempPos - leftDist) < (rightDist - tempPos))) || !rightFound){
            for(int i = 0; i<(tempPos-leftDist);i++){
                printf("right of ");
            }
            printf("%s\n",left);
        }else{
            for(int i = 0; i<(rightDist - tempPos);i++){
                printf("left of ");
            }
            printf("%s\n",right);
        }
    }
}