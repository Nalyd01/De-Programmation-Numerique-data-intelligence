#include "ClassificationStatistics.h"

int researchClasses(int realClasses[], Classe distinctClasses[], int size); 
void goodAnswers(int realClasses[], int estimateClasses[], int size, Classe distinctClasses[], int sizeDistinctClasses);
double calculatePercentage(int nbRep, int nbGoodAnswers); 
double calculateAccuracy(int realClasses[], int estimateClasses[], int size);
int rescaleBarChart(Classe distinctClasses[], int sizeDistinctClasses);

/*void main(void) {
	int realClasses[8] = { 5, 2, 5, 3, 5, 3, 2, 4 };
	int estimateClasses[8] = { 5, 5, 1, 2, 1, 3, 2, 4 };
	int size = 8;

	displayAccuracy(realClasses, estimateClasses, size); 
}*/

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
	double accuracy = calculateAccuracy(realClasses, estimateClasses, size);

	printf("L'accuracy est de %.2f%%\n", accuracy);
	system("pause");
}

double calculateAccuracy(int realClasses[], int estimateClasses[], int size) {
	Classe distinctClasses[MAX_NB_CLASSES];
	int sizeDistinctClasses;
	int sumGoodAnswers = 0;
	int sumNbRep = 0;

	sizeDistinctClasses = researchClasses(realClasses, distinctClasses, size);
	goodAnswers(realClasses, estimateClasses, size, distinctClasses, sizeDistinctClasses);

	for (int i = 0; i < sizeDistinctClasses; i++) {
		sumGoodAnswers += distinctClasses[i].nbGoodAnswers;
		sumNbRep += distinctClasses[i].nbRep;
	}

	return (double)sumGoodAnswers / sumNbRep * 100;
}
void displayBarChart(int realClasses[], int estimateClasses[], int size) {
	int sizeDistinctClasses;
	Classe distinctClasses[MAX_NB_CLASSES];
	int nbGoodAnswers;
	int nbWrongAnswers;
	int nbTotalAnswers;
	int scale;

	sizeDistinctClasses = researchClasses(realClasses, distinctClasses, size);
	goodAnswers(realClasses, estimateClasses, size, distinctClasses, sizeDistinctClasses);
	
	scale = rescaleBarChart(distinctClasses, sizeDistinctClasses);
	
	printf("Legende:\n\tP : nbre de bien place\n\tN : nbre pas correctement place\n\tT : Total\n");
	printf("  %d %d        %d        %d        %d        %d        %d", 0, 1 * scale, 10 * scale, 20 * scale, 30 * scale, 40 * scale, 50 * scale);
	printf("\n__|_|________|_________|_________|_________|_________|_");
	printf("\n  |");
	printf("\n  |");
	printf("\n  |");
	for (int i = 0;i < sizeDistinctClasses;i++) {
		printf("\n P|");
		for (nbGoodAnswers = distinctClasses[i].nbGoodAnswers / scale; nbGoodAnswers > 0; nbGoodAnswers--) {
			printf("_");
		}
		printf("\n%dN|", distinctClasses[i].numClasse);
		nbWrongAnswers = (distinctClasses[i].nbRep - distinctClasses[i].nbGoodAnswers) / scale;
		for (nbWrongAnswers; nbWrongAnswers > 0; nbWrongAnswers--) {
			printf("_");
		}
		printf("\n T|");
		for (nbTotalAnswers = distinctClasses[i].nbRep / scale; nbTotalAnswers > 0; nbTotalAnswers--) {
			printf("_");
		}
		printf("\n  |");
	}
	printf("\n");
	system("pause");
}
int rescaleBarChart(Classe distinctClasses[], int sizeDistinctClasses) {
	int nbMaxClasses = 0;
	int scale = 1;
	
	for (int i = 0;i < sizeDistinctClasses;i++) {
		if (distinctClasses[i].nbRep > nbMaxClasses) {
			nbMaxClasses = distinctClasses[i].nbRep;
		}
	}
	
	while ((nbMaxClasses / scale) > 50)
	{
		scale *= 2;
	}
	
	return scale;
}