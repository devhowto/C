CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

outdir:
	mkdir -pv ./outdir


##
# Run like:
#
#   $ make outdir/ex01ptr
#   $ make outdir/doses
#   $ make buf_fgets
#
outdir/%: %.c
	$(CC) $(CFLAGS) $< -o $@

