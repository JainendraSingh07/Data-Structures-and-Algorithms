#include <bits/stdc++.h>

using namespace std;

int poisonousPlants(vector<int>p){
    stack<pair<int,int>> s;
    int days = 0;

    for(int i = 0 ; i < p.size() ; i++){
        int currPesticide = p[i];
        int currDay = 0;

        while(!s.empty() && currPesticide <= s.top().first){
            currDay = max(s.top().second , currDay);
            s.pop();
        }

        if(s.empty()){
            currDay = 0;
        }else{
            currDay++;
        }

        days = max(currDay , days);
        s.push({currPesticide , currDay});

    }
    return days;
}

int main() {

    vector<int> pesticideLevels = {6, 5, 8, 4, 7, 10, 9};
    int result = poisonousPlants(pesticideLevels);
    cout << result << endl;

    return 0;
}