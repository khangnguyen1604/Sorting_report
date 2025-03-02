#include <bits/stdc++.h>

using namespace std;
const int MX = 1e6;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int test = 1; test <= 10; test++){
        string name = "test" + to_string(test);
        ofstream file(name + ".txt");
        vector <double> v(MX);
        for (int i = 0; i < MX; i++){
            v[i] = (rd() % (int)1e6) / 10.0;
        }
        if (test == 1) sort(v.begin(), v.end());
        if (test == 2) sort(v.begin(), v.end(), greater <double>());
        for (int i = 0; i < MX; i++){
            if (i < MX - 1) file << v[i] << ' ';
            else file << v[i];
        }
    }
    return 0;
}
