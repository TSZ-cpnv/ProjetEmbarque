/*
* Auteur : Thomas Petermann
* Version : 1.0
* Date : 09.11.2021
* description : Ce programme permet de jouer au "Simon says"
*/

#include "Musique.h"

// Initialise les variable globale
int frequenceNote[4]={329,261,220,163};
int sequence[31]={0};
int longueurSequence=1;
int vitesse=500;

int bonneReponse=0;

void setup() {

  // Defini les pin 2 à 5 en sortie
  for(int i = 2; i < 6; i++)
  {
    pinMode(i, OUTPUT);
  }

  // Defini les pin A2,3,4,5 en entrée
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

  // Crée une séquence pseudo-random
  randomSeed(analogRead(0));  
}

int verifieReponse(){

  // Initialisation des variable
  int perdu=0;

  int boutonBleu=0;
  int boutonJaune=0;
  int boutonRouge=0;
  int boutonVert=0;

  do{

    // Lis l'états des bouton
    boutonBleu=digitalRead(A2);
    boutonJaune=digitalRead(A3);
    boutonRouge=digitalRead(A4);
    boutonVert=digitalRead(A5);
  
    switch (sequence[bonneReponse])
    {
    case 2 :
      if(boutonBleu==LOW)
      {     
        // Joue la note Mi3 et allume la led bleu  
        noteBleu();    

        do
        {
          // Lis l'état du bouton bleu
          boutonBleu=digitalRead(A2);
          delay(50);

        } while (boutonBleu==LOW);

        // Eteind le buzzer et la led bleu
        digitalWrite(led[0], LOW); 
        noTone(tonePin);

        // Ajoute une bonne reponse
        bonneReponse++;
      }
      else if(boutonVert==LOW || boutonRouge==LOW || boutonJaune==LOW)
      {       
        perdu=1;
      }
      break;

    case 3 :
      if(boutonJaune==LOW)
      {     
        // Joue la note Do3 et allume la led jaune 
        noteJaune();         

        do
        {
          // Lis l'état du bouton jaune
          boutonJaune=digitalRead(A3);
          delay(50);

        } while (boutonJaune==LOW);

        // Eteind le buzzer et la led jaune
        digitalWrite(led[1], LOW);
        noTone(tonePin);

        // Ajoute une bonne reponse
        bonneReponse++;              
      }
      else if(boutonVert==LOW || boutonRouge==LOW || boutonBleu==LOW)
      {     
        perdu=1;            
      }
      break;  

    case 4 :
      if(boutonRouge==LOW)
      {     
        // Joue la note La2 et allume la led rouge 
        noteRouge();        

        do
        {
          // Lis l'état du bouton rouge
          boutonRouge=digitalRead(A4);
          delay(50);

        } while (boutonRouge==LOW);  

        // Eteind le buzzer et la led rouge
        digitalWrite(led[2], LOW); 
        noTone(tonePin);

        // Ajoute une bonne reponse
        bonneReponse++;            
      }
      else if(boutonVert==LOW || boutonBleu==LOW || boutonJaune==LOW)
      {       
        perdu=1;        
      }
      break;

    case 5 :
      if(boutonVert==LOW)
      {     
        // Joue la note Mi2 et allume la led vert 
        noteVert();        
        do
        {
          // Lis l'état du bouton vert
          boutonVert=digitalRead(A5);
          delay(50);

        } while (boutonVert==LOW);

        // Eteind le buzzer et la led vert
        digitalWrite(led[3], LOW); 
        noTone(tonePin);    

        // Ajoute une bonne reponse
        bonneReponse++;
      }
      else if(boutonBleu==LOW || boutonRouge==LOW || boutonJaune==LOW)
      {
        perdu=1;           
      }     
      break;
    }
  }while(perdu!=1 && bonneReponse!=longueurSequence); // Tant ne s'est pas trompé, ou a fait toute une sequence juste
  return perdu;
}

void verifieResultat(int perdu)
{ 
  // si il a reproduit la sequence correctement
  if(bonneReponse==longueurSequence)
  {   
    rajouteUneLedRandom();
  }     

  // si il a fait une faute
  if(perdu==1)
  {
    reinitialiserJeu();   
  }
}

void choisisPremierLedAleatoire()
{
  // reinitialise les variable
  longueurSequence=1;
  vitesse=500;

  // choisis une premier led aléatoirement
  sequence[longueurSequence-1] = random(2,6);
}

void rajouteUneLedRandom()
{
  // ajoute une led a la séquence
  longueurSequence++;
  sequence[longueurSequence-1]= random(2,6);

  // reinitialise les bonne réponse à 0 
  bonneReponse=0;  
}

void reinitialiserJeu()
{
  // Joue la note perdu Do1
  notePerdu();  
  musiqueIntro();  

  // choisis une premier led aléatoirement
  longueurSequence=1;
  sequence[longueurSequence-1]= random(2,6); 

  // reinitialise les bonne réponse à 0 
  bonneReponse=0;
}

void augmenteLaVitesse()
{
  // Tout les multiple de 3
  if (longueurSequence%3==0)
  {
    // Diminue le temps d'affiche de 10%
    vitesse=vitesse*0.9;
  } 
}

void afficheSequence()
{
  for (int i = 0; i < longueurSequence ; i++)
  {
    // Affiche selon la vitesse une led avec son son
    delay(vitesse);
    digitalWrite(sequence[i], HIGH);
    tone(tonePin, frequenceNote[(sequence[i]-2)], vitesse);
    delay(vitesse);
    digitalWrite(sequence[i], LOW);    
  }
}

void loop()
{
  if (digitalRead(A2)==LOW)
  {
    musiqueIntro();
    choisisPremierLedAleatoire();

    do
    {

      delay(500);
      afficheSequence();
      int perdu = verifieReponse();
      augmenteLaVitesse();
      verifieResultat(perdu);

    } while ((longueurSequence-1)!=31); // Tant que le joueur n'a pas réussi une séquence de 31 led

    delay(500);      
    musiqueGagner(); 
  }    
}
