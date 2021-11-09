int tonePin = 6;
int led[]={2,3,4,5};

int randomLed;
int nombreRandom;


void allumerEteindreLed(){
    digitalWrite(led[randomLed],LOW);
    do
    {
        nombreRandom = random(0,4); 
    } while (nombreRandom==randomLed);
    randomLed=nombreRandom; 
    digitalWrite(led[randomLed],HIGH);      
}

void allumerCoter(){
    digitalWrite(led[0],HIGH);
    digitalWrite(led[3],HIGH);     
    digitalWrite(led[1],LOW);
    digitalWrite(led[2],LOW);   
}
void allumerCentre(){
    digitalWrite(led[0],LOW);
    digitalWrite(led[3],LOW);     
    digitalWrite(led[1],HIGH);
    digitalWrite(led[2],HIGH);   
}
void allumerTout(){
      for (size_t i = 0; i < 4; i++)
      {
        digitalWrite(led[i],HIGH);
      }   
}
void eteindreTout(){
    for (size_t i = 0; i < 4; i++)
      {
        digitalWrite(led[i],LOW);
      }  
}

void musiqueIntro() 
{
    tone(tonePin, 246, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 220, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 246, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 293, 329.67);
    allumerEteindreLed();
    delay(329.67);
    tone(tonePin, 220, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 246, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 220, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 246, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 293, 164.835);
    allumerEteindreLed();
    delay(164.835);
    tone(tonePin, 246, 164.835);
    allumerCoter();
    delay(164.835);
    tone(tonePin, 220, 164.835);
    allumerCentre();
    delay(164.835);
    tone(tonePin, 246, 329.67);
    allumerTout();
    delay(329.67);
    eteindreTout();
}

void musiqueGagner(){
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    allumerEteindreLed();
    delay(797.447727273);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 523, 318.979090909);
    allumerEteindreLed();
    delay(318.979090909);
    tone(tonePin, 493, 318.979090909);
    allumerEteindreLed();
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    allumerEteindreLed();
    delay(797.447727273);
    tone(tonePin, 349, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 261, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 349, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 466, 318.979090909);
    allumerEteindreLed();
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 79.7447727273);
    allumerEteindreLed();
    delay(79.7447727273);
    tone(tonePin, 329, 79.7447727273);
    allumerEteindreLed();
    delay(79.7447727273);
    tone(tonePin, 349, 79.7447727273);
    allumerEteindreLed();
    delay(79.7447727273);
    tone(tonePin, 369, 79.7447727273);
    allumerEteindreLed();
    delay(79.7447727273);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 440, 797.447727273);
    allumerEteindreLed();
    delay(797.447727273);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 523, 318.979090909);
    allumerEteindreLed();
    delay(318.979090909);
    tone(tonePin, 493, 318.979090909);
    allumerEteindreLed();
    delay(318.979090909);
    tone(tonePin, 440, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 293, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 391, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 440, 637.958181818);
    allumerEteindreLed();
    delay(637.958181818);
    tone(tonePin, 349, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 261, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 349, 159.489545455);
    allumerEteindreLed();
    delay(159.489545455);
    tone(tonePin, 466, 318.979090909);
    allumerCentre();
    delay(318.979090909);
    tone(tonePin, 440, 318.979090909);
    allumerCoter();
    delay(318.979090909);
    tone(tonePin, 349, 318.979090909);
    allumerTout();
    delay(318.979090909);
    eteindreTout();
}

void noteBleu(){
    tone(tonePin,329, 200);
    delay(200);
}
void noteJaune(){
    tone(tonePin,261, 200);
    delay(200);
}
void noteRouge(){
    tone(tonePin,220, 200);
    delay(200);
}
void noteVert(){
    tone(tonePin,163, 200);
    
    delay(200);
}
void notePerdu(){
    tone(tonePin,33, 500);
    delay(1000);
}
