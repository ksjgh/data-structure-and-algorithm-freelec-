#ifndef _SIM_UTIL_
#define _SIM_UTIL_

// add new customer to arrived customer queue
void insertCustomer(int arrivalTime, int processTime, LinkedQueue* pQueue);

// move customer from arrived queue to waiting queue
void processArrival(int currentTime, LinkedQueue* pArrivalQueue, LinkedQueue* pWaitQueue);

// process customer in waiting queue
QueueNode* processServiceNodeStart(int curretTime, LinkedQueue* pWaitQueue);

// Check if service is completed
QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode,
							  	 int* pServiceUserCount, int* pTotalWaitTime);

// print customer state
void printSimCustomer(int currentTime, SimCustomer customer);

// print waiting queue state
void printWaitQueueStatus(int currentTime, LinkedQueue* pWaitQueue);

// print final result
void printReport(LinkedQueue* pWaitQueue, int serviceCount, int totalWaitTime);

#endif // !_SIM_UTIL_
