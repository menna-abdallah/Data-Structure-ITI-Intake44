#include <iostream>
#include <string>

using namespace std;

// struct defintion
struct Employee {
    int employeeID;
    string name;
    double salary;
};


void printEmployees(Employee arr[], int size);
void swap (int &item1,int &item2);
void bubbleSort(Employee arr[], int size);

//start main
int main() {
    const int size = 5; // Change the size according to your array
    Employee employees[size] = {
        {103, "menna", 5000.0},
        {101, "aya", 4500.0},
        {105, "sara", 6000.0},
        {102, "mona", 5800.0},
        {104, "yara", 5990.0}
    };

    cout << "Before:" << endl;
    printEmployees(employees, size);


    bubbleSort(employees, size);
    cout<< endl;

    cout << "After" << endl;
    printEmployees(employees, size);

    return 0;
}
// print fuction
void printEmployees(Employee arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout <<" " << arr[i].employeeID <<" :" << arr[i].name << ": "<< arr[i].salary << endl;
    }
}
// swap function
void swap (Employee &item1,Employee &item2)
{
    Employee temp;
    temp = item1;
    item1=item2;
    item2=temp;
}
// sort function
void bubbleSort(Employee arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // Compare based on employee ID (you can change the comparison criteria)
            if (arr[j].employeeID > arr[j + 1].employeeID) {
                // Swap the employees
                swap(arr[j],arr[j + 1]);
            }
        }
    }
}

