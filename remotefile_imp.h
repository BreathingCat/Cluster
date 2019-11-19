#ifndef REMOTEFILE_IMP_H
#define REMOTEFILE_IMP_H

#include "mpi_manager.h"
#include "remotefile.h"
#include "mpi.h"

class remotefile_imp
{
    remotefile* rfile = nullptr;
    MPI_Comm* comm;
public:
    remotefile_imp();
    void readfile_imp(char* filename, char** buff, int bufflen);
    void run();
    ~remotefile_imp();
};

#endif // REMOTEFILE_IMP_H
