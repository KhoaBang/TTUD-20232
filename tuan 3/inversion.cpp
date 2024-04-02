#include <iostream>
using namespace std;

int n;
int* arr;
const unsigned int M = 1000000007;
long long merge(int left, int right, int mid) {
    long long count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* LA = new int[n1];
    int* RA = new int[n2];

    for (int i = 0; i < n1; i++) {
        LA[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        RA[j] = arr[mid + 1 + j];
    }

    int x = 0, y = 0, k = left;
    while (x < n1 && y < n2) {
        if (LA[x] <= RA[y]) {
            arr[k] = LA[x];
            x++;
        }
        else {
            arr[k] = RA[y];
            count += (n1 - x);  // Increment count when merging from the right array.
            y++;
        }
        k++;
    }

    while (x < n1) {
        arr[k] = LA[x];
        x++;
        k++;
    }
    while (y < n2) {
        arr[k] = RA[y];
        y++;
        k++;
    }

    delete[] LA;
    delete[] RA;

    return count;
}

long long mergesort(int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inv_count = mergesort(left, mid);
        inv_count += mergesort(mid + 1, right);
        inv_count += merge(left, right, mid);
    }
    return inv_count;
}

int main() {
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long inversionCount = mergesort(0, n - 1);
    cout <<  inversionCount%M;

    delete[] arr;

    return 0;
}
