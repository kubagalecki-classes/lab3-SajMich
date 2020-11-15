#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
  if (towar > 0)
  {
    int suma;
    suma =0;
    int iter;
    iter = 0;
    int zeglowce;
    zaglowce=0;
    Stocznia stocznia{};

    while ( suma < towar && iter <100000)
    {
    Statek* s1 = stocznia();
    tmp = s1->transportuj();
    suma = suma +tmp;
    iter = iter +1;
    s1=dynamic_cast<Zaglowiec*>(s1);
    if(s1)
    {
      zaglowce = zaglowce +1;
    }
    delete s1;
    }
   return zaglowce
  }

  else
  {
    return 0;
  }

}