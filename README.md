INDEX
-----
 * <a href="UNIXcommands/README.md">Basic UNIX Commands</a>
 * <a href="ShellSCripting/">Shell Programming
 * <a href="ChildProcesses/">Child Processes
 * <a href="CPUScheduling/">CPU Scheduling Algorithms
 * <a href="BankersAlgorithm/">Bankers Algorithm - Deadlock prevention Algorithm
 * <a href="ProcessSync/">Process Synchronization using semaphores
 * <a href="PageReplacement/">Page Replacement Algorithms  
 * <a href="MemoryAllocation/">Dynamic Memory alocation algorithms
 * <a href="DiskScheduling/">Disk Scheduling Algorithms

## [Basic UNIX Commands](UNIXcommands/README.md)
 * w
 * who
 * uptime
 * pwd
 * ls
 * mkdir
 * cd
 * vi
 * head
 * rmdir
 * df
 * du
 * top
 * cp
 * who -Hu-
 * cal
 * tty
 * cal {year}
 * wc
 * bc
 * tail
 * man
 * passwd
 * xcalc
 * history
 * logout
 * exit

## [Shell Programming](ShellScripting/README.md)
 * echo "..."
 * read <VAR_NAME>
 * read -p "" <VAR_NAME>
 * `expr 10 + 20`
 * $(( a+b ))
 * [ a == b ]
 * if [ ... ];
   then
    ...
   else
    ...
   fi
 * for((i=0;i<=n;i++))
   {
       ...
   }
 * case "ch"
     "a")
        ...
     ;;
     "b")
        ...
     ;;
     *)
        ...
     ;;
   esac

## [Child Processes](ChildProcesses/)
 * Child process using fork()
 * Orphan process
 * Zombie process

## [CPU Scheduling Algorithms](CPUscheduling/README.md)
 1. First Come First Serve (FCFS)
 2. Shortest Job First (SJF)
 3. Round Robin (RR)
 4. Priority
 
## [Process Synchronization](ProcessSync/README.md)
 1. Producer Consumer Problem
 2. Readers writers problem
 3. Dining philosophers problem
 4. cigarette smokers problem

## [Memory Allocation Algorithms](MemoryAllocation/README.md)
 1. First Fit
 2. Best Fit
 3. Worst Fit

## [Page Replacement Algorithms](PageReplacement/README.md)
 1. FIFO
 2. Optimal
 3. LRU

## [Disk Scheduling Algorithms](DiskScheduling/)
 1. FCFS
 2. SSTF
 3. SCAN
 4. C-SCAN
 5. LOOK
 6. C-LOOK
