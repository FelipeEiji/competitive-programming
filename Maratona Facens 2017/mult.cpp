#include <bits/stdc++.h>

using namespace std;

int results[10000][10000];

vector<pair<int, int> > vec;

int op(pair<int, int> a, pair<int, int> b) {
    return a.first * a.second * b.second;
}

int cnt;

int calc(int a, int b) {
    if (results[a][b] != -1) {
        return results[a][b];
    }
    
    cnt++;
     
    if (a == b) {
        return 0;
    }

    int minimum = INT_MAX;

    for (int i = a; i < b; i++) {
        int ops = vec.at(a).first * vec.at(i + 1).first * vec.at(b).second;

        int p1 = results[a][i] == -1 ? calc(a, i) : results[a][i];
        int p2 = results[i+1][b] == - 1 ? calc(i + 1, b) : results[i+1][b];

        results[a][i] = p1;
        results[i+1][b] = p2;
        
        int res = p1 + p2 + ops;

        if (res < minimum) {
            minimum = res;
        }
    }

    results[a][b] = minimum;
    return minimum;
}

void solve(int a) {
    memset(results, -1, sizeof(results));
    vec.clear();
    
    int x, y;
    while(a--) {
        scanf("%i %i", &x, &y);
        vec.push_back(make_pair(x, y));
    }

    int minimum;

    if (vec.size() == 2) {
        minimum = op(vec.at(0), vec.at(1));
    } else {
        minimum = calc(0, vec.size() - 1);
    }

    cout << minimum << endl;
}


int main() {
    int a;
   
    
    while (cin >> a && a != 0)
    {
        solve(a);
    }

    // printf("cnt: %d\n", cnt);

    return 0;
}