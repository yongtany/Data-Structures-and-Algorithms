#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
  int answer = 0;
  queue<pair<int, int>> que;
  priority_queue<int> priQue;

  for (int i = 0; i < priorities.size(); i++)
  {
    // 큐에 <처음 대기목록 순서, 작업 중요도> push
    que.push(make_pair(i, priorities[i]));
    // 우선순위 큐에 작업 중요도 push(자동적으로 오름차순 정렬이 되어 비교용으로 사용됨)
    priQue.push(priorities[i]);
  }

  while (!que.empty())
  {
    // 현재 작업 큐의 front와 우선순위 큐의 인쇄 중요도가 동일할 경우(출력순서가 왔을 때)
    if (que.front().second == priQue.top())
    {
      // 문제에서 요청된 문서번호와 현재 작업 큐의 front.first 에 있는 대기목록 순서가 일치 할 경우
      if (que.front().first == location)
      {
        return answer + 1;
      }
      else
      {
        // 출력작업 후 작업 큐와 우선순위 큐에서 문서를 하나씩 pop
        answer++;
        que.pop();
        priQue.pop();
      }
    }
    else
    {
      // 출력순서가 아니므로 front에 있는 값을 큐의 맨 뒤로 이동시키는 작업
      que.push(que.front());
      que.pop();
    }
  }

  return answer;
}
