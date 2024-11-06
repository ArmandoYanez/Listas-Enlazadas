#pragma once
#include "Nodo.h"


enum LIST_TYPE {
	LISTA_LINEAL_LIGADA,
	LISTA_CIRCULAR_LIGADA,
	LISTA_LINEAL_DLIGADA,
	LISTA_CIRCULAR_DLIADA
};

class List
{
public:
	// Constructor que lo rellenara nulo
	List();

	// Destructor de la lista
	~List();

	// Obtener valor guardado en el nodo
	int GetValue(int position);

	// Guardar un entero
	void Push(int newNodo);
	
	// Leer toda la lista
	void ReadList();

	// Retornoar el valor segun el ingresado
	void FindValue(int position);

	// Limpiar una lista
	void ClearList();

	// Eliminar primero y imprimir
	void pop();
	void EraseFirst();

	// Reasingar valor de enum
	void UpdateEnum(LIST_TYPE typeNew);

	// Verificar si root tiene algo
	bool CheckRoot();
	bool CheckRootNext();

	// Mover hacia atras y hacia adelante
	void MoveInlist();

	// Metodo para llenar automaticamente una lista
	void RandomList(int cantValue, int maxValue, int minValue);


	// Ordenamientos 
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();

	// Merge Sort (Extremadamente papu chat giga chat de raro).	
	void MergeSort();

	Nodo* mergeSort(Nodo* head);
	Nodo* findMiddle(Nodo* head);

	Nodo* merge(Nodo* left, Nodo* right);

	// Quick Sort (Extremadamente papu chat giga chat de dificil x2).
	void quickSort();
	
	Nodo* partition(Nodo* start, Nodo* end, Nodo** newStart, Nodo** newEnd);
	Nodo* quickSortRecur(Nodo* start, Nodo* end);
	Nodo* getTail(Nodo* current);
	

	// Ordenamientos Herramientas
	void Swap(Nodo* _nodoIzquierda, Nodo* _nodoDerecha);
	void Insertar(Nodo* _nodoIzquierda, Nodo* _newNodo);

private:
	Nodo* root;

	//Prueba
	LIST_TYPE type;
};

