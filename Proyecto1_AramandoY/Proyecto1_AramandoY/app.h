#pragma once
#include "List.h"
#include <string>
#include <sstream>
#include <limits>

class app
{
public:
	//Constructor
	app();

	//Destructor
	~app();

	void Init();
	void Pop();

	void MainMenu();
	void ListMenu();

	void rellenarLista();

	//Sub menu de seleccion de ordenamiento
	void  menuOrdenamiento();

	// Nueva adicion para orden y gestion
	bool NewFuncActivation;

private:

	List* lista = new List();

	//Funcion para pushear
	void PushValue();
	void ShowList();
	void FindValue();
	void CleanList();
	void EraseFirst();
};


