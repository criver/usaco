/*
ID: nathan.18
TASK: game1
LANG: C++11
*/

#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <unordered_set>

using namespace std;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0R1(i, a) for (int i=1; i<=(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define F0Rd1(i, a) for (int i=a; i>0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000010
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define pA first
#define pB second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
#define MOD (int)(2e+9+11)
#define SET(vec, val, size) for (int i = 0; i < size; i++) vec[i] = val;
#define SET2D(arr, val, dim1, dim2) F0R(i, dim1) F0R(j, dim2) arr[i][j] = val;
#define SET3D(arr, val, dim1, dim2, dim3) F0R(i, dim1) F0R(j, dim2) F0R(k, dim3) arr[i][j][k] = val;
#define READGRID(arr, dim) F0R(i, dim) F0R(j, dim) cin >> arr[i][j];
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

int dp[250][250];
int A[250];

int solve(int l, int r) {
    if (l == r) {
        return A[l];
    } else if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(min(solve(l+2, r), solve(l+1, r-1)) + A[l], min(solve(l+1, r-1), solve(l, r-2)) + A[r]);
}

int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);

    int n; cin >> n;
    F0R(i, n) cin >> A[i];
    SET2D(dp, -1, 250, 250);

    int sum = 0;
    F0R(i, n) sum += A[i];

    cout << solve(0, n-1) << " " << sum - solve(0, n-1) << endl;

    return 0;
}
