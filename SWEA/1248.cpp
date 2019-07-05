#include <iostream>

using namespace std;

int result;

void subtree(int child[][2], int p)
{
  result++;
  if(child[p][0] == 0)
    return;
  if(child[p][0] > 0)
    subtree(child, child[p][0]);
  if(child[p][1] > 0)
    subtree(child, child[p][1]);
}

int main()
{
  int testcase;
  cin >> testcase;

  while(testcase--)
  {
    int V, E;
    cin >> V >> E;

    int node1, node2;
    cin  >> node1 >> node2;

    int parent[10001] = { 0, };
    int child[10001][2] = { { 0, 0 }, };
    bool visited[10001] = { false, };
    for(int i = 0; i < E; i++) {
      int p, c;
      cin >> p >> c;
      parent[c] = p;
      if(child[p][0] == 0)
        child[p][0] = c;
      else
        child[p][1] = c;
    }

    int temp = node1;
    visited[temp] = true;
    while(temp != 1) {
      temp = parent[temp];
      visited[temp] = true;
    }

    temp = node2;
    while(!visited[temp])
      temp = parent[temp];

    result = 0;
    subtree(child, temp);

    cout << "#" << testcase << " " << temp << " " << result << endl;
  }

  return 0;
}
