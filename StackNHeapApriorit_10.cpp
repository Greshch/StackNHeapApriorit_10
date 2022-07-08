// StackNHeapApriorit_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows headers

#include <windows.h>

struct Worker
{
    int id;
    double salary;
};

int main()
{
    srand(time(0));
    const int minSalary = 9000;
    const int maxSalary = 45000;
    const int length = 10000;

    DWORD64 start = GetTickCount64();
    for (int i = 0; i < length; i++)
    {
        Worker worker;
        worker.id = i + 1;
        worker.salary = 1.0 * minSalary + rand() % (maxSalary - minSalary + 1);
    }
    DWORD64 finish = GetTickCount64();
    std::cout << "Stack's time : " << finish - start << "\n";

    start = GetTickCount64();
    for (int i = 0; i < length; i++)
    {
        Worker* worker = static_cast<Worker*>(malloc(sizeof worker));
        if (worker != NULL)
        {
            worker->id = i + 1;
            worker->salary = 1.0 * minSalary + rand() % (maxSalary - minSalary + 1);
        }
        free(worker);
    }
    finish = GetTickCount64();
    std::cout << "Heap's time : " << finish - start << "\n";
}

 