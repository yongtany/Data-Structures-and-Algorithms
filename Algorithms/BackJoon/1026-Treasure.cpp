#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    int n, tmp, min_s = 0;
    vector<int> A, B;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        A.push_back(tmp);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        B.push_back(tmp);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(int i = 0; i < n; i++)
        min_s += A[i] * B[i];

    printf("%d\n", min_s);

    return 0;
}

