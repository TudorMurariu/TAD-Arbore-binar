#include "AB.h"
#include "IteratorAB.h"


IteratorInordine::IteratorInordine(const AB& _ab):ab(_ab) {
	actual = NULL;
	actual = _ab.radacina;
	while (actual != NULL)
	{
		s.push(actual->st);
		actual = actual->st;
	}
	if (!s.empty())
		element();
}


void IteratorInordine::prim(){
	if (!valid())
		throw(exception());
	while (!s.empty())
		s.pop();
	actual = ab.radacina;
	s.push(ab.radacina);
}

// Teta(1)
bool IteratorInordine::valid(){
	return actual != NULL;
}

// Teta(1)
TElem IteratorInordine::element() {
	if (!valid())
		throw(exception());
	return actual->element;
}


void IteratorInordine::urmator(){
	if (!valid())
		throw(exception());
	PNod aux = s.top();
	s.pop();
	if (actual->dr != NULL)
	{
		actual = actual->dr;
		while (actual != NULL)
		{
			s.push(actual);
			actual = actual->st;
		}
	}
	if (!s.empty())
	{
		element();
	}
	else
	{
		actual = NULL;
	}
}

// Teta(1)
IteratorPreordine::IteratorPreordine(const AB& _ab):ab(_ab){
	actual = NULL;
	prim();
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void IteratorPreordine::prim(){
	while (!s.empty())
		s.pop();
	
	actual = ab.radacina;
	s.push(ab.radacina);
}

// Teta(1)
bool IteratorPreordine::valid(){
	return actual != NULL;
}

// Teta(1)
TElem IteratorPreordine::element(){
	if (!valid())
		throw(exception());

	return actual->element;
}

// Teta(1)
void IteratorPreordine::urmator(){
	if (!valid())
		throw(exception());

	PNod aux = s.top();
	s.pop();

	if (aux->dr != NULL)
		s.push(aux->dr);
	if (aux->st != NULL)
		s.push(aux->st);

	if (!s.empty())
		actual = s.top();
	else
		actual = NULL;
}

IteratorPostordine::IteratorPostordine(const AB& _ab):ab(_ab){
	/* de adaugat */
}

void IteratorPostordine::prim(){
	/* de adaugat */
}


bool IteratorPostordine::valid(){
	/* de adaugat */
	return false;
}

TElem IteratorPostordine::element(){
 	/* de adaugat */
	return -1;
}

void IteratorPostordine::urmator(){
	/* de adaugat */
}

// Teta(1)
IteratorLatime::IteratorLatime(const AB& _ab):ab(_ab){
	actual = NULL;
	prim();
	q.push(_ab.radacina);
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
void IteratorLatime::prim(){
	while (!q.empty())
		q.pop();
	actual = ab.radacina;
}

// Teta(1)
bool IteratorLatime::valid(){
	return actual != NULL;
}

// Teta(1)
TElem IteratorLatime::element(){
	if (!valid())
		throw(exception());
	return actual->element;
}

// Teta(1)
void IteratorLatime::urmator(){
	if (!valid())
		throw(exception());

	PNod aux = q.back();
	q.pop();
	if (aux->st != NULL)
		q.push(aux->st);
	if (aux->dr != NULL)
		q.push(aux->dr);

	if (!q.empty())
		actual = q.back();
	else
		actual = NULL;
}
