/**
  @file main.cpp

  @brief File principale di progetto

  File di test dell'esercizio sui puntatori e stringhe C 
*/

#include <iostream>
#include <cassert>
#include "stringheC.h"


int main(int argc, char *argv[]) {
  if (argc>3) {

    std::cout << "Stringa di partenza: " << argv[1] << std::endl;
    sovrascrivi_stringa(argv[1],argv[2],argv[3]);
    std::cout << "Stringa nuova: " << argv[1] << std::endl;


    /*
    char *result = nullptr;
    result=cerca_stringa(argv[1],argv[2]);
    if(result!=nullptr) {
      std::cout << result << std::endl;
    }
    */

    /*

    stampa_caratteri(argv[1]);
    inverti_stringa(argv[1]);
    std::cout<<"-----------"<<std::endl;
    stampa_caratteri(argv[1]);

    std::cout<<"-----------"<<std::endl;

    char *copia = clona_stringa(argv[1]);
    stampa_caratteri(copia);
    delete[] copia;
    copia = nullptr;

    std::cout<<"-----------"<<std::endl;

    char *concat = concatena_stringa(argv[1],argv[2]);
    stampa_caratteri(concat);

    //char *tmp = concat + 1000; 

    delete[] concat;
    concat = nullptr;
  
    */

  }


  return 0;
}