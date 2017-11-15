# PROCESS SYNCRONIZATION
On the basis of synchronization, processes are categorized as one of the following two types:

   * Independent Process : Execution of one process does not affects the execution of other processes.
   * Cooperative Process : Execution of one process affects the execution of other processes.

Process synchronization problem arises in the case of Cooperative process also because resources are shared in 
Cooperative processes.
**SIMULTANEOUS ACCESS TO SHARED DATA/RESOURCES MAY LEAD TO INCONSISTANCY**

## Critical Section Problem
Critical section is a code segment that can be accessed by only one process at a time. Critical section contains 
shared variables which need to be synchronized to maintain consistency of data variables.

![critical-section-problem](https://user-images.githubusercontent.com/26179770/32833739-e7b9bf3e-ca25-11e7-9db4-8c2d14281a46.png)

In the entry section, the process requests for entry in the Critical Section

Any solution to the critical section problem must satisfy three requirements:

   * **Mutual Exclusion** : If a process is executing in its critical section, then no other process is allowed to execute in the critical section.
   * **Progress** : If no process is in the critical section, then no other process from outside can block it from entering the critical section.
   * **Bounded Waiting** : A bound must exist on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted.

**There are some classical problems of synchronizations**
   1. Producer Consumer's Problem
   2. Cigarette Smoker's Problem
   3. Reader Writer's Problem
   4. Dining Philosopher's Problem