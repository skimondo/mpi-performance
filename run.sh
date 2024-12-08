#!/bin/bash
#SBATCH --job-name=bench_bcast         # Job name
#SBATCH --output=bench_bcast_%j.out   # Standard output and error log
#SBATCH --ntasks=64                   # Number of tasks
#SBATCH --time=01:00:00               # Time limit hrs:min:sec

echo "Debut $(date)"

# Info: Number of processors for this script
echo "SLURM_NTASKS=$SLURM_NTASKS"

# Run the MPI program using SLURM_NTASKS
mpiexec -n $SLURM_NTASKS ./build/bench_bcast
srun  --ntasks $SLURM_NTASKS ./build/bench_bcast

echo "Fin $(date)"
