#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType {arrival,start,end} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime; // given value, time needed to process customer service 
	int startTime; // service start time
	int endTime; // time of service is completed , calulated endTime=startTime+serviceTime
} SimCustomer;

#endif // !_SIM_DEF_
