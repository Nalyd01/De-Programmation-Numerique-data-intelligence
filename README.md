# De la programmation numerique à la data intelligence

## Functions

### ResearchClasses

```
int researchClasses (int realClasses[], Classe distinctClasses[], int size) ;
``` 

Renvoie un tableau de structures, chaque cellule correspond à une classe. La fonction renvoie aussi la taille du tableau. La fonction va initialiser la valeur du nombre de bonnes réponses pour chaque classe à 0 et va calculer le nombre de répétition de la classe dans realClasses. 

### DisplayResultsForEachClasses

```
void displayResultsForEachClasses(int realClasses[], int estimateClasses[], int size) ;
```

Permet d’afficher un tableau avec différentes données. (ex : les classes, le nombre de bonnes réponses, le pourcentage de bonnes réponses, …). La fonction bouclera sur le tableau de structures après l’avoir mis à jour avec les fonctions nécessaires. 

### GoodAnswers

```
void goodAnswers(int realClasses[], int estimateClasses[], int size, Classe distinctClasses[], int sizeDistinctClasses) ;
```

Met à jour le tableau de structures, en calculant la nombre de bonnes réponses et en y mettant le résultat dans la structure de la classe correspondante. 

### CalculatePercentage

```
void calculatePercentage(int nbRep, int nbGoodAnswers) ;
```

Calcule le pourcentage de bonne réponses ; 

### DisplayAccuracy

```
void displayAccuracy(int realClasses[], int estimateClasses[], int size);
```

Affiche le taux de précision du programme.

### CalculateAccuracy 

```
double calculateAccuracy(int realClasses[], int estimateClasses[], int size);
```

Calcule le taux de précision du programme en calculant pour chaque classe le taux de bonnes réponses et puis en faisant la moyenne des résultats. 

### DisplayBarChart

```
void displayBarChart(int realClasses[], int estimateClasses[], int size); 
```

Affiche un diagramme en bâtons comprenant le nombre de bonnes réponses, le pourcentage de bonnes réponses, les numéros de classe et le tout selon une certaine échelle.

### RescaleDate

```
int rescaleBarChart (Classe distinctClasses[],int sizeDistinctClasses) ; 
```

Si besoin, mets à l’échelle les nombres trop grands ; 
