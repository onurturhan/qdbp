gcc qdbp_enable.c -o qdbp_enable

gcc example.c -o example.o -c
gcc qdbp.c -o qdbp.o -c

gcc -std=c99 -Wall -Wextra -g -o example example.o qdbp.o

rm -rif *.o

./qdbp_enable ./example

