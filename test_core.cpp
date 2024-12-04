#include <mpi.h>

#include <iostream>

#include "dvec.h"

void test_dvec_bcast_lib() {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  struct dvec v;
  dvec_init(&v, 10);
  dvec_bcast_lib(&v);
  dvec_dump(&v);

  if (!dvec_ok(&v)) {
    std::printf("%d Erreur valeur dvec", rank);
    MPI_Abort(MPI_COMM_WORLD, 99);
  }

  if (rank == 0) {
    std::printf("%d PASS bcast_lib\n", rank);
  }
}

void test_dvec_bcast_seq() {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  struct dvec v;
  dvec_init(&v, 10);
  dvec_bcast_seq(&v);
  dvec_dump(&v);

  if (!dvec_ok(&v)) {
    std::printf("%d Erreur valeur dvec", rank);
    MPI_Abort(MPI_COMM_WORLD, 99);
  }

  if (rank == 0) {
    std::printf("%d PASS bcast_seq\n", rank);
  }
}

int main(int argc, char** argv) {
  int rank;
  int size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (size == 1) {
    std::printf("Erreur: lancer avec au moins deux processeurs");
    MPI_Abort(MPI_COMM_WORLD, 99);
  }

  if (rank == 0) {
    std::printf("TEST dvec_bcast_lib\n");
  }
  test_dvec_bcast_lib();

  if (rank == 0) {
    std::printf("TEST dvec_bcast_seq\n");
  }
  test_dvec_bcast_seq();

  if (rank == 0) {
    std::printf("%d Fin normale\n", rank);
  }
  MPI_Finalize();
  return 0;
}
