#include "my_lib.h"
#include <iostream>

int print_hello_world()
{
    std::cout << "Cout: Hello World" << '\n';

    // Adress Sanitizer should see this :)

    return 1;
}

unsigned int factorial(unsigned int number)
{
    return number <= 1 ? 1 : factorial(number - 1) * number;
}
