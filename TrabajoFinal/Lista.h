#pragma once

#include "Librerias.h"
#include "Usuario.h"

template<class G>
class Nodo {
public:
	Nodo* siguiente;
	Nodo* atras;

	G elemento;

	Nodo(G e) { elemento = e; }
	~Nodo() { delete siguiente, atras; }
};

template<class G>
class Lista {
public:
	Nodo<G>* inicio;
	Nodo<G>* fin;
	size_t cantidad;

	Lista() {
		inicio = nullptr;
		fin = nullptr;
		cantidad = 0;
	}

	~Lista() {}


	void pushFront(G e) {
		Nodo<G>* n = new Nodo<G>(e);

		if (inicio == nullptr) { inicio = n; }
		else {
			fin->siguiente = inicio;
			inicio = n;
		}
		++cantidad;
	}

	void push_back(G e) {
		Nodo<G>* n = new Nodo<G>(e);
		if (cantidad == 0) { inicio = n; fin = n; }
		else {
			n->atras = fin;
			fin->siguiente = n;
			fin = n;
		}
		++cantidad;
	}


	G at(size_t pos) {
		Nodo<G>* aux = inicio;
		for (int i = 0; i < pos; i++) {
			aux = aux->siguiente;
		}
		return aux->elemento;
	}


	void Lista_nueva() {
		inicio = nullptr;
		cantidad = 0;
		return;
	}

	G BuscarElemento() {

	}

	void mostrarLista(function<void(G)>f) {
		Nodo<G>* aux = inicio;

		while (aux != nullptr)
		{
			f(aux->elemento);
			//cout << aux->elemento << " ";
			aux = aux->siguiente;
		}
	}


};