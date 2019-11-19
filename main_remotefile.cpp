#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "remotefile_imp.h"

int main(int argc, char** argv)
{
    remotefile_imp* pclase = new remotefile_imp();
    pclase->run();
    delete pclase;

    return 0;
}
