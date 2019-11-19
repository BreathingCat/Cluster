#include "pruebaclase_imp.h"
#include "pruebaclase_stub.h"

pruebaclase_imp::pruebaclase_imp(){
	// Initialize MPI Libraries
    MPI_Manager::Init();
    this->comm = new MPI_Comm[1];
    MPI_Comm_get_parent(this->comm);
    this->pclase = new pruebaclase();
}

void pruebaclase_imp::run(){
	bool exit = false;
	
	while(!exit){
		int op = -1;
		MPI_Status status;
        MPI_Recv(&op,1,MPI_INT,0,0,*(this->comm),&status);
		
		switch(op){
			case OP_HOLAMUNDO:{
				pclase->holamundo();
				
				int ack = 1;
                MPI_Send(&ack,1,MPI_INT,0,0,*(this->comm));
				
				break;	
			}
				
			case OP_SUMA:{
				int* data = new int[2];
                MPI_Recv(data,2,MPI_INT,0,0,*(this->comm),&status);
				
				int result = pclase->suma(data[0],data[1]);
                MPI_Send(&result,1,MPI_INT,0,0,*(this->comm));
				
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

pruebaclase_imp::~pruebaclase_imp(){
    MPI_Manager::Finalize();
	delete pclase;
    delete[] this->comm;
}
