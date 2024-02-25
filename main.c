#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Number of arguments needs to be 2");
        return 1;
    }

    // delete later
    for (int args = 1; args < argc; args++) {
        printf("Arg %d: %s\n", args, argv[args]);
    }

    // maybe use when choosing algo to run
    if (argv[2] == "FCFS") {
        printf("you have chosen FCFS");
    } else if (argv[2] == "SJF") {
        printf("you have chosen SJF");
    }

    return 0;
}
