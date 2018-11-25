#include <siirtorekisteri.h>

/*

Tämän esimerkkikoodin on kirjoittanut Teemu Laurila 23.11.2018

Voit halutessasi tukea projektejani ja sivustoani ostamalla tekemiäni siirtorekisteripiirejä:
https://teukka.webnode.com/l/tuotesuunnittelu-piirilevy-siirtorekisterille/

*/

siirtorekisteri rekisteri(1); // Luo olio siirtorekisterille ja määritä rekisterien määrä

void setup() {  
  rekisteri.aloita(3,4,5); // Aseta pinnit ulostuloksi ja määritä mitä pinnejä käytetään mihinkin
  /*
  Tässä tapauksessa latch = D3,
                    kellosignaali = D4 ja
                    data = D5

  Latch on STCP, eli pinni 12 piiriltä.
  Kellosignaali on SHCP, eli pinni 11 piiriltä.
  Data on DS, eli pinni 14 piiriltä.
  
  */
}

void loop() {
	
	//Käy kaikki ledit läpi yksitellen
	
	for(int x=0; x<8*rekisteri.count; x++) {
		rekisteri.aseta(x,1);   //Aseta pinni 0 tilaan 1 (päällä)
		delay(200);   			//Odota 200 millisekuntia
		rekisteri.aseta(x,0); 	//Aseta pinni 0 tilaan 0 (pois päältä)
	}
	
}