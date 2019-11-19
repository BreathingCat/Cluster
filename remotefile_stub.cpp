#include "remotefile_stub.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

remotefile_stub::remotefile_stub(char* ip)
{
    // INITIALIZE AND INSTANCIATE
    MPI_Manager::Init();
    this->comm = MPI_Manager::Instanciate("rpc_remotefile", ip);

}

void remotefile_stub::readfile(char *filename, char **buff, unsigned long int* bufflen)
{

    // SEND OPERATION TYPE
    MPI_Status status;
    int op = OP_READFILE;
    MPI_Send(&op, 1, MPI_INT, 0, 0, *(this->comm));

    // SEND PARAMETERS
    unsigned long int fileLen = strlen(filename) + 1;
    MPI_Send(&fileLen, 1, MPI_LONG_INT, 0, 0, *(this->comm));
    MPI_Send(filename, fileLen, MPI_CHAR, 0, 0, *(this->comm));

    //  RECEIVE SIZE
    MPI_Recv(bufflen, 1, MPI_LONG_INT, 0, 0, *(this->comm), &status);

    //  ALLOCATE MEMORY FOR BUFFER
    *buff = new char[*bufflen + 1];

    // RECEIVE DATA
    MPI_Recv(*buff, *bufflen, MPI_CHAR, 0, 0, *(this->comm), &status);

}

remotefile_stub::~remotefile_stub()
{
    int op = OP_EXIT;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
}

