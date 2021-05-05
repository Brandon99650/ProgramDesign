all:q.exe m.exe h.exe
q.exe:
	gcc -o q.exe quicksort.c
m.exe:
	gcc -o m.exe mergesort_main.c
h.exe:
	gcc -o h.exe heapsort.c
clear:
	rm -f q.exe m.exe h.exe
