//Round Robin


// New File create : touch round_robin.c
//Open IDE : vi round_robin
// Run Code : gcc round_robin.c -o test1
// Run Code : ./test1

#include <stdio.h>

int main()
{
    int n, quantum, t = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processes[n], burstTime[n], remaining[n], waitingTime[n], turnaroundTime[n];

    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remaining[i] = burstTime[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while (!done)
    {
        done = 1;
        for (int i = 0; i < n; i++)
        {
            if (remaining[i] > 0)
            {
                done = 0;
                if (remaining[i] > quantum)
                {
                    t += quantum;
                    remaining[i] -= quantum;
                } else
                {
                    t += remaining[i];
                    waitingTime[i] = t - burstTime[i];
                    remaining[i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    return 0;
}


/* Output :

Enter number of processes: 3
Enter burst time for process 1: 10
Enter burst time for process 2: 5
Enter burst time for process 3: 8
Enter time quantum: 3

*/