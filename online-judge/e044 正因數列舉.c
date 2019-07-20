#include <iostream>
#include <iterator>
#include <deque>
#include <cmath>

using namespace std;


deque<int> get_factors(int num) {
  deque<int> factors; // ascending

  for (int i=sqrt(num); i>=1; i--) {
    if (num % i == 0) {
      factors.push_front(i);

      // avoid duplicate factors with square numbers
      if (num != i*i) {
        factors.push_back(num / i);
      }
    }
  }

  return factors;
}

int main() {
  int n;
  cin >> n;

  deque<int> factors = get_factors(n);

  if (factors.empty()) {
    cout << "Prime";
  } else {
    copy(factors.rbegin()+1, factors.rend()-1, ostream_iterator<int>(cout, " "));
  }

  cout << endl;

  return 0;
}