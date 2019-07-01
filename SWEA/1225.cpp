#include<iostream>
#include<queue>
using namespace std;
queue <int> q;

int main() {
    int num;
    for (int t = 1; t <= 10; t++) {
        cin >> num;
        for (int i = 0; i < 8; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        while (q.back()>0) {
            for (int i = 1; i <= 5; i++){//한 사이클
                int a;
                a = q.front();
                q.pop();
                a -= i;
                q.push(a);
                if (q.back() <= 0) {//암호배열조건
                    q.back() = 0;
                    break;
                }
            }
        }
        cout << "#" << num << ' ';
        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
    }

  return 0;
}
