#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "pruebaclase_imp.h"

int main(int argc, char** argv)
{
    pruebaclase_imp* pclase = new pruebaclase_imp();
    pclase->run();
    delete pclase;

    return 0;
}
