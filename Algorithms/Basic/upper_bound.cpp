#include <iostream>
#include <algorithm>

using namespace std;

int n, k, A[100001];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    cin >> k;
    cout << upper_bound(A, A+n, k) - A+1 << endl;
}
