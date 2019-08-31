#include <vector>

int solution(int N)
{
  vector<int> arr;

  int count = 0;
  int max = 0;
  bool flag = false;

  while (N > 0)
  {
    arr.push_back(N % 2);
    N /= 2;
  }

  for (int i = arr.size() - 1; i >= 0; i--)
  {
    if (arr[i] == 1)
    {
      if (flag)
      {
        if (count > max)
        {
          max = count;
        }
        count = 0;
      }
      else
      {
        count = 0;
        flag = true;
      }
    }
    else
    {
      count++;
    }
  }
  return max;
}
