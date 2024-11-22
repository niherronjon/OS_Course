//First Come First Serve (FCFS) Algorithm


// New File create : touch fcfs.c
//Open IDE : vi fcfs.c
// Run Code : gcc fcfs.c -o test4
// Run Code : ./test4


#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);

    return 0;
}


/* Output :

Enter number of processes: 4
Enter burst time for process 1: 5
Enter burst time for process 2: 9
Enter burst time for process 3: 6
Enter burst time for process 4: 3

*/
