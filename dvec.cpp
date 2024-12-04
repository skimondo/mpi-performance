#include "dvec.h"

#include <mpi.h>

#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>

void dvec_init(dvec* v, int n) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  v->data = new int[n];
  v->n = n;

  // le rank 0 initialise les données à diffuser
  if (rank == 0) {
    std::iota(v->data, v->data + n, 1);
  } else {
    std::fill(v->data, v->data + n, 0);
  }
}

void dvec_free(dvec* v) {
  delete[] v->data;  //
}

bool dvec_ok(dvec* v) {
  for (int i = 0; i < v->n; i++) {
    if (v->data[i] != i + 1) {
      return false;
    }
  }
  return true;
}

void dvec_dump(dvec* v) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::ostringstream oss;
  oss << std::setw(3) << std::setfill('0') << "dvec_dump_" << rank << ".dat";
  std::ofstream ofs(oss.str());
  for (int i = 0; i < v->n; i++) {
    ofs << v->data[i] << "\n";
  }
}

/*
 * Méthode point-à-point: MPI_Send() et MPI_Recv()
 */
void dvec_bcast_seq(dvec* v) {
  // À COMPLÉTER
}

/*
 * Méthode collective: MPI_Bcast()
 */
void dvec_bcast_lib(dvec* v) {
  // À COMPLÉTER
}

