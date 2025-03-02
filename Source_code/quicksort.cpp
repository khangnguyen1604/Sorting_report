#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int parti(vector<double> &v, int l, int r) {
    double pivot = v[(l + r) / 2];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);
    return (i + 1);
}

void qS(vector<double> &v, int l, int r) {
    if (l < r) {
        int p = parti(v, l, r);
        qS(v, l, p - 1);
        qS(v, p + 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream output("timeQuicksort.txt");
    for (int test = 1; test <= 10; test++) {
        string filename = "test" + to_string(test) + ".txt";
        ifstream file(filename);
        vector<double> data;
        double x;
        while (file >> x) {
            data.push_back(x);
        }
        file.close();
        auto start = high_resolution_clock::now();
        qS(data, 0, (int)data.size() - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        output << "Test " << test << ": " << duration.count() << " ms\n";
    }
    output.close();
    return 0;
}
