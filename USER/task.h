#ifndef _TASK_H
#define _TASK_H

typedef void (*pFun)(void);
typedef struct __Task
{
    pFun pTask;                 //任务函数指针
    uint16_t Delay;             //任务延时
    uint16_t Period;            //任务周期
    uint8_t RunFlag;            //运行标志
}Task;

extern void DispatchTasks(void);
extern uint8_t AddTask(pFun pTask, uint16_t delay, uint16_t period);
extern uint8_t DeleteTask(uint8_t TaskIndex);
extern void UpdateTask(void);

#endif  //_TASK_H