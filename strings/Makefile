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
	$(CC) $(CFLAGS) $< -o $@

