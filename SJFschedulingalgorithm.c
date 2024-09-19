
#include <stdio.h>


void findWaitingTime(int processes[], int n, int bt[], int wt[]) {

    wt[0] = 0;


    for (int i = 1; i < n; i++) {

        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

   findWaitingTime(processes, n, bt, wt);


    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}
void sortProcessesByBurstTime(int processes[], int bt[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
               
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
               
                int temp_proc = processes[i];
                processes[i] = processes[j];
                processes[j] = temp_proc;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
   
    int processes[n], burst_time[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs from 1 to n
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
printf("\nSJF scheduling algorithm\n");
printf("\n");
    sortProcessesByBurstTime(processes, burst_time, n);

    findAverageTime(processes, n, burst_time);

    return 0;
}
