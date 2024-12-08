#!/bin/bash

for i in 2 4 8 16 32 64 80 100 128; do
    sleep 3s
    echo "Lancement tache avec ${i} processeurs"

    # le parametre --ntasks a préséance sur
    # la valeur dans le script lui-même
    sbatch --ntasks=${i} launch-one.sh ${i}
done

