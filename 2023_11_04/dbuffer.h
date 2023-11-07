/**
  @file dbuffer.h

  @brief File header della classe dbuffer

  File di dichiarazioni della classe dbuffer 
*/

#ifndef DBUFFER_H
#define DBUFFER_H

#include <ostream> // std::ostream

/**
  @brief Classe dbuffer

  Classe che rappresenta un array dinamico di interi.
*/
class dbuffer {
public:
  typedef unsigned int size_type; ///< Tipo di dato per la dimensione dell'array

private:
  size_type _size; ///< Dimensione dell'array
  int * _buffer;      ///< Puntatore all'array di interi

public:

  /**
    @brief Costruttore di default

    1° METODO FONDAMENTALE DELLE CLASSI
    Construttore di default che inizializza il 
    dbuffer ad un array dinamico vuoto.

    @post _size == 0
    @post _buffer == nullptr
  */
  dbuffer();

  /**
    @brief Costruttore secondario

    Costruttore secondario che permette di creare un array
    dinamico di interi della dimensione data.

    @param size dimensione dell'array da istanziare

    @post _size == size
    @post _buffer != nullptr 
  */
  explicit dbuffer(size_type size);

  /**
    @brief Costruttore secondario

    Costruttore secondario che permette di creare un array
    dinamico di interi della dimensione data e contenenti
    il valore passato.

    @param size dimensione dell'array da istanziare
    @param value valore da assegnare a tutte le celle dell'array

    @post _size == size
    @post _buffer != nullptr 
    @post _buffer[i] == value
  */
  dbuffer(size_type size, int value);

  /**
    @brief Distruttore

    2° METODO FONDAMENTALE DELLE CLASSI
    IL distruttore della classe rimuove le eventuali risorse
    richieste dall'oggetto.

    @post _size == 0
    @post _buffer == nullptr
  */
  ~dbuffer();

  /**
    @brief Getter della dimensione dell'array

    Metodo che ritorna la dimensione dell'array di interi

    @return la dimensione dell'array di interi
  */
  size_type size(void) const;

  /*
  int get_value(unsigned int index);
  void set_value(unsigned int index, int value);
  */

  /**
    @brief Metodo getter/setter di una cella dell'array

    @param index della cella da leggere/scrivere
    @return reference all'intero da leggere/scrivere
    
    @pre index<_size
  */
  int& value(size_type index);

  /**
    @brief Metodo getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
  const int& value(size_type index) const;

  /**
    Operatore getter/setter di una cella dell'array

    @param index della cella da leggere/scrivere
    @return reference al'intero da leggere/scrivere
    
    @pre index<_size
  */
  int& operator[](size_type index);

  /**
    @brief Operatore getter di una cella dell'array

    @param index della cella da leggere
    @return reference all'intero da leggere
    
    @pre index<_size
  */
   const int& operator[](size_type index) const;

  /**
    @brief Stampa il contenuto dell'array dinamico su cout

    Stampa il contenuto dell'array dinamico su cout
  */
  void print(void) const; 

  /**
    @brief Metodo di riempimento dell'array

    Metodo che assegna ad ogni cella dell'array il valore 
    passato. value == 0 di default.

    @param value valore da assegnare alle celle dell'array

    @post _buffer[i] == value
  */
  void fill(int value=0);

  /**
    @brief Costruttore di copia (Copy constructor)

    3° METODO FONDAMENTALE DELLE CLASSI
    Crea un dbuffer a partire da un altro dbuffer

    @param other dbuffer sorgente

    @post _size == other._size
    @post _buffer[i] == other._buffer[i]
  */
  dbuffer(const dbuffer &other);

  /**
    @brief Operatore di assegnamento

    4° METODO FONDAMENTALE DELLE CLASSI
    Operatore che compia il contenuto di un dbuffer
    nel dbuffer corrente.

    @param other dbuffer sorgente

    @return reference a this

    @post _size == other._size
    @post _buffer[i] == other._buffer[i]
  */
  dbuffer& operator=(const dbuffer &other); // "*this" = other

  /**
    @brief Metodo swap

    Metodo che scambia lo stato di other con quello di this.

    @param other dbuffer con cui scambiare lo stato

    @post this->_size == other._size
    @post this->_buffer == other._buffer
    @post other._size == this->_size
    @post other._buffer == this->other._buffer
  */  
  void swap(dbuffer &other);

  // Permette alla funzione globale di accedere ai dati privati
  friend std::ostream& operator<<(std::ostream &os, const dbuffer &db);
};

/**
  @brief Operatore di stream

  Ridefinizione dell'operatore di stream per inviare su
  ostream il contenuto di un dbuffer

  @param os stream di output (operando di sinistra)
  @param db dbuffer da spedire (operando di destra)

  @return reference allo stream di output (operando di sinistra)
*/
std::ostream& operator<<(std::ostream &os, const dbuffer &db);

#endif