THREADS?=1

all: compile

compile: cilk_merge_sort.c
	clang -fopencilk -Wall cilk_merge_sort.c -o cilk_merge_sort.exe 

submit: 
	sbatch ./submit.slurm

run:
	CILK_NWORKERS=$(THREADS) ./cilk_merge_sort.exe

clean:
	rm -f cilk_merge_sort.exe