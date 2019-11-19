#ifndef REMOTEFILE_STUB_H
#define REMOTEFILE_STUB_H

#define OP_EXIT 0
#define OP_READFILE 1

#include "mpi_manager.h"


class remotefile_stub
{
    MPI_Comm* comm;

public:
    remotefile_stub(char* ip);

    // Opens file "filename", copies content in "buff"
    void readfile(char* filename, char** buff, unsigned long int* bufflen);
    ~remotefile_stub();
};

#endif // REMOTEFILE_STUB_H
