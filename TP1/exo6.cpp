#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    int n;
    Noeud *dernier;

};

struct DynaTableau{
    int* donnees;
    int taille;
    int capacite;

};


void initialise(Liste* liste)
{   liste->premier=nullptr;
    liste->dernier=nullptr;
    liste->n=0;

}

bool est_vide(const Liste* liste)
{
    if(liste->n==0){
        return true;} 
    else {
        return false;}
}

//Ajoute une nouvelle valeur à la fin de la structure (alloue de la mémoire en plus si nécessaire)
void ajoute(Liste* liste, int valeur)
{
    Noeud *nouveau = (Noeud*)malloc(sizeof(Noeud));
    if(nouveau == nullptr) {
        cout << "erreur allocation de mémoire" << endl;
    }

    //donne valeur au nouvel elem
    nouveau->donnee=valeur;
    nouveau->suivant=nullptr;

    if(liste->premier == nullptr){
        liste->premier=nouveau;
        liste->dernier=nouveau;} 
    else {
        liste->dernier->suivant=nouveau;
        liste->dernier=liste->dernier->suivant;
    }

    liste->n = liste->n+1;
}

//affiche la liste
void affiche(const Liste* liste)
{
    if(liste == nullptr){
        cout << "liste vide" << endl;
    }

    Noeud* actuel = liste->premier;

    while (actuel != nullptr){
        cout << "valeur : " << actuel->donnee << endl;
        actuel = actuel->suivant;
    }

}

//Retourne le nième entier de la structure
int recupere(const Liste* liste, int n)
{
    if(n>=0 && n<=liste->n){
        Noeud* actuel= liste->premier;
        for(int i=0; i<n-1; i++){
            actuel = actuel->suivant;
        }
        return actuel->donnee;} 
    else {return -1;}
}

//demander verif philippe pour le -1
//Retourne l’index de valeur dans la structure ou -1 s’il n’existe pas
int cherche(const Liste* liste, int valeur)
{
    int index = 0;
    int compteur = 0;
    bool cherche = false;
    Noeud* actuel= liste->premier;
    while(cherche!=true && actuel!=nullptr){
        if(actuel->donnee==valeur){
            index=compteur;
            cherche=true;
        }
        actuel=actuel->suivant;
        compteur++;
    }
    return index;

    return -1;
}

//Redéfini la nième valeur de la structure avec valeur
void stocke(Liste* liste, int n, int valeur)
{
    if(n>=0 && n<=liste->n){
        Noeud* actuel = liste->premier;
        for(int i=0; i<n-1; i++){
            actuel = actuel->suivant;
        }
        actuel->donnee=valeur;} 
    else {
        cout << "il n'y pas de valeur a cette nieme place" << endl;
    }
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->taille < tableau->capacite){
        tableau->donnees[tableau->taille]=valeur;
        tableau->taille ++;} 
    else {
        //on augmente la capacite de 1 a chaque fois qu'il manque une place
        tableau->capacite ++;
        //realloc(pointeur actuel, nouvelle taille) pour bien avoir la place en memoire (tableau d'entier int*)
        int *ajoutdonnees = (int*)realloc(tableau->donnees, tableau->capacite*sizeof(int));
        if(ajoutdonnees!=NULL){
            tableau->donnees = ajoutdonnees;
            tableau->donnees[tableau->taille]=valeur;
            tableau->taille++;} 
        else {
            cout << "erreur allocation memoire" << endl;
        }
    }

}


void initialise(DynaTableau* tableau, int capacite){
    tableau->donnees=(int*)malloc(capacite *sizeof(int));
    tableau->capacite=capacite;
    tableau->taille=0;
}

bool est_vide(const DynaTableau* liste)
{
    if(liste->taille==0){
        return true;} 
    else {
        return false;
    }
}

void affiche(const DynaTableau* tableau)
{
    for(int i=0; i<tableau->taille; i++){
        cout << "Valeur :" << tableau->donnees[i] << endl;
    }

}

int recupere(const DynaTableau* tableau, int n)
{
    if(n>=0 && n<=tableau->taille){
        return tableau->donnees[n];
    } else {
        cout << "il n'y a pas de valeur pour n" << endl;
    }
    return 0;
}

//verif philippe
int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->taille; i++){
        if(tableau->donnees[i]==valeur){
            return i;
        }
    }
    return -1;

}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n>=0 && n<=tableau->taille){
        tableau->donnees[n]=valeur;
    } else {
        cout << "il n'y a pas de valeur pour n" << endl;
    }

}

//void pousse_file(DynaTableau* liste, int valeur)
//ajouter une valeur a la fin
void pousse_file(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_file(Liste* liste)
//retire la premier valeur rentree
int retire_file(Liste* liste)
{
    Noeud* actuel = liste->premier;
    int valeur = actuel->donnee;

    liste->premier=liste->premier->suivant;
    liste->n=liste->n-1;
    free(actuel);
    return valeur ;
}

//void pousse_pile(DynaTableau* liste, int valeur)
//ajoute a la fin
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

//int retire_pile(DynaTableau* liste)
//retire au debut
int retire_pile(Liste* liste)
{
    Noeud* actuel = liste->premier;
    Noeud *avantActuel = nullptr;
    while(actuel->suivant!=nullptr){
        avantActuel=actuel;
        actuel=actuel->suivant;
    }
    int retour = actuel->donnee;
    //verif si liste ne contient pas qu'un elem
    if (liste->premier!=liste->dernier){
        avantActuel->suivant=nullptr;
    }
    liste->dernier=avantActuel;
    liste->n-=1;

    free(actuel);

    return retour;
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
