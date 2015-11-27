#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){
  int my_rank, tag=0;
  char recvbuf[20], sendbuf[20];
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  if(my_rank == 0){
    strcpy(recvbuf, "Hello");
    strcpy(sendbuf, "Hello");
    MPI_Recv(recvbuf, strlen(recvbuf)+1, MPI_CHAR, 1, tag, MPI_COMM_WORLD, &status );
    MPI_Send(sendbuf, strlen(sendbuf)+1,MPI_CHAR,1,tag,MPI_COMM_WORLD );
    
  
  } else if (my_rank == 1) {
    strcpy(recvbuf, "Hello");
    strcpy(sendbuf, "Hello");
    MPI_Recv(recvbuf, strlen(recvbuf)+1, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status );
    MPI_Send(sendbuf, strlen(sendbuf)+1,MPI_CHAR,0,tag,MPI_COMM_WORLD );
  }
  MPI_Finalize();
  
}
