#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_REQUESTS 10 // Maximum number of requests that can be handled
#define MIN_TIME 5 // Minimum time in minutes to handle a request
#define MAX_TIME 20 // Maximum time in minutes to handle a request

int main()
{
    int student_queue[MAX_REQUESTS], faculty_queue[MAX_REQUESTS];
    int student_count = 0, faculty_count = 0;
    int total_time = 0;

    srand(time(NULL)); // Seed the random number generator with the current time

    for (int time = 600; time <= 720; time++) // Loop from 10am to 12am
    {
        if (rand() % 2 == 0 && student_count < MAX_REQUESTS) // 50% chance of a new student request
        {
            student_queue[student_count++] = rand() % (MAX_TIME - MIN_TIME + 1) + MIN_TIME; // Add a random request time to the student queue
        }

        if (rand() % 4 == 0 && faculty_count < MAX_REQUESTS) // 25% chance of a new faculty request
        {
            faculty_queue[faculty_count++] = rand() % (MAX_TIME - MIN_TIME + 1) + MIN_TIME; // Add a random request time to the faculty queue
        }

        if (student_count == 0 && faculty_count == 0) // No requests to handle
        {
            continue;
        }

        int request_time;

        if (student_count > 0 && (faculty_count == 0 || rand() % 2 == 0)) // Handle a student request
        {
            request_time = student_queue[0];
            for (int i = 1; i < student_count; i++)
            {
                student_queue[i - 1] = student_queue[i]; // Shift the queue left to remove the handled request
            }
            student_count--;
        }
        else // Handle a faculty request
        {
            request_time = faculty_queue[0];
            for (int i = 1; i < faculty_count; i++)
            {
                faculty_queue[i - 1] = faculty_queue[i]; // Shift the queue left to remove the handled request
            }
            faculty_count--;
        }

        total_time += request_time;
    }

    printf("Total time spent on handling queries: %d minutes\n", total_time);
    printf("Average query time: %.2f minutes\n", (float)total_time / (MAX_REQUESTS * 2));

    return 0;
}
