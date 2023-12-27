#include <iostream>
using namespace std;
void Merge(int arr[],int start,int mid,int end);
void MergeSort(int arr[],int start,int end);
void printarray(int arr[], int size);

int main (){
    int size = 6;
    int arr[] = {12, 11, 13, 5, 6, 7};

    cout << "Besfore: ";
    printarray(arr,size);

    MergeSort(arr, 0, size - 1);
    cout << endl;
    cout << "After: ";
    printarray(arr,size);

    return 0;
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ,";
    }
}
void Merge(int arr[],int start,int mid,int end) {

    int size1=mid-start+1;
    int size2=end-mid;
    // initialize new 2 arrays
    int* A1=new int [size1];
    int* A2=new int[size2];
    int i,j;
    // copy to the new array
    for(int i=0;i<size1;i++) {
        A1[i]=arr[start+i];
        }
    for(int j=0;j<size2;j++) {
        A2[j]=arr[mid+1+j];
        }

    i=j=0;
    int k=start;
    // start sorting from different 2 arrays
    while((i<size1)&&(j<size2)){
        if(A1[i]<A2[j]) {
            arr[k]=A1[i];
            i++;
             }
        else {
            arr[k]=A2[j];
            j++;
            }
        k++;
        }
        // print the remaining array
    while (i<size1)
    {
        arr[k]=A1[i];
        k++;
        i++;
         }
    while (j<size2) {
        arr[k]=A2[j];
        k++;
        j++;
        }
}

// merge sort with recording
void MergeSort(int arr[],int start,int end){
    if(start<end)
    {
        int mid=(start + end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
}
}
