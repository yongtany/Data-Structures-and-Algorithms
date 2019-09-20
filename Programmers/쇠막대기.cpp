#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string str) {
    int result = 0;
    stack<char> st;

    for(int i = 0; i <str.length(); i++) {
      // 여는 괄호면 스택에 넣는다.
      if(str[i] == '(' ) st.push(str[i]);
      // 닫는 괄호면 이 괄호가 레이저인지, 파이프 끝인지 알아본다.
      else {
        st.pop();
        // 레이저이면
        if(str[i -1] == '(' )
          result += st.size();  // 잘린 갯수 추가.
        // 파이프 끝이면
        else result++;  // 닫혀서 잘려진 갯수 추가.
      }
    }

    return result;
}
