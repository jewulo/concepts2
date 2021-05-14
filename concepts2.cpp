// concepts2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.youtube.com/watch?v=8gGeZbr0e7Q

#include <iostream>
#include <concepts>

/*
* concepts enable the following:
* constraints
* associated constraints
* requires-clause
*/

// AllowedType is a concept
template <typename T>
concept AllowedType = std::is_same_v<T, int> || std::is_same_v<T, unsigned>;

// we want to constrain the type of T in class rational

// using a requires clause
namespace using_requires_clause
{
    // class template rational has its associated constraints
    // which is AllowedType<T>, where
    // AllowedType is a concept
    // but AllowedType<T> is a constraint over its template argument T
    template <typename T>
        requires AllowedType<T> // constraint using a requires-clause
    class rational
    {
    private:
        T m_p;  // numerator
        T m_q;  // denominator

    public:
        rational(T p, T q) : m_p(p), m_q(q) {}
    };
}

// using constraints
namespace using_constraint
{
    // AllowedType is called a type concept
    // (AllowedType T) is called a type constraint
    template <AllowedType T>
    class rational
    {
    private:
        T m_p;  // numerator
        T m_q;  // denominator

    public:
        rational(T p, T q) : m_p(p), m_q(q) {}
    };
}


int main()
{
    std::cout << "Hello World!\n";
    using_requires_clause::rational r1{ 3,2 };
    using_requires_clause::rational r2{ 3,2.0 };

    using_constraint::rational r3{ 3,2 };
    using_constraint::rational r4{ 3,2.0 };
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
