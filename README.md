# SJF_Scheduling_algorithm_c
Here's a breakdown of the code:

Functions

findWaitingTime(): Calculates the waiting time for each process.

The waiting time for the first process is 0.
For subsequent processes, the waiting time is the sum of the previous process's burst time and waiting time.
findTurnAroundTime(): Calculates the turnaround time for each process.

The turnaround time is the sum of the burst time and waiting time.
findAverageTime(): Calculates and prints the average waiting time and average turnaround time.

sortProcessesByBurstTime(): Sorts processes by their burst times in ascending order.

Main Function

Asks the user to input the number of processes.
Initializes arrays for process IDs and burst times.
Asks the user to input the burst time for each process.
Sorts processes by their burst times using sortProcessesByBurstTime().
Calls findAverageTime() to calculate and print the average waiting time and average turnaround time.
Output

The program displays:

A table with process IDs, burst times, waiting times, and turnaround times.
The average waiting time.
The average turnaround time.
