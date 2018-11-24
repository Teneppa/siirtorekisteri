/*

Tämän kirjaston on koodannut Teemu Laurila 23.11.2018

*/

#include "siirtorekisteri.h"

/********************************************************************************************************************************/

// Varaa tarvittavan tilan puskurille

siirtorekisteri::siirtorekisteri(int regcount) {
  delete [] buffer;           //Ihan varotoimenpiteenä
  buffer = new int[regcount]; //Varaa muistia pinnien tiloille
  count = regcount;           //Tallenna rekisterien määrä
}

/********************************************************************************************************************************/

// Määrittää pinnien tilat ja alustaa rekisterit

void siirtorekisteri::aloita(int latch, int clock, int data) { //Määritä käytettävät pinnit ja aseta ne ulostuloiksi

  //Kirjaston käyttämät paikalliset muuttujat
  _latchpin = latch;
  _clockpin = clock;
  _datapin = data;
  _pincount = count * 8;

  //Aseta pinnit ulostuloiksi
  pinMode(_latchpin, OUTPUT);
  pinMode(_clockpin, OUTPUT);
  pinMode(_datapin, OUTPUT);

  //Alusta rekisterin kaikki arvot nolliksi
  for (int cls = 0; cls < _pincount; cls++) {
    aseta(cls, 0);
  }

}

/********************************************************************************************************************************/

// Määrittää yksittäisen pinnin tilan puskuriin ja päivittää rekisterit

void siirtorekisteri::aseta(int _pin, int _state) { //Määritä pinnin tila
  if (_pin >= 0 && _pin < _pincount) { //Tarkista että kyseinen pinni löytyy
    if ((_state == 0) || (_state == 1)) { //Tarkista että tila on joko nolla tai yksi
      buffer[_pin] = _state;  //Muuta arvo puskurista
    }
  }

  paivitaRekisteri();
}

/********************************************************************************************************************************/

// Päivittää rekisterit

void siirtorekisteri::paivitaRekisteri() {
  digitalWrite(_latchpin, 0); //Kun latch = 0, kaikki ledit sammuvat (eivät vilku kun puskuri päivitetään)
	
	/*
	Rekisterien kirjoitusjärjestys on aika mielenkiintoinen siirtorekisterin toimintaperiaatteen vuoksi
  
	Esimerkiksi jos käytät kahta rekisteriä ja ledit on numeroitu vasemmalta oikealle 0-15, on tilat kirjoitettava jäjestyksessä
	15,14,13,12,11,10,9,8,0,1,2,3,4,5,6,7
  */
  
  for (int x=count-1; x>=0; x--) { // Käy jokainen rekisteri läpi  
    for(int n=0; n<8; n++) {
      digitalWrite(_datapin, buffer[x*8+n]); //Ensin data
      digitalWrite(_clockpin, 1); //Sitten pulssitetaan kelloa
      digitalWrite(_clockpin, 0);
    }
  }
  

  digitalWrite(_latchpin, 1); //Kun latch = 1, kaikki ledit toimivat taas normaalisti
}
