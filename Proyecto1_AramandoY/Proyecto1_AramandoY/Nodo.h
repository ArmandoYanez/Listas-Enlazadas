#pragma once
#include <iostream>

class Nodo
{
public:
	//Constructor explicito(Por parametros)
	Nodo(int _value, Nodo* _nextNodo, Nodo* _previousNodo);

	Nodo(Nodo* _nextNodo, Nodo* _previousNodo);

	//Constructor por implicito(Por default)
	Nodo();

	//Desctructor en cadena
	~Nodo();

	//Getter
	int GetValue();
	Nodo* GetNext();
	Nodo* GetPrevious();

	//Setter
	void SetValue(int _value);
	void SetNext(Nodo* _nextNodo);
	void SetPrevValu(Nodo* _nextNodo);

	void SetPrevious(Nodo* _previous, Nodo* _nextNodo);

	void SetNextCircular(Nodo* _nextNodo);
	void SetPreviousCircular(Nodo* _previous, Nodo* _nextNodo);

	//Delete next, previous
	void DeleteNext();
	void DeletePrevious();


private:
	int value;

	Nodo* nextNodo;
	Nodo* previousNodo;
};