CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

outdir:
	mkdir -pv ./outdir

##
# Run like:
#
#   $ make outdir/foo
#
outdir/%: %.c
	mkdir -pv outdir
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm -v ./outdir/*
