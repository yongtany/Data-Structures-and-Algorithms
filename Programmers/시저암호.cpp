#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
  string answer = "";

  for (int i = 0; i < s.size(); i++)
  {
    // 스페이스바에 해당하는 입력이면 그대로 항목에 넣어줌
    if (s[i] == 32)
      answer.push_back(s[i]);
    // 대문자일 때, 항목에 n을 더한 값이 'Z' 값을 넘어가는 경우 다시 'A'로 돌린다음 푸시
    else if ((91 <= s[i] + n) && s[i] < 91)
      answer.push_back(s[i] + n - 26);
    // 소문자일 때, 항목에 n을 더한 값이 'z' 값을 넘어가는 경우 다시 'a'로 돌린다음 푸시
    else if ((123 <= s[i] + n) && s[i] < 123)
      answer.push_back(s[i] + n - 26);
    // 이 외의 경우 모두 항목에 n을 더한 값을 푸시
    else
      answer.push_back(s[i] + n);
  }

  return answer;
}
