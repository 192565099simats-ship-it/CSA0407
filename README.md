# Operating Systems – Assignment 2 (CO2)

**Student:** S.Malavika  
**Register Number:** 192565099  
**Department:** CSE(CS)  
**GitHub repository:** https://github.com/192565099simats-ship-it/CSA0407.git

## Contents
- `Operating_Systems_Assignment_2_Answers_Filled.docx` – completed written answers.
- `source_code/` – C source files for Q1–Q6.
- `evidence/` – place your own terminal screenshots and measured timing results here.

## Compile and run (Linux)
Run commands from the `source_code` folder:

```bash
gcc q1_fork.c -o q1_fork && ./q1_fork
gcc q2_round_robin.c -o q2_round_robin && ./q2_round_robin
gcc q3_threads.c -o q3_threads -pthread && ./q3_threads
gcc q4_pipe.c -o q4_pipe && ./q4_pipe
gcc q4_shared_memory.c -o q4_shared_memory -pthread -lrt && ./q4_shared_memory
gcc q5_bounded_buffer.c -o q5_bounded_buffer -pthread && ./q5_bounded_buffer
gcc q6_bankers.c -o q6_bankers && ./q6_bankers
```

On some modern Linux distributions, `-lrt` is not needed. Add your actual output screenshots and timing measurements to `evidence/` before final submission.

## Important
The assignment requires executed programs, evidence/screenshots, Gantt charts and measured timings. The evidence folder is intentionally empty; run the programs on your Linux system and add your own results. Do not claim unmeasured timings as actual results.
