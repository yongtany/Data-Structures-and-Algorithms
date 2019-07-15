#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
}map[10];
int visit[10];
int startX, startY, endX, endY;
int minVal = 2123456789;
int n;

void problem() {
	cin >> n;
	cin >> startX >> startY;
	cin >> endX >> endY;
	for (int i = 0; i < n; i++) {
		cin >> map[i].x >> map[i].y;
	}
}

void dfs(int depth, int x, int y, int sum) {
	if (depth == n) {
		sum += (abs(endX - x) + abs(endY - y));
		minVal = min(minVal, sum);
		sum -= (abs(endX - x) + abs(endY - y));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(depth + 1, map[i].x, map[i].y, (sum + abs(map[i].x - x) + abs(map[i].y - y)));
			visit[i] = 0;
		}
	}
}

void solve() {
	dfs(0, startX, startY, 0);
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		problem();
		solve();
		cout << "#" << tc << " " << minVal << endl;
		minVal = 2123456789;
	}
	return 0;
}
