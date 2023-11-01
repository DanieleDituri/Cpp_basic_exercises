#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer {

  /**
    @brief Dato che rappresenta un array di interi dinamico.
    
    Dato che rappresenta un array di interi dinamico.
  */
  struct dynamic_buffer {
    unsigned int size; ///< dimensione dell'array
    int *buffer;       ///< puntatore all'array di interi
  };

  /**
    @brief Stampa il contenuto di un dynamic_buffer

    Stampa il contenuto di un dynamic_buffer

    @param db dynamic_buffer da stampare
  */
  void print_dbuffer(const dynamic_buffer &db);

  /**
    @brief Inizializza un dynamic_buffer "a 0"

    Funzione che inizializza un dynamic_buffer ad un 
    array di interi vuoto.

    @param db dynamic_buffer da inizializzare

    @post db.size = 0
    @post db.buffer = nullptr
  */
  void initialize_dbuffer(dynamic_buffer &db);

  /**
    @brief Alloca un dynamic_buffer 

    Funzione che alloca un dynamic_buffer ad una 
    dimensione data.

    @param db dynamic_buffer da allocare
    @param size dimensione dell'array di interi

    @post db.size = size
    @post db.buffer != nullptr
  */
  void allocate_dbuffer(dynamic_buffer &db, unsigned int size=10);


  /**
    @brief Dealloca un dynamic_buffer 

    Funzione che dealloca un dynamic_buffer.

    @param db dynamic_buffer da deallocare

    @post db.size = 0
    @post db.buffer == nullptr
  */
  void deallocate_dbuffer(dynamic_buffer &db);

  /**
    @brief Riempie un dynamic_buffer con valori identici

    Funzione che riempie un dynamic_buffer con valori identici
    al parametro passato in input.

    @param db dynamic_buffer da riempire
    @param value valore di riempimento

    @post db.buffer[i] == value per i=0 a db.size
  */
  void fill_dbuffer(dynamic_buffer &db, int value);

  /**
    @brief Riempie un dynamic_buffer con valori passati 


    Funzione che riempie un dynamic_buffer con valori passati
    in un array di interi della stessa dimensione del dynamic_buffer

    @param db dynamic_buffer da riempire
    @param values array di interi dei valori sorgenti
    @param nvalues dimensione dell'array di input

    @pre values != nullptr
    @pre nvalues == db.size 
    @post db.buffer[i] == values[i] per i=0 a nvalues
  */
  void fill_dbuffer(dynamic_buffer &db, const int*values, int nvalues);

  void copy_dbuffer(const dynamic_buffer &src, dynamic_buffer &dst);
  

}


#endif