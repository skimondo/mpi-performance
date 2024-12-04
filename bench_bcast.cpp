#include <mpi.h>

#include <chrono>
#include <iostream>

#include "dvec.h"

typedef void (*bcast_op_t)(struct dvec* v);

double BM_Bcast(int n, int repeat, bcast_op_t bcast) {
  struct dvec v;
  dvec_init(&v, n);
  auto t1 = std::chrono::steady_clock::now();
  for (int i = 0; i < repeat; i++) {
    bcast(&v);
  }
  auto t2 = std::chrono::steady_clock::now();
  dvec_free(&v);
  return std::chrono::duration<double>(t2 - t1).count() / repeat;
}

int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);

  int rank;
  int size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int max_data = (1 << 20);
  for (int data_size = 1; data_size <= max_data; data_size *= 2) {
    double temps_lib = BM_Bcast(data_size, 10, dvec_bcast_lib);
    double temps_seq = BM_Bcast(data_size, 10, dvec_bcast_seq);
    if (rank == 0) {
      std::cout << size << " " << data_size << " " << temps_lib << " " << temps_seq << "\n";
    }
  }

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}
