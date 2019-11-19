#ifndef MPI_MANAGER_H
#define MPI_MANAGER_H

#include <vector>
#include "mpi.h"

class MPI_Manager{
private:
    static std::vector<MPI_Comm*> comms;
    static bool init;

public:
    MPI_Manager();
    static void Init();
    static void Finalize();
    // Returns Comm of process Init after main
    static MPI_Comm* Instanciate(char* processName, char* ip);
};

#endif // MPI_MANAGER_H
