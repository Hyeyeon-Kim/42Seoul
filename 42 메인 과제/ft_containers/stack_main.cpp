#include <iostream>
// using namespace std;
// #include <stack>
#include "stack/stack.hpp"

void stack()
{
    ft::stack<int> stack;

    stack.push(32);
    stack.push(2141);
    stack.push(-123);
    stack.push(0);
    stack.push(2131);

    std::cout << "top: " << stack.top() << std::endl;
    std::cout << "size: " << stack.size() << std::endl;

    stack.pop();

    std::cout << "top: " << stack.top() << std::endl;
    std::cout << "size: " << stack.size() << std::endl;


    std::cout << "swap: " << std::endl;
    ft::stack<int> foo,bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push (111); bar.push(222);

    std::cout << "size of foo: " << foo.size() << '\n';
    std::cout << "size of bar: " << bar.size() << '\n';

    foo.swap(bar);

    std::cout << "size of foo: " << foo.size() << '\n';
    std::cout << "size of bar: " << bar.size() << '\n';
}

int main()
{
    stack();
    system("leaks ft_containers");
}