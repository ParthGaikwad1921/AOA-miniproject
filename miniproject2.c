#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct student
{
    int id;
    char name[50];
    int marks;
} student;

int sorting_field = 1;
int sorting_order = 1;
int pivot_rule = 1;

long long comparisons = 0;
long long swaps = 0;
long long recursive_calls = 0;

int current_depth = 0;
int max_depth = 0;

int compare_students(student a, student b)  
{
    if (sorting_field == 1)
    {
        if (a.id < b.id)
            return -1;
        else if (a.id > b.id)
            return 1;
        else
            return 0;
    }
    else if (sorting_field == 2)
    {
        int result = strcmp(a.name, b.name);

        if (result < 0)
            return -1;
        else if (result > 0)
            return 1;
        else
            return 0;
    }
    else
    {
        if (a.marks < b.marks)
            return -1;
        else if (a.marks > b.marks)
            return 1;
        else
            return 0;
    }
}

int give_partition(student array[],int lb,int ub)
{
    int down, up;
    int pivotIndex;

    student val;
    student temp;

    if (pivot_rule == 1)
        pivotIndex = lb;
    else if (pivot_rule == 2)
        pivotIndex = (lb + ub) / 2;
    else
        pivotIndex = ub;

    val = array[pivotIndex];

    temp = array[lb];
    array[lb] = array[pivotIndex];
    array[pivotIndex] = temp;

    down = lb + 1;
    up = ub;

    if (sorting_order == 1)
    {
        while (1)
        {
            while (down <= ub)
            {
                comparisons++;

                if (compare_students(array[down], val) >= 0)
                    break;

                down++;
            }

            while (up >= lb + 1)
            {
                comparisons++;

                if (compare_students(array[up], val) <= 0)
                    break;

                up--;
            }

            if (down > up)
                break;

            temp = array[down];
            array[down] = array[up];
            array[up] = temp;

            swaps++;

            down++;
            up--;
        }
    }
    else
    {
        while (1)
        {
            while (down <= ub)
            {
                comparisons++;

                if (compare_students(array[down], val) <= 0)
                    break;

                down++;
            }

            while (up >= lb + 1)
            {
                comparisons++;

                if (compare_students(array[up], val) >= 0)
                    break;

                up--;
            }

            if (down > up)
                break;

            temp = array[down];
            array[down] = array[up];
            array[up] = temp;

            swaps++;

            down++;
            up--;
        }
    }

    temp = array[lb];
    array[lb] = array[up];
    array[up] = temp;

    swaps++;

    return up;
}

void quickSort(student array[], int lb, int ub)
{
    int partition;

    if (lb < ub)
    {
        recursive_calls++;

        current_depth++;

        if (current_depth > max_depth)
            max_depth = current_depth;

        partition = give_partition(array, lb, ub);

        quickSort(array, lb, partition - 1);

        quickSort(array, partition + 1, ub);

        current_depth--;
    }
}

int main()
{
    student students_record[100];

    int record_count = 0;
    int choice = 0;
    int n;
    int start = 0;

    student test_records[100];
    int test_count;

    while (choice != 9)
    {
        printf("\n");
        printf("========================================\n");
        printf("       QUICK SORT RECORD ORGANIZER\n");
        printf("========================================\n");

        printf("1. Add records\n");
        printf("2. Display records\n");
        printf("3. Choose sorting field\n");
        printf("4. Choose sorting order\n");
        printf("5. Choose pivot rule\n");
        printf("6. Sort records\n");
        printf("7. Analyze performance\n");
        printf("8. Generate test data\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 2 && choice <= 7 && record_count == 0)
        {
            printf("\nPlease enter at least one record first.\n");
            continue;
        }

        if (choice == 1)
        {
            printf("\nEnter the number of records to be entered: ");
            scanf("%d", &n);

            if (n <= 0 || record_count + n > 100)
            {
                printf("Invalid number of records.\n");
                printf("Maximum capacity is 100 records.\n");
                continue;
            }

            start = record_count;

            for (int i = start; i < start + n; i++)
            {
                printf("\nEnter the Id of student: ");
                scanf("%d", &students_record[i].id);

                printf("Enter the Name of student: ");
                scanf(" %[^\n]", students_record[i].name);

                printf("Enter the marks of student: ");
                scanf("%d", &students_record[i].marks);
            }

            record_count += n;

            printf("\nTotal records filled: %d\n", record_count);
        }

        else if (choice == 2)
        {
            printf("\n");
            printf("========================================\n");
            printf("           STUDENTS RECORD\n");
            printf("========================================\n");

            printf("Id\tName\t\t\tMarks\n");
            printf("----------------------------------------\n");

            for (int i = 0; i < record_count; i++)
            {
                printf("%d\t%-20s\t%-10d\n",
                       students_record[i].id,
                       students_record[i].name,
                       students_record[i].marks);
            }
        }

        else if (choice == 3)
        {
            printf("\nField of sorting\n");
            printf("1. ID\n");
            printf("2. Name\n");
            printf("3. Marks\n");

            printf("Enter your choice: ");
            scanf("%d", &sorting_field);

            if (sorting_field >= 1 && sorting_field <= 3)
            {
                printf("Sorting field successfully selected.\n");
            }
            else
            {
                printf("Invalid sorting field.\n");
                sorting_field = 1;
            }
        }

        else if (choice == 4)
        {
            printf("\nOrder of sorting\n");
            printf("1. Ascending\n");
            printf("2. Descending\n");

            printf("Enter your choice: ");
            scanf("%d", &sorting_order);

            if (sorting_order >= 1 && sorting_order <= 2)
            {
                printf("Sorting order selected successfully.\n");
            }
            else
            {
                printf("Invalid sorting order.\n");
                sorting_order = 1;
            }
        }

        else if (choice == 5)
        {
            printf("\nEnter the pivot rule\n");
            printf("1. First Element\n");
            printf("2. Middle Element\n");
            printf("3. Last Element\n");

            printf("Enter your choice: ");
            scanf("%d", &pivot_rule);

            if (pivot_rule >= 1 && pivot_rule <= 3)
            {
                printf("Pivot rule successfully selected.\n");
            }
            else
            {
                printf("Invalid pivot rule.\n");
                pivot_rule = 1;
            }
        }

        else if (choice == 6)
        {
            printf("\n");
            printf("========================================\n");
            printf("          STARTING QUICK SORT\n");
            printf("========================================\n");

            printf("Sorting Field: ");

            if (sorting_field == 1)
                printf("ID\n");
            else if (sorting_field == 2)
                printf("Name\n");
            else
                printf("Marks\n");

            printf("Sorting Order: ");

            if (sorting_order == 1)
                printf("Ascending\n");
            else
                printf("Descending\n");

            printf("Pivot Rule: ");

            if (pivot_rule == 1)
                printf("First Element\n");
            else if (pivot_rule == 2)
                printf("Middle Element\n");
            else
                printf("Last Element\n");

            comparisons = 0;
            swaps = 0;
            recursive_calls = 0;

            current_depth = 0;
            max_depth = 0;

            quickSort(students_record, 0, record_count - 1);

            printf("\nRecords sorted successfully!\n");

            printf("\nSorted Records:\n");
            printf("----------------------------------------\n");

            printf("Id\tName\t\t\tMarks\n");
            printf("----------------------------------------\n");

            for (int i = 0; i < record_count; i++)
            {
                printf("%d\t%-20s\t%-10d\n",
                       students_record[i].id,
                       students_record[i].name,
                       students_record[i].marks);
            }
        }

        else if (choice == 7)
        {
            printf("\n");
            printf("========================================\n");
            printf("          PERFORMANCE ANALYSIS\n");
            printf("========================================\n");

            printf("Number of Records       : %d\n", record_count);

            printf("Sorting Field           : ");

            if (sorting_field == 1)
                printf("ID\n");
            else if (sorting_field == 2)
                printf("Name\n");
            else
                printf("Marks\n");

            printf("Sorting Order           : ");

            if (sorting_order == 1)
                printf("Ascending\n");
            else
                printf("Descending\n");

            printf("Pivot Rule              : ");

            if (pivot_rule == 1)
                printf("First Element\n");
            else if (pivot_rule == 2)
                printf("Middle Element\n");
            else
                printf("Last Element\n");

            printf("----------------------------------------\n");

            printf("Comparisons             : %lld\n", comparisons);
            printf("Swaps                   : %lld\n", swaps);
            printf("Recursive Calls         : %lld\n", recursive_calls);
            printf("Maximum Recursion Depth : %d\n", max_depth);

            printf("----------------------------------------\n");

            if (record_count > 1)
            {
                if (max_depth > record_count / 2)
                {
                    printf("Warning: Highly unbalanced recursion detected.\n");
                }
                else
                {
                    printf("Partitioning appears reasonably balanced.\n");
                }
            }

            printf("========================================\n");
        }

        else if (choice == 8)
        {
            int test_choice;
            int selected_pivot;
            int original_pivot_rule;

            printf("\n");
            printf("========================================\n");
            printf("          GENERATE TEST DATA\n");
            printf("========================================\n");

            printf("1. Random Data\n");
            printf("2. Sorted Data\n");
            printf("3. Reverse Sorted Data\n");

            printf("Enter your choice: ");
            scanf("%d", &test_choice);

            printf("Enter number of test records (max 100): ");
            scanf("%d", &test_count);

            if (test_count <= 0 || test_count > 100)
            {
                printf("Invalid number of records.\n");
            }

            else if (test_choice < 1 || test_choice > 3)
            {
                printf("Invalid test data choice.\n");
            }

            else
            {
                srand((unsigned int)time(NULL));

                if (test_choice == 1)
                {
                    for (int i = 0; i < test_count; i++)
                    {
                        test_records[i].id = rand() % 1000 + 1;

                        sprintf(test_records[i].name,
                                "Student%d",
                                i + 1);

                        test_records[i].marks = rand() % 101;
                    }
                }

                else if (test_choice == 2)
                {
                    for (int i = 0; i < test_count; i++)
                    {
                        test_records[i].id = i + 1;

                        sprintf(test_records[i].name,
                                "Student%d",
                                i + 1);

                        test_records[i].marks = i;
                    }
                }

                else if (test_choice == 3)
                {
                    for (int i = 0; i < test_count; i++)
                    {
                        test_records[i].id = test_count - i;

                        sprintf(test_records[i].name,
                                "Student%d",
                                i + 1);

                        test_records[i].marks = test_count - i;
                    }
                }

                printf("\nTest data generated successfully!\n");

                printf("\nGenerated Records:\n");
                printf("----------------------------------------\n");

                printf("Id\tName\t\t\tMarks\n");
                printf("----------------------------------------\n");

                for (int i = 0; i < test_count; i++)
                {
                    printf("%d\t%-20s\t%d\n",
                           test_records[i].id,
                           test_records[i].name,
                           test_records[i].marks);
                }

                original_pivot_rule = pivot_rule;

                printf("\n");
                printf("========================================\n");
                printf("       PIVOT PERFORMANCE COMPARISON\n");
                printf("========================================\n");

                for (selected_pivot = 1;
                     selected_pivot <= 3;
                     selected_pivot++)
                {
                    student temp_records[100];

                    for (int i = 0; i < test_count; i++)
                    {
                        temp_records[i] = test_records[i];
                    }

                    pivot_rule = selected_pivot;

                    comparisons = 0;
                    swaps = 0;
                    recursive_calls = 0;

                    current_depth = 0;
                    max_depth = 0;

                    quickSort(temp_records, 0, test_count - 1);

                    printf("\n");
                    printf("----------------------------------------\n");

                    printf("Pivot Rule: ");

                    if (selected_pivot == 1)
                        printf("First Element\n");
                    else if (selected_pivot == 2)
                        printf("Middle Element\n");
                    else
                        printf("Last Element\n");

                    printf("Comparisons             : %lld\n",
                           comparisons);

                    printf("Swaps                   : %lld\n",
                           swaps);

                    printf("Recursive Calls         : %lld\n",
                           recursive_calls);

                    printf("Maximum Recursion Depth : %d\n",
                           max_depth);

                    if (test_count > 1)
                    {
                        if (max_depth > test_count / 2)
                            printf("Warning: Highly unbalanced partitioning.\n");
                        else
                            printf("Partitioning appears reasonably balanced.\n");
                    }
                }

                pivot_rule = original_pivot_rule;

                printf("\n");
                printf("========================================\n");
                printf("Performance analysis completed.\n");
                printf("Original pivot rule restored.\n");
                printf("========================================\n");
            }
        }

        else if (choice != 9)
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\nProgram terminated successfully.\n");

    return 0;
}
