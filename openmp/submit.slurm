#!/bin/bash
#SBATCH --job-name=omp_merge_sort
#SBATCH --output=result.txt
#SBATCH --partition=nu
#SBATCH --ntasks=1
#SBATCH --time=00:30:00

for num_threads in 1 2 4 8 16 32
do
    make run THREADS=$num_threads
done