#ifndef _TASK_H
#define _TASK_H

typedef void (*pFun)(void);
typedef struct __Task
{
    pFun pTask;                 //������ָ��
    uint16_t Delay;             //������ʱ
    uint16_t Period;            //��������
    uint8_t RunFlag;            //���б�־
}Task;

extern void DispatchTasks(void);
extern uint8_t AddTask(pFun pTask, uint16_t delay, uint16_t period);
extern uint8_t DeleteTask(uint8_t TaskIndex);
extern void UpdateTask(void);

#endif  //_TASK_H