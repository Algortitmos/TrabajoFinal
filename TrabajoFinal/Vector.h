#pragma once
#include "Librerias.h"

template <class G> 
class Vector {
private:
	vector<G> elemento;
public:
	Vector();
	~Vector();
	void PushFront(G e);
	void Print(function<void(G)>f);
	void DeletePos(size_t pos);
	void Pop();
	void PopToFinally();
	bool Find(function<bool(G, G)>CompareFunction, G ElementToFind);

	size_t GetSize();
	void DeleteAll();
	void PushFrontCondition(function<bool(G)>f, G ElementCondition);
	G At(size_t i = 0);

	void HeapSort(function<bool(G, G)>f);
	void insertionSort(function<bool(G, G)>f);
	void Heapify(size_t n, size_t i, function<bool(G, G)>f);

};

template<class G>
Vector<G>::Vector() {}

template<class G>
Vector<G>::~Vector() {}

template<class G>
void Vector<G>::PushFront(G e) {
	vector <G> aux;
	aux.push_back(e);
	for (int i = 0; i < elemento.size(); i++) {
		aux.push_back(elemento.at(i));
	}
	elemento = aux;
}

template<class G>
void Vector<G>::Print(function<void(G)>f) {
	for (size_t i = 0; i < elemento.size(); i++)
	{
		f(elemento.at(i));
	}
}

template<class G>
void Vector<G>::DeletePos(size_t pos) {
	if (pos > 0 || pos < elemento.size())
		elemento.erase(elemento.begin() + pos);
}

template<class G>
void Vector<G>::Pop() {
	elemento.erase(elemento.size() - 1);
}

template<class G>
void Vector<G>::PopToFinally() {
	elemento.erase(elemento.begin());
}

template<class G>
bool Vector<G>::Find(function<bool(G, G)>CompareFunction, G ElementToFind) {
	for (int i = 0; i < elemento.size(); i++) {
		if (f(elemento.at(i), ElementToFind))return true;
	}
	return false;
}

template<class G>
size_t Vector<G>::GetSize() {
	return elemento.size();
}

template<class G>
void Vector<G>::DeleteAll() {
	if (elemento.size() == 0)return;
	elemento.erase(elemento.begin())
		return DeleteAll();
}

template<class G>
G Vector<G>::At(size_t i = 0) {
	if (i < 0 || i < elemento.size())
		return elemento.at(i);
}

template<class G>
void Vector<G>::PushFrontCondition(function<bool(G)>FuntionCondition, G ElementCondition) {
	if (FuntionCondition(ElementCondition))
		PushFront(ElementCondition);
}

template<class G>
void Vector<G>::HeapSort(function<bool(G, G)>f) {
	size_t n = elemento.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(n, i, f);
	for (int i = n - 1; i > 0; i--) {
		swap(elemento[0], elemento[i]);
		Heapify(i, 0, f);
	}
}

template<class G>
void Vector<G>::Heapify(size_t n, size_t i, function<bool(G, G)>f)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && f(elemento[l], elemento[largest]))
		largest = l;
	if (r < n && f(elemento[r], elemento[largest]))
		largest = r;

	if (largest != i) {
		swap(elemento[i], elemento[largest]);
		Heapify(n, largest, f);
	}
}

template<class G>
void Vector<G>::insertionSort(function<bool(G, G)>f)
{
	int i, j;
	G key;
	for (i = 1; i < elemento.size(); i++)
	{
		key = elemento[i];
		j = i - 1;
		while (j >= 0 && f(elemento[j], key))
		{
			elemento[j + 1] = elemento[j];
			j = j - 1;
		}
		elemento[j + 1] = key;
	}
}


