#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> left, vector<int> right, int *comp, int *inv) {
    vector<int> merged(left.size() + right.size());
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < left.size() && j < right.size();) {
        if (left[i] < right[j]) {
            merged[k++] = left[i++];
        } else {
            merged[k++] = right[j++];
            (*inv) = (*inv) + left.size() - i;
        }
        (*comp)++;
    }
    while (i < left.size()) merged[k++] = left[i++];
    while (j < right.size()) merged[k++] = right[j++];
    return merged;
}

vector<int> merge_sort(vector<int> v, int *comp, int *inv) {
    if (v.size() == 1) {
        return v;
    }
    int mid = v.size() / 2;
    vector<int> left(mid);
    vector<int> right(v.size() - mid);
    for (int i = 0; i < mid; i++) left[i] = v[i];
    for (int i = mid; i < v.size(); i++) right[i - mid] = v[i];
    vector<int> left2 = merge_sort(left, comp, inv);
    vector<int> right2 = merge_sort(right, comp, inv);
    vector<int> ans = merge(left2, right2, comp, inv);
    return ans;
}

int main() {


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int comparisions=0, inversions=0;
        vector<int> sarr = merge_sort(arr, &comparisions, &inversions);
        for (int i = 0; i < sarr.size(); i++) {
            cout << sarr[i] << " ";
        }
        cout << "\n";
        cout << "comparisions = " << comparisions << "\n";
        cout << "inversions = " << inversions << "\n";
    }
    return 0;
}