/*
* Auteur : Thomas Petermann
* Version : 1.0
* Date : 09.11.2021
* description : Ce programme permet de jouer au "Simon says"
*/


#include "Musique.h"

int frequenceNote[]={329,261,220,163};
int debounce=0;
int sequence[]={};
int longueurSequence=1;
int vitesse=500;

int boutonBleu=0;
int boutonJaune=0;
int boutonRouge=0;
int boutonVert=0;

int bonneReponse=0;
int perdu=0;


void setup() {

  for(int i = 2; i < 6; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);

}

void loop()
{

  if (digitalRead(A2)==LOW)
  {
    premierModeDeJeu();
  }    

}

void premierModeDeJeu(){

    musiqueIntro();
    choisisPremierLedAleatoire();

    do{

      delay(500);
      afficheSequence();  
      verifieReponse();
      augmenteLaVitesse();
      verifieResultat();  

    } while ((longueurSequence-1)!=15);

    delay(500);      
    musiqueGagner(); 

}

void verifieResultat(){

  if(bonneReponse==longueurSequence){   
    rajouteUneLedRandom();
  }     
  if(perdu==1){
    reinitialiserJeu();   
  }

}

void choisisPremierLedAleatoire(){

  longueurSequence=1;
  randomSeed(analogRead(0));
  sequence[longueurSequence-1]= random(2,6); 

}

void rajouteUneLedRandom(){

  randomSeed(analogRead(0));
  longueurSequence++;
  bonneReponse=0;
  sequence[longueurSequence-1]= random(2,6); 

}

void reinitialiserJeu(){

  notePerdu();  
  musiqueIntro();  
  longueurSequence=1;
  bonneReponse=0;
  perdu=0; 

}

void augmenteLaVitesse(){

  if (longueurSequence%3==0)
  {
    vitesse=vitesse*0.9;
  } 

}

void afficheSequence(){

  for (int i = 0; i < longueurSequence ; i++) {
    delay(vitesse);
    digitalWrite(sequence[i], HIGH);
    tone(tonePin, frequenceNote[(sequence[i]-2)], vitesse);
    delay(vitesse);
    digitalWrite(sequence[i], LOW);    
  }

}

void verifieReponse(){

  do{
            
    boutonBleu=digitalRead(A2);
    boutonJaune=digitalRead(A3);
    boutonRouge=digitalRead(A4);
    boutonVert=digitalRead(A5);
  
    switch (sequence[bonneReponse])
    {

    case 2 :
      if(boutonBleu==LOW && debounce==0)
      {     
        noteBleu();
        bonneReponse++;          
        debounce=1;              
      }else if(boutonVert==LOW || boutonRouge==LOW || boutonJaune==LOW)
      {       
        perdu=1;                   
      }
      if(boutonBleu==LOW && debounce==1)
      {              
        debounce=0;         
      }
      break;

    case 3 :
      if(boutonJaune==LOW && debounce==0)
      {     
        noteJaune();
        bonneReponse++;          
        debounce=1;               
      }else if(boutonVert==LOW || boutonRouge==LOW || boutonBleu==LOW)
      {     
        perdu=1;                     
      }
      if(boutonJaune==LOW && debounce==1)
      {              
        debounce=0;         
      }
      break;  

    case 4 :
      if(boutonRouge==LOW && debounce==0)
      {     
        noteRouge();
        bonneReponse++;          
        debounce=1;               
      }else if(boutonVert==LOW || boutonBleu==LOW || boutonJaune==LOW)
      {       
        perdu=1;                  
      }
      if(boutonRouge==LOW && debounce==1)
      {              
        debounce=0;         
      }
      break;

    case 5 :
      if(boutonVert==LOW && debounce==0)
      {     
        noteVert();
        bonneReponse++;          
        debounce=1;              
      }else if(boutonBleu==LOW || boutonRouge==LOW || boutonJaune==LOW)
      {       
        perdu=1;                    
      }
      if(boutonVert==LOW && debounce==1)
      {              
        debounce=0;         
      }
      break;  
    } 
  }while(perdu!=1 && bonneReponse!=longueurSequence);

}


