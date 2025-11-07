#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxi) maxi = arr[i];

    vector<int> count(maxi + 1, 0);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxi; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

int main() {
    int n;
    cin >> n;
  int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    countingSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
