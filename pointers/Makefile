CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

##
# Run like:
#
#   $ make outdir/foo
#
out/%: %.c
	mkdir -pv out
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm -v ./out/*
