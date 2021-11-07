
int sequence[]={};
int led[]={2,3,4,5};
int compteur=1;

int tonePin = 6;

int boutonBleu=0;
int boutonJaune=0;
int boutonRouge=0;
int boutonVert=0;

int bonneReponse=0;
int perdu=0;


void setup() {
  randomSeed(analogRead(0));
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
 
  while(digitalRead(A2)==HIGH){}
  sequence[compteur-1]= random(2,6);
  musique();
  
}

void loop(){
  
  
  //affiche la sequence
  for (int i = 0; i < compteur; i++) {
    delay(1000);
    digitalWrite(sequence[i], HIGH);
    delay(2000);
    digitalWrite(sequence[i], LOW);    
    }
    
   do{
      // Lis si un bouton est appuier
      boutonBleu=digitalRead(A2);
      boutonJaune=digitalRead(A3);
      boutonRouge=digitalRead(A4);
      boutonVert=digitalRead(A5);

      // Regarde si le bouton appuier est le bon
      if(boutonBleu==LOW && led[0]==sequence[bonneReponse]){  
          bonneReponse++;       
        }else{ 
          perdu++;    
        }

        if(boutonJaune==LOW && led[1]==sequence[bonneReponse]){    
          bonneReponse++;           
        }else{  
          perdu++;      
        }

        if(boutonRouge==LOW && led[2]==sequence[bonneReponse]){     
          bonneReponse++;     
        }else{
          perdu++;
        }

        if(boutonVert==LOW && led[3]==sequence[bonneReponse]){ 
          bonneReponse++;                
        }else{ 
          perdu++;      
        }
        
  }while(perdu!=1 || bonneReponse!=(compteur-1));

  if(perdu==1){
    digitalWrite(2, HIGH);
      compteur=1;
      bonneReponse=0;
      perdu=0;   
  }
  
  if(bonneReponse==(compteur-1)){
    digitalWrite(3, HIGH);
    perdu=0;
    compteur++;
    bonneReponse=0;
    sequence[compteur-1]= random(2,6);
    }

  
     
}

void musique() 
{
    tone(tonePin, 391, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 391, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 391, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 391, 237.98115);
    delay(240.385);
    tone(tonePin, 415, 118.990575);
    delay(120.1925);
    tone(tonePin, 391, 118.990575);
    delay(120.1925);
    tone(tonePin, 349, 118.990575);
    delay(120.1925);
    tone(tonePin, 391, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 349, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    delay(120.1925);
    tone(tonePin, 311, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 311, 118.990575);
    delay(120.1925);
    delay(120.1925);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    tone(tonePin, 293, 237.98115);
    delay(240.385);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    tone(tonePin, 349, 237.98115);
    delay(240.385);
    tone(tonePin, 391, 475.9623);
    delay(480.77);
    tone(tonePin, 311, 356.971725);
    delay(360.5775);
    delay(120.1925);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    tone(tonePin, 293, 237.98115);
    delay(240.385);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    tone(tonePin, 349, 237.98115);
    delay(240.385);
    tone(tonePin, 391, 475.9623);
    delay(480.77);
    tone(tonePin, 391, 475.9623);
    delay(480.77);
    tone(tonePin, 311, 237.98115);
    delay(240.385);
    tone(tonePin, 391, 475.9623);
    delay(480.77);
    tone(tonePin, 349, 475.9623);
    delay(480.77);
    tone(tonePin, 311, 594.952875);
    delay(600.9625);
}
