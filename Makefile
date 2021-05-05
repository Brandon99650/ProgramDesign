all:q.exe m.exe r.exe
q.exe:
	gcc -o q.exe quicksort.c
m.exe:
	gcc -o m.exe mergesort_main.c
r.exe:
	gcc -o r.exe radixsort.c
clear:
	rm -f q.exe m.exe r.exe