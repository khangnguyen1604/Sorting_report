#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void heapify(vector<double> &v, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && v[left] > v[largest]) largest = left;
    if (right < n && v[right] > v[largest]) largest = right;
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void hS(vector<double> &v) {
    int n = v.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream output("timeHeapsort.txt");
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
        hS(data);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        output << "Test " << test << ": " << duration.count() << " ms\n";


    }
    output.close();
    return 0;
}
