#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int employeeId;
    string name;
    int salary;
};

int SearchByName(Employee arr[], int size, const string& targetName) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].name == targetName) {
            return i; //found
        }
    }

    return -1; // not found
}

int SearchById(Employee arr[], int size, int targetId) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].employeeId == targetId) {
            return i; //  found
        }
    }

    return -1; //  not found
}

int SearchBySalary(Employee arr[], int size, double targetSalary) {
    for (int i = 0; i < size; ++i) {
        if (arr[i].salary == targetSalary) {
            return i; //  found
        }
    }

    return -1; //  not found
}

int main() {
    const int size = 5;
    Employee employees[size] = {
        {103, "menna", 5000},
        {101, "aya", 4500},
        {105, "sara", 6000},
        {102, "mona", 5800},
        {104, "yara", 5990}
    };


    string targetName = "mona";
    int resultName = SearchByName(employees, size, targetName);

    if (resultName != -1) {
        cout << "Employee " << targetName << " found at index " << endl;
    } else {
        cout << "Employee " << targetName << " not found" << endl;
    }

    int targetId = 103;
    int resultId = SearchById(employees, size, targetId);

    if (resultId != -1) {
        cout << "Employee with ID " << targetId << " found at index " << resultId << endl;
    } else {
        cout << "Employee with ID " << targetId << " not found " << endl;}

    int targetsalary = 50500.0;
    int resultsalary = SearchBySalary(employees, size, targetsalary);

    if (resultId != -1) {
        cout << "Employee with Salary " << targetsalary << " found at index " << resultsalary <<endl;
    } else {
        cout << "Employee with salary " << targetsalary << " not found " << endl;}
}

