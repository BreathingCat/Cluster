#include "remotefile_imp.h"
#include "remotefile_stub.h"

remotefile_imp::remotefile_imp(){
    // Initialize MPI Libraries
    MPI_Manager::Init();
    this->comm = new MPI_Comm[1];
    MPI_Comm_get_parent(this->comm);
    this->rfile = new remotefile();
}

void remotefile_imp::run(){
    bool exit = false;

    while(!exit){
        int op = -1;
        MPI_Status status;
        MPI_Recv(&op,1,MPI_INT,0,0,*(this->comm),&status);

        switch(op){
            case OP_READFILE:{
                // RECEIVE SIZE OF BUFFER
                unsigned long int fileLen = 0;
                MPI_Recv(&fileLen, 1, MPI_LONG_INT, 0, 0, *(this->comm), &status);

                // RECEIVE FILENAME
                char* filename = new char[fileLen];
                MPI_Recv(filename, fileLen, MPI_CHAR, 0, 0, *(this->comm), &status);

                // EXECUTE OPERATION
                char* buff = NULL;
                unsigned long int bufflen = 0;

                this->rfile->readfile(filename, &buff, &bufflen);

                // SEND BUFFER SIZE
                MPI_Send(&bufflen,1,MPI_INT,0,0,*(this->comm));

                // SEND DATA
                MPI_Send(buff,bufflen,MPI_CHAR,0,0,*(this->comm));

                break;

            }

            case OP_EXIT:{
                exit = true;
                break;
            }

            default:
                std::cout << "ERROR SLAVE: Not supported operation " << __LINE__  << __FILE__ << std::endl;
                break;

        }
    }
}

remotefile_imp::~remotefile_imp(){
    MPI_Manager::Finalize();
    delete this->rfile;
    delete[] this->comm;
}
