# CSA04 – Operating Systems – Assignment 1

**Assignment:** Evaluate and Justify the Operating-System Design of a Smart Hospital

## Repository structure

```text
CSA04-Assignment1/
├── Assignment1_Answers.docx
├── README.md
├── .gitignore
├── Task01/ ... Task05/
├── Task06-System-Call-Cost/
│   ├── copy.c
│   └── run.sh
├── Task07-Process-Control/
│   ├── process.c
│   └── run.sh
├── Task08-CPU-Protection/
├── Task09-Memory-and-IO/
├── Task10-Measurements/
│   ├── README.md
│   ├── process_bench.c
│   ├── thread_bench.c
│   └── run_measurements.sh
├── Task11-Final-OS-Plan/
└── Task12-Design-Challenge/
```

## Requirements

- Linux environment (Ubuntu/Kali or another Linux distribution)
- GCC compiler
- `strace` and `/usr/bin/time` for system-call and timing measurements
- POSIX threads support for the thread benchmark

## Compile and run

### Task 6 – System-call cost

```bash
cd Task06-System-Call-Cost
chmod +x run.sh
./run.sh
```

### Task 7 – Process control

```bash
cd Task07-Process-Control
chmod +x run.sh
./run.sh
```

### Task 10 – Measurements

```bash
cd Task10-Measurements
chmod +x run_measurements.sh
./run_measurements.sh
```

Run the measurements on your own Linux system. Save the terminal output in the relevant task folder (for example, `output.txt`) and add screenshots if your faculty requires them. Do not report sample or expected values as measured results.

## Before submission

1. Replace the student details in `Assignment1_Answers.docx`.
2. Execute and test the programs on Linux.
3. Add actual `strace` and timing outputs.
4. Fill the Task 10 measurement table in the report using your own results.
5. Add screenshots and any additional code/configuration files required by your lab.
6. Commit progressively, preferably one commit per task.
7. Copy the final GitHub repository URL to the assignment cover page.

## Suggested commit sequence

```bash
git add Task01 && git commit -m "Add Task 1 requirement analysis"
git add Task02 && git commit -m "Add Task 2 OS type evaluation"
# Repeat for each task after adding its completed files/evidence.
```
