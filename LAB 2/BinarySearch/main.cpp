#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right)  / 2;

        // is present at the middle
        if (arr[mid] == key)
            return mid;

       // is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;
        // is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // is not present in the array
    return -1;
}


int main() {

    int size;
    int arr[100]={0};
    int key;
    cout << "Enter the size of array : ";
    cin >> size;
    for(int i =0 ; i < size ; i++){
        cout << " enter element "<< i+1 << " : ";
        cin >> arr[i];
    }
    cout << " enter the value you want to search for: ";
    cin >> key;
    int result = BinarySearch(arr , 0 , size -1, key);

    if (result != -1)
        cout << "Element " << key << " found at index " << result << endl;
    else
        cout << "Element " << key << " not found in the array" << endl;

    return 0;
}
