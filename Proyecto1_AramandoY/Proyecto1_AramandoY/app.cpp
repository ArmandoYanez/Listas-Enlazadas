	#include "app.h"
#include <string>
#include <sstream>
#include <limits>

enum OPTION {
	LISTA_LINEAL_LIGADA_OP,
	LISTA_CIRCULAR_LIGADA_OP,
	LISTA_LINEAL_DLIGADA_OP,
	LISTA_CIRCULAR_DLIADA_OP
};

app::app()
{
}

app::~app()
{

}


void app::Init()
{
	ListMenu();
	MainMenu();
}

void app::MainMenu()
{
	std::string input;
	while (input != "8") {
		std::cout << std::endl;
		system("CLS");
		std::cout << "Selecciona la opcion deseada:" << std::endl;
		std::cout << "[1] - Insertar numero a la lista." << std::endl;
		std::cout << "[2] - Mostrar lista." << std::endl;
		std::cout << "[3] - Buscar valor por indice." << std::endl;
		std::cout << "[4] - Limpiar lista." << std::endl;
		std::cout << "[5] - Borrar ultimo nodo." << std::endl;
		std::cout << "[6] - Borrar primer nodo." << std::endl;

		if (!lista->CheckRoot()) {
			std::cout << "[7] - Crear nueva lista" << std::endl; // Cambié el texto a "Inicializar lista"
		}
		else {
			std::cout << "[7] - Opcion no disponible (Borra lista para poder crear una nueva)." << std::endl; // Mostrar como no disponible si no se puede inicializar
		}

		std::cout << "[8] - Salir." << std::endl;

		std::cout << "[9] - Rellenar lista." << std::endl;

		if (NewFuncActivation) {
			std::cout << "[10] - Recorrido." << std::endl;
		}

		std::cout << "[11] - Ordenar." << std::endl;

		std::cin >> input;
		std::cin.clear();

		if (input == "1") {
			PushValue();
		}
		else if (input == "2") {
			ShowList();
		}
		else if (input == "3") {
			FindValue();
		}
		else if (input == "4") {
			CleanList();
		}
		else if (input == "5") {
			Pop();
		}
		else if (input == "6") {
			EraseFirst();
		}
		else if (input == "7") {
			if (!lista->CheckRoot()) {
				Init(); 
			}
			else {
				std::cout << "Opcion no disponible." << std::endl; 
			}
		}
		else if(input == "9"){
			rellenarLista();
		}
		else if (input == "11") {
			menuOrdenamiento();
		}
		else if (NewFuncActivation) {
				if (input == "10") {
					lista->MoveInlist();
				}
		}
		
		else if (input != "8") {
			std::cout << "Opcion no disponible." << std::endl;
		}
	}
}

void app::ListMenu()
{
	NewFuncActivation = false;

	std::string input = "1";
	while (input != "1" || input != "2" || input != "3" || input != "4") {
		std::cout << std::endl;
		system("CLS");
		std::cout << "Selecciona la opcion deseada:" << std::endl;
		std::cout << "[1] - Lista lineal ligada." << std::endl;
		std::cout << "[2] - Lista circular ligada." << std::endl;
		std::cout << "[3] - Lista lineal doblemente ligada." << std::endl;
		std::cout << "[4] - Lista circular doblemente ligada." << std::endl;

		std::cin >> input;
		std::cin.clear();

		if (input == "1") {
			std::cout << "Lista lineal ligada creada" << std::endl;

			lista->UpdateEnum(LISTA_LINEAL_LIGADA);
			system("pause");
			break;
		}
		else if (input == "2") {
			std::cout << "Lista circular ligada creada" << std::endl;

			lista->UpdateEnum(LISTA_CIRCULAR_LIGADA);
			system("pause");
			break;
		}
		else if (input == "3") {
			std::cout << "Lista lineal doblemente ligada" << std::endl;

			lista->UpdateEnum(LISTA_LINEAL_DLIGADA);
			system("pause");
			break;
		}
		else if (input == "4") {
			std::cout << "Lista circular doblemente ligada creada" << std::endl;

			//Activamos bandera
			NewFuncActivation = true;

			lista->UpdateEnum(LISTA_CIRCULAR_DLIADA);
			system("pause");
			break;
		}
	}
}



void app::rellenarLista()
{
	int listSize, MaxVlue, MinVlue;
	bool validInput = false;
	bool validInput2 = false;
	bool validInput3 = false;

	//Añadimos comprobacion
	while (!validInput) {
		std::cout << "Ingresa la cantidad de datos a rellenar: ";
		std::string input;
		std::cin >> input;

		try {
			listSize = std::stoi(input);
			validInput = true;

			while (!validInput2) {
				std::cout << "Ingresa el valor maximo que pueden alcanzar los datos: ";
				std::string input2;
				std::cin >> input2;

				try {
					MaxVlue = std::stoi(input2);
					validInput2 = true;

					while (!validInput3) {
						std::cout << "Ingresa el valor minimo que pueden alcanzar los datos: ";
						std::string input3;
						std::cin >> input3;

						try {
							MinVlue = std::stoi(input3);
							validInput3 = true;
						}
						catch (std::invalid_argument&) {
							std::cout << "Caracter invalido, ingresa un numero entero." << std::endl;
						}
						catch (std::out_of_range&) {
							std::cout << "Caracter invalido, ingresa un numero mas chico." << std::endl;
						}
					}
				}
				catch (std::invalid_argument&) {
					std::cout << "Caracter invalido, ingresa un numero entero." << std::endl;
				}
				catch (std::out_of_range&) {
					std::cout << "Caracter invalido, ingresa un numero mas chico." << std::endl;
				}
			}
		}
		catch (std::invalid_argument&) {
			std::cout << "Caracter invalido, ingresa un numero entero." << std::endl;
		}
		catch (std::out_of_range&) {
			std::cout << "Caracter invalido, ingresa un numero mas chico." << std::endl;
		}
	}


	lista->RandomList(listSize, MaxVlue, MinVlue);
	system("pause");

}

void app::menuOrdenamiento()
{
	//Agreger comprobacion para comprobar si la lista tiene mas de 1 dato para ser utilizado.
	if (!lista->CheckRoot() || !lista->CheckRootNext()) {
		std::cout << "Inserte mas valores para poder ordenarlos." << std::endl;
		system("pause");
		return;
	}

	std::string input = "1";
	while (input != "1" || input != "2" || input != "3" || input != "4" || input != "5") {
		std::cout << std::endl;
		system("CLS");
		std::cout << "Selecciona el ordenamiento que deseas usar:" << std::endl;
		std::cout << "[1] - Bubble Sort." << std::endl;
		std::cout << "[2] - Selection Sort." << std::endl;
		std::cout << "[3] - Insertion Sort." << std::endl;
		std::cout << "[4] - Pendiente." << std::endl;
		std::cout << "[5] - Pendiente." << std::endl;
		std::cout << "[6] - Salir." << std::endl;

		std::cin >> input;
		std::cin.clear();

		if (input == "1") {
			std::cout << "Ordenamiento seleccionado : Bubble Sort" << std::endl;

			// Agregar metodo de ordenamineto burbuja
			lista->BubbleSort();

			system("pause");
			break;
		}
		else if (input == "2") {
			std::cout << "Ordenamiento seleccionado : Selection Sort" << std::endl;
			
			// Agregar metodo de ordenamineto InsertionSort
			lista->SelectionSort();

			system("pause");
			break;
		}
		else if (input == "3") {
			std::cout << "Ordenamiento seleccionado : Insertion Sort" << std::endl;

			// Agregar metodo de ordenamineto pendiente
			lista->InsertionSort();

			system("pause");
			break;
		}
		else if (input == "4") {
			std::cout << "Ordenamiento seleccionado :" << std::endl;

			// Agregar metodo de ordenamineto pendiente
			std::cout << "4" << std::endl;

			system("pause");
			break;
		}
		else if (input == "5") {
			std::cout << "Ordenamiento seleccionado :" << std::endl;

			// Agregar metodo de ordenamineto pendiente
			std::cout << "5" << std::endl;

			system("pause");
			break;
		}
		else if (input == "6") {
			break;
		}
	}

	return;
}

void app::PushValue()
{
	int value = 0;

	bool validInput = false;

	//Añadimos comprobacion
	while (!validInput) {
		std::cout << "Ingresa el valor que deseas agregar: ";
		std::string input;
		std::cin >> input;


		try {
			value = std::stoi(input);
			validInput = true;
		}
		catch (std::invalid_argument&) {
			std::cout << "Caracter invalido, ingresa un numero entero." << std::endl;
		}
		catch (std::out_of_range&) {
			std::cout << "Caracter invalido, ingresa un numero mas chico." << std::endl;
		}
	}

	lista->Push(value);
	system("pause");
}

void app::FindValue()
{
	int value = 0;
	bool validInput = false;

	//Añadimos comprobacion
	while (!validInput) {
		std::cout << "Ingresa el valor que deseas buscar: ";
		std::string input;
		std::cin >> input;

		try {
			value = std::stoi(input);
			validInput = true;
		}
		catch (std::invalid_argument&) {
			std::cout << "Caracter invalido, ingresa un numero entero." << std::endl;
		}
		catch (std::out_of_range&) {
			std::cout << "Caracter invalido, ingresa un numero mas chico." << std::endl;
		}
	}

	lista->FindValue(value);
	system("pause");
}

void app::CleanList()
{
	lista->ClearList();
	system("pause");
}


void app::ShowList()
{
	lista->ReadList();
	system("pause");
}

void app::Pop()
{
	lista->pop();
	system("pause");
}

void app::EraseFirst()
{
	lista->EraseFirst();
	system("pause");
}
