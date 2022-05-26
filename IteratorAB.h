#pragma once
#include "AB.h"
#include <queue>
#include <stack>

using namespace std;


//PNod copiere(PNod p) 
//{
//	if (p != NULL) {
//		//creez radacina
//		PNod pNew = new Nod(p->element, NULL, NULL);
//		pNew->st = copiere(p->st);
//		pNew->dr = copiere(p->dr);
//		return pNew;
//	}
//	return NULL;
//}

class IteratorAB {
public:

	friend class AB;

	//operatii pe iterator
	virtual void prim()=0;

	virtual void urmator()=0;

	virtual TElem element() = 0;

	virtual bool valid() = 0;
};

class IteratorPreordine: public IteratorAB{
    friend class AB;
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorPreordine(const AB& _ab);

	//contine o referinta catre containerul pe care il itereaza

   	const AB& ab;

	/* aici e reprezentarea specifica a itertorului*/
	stack<PNod> s;
	PNod actual;

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid();

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element();
};


#include <exception>
class IteratorInordine: public IteratorAB{
   friend class AB;
private:
  //constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
   IteratorInordine(const AB& _ab);

  //contine o referinta catre containerul pe care il itereaza

   const AB& ab;
   /* aici e reprezentarea specifica a iteratorului*/



public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid();

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element();
};


class IteratorPostordine: public IteratorAB{
   friend class AB;
private:

    //constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
  	IteratorPostordine(const AB& _ab);
    //contine o referinta catre containerul pe care il itereaza

	const AB& ab;
	/* aici e reprezentarea specifica a itertorului*/


public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid();

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element();
};

class IteratorLatime: public IteratorAB{
   friend class AB;
private:

   //constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
   IteratorLatime(const AB& _ab);
   //contine o referinta catre containerul pe care il itereaza

   const AB& ab;
 	/* aici e reprezentarea pecifica a itratorului*/

   queue<PNod> q;
   PNod actual;

public:

		//reseteaza pozitia iteratorului la inceputul containerului
		void prim();

		//muta iteratorul in container
		// arunca exceptie daca iteratorul nu e valid
		void urmator();

		//verifica daca iteratorul e valid (indica un element al containerului)
		bool valid();

		//returneaza valoarea elementului din container referit de iterator
		//arunca exceptie daca iteratorul nu e valid
		TElem element();
};
