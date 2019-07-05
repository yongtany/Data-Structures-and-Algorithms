#include <iostream>
#include <string>
#include<cstring>

using namespace std;

int w = 0;
int d[1000000];
int ans = 0;

void go(string n, int cnt) {

    int now = stoi(n);

    if (d[cnt] > now) {
        return;
    }
    else {
        d[cnt] = now;
    }

    if (cnt == w) {
        if (now > ans) {
            ans = now;
        }
        return;
    }

    for (int i = 0; i < n.size(); i++) {
        for (int j = i + 1; j < n.size(); j++) {
            string tmp = n;
            swap(tmp[i], tmp[j]);
            go(tmp, cnt + 1);
        }
    }
}

int main() {


    int testcase;
    cin >> testcase;

    int a = 0;

    while (testcase--) {

        memset(d, -1, sizeof(d));

        string s;

        a++;

        cin >> s >> w;


        go(s, 0);

        cout << "#" << a << " " << ans << endl;
        ans = 0;
    }

    return 0;
}
