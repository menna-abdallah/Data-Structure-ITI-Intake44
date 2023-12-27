#include <iostream>
using namespace std;

int sentinelLinear(int arr[], int size, int target);
int main() {
    int size = 6;
    int arr[] = {2, 3, 4, 10, 40};
    int target = 10;
    int result = sentinelLinear(arr, size, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result;
    else
        cout << "Element " << target << " not found";

    return 0;
}
int sentinelLinear(int arr[], int size, int key) {
    int last = arr[size - 1];
    arr[size - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    arr[size - 1] = last;

    if (i < size - 1 || arr[size - 1] == key) {
        return i;
    } else {
        return -1;
    }
}
