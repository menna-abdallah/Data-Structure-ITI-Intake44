#include <iostream>
#include<string>
using namespace std;

void printArray(string arr[], int size);
void swap(string &x,string &y);
void selection_sort(string arr[], int n);

//start main
int main() {
    int size = 5;
    string arr[size] = {"Ali" , "Ahmed","Menna","Sally","iren"};

    cout << "Before ";
    printArray(arr, size);

    selection_sort(arr, size);
        cout << endl;

    cout << "After ";
    printArray(arr, size);

    return 0;
}

//swapfunction
void swap(string &item1,string &item2)
{
    string temp;
    temp = item1;
    item1=item2;
    item2=temp;
}

//sort function
void selection_sort(string arr[], int n) {
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
void printArray(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " :";
    }
}
