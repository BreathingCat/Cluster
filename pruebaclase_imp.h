#ifndef PRUEBACLASE_IMP_H
#define PRUEBACLASE_IMP_H
#include "pruebaclase.h"
#include "mpi_manager.h"

class pruebaclase_imp
{
    MPI_Comm* comm;
    pruebaclase* pclase=nullptr;
public:
    pruebaclase_imp();
    void run();
    ~pruebaclase_imp();
};

#endif // PRUEBACLASE_IMP_H
