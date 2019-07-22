#include <iostream>
#include <queue>

using namespace std;

// BFS에 사용할 큐(위치, 이동횟수)
queue <pair <int, int>> que;
int T, S, E;
// 이미 방문한 곳을 체크하기 위한 배열
int visited[50001];
int Answer;
int main() {
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++) {
    scanf("%d %d", &S, &E);
    for(int i = 1; i <= 50000; i++) {
      visited[i] = 0;
    }
    while(!que.empty()) {
      que.pop();
    }
    que.push(make_pair(S, 0));
    visited[S] = 1;
    while(!que.empty()) {
      int now = que.front().first;
      int cost = que.front().second;
      que.pop();
      if(now == E) {
        Answer = cost;
        break;
      }
      // 통로, 이전방으로 이동
      if(now - 1 >= 1 && visited[now - 1] == 0) {
        visited[now - 1] = 1;
        que.push(make_pair(now - 1, cost + 1));
      }
      // 통로, 다음방으로 이동
      if(now + 1 <= 50000 && visited[now + 1] == 0) {
        visited[now + 1] = 1;
        que.push(make_pair(now + 1, cost + 1));
      }
      if(now * 2 <= 50000 && visited[now *2 ] == 0) {
        visited[now * 2];
        que.push(make_pair(now * 2, cost + 1));
      }
    }
    printf("#%d %d\n", test_case, Answer);
  }
}
