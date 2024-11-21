//Shortest Job First (SJF)



// New File create : touch sjf.c
//Open IDE : vi sjf.c
// Run Code : gcc sjf.c -o test3
// Run Code : ./test3

#include <stdio.h>

int main()
{
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
    // Sorting burst times to implement SJF (non-preemptive)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    waitingTime[0] = 0; // First process has no waiting time
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


/*
Output:

Enter number of processes: 3
Enter burst time for process 1: 6
Enter burst time for process 2: 8
Enter burst time for process 3: 7

*/