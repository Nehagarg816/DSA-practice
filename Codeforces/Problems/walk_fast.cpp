#include <bits/stdc++.h>
using namespace std;

long long solve(int start, int end, int P, const vector<int> &positions)
{
    return abs(positions[start - 1] - positions[end - 1]) * P;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, A, B, C, D, P, Q, Y;
        cin >> N >> A >> B >> C >> D >> P >> Q >> Y;
        vector<int> positions(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> positions[i];
        }
        long long walk = solve(A, B, P, positions);
        long long train = LLONG_MAX;
        long long reach = solve(A, C, P, positions);

        if (reach <= Y)
        {
            long long travel = abs(positions[C - 1] - positions[D - 1]) * Q;
            long long travelB = solve(D, B, P, positions);

            train = max(reach, (long long)Y) + travel + travelB;
        }
        cout << min(walk, train) << endl;
    }
    return 0;
}