#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void merge(vector<double>& arr, vector<double>& temp, int left, int mid, int right) {
    if (arr[mid] <= arr[mid + 1]) return;

    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    copy(temp.begin() + left, temp.begin() + right + 1, arr.begin() + left);
}

void mergeSort(vector<double>& arr, vector<double>& temp, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ofstream output("timeMergeSort.txt");

    for (int test = 1; test <= 10; test++) {
        string filename = "test" + to_string(test) + ".txt";
        ifstream file(filename);

        vector<double> data;
        double x;
        while (file >> x) {
            data.push_back(x);
        }
        file.close();

        vector<double> temp(data.size());
        auto start = high_resolution_clock::now();
        mergeSort(data, temp, 0, (int)data.size() - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        output << "Test " << test << ": " << duration.count() << " ms\n";
    }
    output.close();
    return 0;
}
