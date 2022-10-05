#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, string, string> iss;

bool cmp (iss &A, iss &B){
    auto ageA = get<0>(A); auto lastA = get<1>(A); auto firstA = get<2>(A);
    auto ageB = get<0>(B); auto lastB = get<1>(B); auto firstB = get<2>(B);    
    if(ageA != ageB) return ageA < ageB;
    if(lastA != lastB) return lastA > lastB;
    return firstA < firstB;
}

int main(){
    vector<iss> people;
    people.emplace_back(make_tuple(23, "Maruyama", "Felipe"));
    people.emplace_back(make_tuple(26, "Maruyama", "Alessandro"));
    people.emplace_back(make_tuple(22, "Maruyama", "Elisa"));
    people.emplace_back(make_tuple(22, "Umeda", "Elisa"));
    people.emplace_back(make_tuple(22, "Fukuoka", "Elise"));
    people.emplace_back(make_tuple(22, "Fukuoka", "Elisa"));
    people.emplace_back(make_tuple(20, "Maruyama", "Marcos"));
    sort(people.begin(), people.end(), cmp);
    for(auto person : people){
        cout << get<0>(person) << " ";
        cout << get<1>(person) << " ";
        cout << get<2>(person) << endl;
    }
}