# Quick Sort Record Organizer

![Language](https://img.shields.io/badge/language-C-blue)
![Algorithm](https://img.shields.io/badge/algorithm-Quick%20Sort-orange)
![Capacity](https://img.shields.io/badge/max%20records-100-success)

A menu-driven C application for organizing student records using the **Quick Sort** algorithm. The program supports sorting by student ID, name, or marks, and allows users to compare the performance of different pivot-selection strategies.

## Table of Contents

- [About the Project](#about-the-project)
- [Problem Statement](#problem-statement)
- [Module and Learning Objectives](#module-and-learning-objectives)
- [Functional Requirements](#functional-requirements)
- [Features](#features)
- [How Quick Sort Is Used](#how-quick-sort-is-used)
- [Input and Output](#input-and-output)
- [Getting Started](#getting-started)
- [Menu Options](#menu-options)
- [Sample Demonstration](#sample-demonstration)
- [Performance Metrics](#performance-metrics)
- [Team Members](#team-members)
- [Project File](#project-file)

## About the Project

The **Quick Sort Record Organizer** stores student information in a structured record containing:

| Field | Description |
| --- | --- |
| `ID` | Unique student identifier |
| `Name` | Student name |
| `Marks` | Student marks |

Users can enter records manually, display them, select sorting preferences, sort the records, analyze sorting performance, and generate test data for experimentation.

## Problem Statement

### Quick Sort-Based Record Organizer

Develop a console-based record-management application that arranges student records using the **Quick Sort** algorithm. The user selects the sorting field, sorting order, and pivot rule. The program partitions the records around the selected pivot, recursively sorts the two resulting subarrays, and reports how the pivot choice affects performance.

This project demonstrates the use of **partition-based divide and conquer** on structured records rather than on simple numeric arrays.

## Module and Learning Objectives

**Module 2: Divide and Conquer Approach**

The project focuses on:

- Understanding Quick Sort and its partitioning process
- Implementing Quick Sort for records containing multiple fields
- Selecting a sorting field and pivot rule at runtime
- Understanding the recurrence-based analysis of Quick Sort
- Comparing balanced and unbalanced partitions
- Measuring comparisons, swaps, recursive calls, and recursion depth

For a subproblem of size `n`, Quick Sort can be expressed using the recurrence:

```text
T(n) = T(k) + T(n - k - 1) + O(n)
```

where `k` is the number of records placed before the pivot. Balanced partitions lead to approximately `O(n log n)` average behavior, while repeatedly unbalanced partitions can lead to `O(n^2)` behavior.

## Functional Requirements

The application satisfies the following requirements:

1. Store student records in an array with ID, name, and marks fields.
2. Allow users to add and display records.
3. Allow users to choose the sorting field and sorting order.
4. Support first-element, middle-element, and last-element pivot rules.
5. Implement a dedicated partition function and recursive `quickSort` function.
6. Count comparisons, swaps, recursive calls, and maximum recursion depth.
7. Generate random, sorted, and reverse-sorted test inputs.
8. Compare the work performed by each pivot rule.
9. Warn the user when the measured recursion depth suggests highly unbalanced partitioning.

## Features

- Add up to **100 student records**
- Display all stored student records
- Sort records by:
  - Student ID
  - Student name
  - Student marks
- Sort in ascending or descending order
- Select one of three pivot rules:
  - First element
  - Middle element
  - Last element
- Track Quick Sort performance using:
  - Number of comparisons
  - Number of swaps
  - Number of recursive calls
  - Maximum recursion depth
- Generate:
  - Random test data
  - Sorted test data
  - Reverse-sorted test data
- Compare the performance of all pivot rules on generated data

## How Quick Sort Is Used

The program applies Quick Sort recursively:

1. A pivot is selected according to the chosen pivot rule.
2. The records are partitioned around the pivot.
3. The left and right partitions are sorted recursively.
4. The process continues until all records are ordered.

The implementation records performance statistics during sorting. This makes it possible to observe how pivot selection affects partition balance, recursion depth, comparisons, and swaps.

The program does not print every individual partition boundary. Instead, partition behavior is demonstrated through the performance counters, recursion depth, and the warning displayed when partitioning becomes highly unbalanced.

### Complexity

| Case | Time Complexity |
| --- | --- |
| Best case | `O(n log n)` |
| Average case | `O(n log n)` |
| Worst case | `O(n^2)` |

The additional recursion space is typically `O(log n)` for balanced partitions and can reach `O(n)` for highly unbalanced partitions.

## Input and Output

### Input

The program accepts:

- Number of records, up to 100
- Student ID
- Student name
- Student marks
- Sorting field: ID, name, or marks
- Sorting order: ascending or descending
- Pivot rule: first, middle, or last element
- Test-data type: random, sorted, or reverse-sorted

### Output

The program displays:

- The current student records
- The selected sorting configuration
- The sorted records
- Comparison, swap, recursive-call, and maximum-depth counts
- A partition-balance message or warning
- Pivot-performance comparisons for generated test data

## Getting Started

### Prerequisites

Install a C compiler such as:

- GCC through MinGW on Windows
- GCC on Linux
- Clang on macOS

### Compile

From the project directory, run:

```powershell
gcc miniproject2.c -o miniproject2
```

### Run on Windows PowerShell

```powershell
.\miniproject2
```

### Run on Linux or macOS

```bash
gcc miniproject2.c -o miniproject2
./miniproject2
```

## Menu Options

| Option | Operation |
| --- | --- |
| `1` | Add student records |
| `2` | Display records |
| `3` | Choose the sorting field |
| `4` | Choose ascending or descending order |
| `5` | Choose the pivot rule |
| `6` | Sort and display the records |
| `7` | Display performance statistics |
| `8` | Generate test data and compare pivot rules |
| `9` | Exit the program |

## Sample Demonstration

The following output demonstrates:

- Adding eight student records
- Displaying the records
- Sorting by ID in ascending order
- Sorting by marks in descending order
- Sorting by name in ascending order
- Viewing performance metrics
- Comparing first, middle, and last pivot rules
- Generating random, sorted, and reverse-sorted test data

<details>
<summary><strong>View complete sample output</strong></summary>

```text
========================================
       QUICK SORT RECORD ORGANIZER
========================================
1. Add records
2. Display records
3. Choose sorting field
4. Choose sorting order
5. Choose pivot rule
6. Sort records
7. Analyze performance
8. Generate test data
9. Exit
Enter your choice: 1

Enter the number of records to be entered: 8

Enter the Id of student: 105
Enter the Name of student: Rahul
Enter the marks of student: 78

Enter the Id of student: 101
Enter the Name of student: Aman
Enter the marks of student: 92

Enter the Id of student: 108
Enter the Name of student: Riya
Enter the marks of student: 65

Enter the Id of student: 103
Enter the Name of student: Neha
Enter the marks of student: 88

Enter the Id of student: 110
Enter the Name of student: Karan
Enter the marks of student: 55

Enter the Id of student: 102
Enter the Name of student: Priya
Enter the marks of student: 95

Enter the Id of student: 107
Enter the Name of student: Arjun
Enter the marks of student: 72

Enter the Id of student: 104
Enter the Name of student: Sneha
Enter the marks of student: 81

Total records filled: 8

========================================
           STUDENTS RECORD
========================================
Id      Name                    Marks
----------------------------------------
105     Rahul                   78
101     Aman                    92
108     Riya                    65
103     Neha                    88
110     Karan                   55
102     Priya                   95
107     Arjun                   72
104     Sneha                   81

Field of sorting
1. ID
2. Name
3. Marks
Enter your choice: 1
Sorting field successfully selected.

Order of sorting
1. Ascending
2. Descending
Enter your choice: 1
Sorting order selected successfully.

Enter the pivot rule
1. First Element
2. Middle Element
3. Last Element
Enter your choice: 1
Pivot rule successfully selected.

========================================
          STARTING QUICK SORT
========================================
Sorting Field: ID
Sorting Order: Ascending
Pivot Rule: First Element

Records sorted successfully!

Sorted Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
101     Aman                    92
102     Priya                   95
103     Neha                    88
104     Sneha                   81
105     Rahul                   78
107     Arjun                   72
108     Riya                    65
110     Karan                   55

Sorting Field: Marks
Sorting Order: Descending
Pivot Rule: First Element

Records sorted successfully!

Sorted Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
102     Priya                   95
101     Aman                    92
103     Neha                   88
104     Sneha                   81
105     Rahul                   78
107     Arjun                   72
108     Riya                    65
110     Karan                   55

Sorting Field: Name
Sorting Order: Ascending
Pivot Rule: First Element

Records sorted successfully!

Sorted Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
101     Aman                    92
107     Arjun                   72
110     Karan                   55
103     Neha                    88
102     Priya                   95
105     Rahul                   78
108     Riya                    65
104     Sneha                   81

========================================
          PERFORMANCE ANALYSIS
========================================
Number of Records       : 8
Sorting Field           : Name
Sorting Order           : Ascending
Pivot Rule              : First Element
----------------------------------------
Comparisons             : 21
Swaps                   : 7
Recursive Calls         : 5
Maximum Recursion Depth : 3
----------------------------------------
Partitioning appears reasonably balanced.
========================================

========================================
          GENERATE TEST DATA
========================================
1. Random Data
2. Sorted Data
3. Reverse Sorted Data
Enter your choice: 1
Enter number of test records (max 100): 10

Test data generated successfully!

Generated Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
868     Student1                46
241     Student2                31
876     Student3                95
198     Student4                72
111     Student5                45
276     Student6                73
358     Student7                22
101     Student8                58
412     Student9                77
523     Student10               62

========================================
       PIVOT PERFORMANCE COMPARISON
========================================

----------------------------------------
Pivot Rule: First Element
Comparisons             : 38
Swaps                   : 9
Recursive Calls         : 5
Maximum Recursion Depth : 5
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Middle Element
Comparisons             : 29
Swaps                   : 9
Recursive Calls         : 6
Maximum Recursion Depth : 4
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Last Element
Comparisons             : 46
Swaps                   : 9
Recursive Calls         : 8
Maximum Recursion Depth : 8
Warning: Highly unbalanced partitioning.

========================================
Performance analysis completed.
Original pivot rule restored.
========================================

========================================
          GENERATE TEST DATA
========================================
1. Random Data
2. Sorted Data
3. Reverse Sorted Data
Enter your choice: 2
Enter number of test records (max 100): 10

Test data generated successfully!

Generated Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
1       Student1                0
2       Student2                1
3       Student3                2
4       Student4                3
5       Student5                4
6       Student6                5
7       Student7                6
8       Student8                7
9       Student9                8
10      Student10               9

========================================
       PIVOT PERFORMANCE COMPARISON
========================================

----------------------------------------
Pivot Rule: First Element
Comparisons             : 38
Swaps                   : 9
Recursive Calls         : 5
Maximum Recursion Depth : 5
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Middle Element
Comparisons             : 29
Swaps                   : 9
Recursive Calls         : 6
Maximum Recursion Depth : 4
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Last Element
Comparisons             : 46
Swaps                   : 9
Recursive Calls         : 8
Maximum Recursion Depth : 8
Warning: Highly unbalanced partitioning.

========================================
Performance analysis completed.
Original pivot rule restored.
========================================

========================================
          GENERATE TEST DATA
========================================
1. Random Data
2. Sorted Data
3. Reverse Sorted Data
Enter your choice: 3
Enter number of test records (max 100): 10

Test data generated successfully!

Generated Records:
----------------------------------------
Id      Name                    Marks
----------------------------------------
10      Student1                10
9       Student2                9
8       Student3                8
7       Student4                7
6       Student5                6
5       Student6                5
4       Student7                4
3       Student8                3
2       Student9                2
1       Student10               1

========================================
       PIVOT PERFORMANCE COMPARISON
========================================

----------------------------------------
Pivot Rule: First Element
Comparisons             : 38
Swaps                   : 9
Recursive Calls         : 5
Maximum Recursion Depth : 5
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Middle Element
Comparisons             : 29
Swaps                   : 9
Recursive Calls         : 6
Maximum Recursion Depth : 4
Partitioning appears reasonably balanced.

----------------------------------------
Pivot Rule: Last Element
Comparisons             : 46
Swaps                   : 9
Recursive Calls         : 8
Maximum Recursion Depth : 8
Warning: Highly unbalanced partitioning.

========================================
Performance analysis completed.
Original pivot rule restored.
========================================

========================================
       QUICK SORT RECORD ORGANIZER
========================================
1. Add records
2. Display records
3. Choose sorting field
4. Choose sorting order
5. Choose pivot rule
6. Sort records
7. Analyze performance
8. Generate test data
9. Exit
Enter your choice: 9

Program terminated successfully.
```

</details>

## Performance Metrics

The performance analyzer reports the following values for the most recent sort:

| Metric | Meaning |
| --- | --- |
| Comparisons | Number of record comparisons performed |
| Swaps | Number of record exchanges performed |
| Recursive Calls | Number of non-trivial recursive Quick Sort calls |
| Maximum Recursion Depth | Deepest level reached during recursion |

For generated test data, the program runs the sort with all three pivot rules and restores the original pivot selection afterward.

## Team Members

| No. | Name | Roll Number |
| ---: | --- | --- |
| 1 | Parth Gaikwad | `25102A0012` |
| 2 | Sanskar Parab | `25102A0018` |
| 3 | Arhan Khan | `25102A0005` |
| 4 | Parth Naik | `25102A0006` |

## Project File

```text
miniproject2.c
```

This project is intended for learning and demonstrating Quick Sort, recursion, partitioning strategies, and basic algorithm-performance analysis in C.
