# Algoritm-CYK
Nume: Popa Andreea-Denisa

Descriere: Pentru o gramatica in FNC si un cuvant, sa se verifice daca cuvantul apartine gramaticii.

Input: O gramatica relugata,citita din fisierul "gramatica.txt" si un cuvant citit de la tastatura.

Observatii: Productiile sunt de forma A->a sau A->BC. Gramtica in FNC este implementata printr-o clasa care este compusa dintr-un vector de tip pair<char,pair<char,char>>> in care salvam productiile si o varabiabila de tip int in care salvam numarul total de productii. 

Functii:

1. gramaticaFNC();

-constructor fara parametri;

-citeste din fisier numarul de productii si elementele vectorului.

2. void afisare();

-afiseaza pe ecran productiiile gramaticii in FNC.

3. bool algoritmCYK()

-creaza o matrice tridimensionala reprezentand tabelul necesar algoritmului;

-completeaza mai intai prima linie din matrice: caut productiile in care se regaseste a i-a litera din cuvant si adaug neterminalul in matrice;

-parcurgem restul matricei, verificam productiile si completam matricea;

-la sfarsit pargurgem in adamcime cu contorul si verificam daca unul elelementele matricei de pe pozitia[strlen(cuvant)-1][0][i] este egal cu simbolul de start "S";

-returneaza true daca cuvantul este acceptat de gramatica in FNC sau false,invers.


4. ~gramaticaFNC();

-destructor;

-elibereaza memoria alocata.
