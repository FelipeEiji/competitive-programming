#include <bits/stdc++.h>
using namespace std;

char danceInput[2002][2002];

int main(){
    int command;
    int game[4][4];
    for(int i = 0; i<4;i++){
        for(int j = 0; j< 4; j++){
            scanf("%d", &game[i][j]);
        }
    }

    scanf("%d", &command);

    if(command == 0){
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4;j++){
                for(int k = j+1; k<4; k++){
                    if(game[i][j] == 0 && game[i][k] != 0){
                        game[i][j] = game[i][k];
                        game[i][k] = 0;
                        j--;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] == game[i][k]){
                        game[i][j] *= 2;
                        game[i][k] = 0;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] != game[i][k] && game[i][k] != 0){
                        break;
                    }
                }
            }
        }
    }

    if(command == 1){
        for(int j = 0; j<4; j++){
            for(int i = 0; i<4;i++){
                for(int k = i+1; k<4; k++){
                    if(game[i][j] == 0 && game[k][j] != 0){
                        game[i][j] = game[k][j];
                        game[k][j] = 0;
                        i--;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] == game[k][j]){
                        game[i][j] *= 2;
                        game[k][j] = 0;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] != game[k][j] && game[k][j] != 0){
                        break;
                    }
                }
            }
        }
    }

    if(command == 2){
        for(int i = 3; i>=0; i--){
            for(int j = 3; j>=0;j--){
                for(int k = j-1; k>=0; k--){
                    if(game[i][j] == 0 && game[i][k] != 0){
                        game[i][j] = game[i][k];
                        game[i][k] = 0;
                        j++;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] == game[i][k]){
                        game[i][j] *= 2;
                        game[i][k] = 0;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] != game[i][k] && game[i][k] != 0){
                        break;
                    }
                }
            }
        }
    }

    if(command == 3){
        for(int j = 3; j>=0; j--){
            for(int i = 3; i>=0;i--){
                for(int k = i-1; k>=0; k--){
                    if(game[i][j] == 0 && game[k][j] != 0){
                        game[i][j] = game[k][j];
                        game[k][j] = 0;
                        i++;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] == game[k][j]){
                        game[i][j] *= 2;
                        game[k][j] = 0;
                        break;
                    }
                    if(game[i][j] != 0 && game[i][j] != game[k][j] && game[k][j] != 0){
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i<4;i++){
        for(int j = 0; j< 4; j++){
            printf("%d ", game[i][j]);
        }
        printf("\n");
    }
}