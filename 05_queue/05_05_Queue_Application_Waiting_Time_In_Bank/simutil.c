#include <stdint.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

//// add new customer to arrived customer queue
//void insertCustomer(int arrivalTime, int processTime, LinkedQueue* pQueue)
//{
//
//}
//
//// move customer from arrived queue to waiting queue
//void processArrival(int currentTime, LinkedQueue* pArrivalQueue, LinkedQueue* pWaitQueue)
//{
//
//}
//
//// process customer in waiting queue
//QueueNode* processServiceNodeStart(int curretTime, LinkedQueue* pWaitQueue)
//{
//
//}
//
//// Check if service is completed
//QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode,
//	int* pServiceUserCount, int* pTotalWaitTime)
//{
//
//}
//
//// print customer state
//void printSimCustomer(int currentTime, SimCustomer customer)
//{
//
//}
//
//// print waiting queue state
//void printWaitQueueStatus(int currentTime, LinkedQueue* pWaitQueue)
//{
//
//}
//
//// print final result
//void printReport(LinkedQueue* pWaitQueue, int serviceCount, int totalWaitTime)
//{
//
//}

//////////////////////////////////////////////////////////////////////////////////////

// add new customer to arrived customer queue
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue* pQueue)
{
	int i = 0;
	if (pQueue != NULL) {
		QueueNode node = { 0, };
		node.data.status = arrival;
		node.data.arrivalTime = arrivalTime;
		node.data.serviceTime = serviceTime;
		node.data.startTime = 0;
		node.data.endTime = 0;
		enqueueLQ(pQueue, node);
	}
}

// move customer from arrived queue to waiting queue if meet the condition
void processArrival(int currentTime, LinkedQueue* pArrivalQueue, LinkedQueue* pWaitQueue)
{
	QueueNode* pArrivalNode = NULL;
	int isEmpty = 0;

	isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	while (isEmpty == FALSE) {
		pArrivalNode = peekLQ(pArrivalQueue);
		
		// move node from Arrival Queue to Wait Queue
		if (pArrivalNode->data.arrivalTime == currentTime) {
			enqueueLQ(pWaitQueue, *pArrivalNode);
			printSimCustomer(currentTime, pArrivalNode->data);

			free(dequeueLQ(pArrivalQueue));
		}
		else {
			break;
		}

		isEmpty = isLinkedQueueEmpty(pArrivalQueue);
	}
}

// start new customer service in waiting queue
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue* pWaitQueue)
{
	QueueNode* pReturn = NULL; // 
	QueueNode* pServiceNode = NULL; // service start node
	int isEmpty = 0;

	if (pWaitQueue == NULL) {
		return NULL;
	}

	isEmpty = isLinkedQueueEmpty(pWaitQueue);
	if (isEmpty == FALSE) {
		pServiceNode = dequeueLQ(pWaitQueue);
		if (pServiceNode != NULL) {
			pServiceNode->data.status = start;
			pServiceNode->data.startTime = currentTime;
			printSimCustomer(currentTime, pServiceNode->data);

			pReturn = pServiceNode;
		}
	}

	return pReturn;
}

// Check if current service node is completed or not
// if service is completed , update ServiceUserCount & TotalWaitTime
QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode,
	int* pServiceUserCount, int* pTotalWaitTime)
{
	int endTime = 0;
	int waitTime = 0;
	QueueNode* pReturn = NULL;

	if (pServiceNode == NULL || pServiceUserCount == NULL || pTotalWaitTime == NULL) {
		return NULL;
	}

	endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;

	// check if service is finished
	if (endTime <= currentTime) {
		waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
		(*pServiceUserCount)++;
		(*pTotalWaitTime) += waitTime;

		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);

		free(pServiceNode);
		pReturn = NULL;
	}
	else {
		//do nothing
		pReturn = pServiceNode;
	}

	return pReturn;
}

// print customer state
void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("[%d],", currentTime);

	switch (customer.status)
	{
		case arrival:
			printf("Customer Arrived\n");
			break;
		case start:
			printf("Service Start");
			printf(",Arrived Time-%d, waiting time-%d\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));
			break;
		case end:
			printf("Service End");
			printf(",Arrived Time-%d,Start Time-%d,Waiting Time-%d,Service Time-%d\n",
				customer.arrivalTime, customer.startTime,
				customer.startTime - customer.arrivalTime,
				customer.endTime - customer.startTime);
			break;
		default:
			break;
	}
}

// print waiting queue state
void printWaitQueueStatus(int currentTime, LinkedQueue* pWaitQueue)
{
	printf("[%d], Number of Waiting Customers : %d\n",
		currentTime,
		pWaitQueue->currentElementCount);
}

// print final result
void printReport(LinkedQueue* pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("\n\n------- REPORT ------------------\n");
	printf("Number of Serviced Customers: %d\n", serviceUserCount);
	if (serviceUserCount > 0) {
		printf("Average Waiting Time: %f\n", 
			( (float)totalWaitTime / (float)serviceUserCount) );
	}
	printf("Current Number of Waiting Customers: %d\n",
		pWaitQueue->currentElementCount);
}