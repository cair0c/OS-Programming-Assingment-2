// Cairo Crawford PantherID: 6389250
// Cedric Cherestal PantherID: 5512167
// Camila Castaneda PantherID: 6059028

#include <stdio.h>
#include <stdlib.h>

void firstComeFirstServed() {
    printf("you have chosen FCFS");
}

void shortestJobFirst() {
    printf("you have chosen SJF");
}

int main(int argc, char *argv[]) {

    // PROVIDED VARIABLES
    FILE *file;
    int num_process;
    int *arrival;
    int *burst;
    // END OF PROVIDED VARIABLES

    if (argc != 2) {
        printf("Number of arguments needs to be 2");
        return 1;
    }

    // delete later
    for (int args = 1; args < argc; args++) {
        printf("Arg %d: %s\n", args, argv[args]);
    }

    //START OF PROVIDED CODE
    // Open the file
    file = fopen(argv[1], "r");
    // Read the first line - number of processes, note the '&' operator before num_process
    fscanf(file, "%d", &num_process);
    // Allocate the arrays to store the arrival time and burst time, one element for each process
    arrival = (int *)malloc(num_process * sizeof(int));
    burst = (int *)malloc(num_process * sizeof(int));
    // Read each line of the file for arrival time and burst time, note that no '&' operator used here
    for (int i = 0; i < num_process; i++)
    {
        fscanf(file, "%d", arrival + i);
        fscanf(file, "%d", burst + i);
    }
    // You should close the file after reading, even though it's usually ok to forget
    fclose(file);
    // In this example I only print the values, in your assignment you have to compute the execution sequence
    // as well as the average waiting time and average turnaround time
    printf("There are %d processes\n", num_process);
    for (int i = 0; i < num_process; i++)
    {
        printf("Process %d arrives at %d with burst time %d\n", i + 1, arrival[i],
               burst[i]);
    }
    //END OF PROVIDED CODE

    // maybe use when choosing algo to run
    if (argv[2] == "FCFS") {
        firstComeFirstServed();
    } else if (argv[2] == "SJF") {
        shortestJobFirst();
    }

    // And remember to release the dynamically allocated memory after using
    free(arrival);
    free(burst);

    return 0;
}
