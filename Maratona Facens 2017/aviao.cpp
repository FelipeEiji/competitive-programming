#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> timezones;
    int A;
    int i;
    char IATA[4];
    string sIATA;

    scanf("%d", &A);

    while(A--){
        scanf("%s %d", IATA, &i);
        sIATA = IATA;
        timezones[sIATA] = i;
    }

    map<string,map<string,double>> flights;
    int V;
    double distance;
    char IATA1[4], IATA2[4];
    string sIATA1, sIATA2;

    scanf("%d", &V);

    while(V--){
        scanf("%s %s %lf", IATA1, IATA2, &distance);        
        if(distance <=12000){
            sIATA1 = IATA1;
            sIATA2 = IATA2;
            flights[sIATA1][sIATA2] = ((distance/1000) + 3);
            flights[sIATA2][sIATA1] = ((distance/1000) + 3);
        }
    }


    int R;
    char orig[4], dest[4];
    string sorig, sdest;
    int time1, time2;
    double timetraveling;
    priority_queue<pair<string,int>> pq;
    map<string,double> dist;

    scanf("%d", &R);


    while(R--){
        pq = priority_queue<pair<string,int>>();
        dist = map<string,double>();
        scanf("%s %s %d %d", orig, dest, &time1, &time2);
        sorig = orig;
        sdest = dest;
        timetraveling = (time2 - ((timezones[sdest] - timezones[sorig]) + time1))*1.0;
        
        //dijkstra
        pq.push({sorig,0});
        dist[sorig] = 0;

        while(pq.size()>0){
            string v = pq.top().first;
            double w = pq.top().second;

            pq.pop();

            for(auto it = flights[v].begin(); it!= flights[v].end();it++){
                string airport = it->first;
                double cost = it->second;
                if(dist[airport] == 0 && airport != sorig) {
                    dist[airport] = DBL_MAX;
                }
                if(dist[airport]>dist[v]+cost){
                    dist[airport] = dist[v]+cost;
                    pq.push({airport,dist[airport]});
                }
            }
        }


        if(timetraveling >= dist[sdest] - 3){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }

    return 0;
}