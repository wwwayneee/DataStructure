#ifndef header_h
#define header_h

#include <stdio.h>
typedef enum {GoingUP = 1, GoingDown, SpeedUp, SpeedDown, SlowUp, SlowDown, Idle, Stop, DoorOpen, DoorOpening, DoorClosing} ElevatorState;
#define CLOSETEST			40		/* 每隔40t测试一次，无人进出则关门 */
#define OVERTIME			300		/* 电梯在非一层等待的最长时间，超过则返回一层 */
#define ACCELERATE		15		/* 加速时间？ */
#define	 UPTIME				51		/* 上升时间？ */
#define DOWNTIMW			61		/* 下降时间？ */
#define UPDECELERATE		14		/* 上升减速 */
#define	 DOWNDECELERATE	23		/* 下降减速 */
#define DOORTIME			20		/* 开关门时间 */
#define INOUTTIME			25		/* 每个人进出电梯所需时间 */
#define	 MAXTIME			10000	/* 模拟时钟的终值 */
#define	 MAXFLOOR			5
#define BASEFLOOR			1

#define Init() (\
{\
	int i;\
	for (i = 0; i <= MAXFLOOR - 1; i++) {\
		Stack[i].next = NULL;\
		Queue[i].next = NULL;\
	}\
	activity.next = NULL;\
})

typedef struct Passenger {
	int ID;
//	int InFloor;	/* 该人进入哪层 */
	int OutFloor;	/* 改人要到哪层 */
	int	GiveupTime;	/* 该人能容忍的等待时间 */
	struct Passenger * next;
}Passenger;

typedef struct Activity {
	int time;
	void (*func)(void);
	struct Activity * next;
}Activity;

typedef struct Passenger_Ele {
	int ID;
	struct Passenger_Ele * next;
}Passenger_Ele;

#endif /* header_h */
