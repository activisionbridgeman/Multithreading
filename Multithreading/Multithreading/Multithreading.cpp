// Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

bool DidQuit = false;
int ThreadVar = 0;

void HelloWorldThread() 
{
    while (!DidQuit)
    {
        ThreadVar++;
        if (ThreadVar > 1000) 
        {
            ThreadVar = 0;
        }
    }
}

int main()
{
    std::cout << "hello world\n";
    char userInput;
    std::thread Hello(HelloWorldThread);

    while (!DidQuit)
    {
        std::cout << "enter any key to display counter\n";
        std::cout << "q to quit\n";
        std::cin >> userInput;
        DidQuit = (userInput == 'q');
        std::cout << "ThreadVar: " << ThreadVar << '\n';
    }
    Hello.join();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
