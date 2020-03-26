#include <stdio.h>
#include <stdlib.h> 

#define MAX_NB_CLASSES 100

typedef struct classe {
	int numClasse; // Class number (which corresponds to an activity)
	int nbRep; // Number of class occurrences in the table realClasses
	int nbGoodAnswers; // Number of goog answers
} Classe;

int researchClasses(int realClasses[],Classe distinctClasses[], int size);
void displayResultsForEachClasses(int realClasses[], int estimateClasses[], int size);
void goodAnswers(int realClasses[], int estimateClasses[], int size, Classe distinctClasses[], int sizeDistinctClasse);
double calculatePercentage(int nbRep, int nbGoodAnswers);
void displayAccuracy(int realClasses[], int estimateClasses[], int size); 
double calculateAccuracy(Classe distinctClasses[], int size);

void main(void) {
	int realClasses[8] = { 5, 2, 5, 3, 5, 3, 2, 4 };
	int estimateClasses[8] = { 5, 5, 1, 2, 1, 3, 2, 4 };
}

int researchClasses(int realClasses[], Classe distinctClasses[], int size) {
	int currentRealClasse = 0;
	int realClasse;
	int currentDistinctClasse;
	int nbDistinctClasses = 0;
	int posDistinctClasses;
	while (currentRealClasse < size) {
		realClasse = realClasses[currentRealClasse];
		currentDistinctClasse = 0;
		while (currentDistinctClasse < nbDistinctClasses && realClasse > distinctClasses[currentDistinctClasse].numClasse)
		{
			currentDistinctClasse++;
		}
		if (realClasse != distinctClasses[currentDistinctClasse].numClasse) {

			for (posDistinctClasses = nbDistinctClasses;posDistinctClasses > currentDistinctClasse;posDistinctClasses--) {
				distinctClasses[posDistinctClasses].numClasse = distinctClasses[posDistinctClasses - 1].numClasse;
				distinctClasses[posDistinctClasses].nbRep = distinctClasses[posDistinctClasses - 1].nbRep;
				distinctClasses[posDistinctClasses].nbGoodAnswers = distinctClasses[posDistinctClasses - 1].nbGoodAnswers;
			}
			distinctClasses[currentDistinctClasse].numClasse = realClasse;
			distinctClasses[currentDistinctClasse].nbRep = 1;
			distinctClasses[currentDistinctClasse].nbGoodAnswers = 0;
			nbDistinctClasses++;
		}
		else {
			distinctClasses[currentDistinctClasse].nbRep++;
		}
		currentRealClasse++;
	}
	return nbDistinctClasses;
}

void displayResultsForEachClasses(int realClasses[], int estimateClasses[], int size) {
	double percentage;
	int sizeDistinctClasses; 
	Classe distinctClasses[MAX_NB_CLASSES];

	sizeDistinctClasses = researchClasses(realClasses, distinctClasses, size); 

	goodAnswers(realClasses, estimateClasses, size, distinctClasses, sizeDistinctClasses);

	printf("      Classe\t|   Bien classes   |\tTotal\t|\tPourcentage\n");

	for (int i = 0; i < sizeDistinctClasses; i++) {
		percentage = calculatePercentage(distinctClasses[i].nbRep, distinctClasses[i].nbGoodAnswers);

		printf("\t%d\t|\t %d \t   |\t  %d\t|\t  %.2f%%\n", distinctClasses[i].numClasse, distinctClasses[i].nbGoodAnswers, distinctClasses[i].nbRep, percentage);
	}

	system("pause");
}

void goodAnswers(int realClasses[], int estimateClasses[], int size, Classe distinctClasses[], int sizeDistinctClasses) {
	for (int i = 0; i < size; i++) {

		if (realClasses[i] == estimateClasses[i]) {

			for (int j = 0; j < sizeDistinctClasses; j++) {

				if (distinctClasses[j].numClasse == realClasses[i]) {
					distinctClasses[j].nbGoodAnswers++;
					break;
				}
			}
		}
	}
}

double calculatePercentage(int nbRep, int nbGoodAnswers) {
	return (double)nbGoodAnswers / nbRep * 100;
}

void displayAccuracy(int realClasses[], int estimateClasses[], int size) {
	Classe distinctClasses[MAX_NB_CLASSES];

	int sizeDistinctClasses = researchClasses(realClasses, distinctClasses, size); 
	goodAnswers(realClasses, estimateClasses, size, distinctClasses, sizeDistinctClasses);

	double accuracy = calculateAccuracy(distinctClasses, sizeDistinctClasses);

	printf("L'accuracy est de %.2f%%\n", accuracy);
	system("pause");
}

double calculateAccuracy(Classe distinctClasses[], int sizeDistinctClasses) {
	double sum = 0;

	for (int i = 0; i < sizeDistinctClasses; i++) {
		sum += calculatePercentage(distinctClasses[i].nbRep, distinctClasses[i].nbGoodAnswers);
	}
	 
	return sum / sizeDistinctClasses;
}