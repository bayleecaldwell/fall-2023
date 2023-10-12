#include <iostream>
#include <vector>

std::vector<int *> *leakMemory() {
    std::vector<int *> *buffer = new std::vector<int *>;
    for (int i = 0; i < 10; i++) {
        buffer->push_back(new int[100000]);
    }
    return buffer;
}

void mistake1() {
    std::cout << "Mistake 1: Use an Uninitialized Pointer or a nullptr "
              << std::endl;
    int *aIntPtr;
    int n = *aIntPtr;
    std::cout << n << std::endl;
    aIntPtr = nullptr;
    std::cout << *aIntPtr << std::endl;
}

void mistake2() {
    std::cout << "Mistake 2: Forgetting You're Doing Arrays" 
              << std::endl;
    const unsigned int ARRAYSIZE = 100;
    int *ptrToIntArray = new int[ARRAYSIZE];
    std::cout << "Do some really interesting array sort of arrays." 
              << std::endl;
    delete ptrToIntArray;
    int aUsefulInteger = 42;
    int *anotherPtrInt = &aUsefulInteger;
    std::cout << "And some more interesting things." << std::endl;
    delete [] anotherPtrInt;
}

void mistake3() {
    std::cout << "Mistake 3: Assigning a ptr to an uninitialized variable " 
              << std::endl;
    int * p1;
    int m;
    p1 = &m; // Set pointer to address of uninitialized variable
    int n = *p1;
    std::cout << n << std::endl;
}

std::vector<int> &badReturn() {
    std::vector<int> aBuffer;
    aBuffer.push_back(3);
    aBuffer.push_back(4);
    return aBuffer;
}

void mistake4() {
    std::cout << "Mistake 4: Returning a Reference to a Local Object"
              << std::endl;
    std::vector<int> &aBuffer = badReturn();
    std::cout << aBuffer[0] << aBuffer[1] << std::endl;
}

void mistake5() {
    std::cout << "Mistake 5: Memory Leak By Forgetting To Delete" << std::endl;
    std::vector<int *> *ourBuffer = new std::vector<int *>;
    for (int i = 0; i < 10; i++) {
        ourBuffer = leakMemory();
    }
    std::cout << "Now don't do any deleting, just return to called" <<std::endl;
}

int main() {
    std::cout << "Hello, World!\n";
    mistake1();
    mistake2();
    mistake3();
    mistake4();
    mistake5();
    return 0;
}
