#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for(int i = 0; i < progresses.size(); i++) {
        int dayCount = 0;
        while(progresses[i] < 100) {
            progresses[i] += speeds[i];
            dayCount++;
        }
        q.push(dayCount);
    }

    int cnt = 1;
    int curr = q.front();
    q.pop();
    while(!q.empty()) {
        if(q.front() <= curr) {
            q.pop();
            cnt++;
        } else {
            answer.push_back(cnt);
            cnt = 1;
            curr = q.front();
            q.pop();
        }
    }
    answer.push_back(cnt);

    return answer;
}
