all: compile

compile: merge_sort.c
	gcc -Wall merge_sort.c -o merge_sort.exe

submit: 
	sbatch ./submit.slurm

run:
	./merge_sort.exe

clean:
	rm -f merge_sort.exe