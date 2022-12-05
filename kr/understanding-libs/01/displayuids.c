/*

Generates displayuids.o:

    gcc -std=c99 -Wall -pedantic -fPIC displayuids.c

Generates libdisplayuids.so

    gcc -std=c99 -Wall -pedantic -shared -o libdisplayuids.so 


*/


void display_uid(void) {
    int real = getuid();
    int euid = geteuid();
    printf("The real UID: %d\n", real);
    printf("The effective UID: %d\n", euid);
}
