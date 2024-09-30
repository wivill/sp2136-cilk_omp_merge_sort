THREADS?=1

all: compile

compile_local: cilk_merge_sort.c
	export PATH=/opt/opencilk/bin:$PATH
	clang -fopencilk -Wall cilk_merge_sort.c -o cilk_merge_sort.exe 

compile: cilk_merge_sort.c
	# Ensure these modules are loaded:
	# module load gcc/7.2.0
	# module load mpich/3.2.1-gcc-7.2.0
	# module load cmake/3.17.2
	gcc -fcilkplus -Wall cilk_merge_sort.c -o cilk_merge_sort.exe 

submit: 
	sbatch ./submit.slurm

run:
	CILK_NWORKERS=$(THREADS) ./cilk_merge_sort.exe

clean:
	rm -f cilk_merge_sort.exe