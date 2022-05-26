#include "AB.h"
#include "IteratorAB.h"

IteratorInordine::IteratorInordine(const AB& _ab):ab(_ab) {
	/* de adaugat */
}

void IteratorInordine::prim(){
	/* de adaugat */
}

bool IteratorInordine::valid(){
	/* de adaugat */
	return false;
}

TElem IteratorInordine::element() {
	/* de adaugat */
	return -1;
}

void IteratorInordine::urmator(){
	/* de adaugat */
}

// Teta(1)

IteratorPreordine::IteratorPreordine(const AB& _ab):ab(_ab){
	actual = NULL;
	prim();
}

// Teta(1)
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

// Teta(1)
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
	if (aux->dr != NULL)
		q.push(aux->dr);
	if (aux->st != NULL)
		q.push(aux->st);

	if (!q.empty())
		actual = q.back();
	else
		actual = NULL;
}
