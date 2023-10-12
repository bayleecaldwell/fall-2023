#include <iostream>
#include <vector>
#include <string>


template <typename T>
void printAVec(const std::vector<T>& aVector) {
    for (const auto& aThing : aVector) {
        std::cout << aThing << " ";
    }
    std::cout << std::endl;
}


template <typename T>
void swap(T& item1, T& item2) {
    T temp = item1;
    item1 = item2;
    item2 = temp;
}


template <typename T>
void bubbleSort(std::vector<T>& data) {
    int maxElement;
    int index;
    for (maxElement = data.size() - 1; maxElement > 0; maxElement--) {
        for (index = 0; index < maxElement; index++) {
            if (data[index] > data[index + 1]) {
                swap(data[index], data[index + 1]);
            }
        }
    }
}

// Employee structure
struct Employee {
    int empId;
    std::string name;

    Employee(int id, std::string empName) : empId(id), name(empName) {}

    
    inline bool operator<(const Employee& anotherEmp) const {
        return empId < anotherEmp.empId;
    }

    inline bool operator>(const Employee& anotherEmp) const {
        return empId > anotherEmp.empId;
    }

    inline bool operator==(const Employee& anotherEmp) const {
        return empId == anotherEmp.empId;
    }

    
    friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
};


std::ostream& operator<<(std::ostream& out, const Employee& emp) {
    out << " Employee Name: " << emp.name << std::endl;
    out << " Id Number:      " << emp.empId << std::endl;
    out << std::endl;
    return out;
}

int main() {
    
    std::vector<int> intVector = {4, 2, 7, 1, 9};
    std::cout << "Original Integer Vector: ";
    printAVec(intVector);
    bubbleSort(intVector);
    std::cout << "Sorted Integer Vector:   ";
    printAVec(intVector);

    
    std::vector<double> doubleVector = {3.14, 1.1, 2.2, 0.5, 4.0};
    std::cout << "\nOriginal Double Vector:  ";
    printAVec(doubleVector);
    bubbleSort(doubleVector);
    std::cout << "Sorted Double Vector:    ";
    printAVec(doubleVector);

    
    std::vector<Employee> employeeVector = {
        Employee(101, "John"),
        Employee(102, "Alice"),
        Employee(100, "Bob"),
    };
    std::cout << "\nOriginal Employee Vector:\n";
    for (const auto& emp : employeeVector) {
        std::cout << emp;
    }
    bubbleSort(employeeVector);
    std::cout << "Sorted Employee Vector:\n";
    for (const auto& emp : employeeVector) {
        std::cout << emp;
    }

    return 0;
}
