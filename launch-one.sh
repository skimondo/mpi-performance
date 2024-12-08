#!/bin/bash
#SBATCH --job-name=work
#SBATCH --output=stdout_%j.out
#SBATCH --time=01:00:00

echo "Debut $(date)"

# Info: Nombre de processeurs pour ce script
echo "SLURM_NTASKS=$SLURM_NTASKS"

# Pas besoin de specifier encore --ntasks, srun le fait automatiquement
srun echo "Exécution sur $(hostname)" > work_$(printf "%03d" ${SLURM_NTASKS}).out
srun  --ntasks $SLURM_NTASKS ./build/bench_bcast

echo "Fin $(date)"
