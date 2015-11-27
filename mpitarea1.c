#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <mpi.h>


int main(int argc, char **argv){
  int my_rank, p, tag=0;
    int dest, source;
  char outmsg[20], inmsg[20];
  
  
  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  if(my_rank == 0){
    dest=1;
    source=1;
    
    strcpy(outmsg, "Hello");
    MPI_Send(&outmsg, strlen(outmsg)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD );
    MPI_Recv(&inmsg, 20, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
    printf("Message received: %s said %d\n", inmsg , my_rank);
  
  } else if (my_rank == 1) {
    dest=0;
    source=0;
    int i;
    
    MPI_Recv(outmsg, 20, MPI_CHAR, source, tag, MPI_COMM_WORLD, &status);
    printf("Message received, said: %d\n", my_rank );
 
 for(i=0; i<=strlen(outmsg);i++){
   if(outmsg[i]>=97 && outmsg[i]<=122)
     outmsg[i]=outmsg[i]-32;
 }
 strcpy(inmsg, outmsg);
    MPI_Send(inmsg, strlen(inmsg)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD );
    
  }
  MPI_Finalize();
  
}
