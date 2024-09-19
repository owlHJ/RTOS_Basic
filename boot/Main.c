#include "stdint.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#include "HalUart.h"
#include "HalTimer.h"
#include "task.h"
#include "Kernel.h"

static void Hw_Init(void);

static void Printf_test(void);
static void Timer_test(void);

static void Kernel_init(void);

void User_task0(void);
void User_task1(void);
void User_task2(void);
void User_task3(void);

void main(void)
{

    Hw_Init();

    uint32_t i = 100;
    while ((--i))
    {
        /* code */
        //Hal_uart_put_char("1");
        Hal_uart_put_char('a');
    }
    
    Hal_uart_put_char('\n');

    putstr("Hello World!\n");

    Printf_test();
    Timer_test();

    Kernel_init();

    while(true);

}
static void Hw_Init(void)
{
    Hal_interrupt_init();
    Hal_uart_init();
    Hal_timer_init();
}
static void Printf_test(void)
{
    char* str           = "printf pointer test";
    char* nullptr       = 0;
    uint32_t i          = 5;
    uint32_t* sysctrl0  = (uint32_t*)0x10001000;

    debug_printf("%s\n", "Hello printf");
    debug_printf("output string pointer: %s\n", str );
    debug_printf("%s is null pointer, %u number\n", nullptr, 10);
    debug_printf("%u = 5\n", i);
    debug_printf("dec=%u hex=%x\n",0xff,0xff);
    debug_printf("print zero %u\n",0);
    debug_printf("SYSCTRL0 %x\n", *sysctrl0);
    
    return;
}
static void Timer_test(void)
{
    for(uint32_t i = 0; i < 5 ; i++)
    {
        debug_printf("current count : %u\n", Hal_timer_get_1ms_counter());
        delay(10);
    }
}
static void Kernel_init(void)
{
    uint32_t taskId;

    Kernel_task_init();

    taskId = Kernel_task_create(User_task0,1);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task0 Creation fail\n");
    }
    taskId = Kernel_task_create(User_task1,1);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task1 Creation fail\n");
    }
    taskId = Kernel_task_create(User_task2,1);
    if (NOT_ENOUGH_TASK_NUM == taskId)
    {
        putstr("Task2 Creation fail\n");
    }

    Kernel_start();

    return;
}
void User_task0(void)
{   
    uint32_t local = 0;

    while(true)
    {
        debug_printf("User Task #0 SP=0x%x\n\n",&local);
        Kernel_yield();
    }

    return;
}
void User_task1(void)
{
    uint32_t local = 0;
    
    while(true)
    {
        debug_printf("User Task #1 SP=0x%x\n\n",&local);
        Kernel_yield();
    }

    return;
}
void User_task2(void)
{
    uint32_t local = 0;
    
    while(true)
    {
        debug_printf("User Task #2 SP=0x%x\n\n",&local);
        Kernel_yield();
    }

    return;
}
void User_task3(void)
{
    uint32_t local = 0;
    
    while(true)
    {
        debug_printf("User Task #3 SP=0x%x\n\n",&local);
        Kernel_yield();
    }

    return;
}