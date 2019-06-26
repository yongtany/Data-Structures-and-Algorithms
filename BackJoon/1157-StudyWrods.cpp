#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;             // 입력받을 문자
    int arr[26] = { 0, };   // 앞파벳 개수 카운트하는 배열
    int max_cnt = 0;
    int index = 0;
    int count = 0;


    cin >> str;

    for(int i = 0; i < str.length(); i++) {   // 문자열에서 알파벳 개수 세기
        int n = str.at(i);

        if(n < 97)          // 대문자인 경우
            arr[n - 65]++;
        else                // 소문자인 경우
            arr[n - 97]++;
    }

    for(int i = 0; i < 26; i++) { // 최대빈도 문자를 찾는 과정
        if(arr[i] > max_cnt) {
            max_cnt = arr[i];
            index = i;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(arr[i] == max_cnt) {   // 최대빈도와 같은 문자라면,
            count++;
            if(count >= 2) {      // 문자의 빈도가 같은 게 2개 이상 있다면
                cout << "?" << endl;
                return 0;
            }
        }
    }

    cout << (char)(index+65) << endl;   // 대문자로 바꾸어 출력

    return 0;
}
