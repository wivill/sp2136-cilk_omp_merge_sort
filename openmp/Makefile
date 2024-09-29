THREADS?=1

all: compile

compile: omp_merge_sort.c
	gcc -Wall omp_merge_sort.c -o omp_merge_sort.exe -fopenmp

submit: 
	sbatch ./submit.slurm

run:
	export OMP_NUM_THREADS=$(THREADS) && ./omp_merge_sort.exe

clean:
	rm -f omp_merge_sort.exe