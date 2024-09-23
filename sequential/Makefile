all: compile

compile: merge_sort.c
	gcc -Wall merge_sort.c -o merge_sort

submit: 
	sbatch ./submit.slurm

run:
	./merge_sort

clean:
	rm -f merge_sort