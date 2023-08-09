CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

out:
	mkdir -pv ./out

##
# Run like:
#
#   $ make ./out/foo
#   $ ./out/foo
#
out/%: %.c
	$(CC) $(CFLAGS) $< -o $@

