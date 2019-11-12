#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main(int argc, char* argv[]) 
{
	int currentTime = 0;
	int endTime = 10;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	LinkedQueue* pArrivalQueue = NULL;
	LinkedQueue* pWaitQueue = NULL;
	QueueNode* pServiceNode1 = NULL;

	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	if (pArrivalQueue == NULL || pWaitQueue == NULL) {
		printf("Error, createLinkedQueue() in main()\n");
		return FALSE;
	}

	insertCustomer(0, 3, pArrivalQueue);
	insertCustomer(2, 2, pArrivalQueue);
	insertCustomer(4, 1, pArrivalQueue);
	insertCustomer(6, 1, pArrivalQueue);
	insertCustomer(8, 3, pArrivalQueue);

	for (currentTime = 0; currentTime < endTime; currentTime++) {
		processArrival(currentTime, pArrivalQueue, pWaitQueue);

		// if there are nodes to be processed
		if (pServiceNode1 != NULL) {
			pServiceNode1 = processServiceNodeEnd(currentTime,
				pServiceNode1, &serviceUserCount, &totalWaitTime);
		}

		// get new customer from waiting queue
		if (pServiceNode1 == NULL) {
			pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
		}

		// printf Waiting Queue
		printWaitQueueStatus(currentTime, pWaitQueue);
		printf("\n");

		//// debug
		//if (currentTime == 6) {
		//	int temp=0;
		//}
	}

	// print final result
	printReport(pWaitQueue, serviceUserCount, totalWaitTime);

	// free memory
	if (pServiceNode1 != NULL) {
		free(pServiceNode1);
	}

	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);

	return 0;
}
