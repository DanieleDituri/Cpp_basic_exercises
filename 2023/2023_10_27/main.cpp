#include <iostream>
#include "dbuffer.h"

int main(int argc, char * argv[]) {

  dbuffer::dynamic_buffer db; // non è inizializzato!

  dbuffer::initialize_dbuffer(db); // Da chiamare SEMPRE dopo istanziazione

  dbuffer::print_dbuffer(db); // dynamic_buffer vuoto

  dbuffer::allocate_dbuffer(db,5); // Allochiamo spazio per array di 5 interi

  dbuffer::fill_dbuffer(db,0); // Assegnamo i valori. 

  dbuffer::print_dbuffer(db);

  int values[5]={1,2,3,4,5};

  dbuffer::fill_dbuffer(db,values,5); // Assegnamo i valori presi da values
  dbuffer::print_dbuffer(db);

  dbuffer::dynamic_buffer db2;
  dbuffer::initialize_dbuffer(db2); // Da chiamare SEMPRE dopo istanziazione

  dbuffer::copy_dbuffer(db,db2); // Sostituiamo il contenuto di db2 con quello di db
                                 // I due dynamic_buffer sono indipendenti 

  dbuffer::print_dbuffer(db2);

  dbuffer::deallocate_dbuffer(db); // Da chiamare SEMPRE prima di uscire dallo scope
  dbuffer::deallocate_dbuffer(db2);// Da chiamare SEMPRE prima di uscire dallo scope

  return 0;
}