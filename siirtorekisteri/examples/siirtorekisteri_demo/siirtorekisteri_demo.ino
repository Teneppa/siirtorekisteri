#include <siirtorekisteri.h>

siirtorekisteri rekisteri(1);

void setup() {  
  rekisteri.aloita(3,4,5);
}

void loop() {
  for(int x=0; x<8*rekisteri.count; x++) {
    rekisteri.aseta(x,1);   //Aseta pinni 0 tilaan 1 (päällä)
    delay(200);   //Odota 200 millisekuntia
    rekisteri.aseta(x,0); //Aseta pinni 0 tilaan 0 (pois päältä)
    delay(0);   //Odota 200 millisekuntia
  }
}