#include <iostream>

#include "Foo.hpp"
#include "Text.hpp"

int main(int, char**)
{
    std::cout << "Hello\n";
    Foo_t foo{3};
    foo.say();

    Text_t text{"Hola!"};
    text.say();

    Foo_t hoo{2, "Cola"};
    hoo.sayText();

    return 0;
}