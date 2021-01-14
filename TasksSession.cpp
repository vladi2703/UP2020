#include <iostream>
void printMatrix(double** matrix, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
void printCompleteTasks(double** matrix, int size)
{
    std::cout << "Tasks: ";
    for (int i = size; i >= 0; i--)
    {
        std::cout << matrix[i][0] << ' ';
    }
    std::cout << '\n';
}
void sortTasks(double** taskChar, int taskCount)
{   
    
    for (int i = 0; i < taskCount; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < taskCount; j++)
        {
            if (taskChar[j][3] < taskChar[minIndex][3])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(taskChar[i], taskChar[minIndex]);
        }
    }



}
int distributeTasks(double** taskChar, int totalTime, int* counter, int tasksCount)
{
    if (*counter >= tasksCount || totalTime < int(taskChar[*counter][1]))
    {
        return totalTime;
    }
    totalTime -= int(taskChar[*counter][1]);
    *counter += 1;
    distributeTasks(taskChar, totalTime, counter, tasksCount);
}
void weightCalculation(double** taskChar, int* minutesPerDay, int daysLeft, int tasksCount, int* totalTime)
{
    *totalTime = 0;
    for (int i = 0; i < daysLeft; i++) // calculate total time
    {
        *totalTime += minutesPerDay[i];
    }
    for (int i = 0; i < tasksCount; i++)    ///calculate weight of every task
    {
        taskChar[i][3] = taskChar[i][2] / taskChar[i][1];
    }
}
int main()
{
    int tasksCount, daysLeft;
    std::cin >> tasksCount;
    double** taskChar = new double*[tasksCount];    //every task on a diff line
    for (int i = 0; i < tasksCount; i++)
    {
        taskChar[i] = new double[4];    //task characteristics
        for (int j = 0; j < 3; j++)
        {
            std::cin >> taskChar[i][j];
        }
    }
    std::cin >> daysLeft;
    int* minutesPerDay = new int[daysLeft];
    for (int i = 0; i < daysLeft; i++)
    {
        std::cin >> minutesPerDay[i];
    }

    int totalTime, timeRemaining;
    int tasksComplete = 0;
    
    weightCalculation(taskChar, minutesPerDay, daysLeft, tasksCount, &totalTime);
    sortTasks(taskChar, tasksCount);
    timeRemaining = distributeTasks(taskChar, totalTime, &tasksComplete, tasksCount);
    tasksComplete--; //recursion adds 1 before return
    int minutes = timeRemaining % 60; 
    int hours = timeRemaining/60; 
    printCompleteTasks(taskChar, tasksComplete);
    std::cout << "Time remaining " << hours << ':' << minutes << std::endl;

    //std::cout << distributeTasks(taskChar, totalTime, 0, tasksCount) << std::endl;
   printMatrix(taskChar, tasksCount, 4);
}

//TODO: AKO NE SA PODREDENI PO VREME - PURVI PRIMER