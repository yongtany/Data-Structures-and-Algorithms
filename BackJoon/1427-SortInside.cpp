/* Using STL sort */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[10];

int main(void)
{
    cin >> arr;

    sort(arr, arr+strlen(arr), greater<int>());
    for(int i = 0; i < strlen(arr); i++)
        cout << arr[i];

    return 0;
}

/* using Bubble sort */

// #include <iostream>

// using namespace std;

// void swap(int &n1, int &n2)
// {
//     int tmp;
//     tmp = n1;
//     n1 = n2;
//     n2 = tmp;
// }

// void bubble_sort(int *(&arr), int len)
// {
//     for(int i = 0; i < len - 1; i++) {
//         for(int j = 1; j < len - i; j++) {
//             if(arr[j] > arr[j - 1]) {
//                 swap(arr[j], arr[j-1]);
//             }
//         }
//     }
// }

// void solve(string &str)
// {
//     int len = (int)str.length();
//     int *arr = new int [len];

//     for(int i = 0; i < len; i++)
//         arr[i] = str[i] - '0';


//     bubble_sort(arr, len);

//     for(int i = 0; i < len; i++)
//         printf("%d", arr[i]);

//     delete [] arr;
// }

// int main(void)
// {
//     string str;

//     cin>>str;
//     solve(str);

//     return 0;
// }
