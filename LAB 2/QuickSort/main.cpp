#include <iostream>
using namespace std;

void printarray(int arr[], int size);
void swap (int &item1,int &item2);
int Partition (int arr[],int Lower,int Upper);
void QuickSort(int arr[],int Low,int Up);

int main (){

    int size = 6;
    int arr[] = {12, 11, 13, 5, 6, 7};

    cout << "Before : ";
    printarray(arr,size);
    cout << endl;
    QuickSort(arr, 0, size-1);
      cout << "After : ";
     printarray(arr,size);
     return 0;

}

// print function
void printarray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ,";
    }
}

// get partionLocation
int Partition (int arr[],int Lower,int Upper){
    int Start,End,Pivot;
    Pivot=Lower;
    Start=Lower;
    End=Upper;
    while (Start < End)
    {
        while(arr[Start] <= arr[Pivot]){
            Start++;
        }
        while (arr[End] > arr[Pivot]){
        End--;
        }
        if(Start < End){
            swap(arr[Start],arr[End]);
         }
    }
    swap(arr[Pivot],arr[End]);
    return End;
}

// swap
void swap (int &item1,int &item2)
{
    int temp;
    temp = item1;
    item1=item2;
    item2=temp;
}

// quickSort with recurion
void QuickSort(int arr[],int Low,int Up)
{
    if(Low < Up)
    {
        int partition_location=Partition (arr,Low,Up);
        QuickSort(arr,Low,partition_location-1);
        QuickSort(arr,partition_location+1,Up);
    }
}
