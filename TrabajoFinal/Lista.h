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

	void delete_pos(size_t pos) {

		Nodo<G>* aux = inicio; bool podemos = true;
		if (pos < 0 || pos >= cantidad) {
			cout << "esta posicion no existe" << endl;
			return;
		}
		if (aux != nullptr) {
			if (pos == 0) {
				podemos = false;
				pop();
				return;
			}
			if (pos == cantidad - 1) {
				podemos = false;
				pop_f();
				return;
			}
			if (podemos == true) {
				for (int i = 0; i < pos - 2; i++) {
					aux = aux->siguiente;
				}
				Nodo<G>* aux_eliminar = aux;
				Nodo<G>* puente_aux = aux;
				aux_eliminar = aux_eliminar->siguiente;
				puente_aux = (puente_aux->siguiente)->siguiente;
				delete aux_eliminar;
				aux->siguiente = puente_aux;
				cantidad--;
			}
		}
		return;
	}


};