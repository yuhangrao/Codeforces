#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;
const int INF = 2000000005;
int ans = INF;

int solve(int n, int cnt) {
  if (memo.count(n)) {
    return memo[n];
  }
  int root = sqrt(n);
  if (n > 0 and root * root == n) {
    memo[n] = cnt;
    return cnt;
  }
  string ns = to_string(n);
  for (int i = 0; i < ns.size(); i++) {
    string ms = ns.substr(0, i) + ns.substr(i + 1);
    if (ms == "") {
      break;
    }
    int skip = 0;
    for (int i = 0; i < ms.size(); i++) {
      if (ms[i] == '0') {
        skip++;
      } else {
        break;
      }
    }
    int m = stoi(ms);
    ans = min(ans, solve(m, skip + cnt + 1));
  }
  return min(ans, INF);
}

int main() {
  int n;
  cin >> n;
  int ans = solve(n, 0);
  if (ans == INF) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
