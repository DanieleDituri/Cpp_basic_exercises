/**
  @file stringheC.cpp

  @brief File delle funzioni che manipolano le stringhe C

  Soluzione dell'esercizio sui puntatori e stringhe C.
*/

#include "stringheC.h"
#include <cassert>
#include <iostream>

void stampa_caratteri(const char *str) {
  assert(str!=nullptr);

  while(*str!='\0') {
    std::cout << *str << std::endl;
    str++; // str = str + 1;
  }
}

size_type calcola_lunghezza(const char *str) {
  assert(str!=nullptr);

  size_type length = 0;
  while(*str!='\0') {
    length++;
    str++; // str = str + 1;
  }

  return length;
}

void inverti_stringa(char *str) {
  assert(str!=nullptr);

  size_type n = calcola_lunghezza(str);
  char *str1 = str + n - 1;
  //char tmp;

  for(; str < str1; str++, str1--) {
    std::swap(*str, *str1);
    //tmp = (*str);
    //*str = *str1;
    //*str1 = tmp;
    //str++;
    //str1--;
  }
}

char *clona_stringa(const char *str) {
  assert(str!=nullptr);

  char *result = nullptr;

  size_type n = calcola_lunghezza(str);

//  try {
    result = new char[n+1];
//  }
//  catch(std::bad_alloc &e) {
//    std::cerr << "Impossibile allocare la copia." << std::endl;
//    return nullptr;
//  }

  for(size_type i = 0; i <= n ; ++i) 
    result[i] = str[i];

  return result;
}

char *concatena_stringa(const char *s1, const char *s2) {
  assert(s1!=nullptr);
  assert(s2!=nullptr);

  size_type n1 = calcola_lunghezza(s1);
  size_type n2 = calcola_lunghezza(s2);

  char *result = nullptr;

  result = new char[n1+n2+1];

  for(size_type i = 0; i < n1; ++i)
    result[i] = s1[i];

  for(size_type i = 0; i <= n2; ++i) {
    result[n1+i] = s2[i];
  }

  return result;
}

const char *cerca_stringa(const char *s1, const char *st) {
  assert(s1!=nullptr);
  assert(st!=nullptr);

  size_type i, j;
  size_type n1 = calcola_lunghezza(s1);
  size_type nt = calcola_lunghezza(st);

  assert(n1>0);
  assert(nt>0);
  assert(nt<=n1);

  for(i=0; i<n1-nt+1; ++i) {
    for(j=0;j<nt;++j) {
      if(st[j]!=s1[i+j]) break;
    }
    if(j==nt) return s1+i;
  }
  return nullptr;
}

char *cerca_stringa(char *s1, const char *st) {
  const char *result=cerca_stringa(static_cast<const char*>(s1),st);

  return const_cast<char*>(result);

  /* // Alternativa
  assert(s1!=nullptr);
  assert(st!=nullptr);

  size_type i, j;
  size_type n1 = calcola_lunghezza(s1);
  size_type nt = calcola_lunghezza(st);

  for(i=0; i<n1-nt+1; ++i) {
    for(j=0;j<nt;++j) {
      if(st[j]!=s1[i+j]) break;
    }
    if(j==nt) return s1+i;
  }
  return nullptr;
  */
}

void sovrascrivi_stringa(char *s1, const char *st, const char *s2) {
  assert(s1!=nullptr);
  assert(st!=nullptr);
  assert(s2!=nullptr);

  size_type n1 = calcola_lunghezza(s1);
  size_type nt = calcola_lunghezza(st);
  size_type n2 = calcola_lunghezza(s2);

  assert(n1>0);
  assert(nt>0);
  assert(nt<=n1);
  assert(n2==nt);

  char *res = nullptr;

  res=cerca_stringa(s1,st);
  
  while(res!=nullptr) {
    for(size_type i = 0; i < nt; ++i) {
      res[i] = s2[i];
    }
    if (res[nt]=='\0') return; //*(res+nt)=='\0'
    res=cerca_stringa(res+nt,st);
  }
}

