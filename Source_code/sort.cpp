#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream output("timesort.txt");
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
        sort(data.begin(), data.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        output << "Test " << test << ": " << duration.count() << " ms\n";

    }
    output.close();
    return 0;
}
