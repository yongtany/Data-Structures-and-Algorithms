#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair< string, pair<int, int> > a,
                pair< string, pair<int, int> > b) {
        if(a.second.first == b.second.first)
            return a.second.second > b.second.second;
        else
            return a.second.first > b.second.first;
    }

int main(void) {
    // vector<pair<int, string> > v;
    // v.push_back(pair<int, string>(90, "Choi"));
    // v.push_back(pair<int, string>(85, "Lee"));
    // v.push_back(pair<int, string>(88, "Jang"));
    // v.push_back(pair<int, string>(78, "Kim"));
    // v.push_back(pair<int, string>(95, "Park"));

    // sort(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i].second << ' ';
    // }


    vector< pair<string, pair<int, int>> > v;
    v.push_back(pair<string, pair<int, int>> ("Choi", make_pair(95, 19940614)));
    v.push_back(pair<string, pair<int, int>> ("Lee", make_pair(85, 19930518)));
    v.push_back(pair<string, pair<int, int>> ("Jang", make_pair(88, 19930203)));
    v.push_back(pair<string, pair<int, int>> ("Kim", make_pair(78, 19900920)));
    v.push_back(pair<string, pair<int, int>> ("Park", make_pair(95, 19960615)));

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++)
        cout << v[i].first << ' ';

    return 0;

}

