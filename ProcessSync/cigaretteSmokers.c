#include <stdlib.h>
#include <stdio.h>
 
#include "mtuThread.h"
 
//Semaphores used to control ingredients
SEM_t** smokers;
SEM_t table[3];
 
void smoker(int number, char** argv)
{
	//Print out a message showing this thread has started
	if (number == 0)
		printf(" Smoker(Paper) Thread Started.\n");
	else if (number == 1)
		printf("  Smoker(Tobacco) Thread Started.\n");
	else
		printf("   Smoker(Matches) Thread Started.\n");
 
	//Smokers continue making cigarettes forever
	while(1)
	{
		//Wait for both ingredients that this smoker is missing
		SEMAPHORE_WAIT(smokers[number][0]);
		SEMAPHORE_WAIT(smokers[number][1]);
 
		//Print out a message to show that the ingredients have been received
		if (number == 0)
			printf(" Smoker(Paper) takes the ingredients.\n");
		else if (number == 1)
			printf("  Smoker(Tobacco) takes the ingredients.\n");
		else
			printf("   Smoker(Matches) takes the ingredients.\n");
 
		//Signal the Agent that you have cleared the table
		SEMAPHORE_SIGNAL(table[number % 3]);
		SEMAPHORE_SIGNAL(table[(number + 1) % 3]);
 
		//Smoke the cigarette that was just made
		if (number == 0)
			printf(" Smoker(Paper) is smoking.\n");
		else if (number == 1)
			printf("  Smoker(Tobacco) is smoking.\n");
		else
			printf("   Smoker(Matches) is smoking.\n");
 
	}
}
 
void agent(int count, char** argv)
{
	int i;
	int item;
 
	//Print a message showing the Agent thread has started
	printf("Agent Thread Started.\n");
 
	//Seed the random number generator
	srand(time(NULL));
 
	//Give out ingredients "count" number of times
	for (i = 0; i < count; i++)
	{
		//Choose a random smoker to give the ingredients to
		item = (int)(((double)rand() / (double)RAND_MAX) * 3.0);
 
		//Signal the smoker that the ingredients are on the table
		SEMAPHORE_SIGNAL(smokers[item][0]);
		SEMAPHORE_SIGNAL(smokers[item][1]);
 
		//Print out a message stating that the ingredients have been placed on the table
		if (item == 0)
			printf("Agent gives ingredients to Smoker(Paper).");
		else if (item == 1)
			printf("Agent gives ingredients to Smoker(Tobacco).");
		else
			printf("Agent gives ingredients to Smoker(Matches).");
 
		printf(" (%d)\n", i + 1);
 
		//Wait for a signal from the smoker that the table has been cleared
		SEMAPHORE_WAIT(table[item % 3]);
		SEMAPHORE_WAIT(table[(item + 1) % 3]);
	}
 
	//Exit the thread, resuming the main thread
	THREAD_EXIT();
}
 
int main( int argc, char **argv )
{
	int count, i, j;
 
	//Thread variables
	THREAD_t smoker_threads[3];
	THREAD_t theAgent;
 
	//Check for correct parameter usage
	if (argc != 2)
	{
		printf("Please specify a run count at the command prompt.\n");
		exit(0);
	}
 
	//Figure out how many times to give ingredients away
	count = atoi(argv[1]);
 
	//Create all the Smoker threads and Semaphores
	smokers = (SEM_t**)malloc(sizeof(SEM_t*) * 3);		
	for (i = 0; i < 3; i++)
	{
		smokers[i] = (SEM_t*)malloc(sizeof(SEM_t) * 2);
		for (j = 0; j < 2; j++)
		{
			smokers[i][j] = SEMAPHORE_INIT(0);
		}
		table[i] = SEMAPHORE_INIT(0);
		smoker_threads[i] = THREAD_CREATE(smoker, THREAD_SIZE, THREAD_SUSPENDED, i, (char **) 0);
	}
 
	//Start up the smoker threads
	for (i = 0; i < 3; i++)
		THREAD_RESUME(smoker_threads[i]);
 
	//Create and start the Agent thread
	theAgent = THREAD_CREATE(agent, THREAD_SIZE, THREAD_NORMAL, count, (char**)0);
 
	//Wait for the Agent to quit
	THREAD_JOIN(theAgent);
 
	//Exit the program
    return 0;
}