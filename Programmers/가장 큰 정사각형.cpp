#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
  int answer = 0;
  int lengthY = board.size();
  int lengthX = board[0].size();
  int max = 0;

  if (lengthY < 2 || lengthY < 2)
  {
    for (int i = 0; i < lengthY; i++)
    {
      for (int j = 0; j < lengthX; j++)
      {
        if (board[i][j] == 1)
        {
          max = 1;
        }
      }
    }
  }
  else
  {
    for (int i = 1; i < lengthY; i++)
    {
      for (int j = 1; j < lengthX; j++)
      {
        if (board[i][j] == 1)
        {
          board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;
          if (board[i][j] > max)
          {
            max = board[i][j];
          }
        }
      }
    }
  }

  answer = pow(max, 2);

  return answer;
}

// 배열의 [1][1]부터 반복문을 돌린다. (첫 번째 행, 첫 번째 열 무시, 이유는 2번 참고)
// 현재 값이 1일 경우, 좌측값, 상단값, 좌측상단값 중 가장 작은 값의 +1 한 값을 현재 값으로 할당.
// 배열이 끝날 때 까지 반복.
// 배열의 가장 큰 값이 현재 배열의 가장 큰 정사각형의 값이 된다.
