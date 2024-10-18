#include "Nodo.h"

Nodo::Nodo(int _value, Nodo* _nextNodo, Nodo* _previousNodo) : value(_value), nextNodo(_nextNodo), previousNodo(_previousNodo)
{
}

Nodo::Nodo(Nodo* _nextNodo, Nodo* _previousNodo) : value(0), nextNodo(_nextNodo), previousNodo(_previousNodo)
{
}

Nodo::Nodo() : value(0), nextNodo(NULL), previousNodo(NULL)
{
}

//Desctructor en cadena
Nodo::~Nodo()
{
	std::cout << "Nodo eliminado." << std::endl;
}

//Getter
int Nodo::GetValue()
{
	return value;
}

Nodo* Nodo::GetNext()
{
	return nextNodo;
}

Nodo* Nodo::GetPrevious()
{
	return previousNodo;
}


//Setter
void Nodo::SetValue(int _value)
{
	this->value = _value;
}


void Nodo::SetNext(Nodo* _nextNodo)
{
	if (nextNodo) {
	nextNodo->SetNext(_nextNodo);
	} 
	else {
		this->nextNodo = _nextNodo;
	}
}

void Nodo::SetPrevValu(Nodo* _nextNodo)
{
	this->previousNodo = _nextNodo;
}

void Nodo::SetPrevious(Nodo* _previous, Nodo* _nextNodo)
{
	if (nextNodo) {
		nextNodo->SetPrevious(_previous->GetNext(), _nextNodo);
	}
	else {
		//this->previousNodo = _previous;
		this->nextNodo = _nextNodo;
		_nextNodo->SetPrevValu(this);
	}
	
}

void Nodo::SetNextCircular(Nodo* _nextNodo)
{
	this->nextNodo = _nextNodo;
}

void Nodo::SetPreviousCircular(Nodo* _previous, Nodo* _nextNodo)
{
	this->nextNodo = _nextNodo;
	this->previousNodo = _previous;
}

void Nodo::DeleteNext()
{
	if (nextNodo) {
		delete nextNodo;
		nextNodo = nullptr;
	}
}

void Nodo::DeletePrevious()
{
}

