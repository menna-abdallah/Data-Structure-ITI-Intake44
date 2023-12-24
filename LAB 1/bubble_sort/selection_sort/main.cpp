#include <iostream>
using namespace std;

void printArray(int arr[], int size);
void swap(int &x,int &y);
void selection_sort(int arr[], int n);

//start main
int main() {
    int size = 5;
    int arr[size] = {64, 25, 12, 11, 1};

    cout << "Before ";
    printArray(arr, size);

    selection_sort(arr, size);
        cout << endl;

    cout << "After ";
    printArray(arr, size);

    return 0;
}

//swapfunction
void swap(int &item1,int &item2)
{
    int temp;
    temp = item1;
    item1=item2;
    item2=temp;
}

//sort function
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//print function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
