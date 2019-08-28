#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool myComp(string &a, string &b)
{
  if (a == b)
    return false;

  string ab = a + b;
  string ba = b + a;

  if (ab > ba)
    return true;
  else
    return false;
}

string solution(vector<int> numbers)
{
  string answer = "";
  int zero_count = 0;
  vector<string> s_numbers;

  for (auto i : numbers)
  {
    if (i == 0)
      zero_count++;
    s_numbers.push_back(to_string(i));
  }

  if (zero_count == numbers.size())
    return "0";

  sort(s_numbers.begin(), s_numbers.end(), myComp);

  for (auto s : s_numbers)
    answer.append(s);

  return answer;
}
