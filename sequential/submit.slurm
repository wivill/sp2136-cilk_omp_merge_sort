#!/bin/bash
#SBATCH --job-name=sequential_merge_sort
#SBATCH --output=result.txt
#SBATCH --partition=nu
#SBATCH --ntasks=1
#SBATCH --time=00:30:00

make run