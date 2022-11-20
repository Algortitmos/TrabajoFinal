#pragma once
#ifndef __COLA_H__
#define __COLA_H__

#include <iostream>
using namespace std;
template <class G>
class NodoC {//composicion
public:
	G element;
	NodoC* next;
	NodoC* back;
public:
	NodoC(G e = NULL) { element = e; next = back = nullptr; }
	G get_element() { return element; }
	NodoC* get_back() { return back; }
	NodoC* get_next() { return next; }
	void set_back(NodoC* n) { back = n; }
	void set_next(NodoC* n) { next = n; }
};


template <class G>
class Cola {
private:

	NodoC<G>* head;
	NodoC<G>* tail;
	size_t qsize;

public:
	Cola() {
		head = tail = nullptr;
		qsize = 0;
	}


	~Cola() {  }
	void push(G val) {
		NodoC<G>* aux = new NodoC<G>(val);

		if (qsize == 0) { head = tail = aux; }
		else {
			tail->next = aux;
			aux->next = nullptr;
			aux->back = tail;
			tail = aux;
		}
		qsize++;
	}


	void pop() {
		NodoC<G>* aux = head;
		NodoC<G>* Delete_head = head;
		aux = head->next;
		head = aux;
		delete Delete_head;
		qsize--;
	}

	G front() { return head->get_element(); }


	bool isEmpty() {
		if (head == nullptr) return true;
		else return false;
	}
	size_t size() { return qsize; }



	void clear(size_t _cantidad) {
		if (_cantidad == 0) { qsize = 0; return; }
		NodoC<G>* aux = head;
		NodoC<G>* Delete_head = head;
		aux = head->next;
		head = aux;
		delete Delete_head;
		_cantidad--;
		return clear(_cantidad);
	}


	void print(function<void(G)>f) {
		NodoC<G>* aux = head;
		for (size_t i = 0; i < qsize; i++)
		{
			f(aux->get_element());
			aux = aux->next;
		}

	}



	void eraseToCondition(function<bool(G)>f) {
		NodoC<G>* aux = head;
		Nodo<G>* Delete;
		for (size_t i = 0; i < qsize; i++) {
			if (f(aux->get_element())) {
				Delete = aux;
				aux->back->set_next(aux->next); // El siguiente del nodo anterior de aux = nodo siguiente de aux
				aux->next->set_back(aux->back); // El anterior del nodo siguiente de aux = nodo anterior de aux
				delete Delete;
			}
			aux = aux->next;
		}
	}
};

#endif