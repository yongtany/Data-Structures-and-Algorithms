#include <iostream>

using namespace std;

int main()
{
    int req1, req2, res1, res2;
    int h[2], t[2], o[2];

    cin >> req1;
    cin >> req2;

    for(int i = 0; i < 2; i++) {
      h[0] = req1 / 100;
      t[0] = (req1 / 10) % 10;
      o[0] = (req1 % 100) % 10;

      res1 = (o[0] * 100) + (t[0] * 10) + h[0];

      h[1] = req2 / 100;
      t[1] = (req2 / 10) % 10;
      o[1] = (req2 % 100) % 10;

      res2 = (o[1] * 100) + (t[1] * 10) + h[1];
    }

    if(res1 > res2)
      cout << res1;
    else
      cout << res2;

    return 0;

}
