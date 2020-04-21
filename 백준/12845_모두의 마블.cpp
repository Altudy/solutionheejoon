#include <iostream>     // 백준 12845
#include <algorithm>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int* card = new int[n];
    ll gold(0);
    int best(0);

    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
        gold += card[i];
        best = max(best, card[i]);
    }

    gold += best * (n - 2);

    cout << gold;

    return 0;
}
