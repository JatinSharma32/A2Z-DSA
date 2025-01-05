#include <iostream>
using namespace std;

/**
 * Detailed Explanation of Variadic Templates
 *
 * Base Case: The base case function template template <typename T> void
 * printEverything(T arg1) is called when there is only one argument left.
 * This function prints the argument and ends the recursion.
 *
 * Recursive Case: The recursive case function template template <typename T,
 * typename... ArgumentList> void printEverything(T arg1, ArgumentList... args)
 * is called when there are multiple arguments. It prints the first argument and
 * then recursively calls itself with the remaining arguments.
 *
 * Variadic Templates: The ... (ellipsis) in typename... ArgumentList and args...
 * indicates that this is a variadic template, which can accept an arbitrary
 * number of template parameters and function arguments.
 */

template <typename T>
void printEverything(T arg1)
{
    cout << arg1 << "\n";
}
template <typename T, typename... ArgumentList>
void printEverything(T arg1, ArgumentList... args)
{
    cout << arg1 << " ";
    printEverything(args...);
}

int main()
{
    cout << "Argument List: ";
    printEverything(5, 2.41312, "fdkjls", 'c', true);
    return 0;
}