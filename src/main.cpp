#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <pqxx/pqxx>


int main(void) {
    char buffer_in [256] = {"Conan is a MIT-licensed, Open Source package manager for C and C++ development, "
                            "allowing development teams to easily and efficiently manage their packages and "
                            "dependencies across platforms and build systems."};
    char buffer_out [256] = {0};

    printf("pqxx VERSION: %s\n", PQXX_VERSION);

    return EXIT_SUCCESS;
}
