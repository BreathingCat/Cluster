#ifndef PRUEBACLASE_STUB_H
#define PRUEBACLASE_STUB_H

#define OP_EXIT 0
#define OP_HOLAMUNDO 1
#define OP_SUMA      2

#include "mpi.h"
#include "mpi_manager.h"

class pruebaclase_stub
{
    // "Master" process communicator to interact with the
    // pruebaclase_imp running remotely
    MPI_Comm* comm;
public:
    pruebaclase_stub(char* ip);
    void holamundo();
    int suma(int a, int b);
    ~pruebaclase_stub();
};

#endif // PRUEBACLASE_STUB_H
