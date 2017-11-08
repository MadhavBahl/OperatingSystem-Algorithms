# FCFS
    Enter the number of processes: 4
    Enter the burst time for each process:
        Burst Time for Process P1: 10
        Burst Time for Process P2: 5
        Burst Time for Process P3: 8
        Burst Time for Process P4: 3
    WAITING TIME
    ------------
    P1 --> 0
    P2 --> 10
    P3 --> 15
    P4 --> 23
    TURN AROUND TIME
    ----------------
    P1 --> 10
    P2 --> 15
    P3 --> 23
    P4 --> 26
    The Average Waiting Time Is: 12.000000
    The Average Turnaround Time Is: 18.500000

![image](https://user-images.githubusercontent.com/26179770/32556075-69862e06-c4c4-11e7-8031-c6353ea928ae.png)

**DRAWBACK** - Huge starvation time for processes joining later, even though their burst time may be low.

# SJF
    Enter the number of processes: 4
    Enter the burst time for each process:
        Burst Time for Process P1: 10
        Burst Time for Process P2: 5
        Burst Time for Process P3: 8
        Burst Time for Process P4: 3
    WAITING TIME
    ------------
    P3 --> 0
    P1 --> 3
    P2 --> 8
    P0 --> 16
    TURN AROUND TIME
    ----------------
    P3 --> 3
    P1 --> 8
    P2 --> 16
    P0 --> 26
    The Average Waiting Time Is: 6.750000
    The Average Turnaround Time Is: 13.250000

![image](https://user-images.githubusercontent.com/26179770/32564198-7f757c98-c4d9-11e7-9657-f08721702bd5.png)

**DRAWBACK** - High starvation for process with high burst time

# Priority 
    Enter the number of processes: 4
    Enter the burst time for each process:
        Burst Time for Process P1: 10
        Burst Time for Process P2: 5
        Burst Time for Process P3: 8
        Burst Time for Process P4: 3
    Enter the Priority for each process:
        Priority for Process P1: 2
        Priority for Process P2: 1
        Priority for Process P3: 4
        Priority for Process P4: 3
    WAITING TIME
    ------------
    P1 --> 0
    P0 --> 5
    P3 --> 15
    P2 --> 18
    TURN AROUND TIME
    ----------------
    P1 --> 5
    P0 --> 15
    P3 --> 18
    P2 --> 26
    The Average Waiting Time Is: 9.500000
    The Average Turnaround Time Is: 16.000000

![image](https://user-images.githubusercontent.com/26179770/32565369-e0c3425c-c4dc-11e7-8890-6728241eecfa.png)

**DRAWBACK** - Starvation of process with low priority

# Round Robin
    Enter Total Process:     4
    Enter Arrival Time and Burst Time for Process Process Number 1 :0 10
    Enter Arrival Time and Burst Time for Process Process Number 2 :0 5
    Enter Arrival Time and Burst Time for Process Process Number 3 :0 8
    Enter Arrival Time and Burst Time for Process Process Number 4 :0 3
    Enter Time Quantum:     2


    Process |Turnaround Time|Waiting Time

    P[4]    |       15      |       12
    P[2]    |       18      |       13
    P[3]    |       24      |       16
    P[1]    |       26      |       16

    Average Waiting Time= 14.250000
    Avg Turnaround Time = 20.750000

**DRAWBACK** - Increased waiting time for each process, too many task transitions
