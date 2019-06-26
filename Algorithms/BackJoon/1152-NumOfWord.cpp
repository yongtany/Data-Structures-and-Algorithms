#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int num = 0;
    getline(cin, s);

    for(int i = 0;  i < s.length(); i++) {
        if(s.at(i) == ' ') {
            num++;
        }
    }

    if(s.at(0) == ' ') {
        num--;
    }

    if(s.at(s.length() - 1) == ' ') {
        num--;
    }

    cout << num + 1 << endl;

    return 0;
}
