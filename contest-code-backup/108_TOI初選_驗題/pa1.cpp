// uier
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double x;
    while (cin >> x) {
        int ans = 0;
        for (int i = 0; i < 24 * 60; ++i)
        {
            int y = (i * 12) % 720 - (i) % 720;
            y = (y < 0 ? -y : y);
            if (y == x * 2 || y == (360 - x) * 2)
            {
                //              cout << i/60 << " : " << i%60 << '\n';
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
