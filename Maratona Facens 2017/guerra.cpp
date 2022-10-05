#include <bits/stdc++.h>

using namespace std;

int main() {
    int rot = 0;
    map<char, int> wordMap = {
        {' ', '#'},
        {'A', '@'},
        {'S', '$'},
        {'E', '3'},
        {'I', '!'},
        {'O', '0'}
    };

    do {
        cin >> rot;

        if (rot == 0) continue;

        string str;
        cin.ignore(1, '\n');
        getline(cin, str);

        if((rot < 1 || rot > 20) || (str.size() < 1 || str.size() > 51)){
            printf("ERROR\n");
            continue;
        }

        for (int i = 0; i < str.size(); i++) {
            if (wordMap.count(str[i])) {
                str[i] = wordMap[str[i]];    
            } else {
                str[i] = (str[i] + rot);
                if (str[i] > 'Z') {
                    str[i] = 'A' + (str[i] % 'Z') - 1;
                }
                
            }
        }

        cout << str << endl;
    } while(rot != 0);

    return 0;
}