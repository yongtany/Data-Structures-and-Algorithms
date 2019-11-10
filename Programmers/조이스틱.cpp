#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;

    int n = name.length();

    int tmp = 0, turn = n-1; //오른쪽, 왼쪽 어느 방향으로 가야지 빠른지 확인

    for (int i = 0; i < n; i++) {
        int startto = name[i] - 'A';
        int endto = 'Z' - name[i] + 1; //위로 조작하는 것까지 포함해야 한다.

        if (startto > endto) tmp += endto ;//z부터 세는게 빠르다.
        else tmp += startto;

        int next = i+1; //다음 문자
        while(next < n && name[next] == 'A') next++; //오른쪽 이동

        turn = min(turn, i + n - next  + min(i , n-next)) ;
        //turn - > 전부 오른쪽으로 이동하면서 바꿔나갔을 대의 최대 이동횟수

    }

    tmp += turn;
    answer = tmp;
    return answer;
}
