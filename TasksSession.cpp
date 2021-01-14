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
void printCompleteTasks(int* matrix, int size)
{
    std::cout << "Tasks: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << matrix[i] << ' ';
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
int distributeTasks(double** taskChar, int totalTime, int* counter, int tasksCount, int* completedTasks, int *completedCounter) //completedCounter -> counter to fill the array of completed tasks; counter -> to go thru all the tasks
{
    if (*counter < 0 || totalTime == 0)
    {
        return totalTime;
    }
    if (totalTime < int(taskChar[*counter][1]))
    {
        *counter -= 1;
      return  distributeTasks(taskChar, totalTime, counter, tasksCount, completedTasks, completedCounter);
    }
    totalTime -= int(taskChar[*counter][1]);
    completedTasks[*completedCounter] = int(taskChar[*counter][0]);
    *counter -= 1;
    *completedCounter += 1;
    return distributeTasks(taskChar, totalTime, counter, tasksCount, completedTasks, completedCounter);
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
    int* completedTasks = new int[tasksCount];

    int totalTime, timeRemaining;
    int counter = tasksCount-1; //counter->to go thru all the tasks
    int completedCounter = 0; //completedCounter -> counter to fill the array of completed tasks
    weightCalculation(taskChar, minutesPerDay, daysLeft, tasksCount, &totalTime);
    sortTasks(taskChar, tasksCount);
    timeRemaining = distributeTasks(taskChar, totalTime, &counter, tasksCount, completedTasks, &completedCounter);
    int minutes = timeRemaining % 60; 
    int hours = timeRemaining/60; 
    printCompleteTasks(completedTasks, completedCounter);
    std::cout << "Time remaining " << hours << ':' << minutes << std::endl;;
   // printMatrix(taskChar, tasksCount, 4);
    delete[] completedTasks;
    delete[] minutesPerDay;
    for (int i = 0; i < tasksCount; i++)
    {
        delete[] taskChar[i];
    }
    delete[] taskChar; 
}
