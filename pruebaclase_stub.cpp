#include "pruebaclase_stub.h"

pruebaclase_stub::pruebaclase_stub(char* ip)
{
	// Initialize MPI Libraries
    MPI_Manager::Init();
    // Adapt in remote to host, needs new PATH to executables of MPI_Manager
    this->comm = MPI_Manager::Instanciate("rpc_pruebaclase", ip);

}

/*
    STUB of pruebaclase::holamundo, communicates with running proccess
    pruebaclase_imp remotely to call its holamundo function
*/
void pruebaclase_stub::holamundo(){

    // SEND OPERATION TYPE
    int op = OP_HOLAMUNDO;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
	
    // RECEIVE ACK
	int ack = 0;
	MPI_Status status;
    MPI_Recv(&ack,1,MPI_INT,0,0,*(this->comm),&status);
	
    // CHECK ACK
	if(ack!=1) std::cout << "ERROR MASTER" << __LINE__ << __FILE__ << std::endl;

}

/*
 * STUB of pruebaclase::suma, sends data to pruebaclase_imp running on
 * remote to perform the operation, and receives the result
*/
int pruebaclase_stub::suma(int a, int b)
{

    // SEND OPERATION TYPE
    MPI_Status status;
	int op = OP_SUMA;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));

    // PARSE PARAMETERS
	int* parameter_array = new int[2];
	parameter_array[0] = a;
	parameter_array[1] = b;
	
    // SEND PARAMETERS
    MPI_Send(parameter_array,2,MPI_INT,0,0,*(this->comm));
	
    // RECEIVE RESULT
    int result = 0;
    MPI_Recv(&result,1,MPI_INT,0,0,*(this->comm),&status);
	
    delete[] parameter_array;
	return result;
	
}

/*
 * Sends termination signal to pruebaclase_imp process running
 * on remote
*/
pruebaclase_stub::~pruebaclase_stub()
{
    // SEND OPERATION TYPE
    int op = OP_EXIT;
    MPI_Send(&op,1,MPI_INT,0,0,*(this->comm));
}
