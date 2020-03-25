#include <stdio.h>

#define NB_MAX_CLASSES 15

typedef struct classe {
	int numClasse; 
	int nbRep;
	int nbGoodAnswers;
} Classe;

int researchClasses(int realClasses[],Classe distinctClasses[]);

void main(void) {
	int realClasses[NB_MAX_CLASSES] = { 5, 2, 5, 3, 5, 3, 2, 4, 7, 9, 3, 1, 13, 0, 5 };
	int estimateClasses[NB_MAX_CLASSES] = { 5, 5, 1, 2, 1, 3, 2, 4, 7, 9, 3, 13, 1, 5, 3 };
	
	/*Test function researchClasses
	Classe distinctClasses[NB_MAX_CLASSES];
	int nbDistinctClasses = researchClasses(realClasses, distinctClasses);
	for (int posDistinctClasses = 0;posDistinctClasses < nbDistinctClasses;posDistinctClasses++) {
		printf("NumClasse = %d", distinctClasses[posDistinctClasses].numClasse);
		printf("| NbRep = %d", distinctClasses[posDistinctClasses].nbRep);
		printf("| NbGoodAnswers = %d\n", distinctClasses[posDistinctClasses].nbGoodAnswers);
	}
	printf("Nombre de classes = %d", nbDistinctClasses);
	getchar();
	*/
}

int researchClasses(int realClasses[], Classe distinctClasses[]) {
	int currentRealClasse = 0;
	int realClasse;
	int currentDistinctClasse;
	int nbDistinctClasses = 0;
	int posDistinctClasses;
	while (currentRealClasse < NB_MAX_CLASSES) {
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
