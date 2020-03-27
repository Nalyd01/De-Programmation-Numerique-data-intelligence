#pragma once
#include <stdio.h>
#include <stdlib.h> 

#define MAX_NB_CLASSES 10000

typedef struct classe {
	int numClasse; // Class number (which corresponds to an activity)
	int nbRep; // Number of class occurrences in the table realClasses
	int nbGoodAnswers; // Number of good answers
} Classe;

void displayResultsForEachClasses(int realClasses[], int estimateClasses[], int size);
void displayAccuracy(int realClasses[], int estimateClasses[], int size);
void displayBarChart(int realClasses[], int estimateClasses[], int size);