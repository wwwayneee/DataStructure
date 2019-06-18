#include "header.h"
#include "function.h"

int Time = 0;
int CallUp[MAXFLOOR] = {0};
int CallDown[MAXFLOOR] = {0};
int CallCar[MAXFLOOR] = {0};
int Floor = BASEFLOOR;
ElevatorState State = Idle;
int PassengerID = 0;
Activity activity = {0, NULL, NULL};
Passenger_Ele Stack[5] = {0};
Passenger Queue[5] = {0};

int main(int argc, const char * argv[]) {
	
	return 0;
}
