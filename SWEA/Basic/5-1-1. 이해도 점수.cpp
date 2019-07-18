#include <iostream>

int score [6];
int T;

int main()
{
  scanf("%d", &T);
  for(int test_case = 1; test_case <= T; test_case++)
  {
    for(int i = 0; i < 6; i++)
    {
      scanf("%d", &score[i]);
    }
    int max_score = 0;
    for(int i = 0; i < 6; i++)
    {
      if(max_score < score[i])
      {
        max_score = score[i];
      }
    }
    int min_score = 100;
    for(int i = 0; i < 6; i++)
    {
      if(min_score > score[i])
      {
        min_score = score[i];
      }
    }
    int sum = 0;
    for(int i = 0;  i < 6; i++)
    {
      sum += score[i];
    }
    int res = 0;
    res = (sum - min_score - max_score) / 4;

    printf("#%d %d", T, res);
  }

  return 0;
}
