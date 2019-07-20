#include <bits/stdc++.h>
using namespace std;

struct Cat {
  string name, identity;
  int age;
};

const string P[] = {
  "elder", "nursy", "kit", "warrior",
  "appentice", "medicent", "deputy", "leader"};

bool operator<(const Cat& a, const Cat& b) {
  int ap, bp; // priority
  for (int i=0; i<8; i++) {
    if (a.identity == P[i])
      ap = i;
    if (b.identity == P[i])
      bp = i;
  }

  if (ap != bp) {
    return ap < bp;
  } else if (a.age != b.age) {
    if (ap == 4)
      return a.age < b.age;
    else
      return a.age > b.age;
  } else {
    return a.name < b.name;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  while (cin >> n >> m) {
    vector<Cat> cats;
    for (int i=0; i<n; i++) {
      Cat c;
      cin >> c.name >> c.identity >> c.age;
      cats.push_back(c);
    }

    sort(cats.begin(), cats.end());

    for (int i=0; i<min(n, m); i++)
      cout << cats[i].name << endl;
  }

  return 0;
}