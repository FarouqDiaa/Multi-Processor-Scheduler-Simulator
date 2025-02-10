# MultiProcessor Scheduler Simulator

## 📌 Overview
The **MultiProcessor Scheduler Simulator** is a C++ project that simulates process scheduling in a multiprocessor system. It supports **First-Come-First-Serve (FCFS), Shortest Job First (SJF), and Round Robin (RR)** scheduling algorithms, efficiently managing processes, workload balancing, and CPU utilization.  

The simulator models real-world scheduling scenarios, handling **process migration, work stealing, forking, and termination**, while computing key performance metrics such as **waiting time, response time, turnaround time, and processor utilization**.

## 🚀 Features
- **Multi-Algorithm Scheduling**: Implements FCFS, SJF, and RR scheduling policies.  
- **Process Management**: Tracks process states (Ready, Running, Blocked, Terminated).  
- **Dynamic Load Balancing**: Distributes tasks efficiently across processors.  
- **Process Migration & Work Stealing**: Ensures even workload distribution.  
- **Custom Data Structures**: Uses linked lists, queues, and priority queues (no STL).  
- **Multiple Execution Modes**:
  - **Interactive Mode**: Step through the simulation manually.
  - **Step-By-Step Mode**: Runs automatically with time delays.
  - **Silent Mode**: Runs in the background and generates an output file.  
- **Performance Metrics**: Computes utilization, migration percentages, and load balancing efficiency.



## Contributors  
Developed as part of Cairo University’s **Data Structures and Algorithms** course.  
