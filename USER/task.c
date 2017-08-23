#include "task.h"

#define MAX_TASKS    3
#define TOO_MANY_TASKS  1
Task tasks[MAX_TASKS];
uint8_t errCode;

uint8_t AddTask(pFun pTask, uint16_t delay, uint16_t period)
{
    uint8_t index = 0;
    
    //寻找任务数组的空位置
    while((tasks[index].pTask != 0) && (index < MAX_TASKS))
    {
        index++;
    }
    
    //任务列表已满
    if(index == MAX_TASKS)
    {
        errCode = TOO_MANY_TASKS;
        return MAX_TASKS;
    }
    tasks[index].pTask = pTask;
    tasks[index].Delay = delay;
    tasks[index].Period = period;
    tasks[index].RunFlag = 0;
    
    return index;
}

uint8_t DeleteTask(uint8_t taskIndex) 
{
  uint8_t returnCode;
  
  if (tasks[taskIndex].pTask == 0)
  {
    // No task at this location... 
    // ...also return an error code
    //errCode = CANNOT_DELETE_TASK;
    returnCode = 1;
  }
  else
  {
    returnCode = 0;
  }      
  
  tasks[taskIndex].pTask = 0x0000;
  tasks[taskIndex].Delay = 0;
  tasks[taskIndex].Period = 0;
  tasks[taskIndex].RunFlag = 0;
  
  return returnCode;       // return status
}

void DispatchTasks(void)
{
    uint8_t index = 0;
    
    for(index = 0; index < MAX_TASKS; index++)
    {
        if(tasks[index].RunFlag)
        {
            tasks[index].pTask();
            tasks[index].RunFlag = 0;
            if(0 == tasks[index].Period)
            {
                DeleteTask(index);
            }
        }
        
    }
    //ReportErrStatus();
    //GoToSleep();
    //asm("wfi");
}

void UpdateTask(void)
{
    uint8_t i;
    
    for(i = 0; i < MAX_TASKS; i++)
    {
        if(tasks[i].pTask)
        {
            if(tasks[i].Delay == 0)
            {
                tasks[i].RunFlag = 1;
                tasks[i].Delay = tasks[i].Period;
            }
            else
            {
                tasks[i].Delay -= 1;
            }
        }
    }
}