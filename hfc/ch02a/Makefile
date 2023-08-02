CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

out:
	mkdir -pv ./out


##
# Run like:
#
#   $ make out/ex01ptr
#   $ make out/doses
#   $ make buf_fgets
#
out/%: %.c
	$(CC) $(CFLAGS) $< -o $@

