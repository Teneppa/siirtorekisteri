/*

Tämän kirjaston on koodannut Teemu Laurila 23.11.2018

*/


#ifndef _siirtorekisteri_h
#define _siirtorekisteri_h

#include "Arduino.h"

struct siirtorekisteri {
  public:
    siirtorekisteri(int regcount);  // Alusta olio ja varaa muistia
    int* buffer;          // Määritä osoitin
    uint16_t count;            // Rekisterien määrä
    void aloita(int latch, int kello, int data);
    void aseta(int _pin, int _state);
    void paivitaRekisteri();
    uint16_t _pincount;

  private:
    uint16_t _datapin;
    uint16_t _clockpin;
    uint16_t _latchpin;
    
};

#endif