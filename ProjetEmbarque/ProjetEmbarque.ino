#include "Musique.h"

int frequenceNote[]={329,261,220,163};
int debounce[]={0,0,0,0};
int sequence[]={};
int led[]={2,3,4,5};
int compteur=1;



int boutonBleu=0;
int boutonJaune=0;
int boutonRouge=0;
int boutonVert=0;

int bonneReponse=0;
int perdu=0;


void setup() {
  randomSeed(analogRead(0));
  for(int i = 2; i < 6; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  
  
  sequence[compteur-1]= random(2,6);
  

  
}

void loop(){
  if (digitalRead(A2)==LOW)
  {
    musiqueIntro();
    
  do{
  //affiche la sequence
  delay(500);
  for (int i = 0; i < compteur; i++) {
    delay(250);
    digitalWrite(sequence[i], HIGH);
    tone(tonePin, frequenceNote[(sequence[i]-2)], 500);
    delay(500);
    digitalWrite(sequence[i], LOW);    
    }
    
   do{
      // Lis si un bouton est appuier
      boutonBleu=digitalRead(A2);
      boutonJaune=digitalRead(A3);
      boutonRouge=digitalRead(A4);
      boutonVert=digitalRead(A5);

      // Regarde si le bouton appuier est le bon
      //Bouton bleu
      if(boutonBleu==LOW && led[0]==sequence[bonneReponse] && debounce[0]==0)
      {     
        noteBleu();
          bonneReponse++;          
          debounce[0]=1;              
        }else if(boutonBleu==LOW && led[0]!=sequence[bonneReponse] && debounce[0]==0)
        {  
          musiquePerdu();     
          perdu++;         
          debounce[0]=1;            
        }       
      if(boutonBleu==HIGH && debounce[0]==1){
        debounce[0]=0;
        }

      //Bouton jaune
      if(boutonJaune==LOW && led[1]==sequence[bonneReponse] && debounce[1]==0)
      {  
        noteJaune();
          bonneReponse++;          
          debounce[1]=1;              
        }else if(boutonJaune==LOW && led[1]!=sequence[bonneReponse] && debounce[1]==0)
        { 
          musiquePerdu(); 
          perdu++;         
          debounce[1]=1;            
        }       
      if(boutonJaune==HIGH && debounce[1]==1){
        debounce[1]=0;
        }  

      //Bouton rouge
      if(boutonRouge==LOW && led[2]==sequence[bonneReponse] && debounce[2]==0)
      {  
        noteRouge();
          bonneReponse++;          
          debounce[2]=1;              
        }else if(boutonRouge==LOW && led[2]!=sequence[bonneReponse] && debounce[2]==0)
        { 
          musiquePerdu(); 
          perdu++;         
          debounce[2]=1;            
        }       
      if(boutonRouge==HIGH && debounce[2]==1){
        debounce[2]=0;
        } 

      //Bouton vert
      if(boutonVert==LOW && led[3]==sequence[bonneReponse] && debounce[3]==0)
      {  
        noteVert();
          bonneReponse++;          
          debounce[3]=1;              
        }else if(boutonVert==LOW && led[3]!=sequence[bonneReponse] && debounce[3]==0)
        { 
         musiquePerdu(); 
          perdu++;         
          debounce[3]=1;            
        }       
      if(boutonVert==HIGH && debounce[3]==1){
        debounce[3]=0;
        } 
     
  }while(perdu!=1 && bonneReponse!=compteur);

  
  
    if(bonneReponse==compteur){   
      compteur++;
      bonneReponse=0;
      sequence[compteur-1]= random(2,6);

      
      }
    
    if(perdu==1){    
      compteur=1;
      bonneReponse=0;
      perdu=0;
      
      }
    } while ((compteur-1)!=31);
    delay(500);
    musiqueGagner();
    compteur=1;
  }
  
  
     
}


