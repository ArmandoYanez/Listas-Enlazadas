#include "List.h"
#include <string>
#include <sstream>
#include <limits>

#include <cstdlib> 
#include <ctime> 

// Constructor
List::List() : root(NULL), type(LISTA_LINEAL_LIGADA)
{
}

// Destructor
List::~List()
{
	std::cout << std::endl;
	std::cout << "Lista eliminada." << std::endl;
	ClearList();
}

int List::GetValue(int position)
{
	return 0;
}


// Funcion para añadir valor
void List::Push(int NewValue)
{
	//Creamos el nuevo nodo.
	Nodo* newNode = new Nodo();

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:

		//Creamos el nuevo nodo.
		newNode = new Nodo();

		//Igualamos su entero al nuevo valor,
		newNode->SetValue(NewValue);

		//Si root tiene un nodo usamos el metodo SetNext del siguiente nodo.
		if (root) {
			root->SetNext(newNode);
		}
		else
		{
			root = newNode;
		}
		break;

	case LISTA_CIRCULAR_LIGADA:

		newNode = new Nodo();
		newNode->SetValue(NewValue);

		//Si la lista esta vacia inicia de 0
		if (!root) {
			root = newNode;
		}
		else if(root->GetNext() == NULL) {

			root->SetNext(newNode);
			newNode->SetNext(root);

		}else{
			//Si hay mas nodos
			Nodo* temp = root;

			//Mientras el siguiente no sea root continuara avanzando
			while (temp->GetNext() != root) {
				temp = temp->GetNext();
			}
			
			temp->SetNextCircular(newNode); //El utilimo apunta al nuevo

			newNode->SetNext(root); //El nuevo apunta a root
		}
		break;

	case LISTA_LINEAL_DLIGADA:

		//Creamos el nuevo nodo
		newNode = new Nodo();

		//Igualamos su entero al nuevo valor,
		newNode->SetValue(NewValue);

		//Si root tiene un nodo usamos el metodo SetNext del siguiente nodo.
		if (root) {
			root->SetPrevious(root, newNode);
		}
		else
		{
			root = newNode;	
		}
		break;

	case LISTA_CIRCULAR_DLIADA:
			
		newNode = new Nodo();
		newNode->SetValue(NewValue);

		//Si la lista esta vacia inicia de 0
		if (!root) {
			root = newNode;
		}
		else if (root->GetNext() == NULL) {

			//El circulo entre 2 nodos
			root->SetPreviousCircular(newNode, newNode);
			newNode->SetPreviousCircular(root, root);

		}
		else {
			//Si hay mas nodos
			Nodo* temp = root;
			Nodo* previous;
			

			//Mientras el siguiente no sea root continuara avanzando
			while (temp->GetNext() != root) {
				temp = temp->GetNext();
			}

			//Este pedazo ta heavy pero reasigna los nodos para crear el circulo doblemente enlazado
			temp->SetNextCircular(newNode); //El utilimo apunta al nuevo

			newNode->SetPreviousCircular(temp, root); //El nuevo apunta a root

			root->SetPrevValu(newNode);
		}
		break;

	default:
		break;
	}
}

// Funcion para leer lista
void List::ReadList()
{
	Nodo* actual = root;
	Nodo* nuevo;
	Nodo* inicio;

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:

		actual = root;

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		while (actual != NULL) {

			if (actual) {
				std::cout << actual->GetValue() << " ";

				nuevo = actual->GetNext();
				actual = nuevo;
			}
			else
			{
				std::cout << std::endl; std::cout << "No hay datos guardados";
			}
		}
		std::cout << std::endl;
		break;

	case LISTA_CIRCULAR_LIGADA:

		actual = root;

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (actual->GetNext() == NULL) {
			std::cout << actual->GetValue() << " ";
			return;
		}

		inicio = actual;
		while (true) {
			std::cout << actual->GetValue() << " ";
			actual = actual->GetNext();
			if (actual == inicio) {
				break; 
			}
		}
		std::cout << std::endl;
		break;

	case LISTA_LINEAL_DLIGADA:

		actual = root;

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		while (actual != NULL) {

			if (actual) {
				std::cout << actual->GetValue() << " ";

				nuevo = actual->GetNext();
				actual = nuevo;
			}
			else
			{
				std::cout << std::endl; std::cout << "No hay datos guardados";
			}
		}
		std::cout << std::endl;
		break;

	case LISTA_CIRCULAR_DLIADA:

		actual = root;

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (actual->GetNext() == NULL) {
			std::cout << actual->GetValue() << " ";
			return;
		}

		inicio = actual;
		while (true) {
			std::cout << actual->GetValue() << " ";
			actual = actual->GetNext();
			if (actual == inicio) {
				break;
			}
		}
		std::cout << std::endl;
		break;

	default:
		break;
	}
}

// Funcion para buscar un valor.
void List::FindValue(int position)
{
	Nodo* actual = root;
	int currentValue = 0;

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:
		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		//Mientras no sea nulo
		while (actual != NULL) {

			if (actual) {

				if (currentValue++ == position - 1) {
					std::cout << "El valor en la posicion " << position << " es: " << actual->GetValue() << std::endl;
					return;
				}
				else
				{
					Nodo* nuevo = actual->GetNext();
					actual = nuevo;
				}
			}
			else
			{
				std::cout << std::endl; std::cout << "No hay datos guardados";
			}
		}
		break;

	case LISTA_CIRCULAR_LIGADA:
		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (root->GetNext() == NULL) {
			std::cout << "El valor en la posicion " << position << " es: " << root->GetValue() << std::endl;
			return;
		}

		for (int i = 0; i < position - 1; i++) {
			actual = actual->GetNext();
		}

		std::cout << "El valor en la posicion " << position << " es: " << actual->GetValue() << std::endl;
		break;

	case LISTA_LINEAL_DLIGADA:

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		//Mientras no sea nulo
		while (actual != NULL) {

			if (actual) {

				if (currentValue++ == position - 1) {
					std::cout << "El valor en la posicion " << position << " es: " << actual->GetValue() << std::endl;
					return;
				}
				else
				{
					Nodo* nuevo = actual->GetNext();
					actual = nuevo;
				}
			}
			else
			{
				std::cout << std::endl; std::cout << "No hay datos guardados";
			}
		}
		break;

	case LISTA_CIRCULAR_DLIADA:
		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (root->GetNext() == NULL) {
			std::cout << "El valor en la posicion " << position << " es: " << root->GetValue() << std::endl;
			return;
		}

		for (int i = 0; i < position - 1; i++) {
			actual = actual->GetNext();
		}

		std::cout << "El valor en la posicion " << position << " es: " << actual->GetValue() << std::endl;
		break;

	default:
		break;
	}
}

// Funcion para limpiar lista.
void List::ClearList()
{
	Nodo* actual = root;
	Nodo* next;
	Nodo* temp;

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		while (actual != NULL) {

			Nodo* next = actual->GetNext();
			delete actual;
			actual = next;
		}
		root = nullptr;

		break;

	case LISTA_CIRCULAR_LIGADA:

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (!root) {

		}

		if (root) {
			actual = root;

			if (root->GetNext() == NULL) {
				delete actual;
				root = nullptr;
				return;
			}
			
			next = actual->GetNext();

			while (next != root) {
				temp = next;          
				next = next->GetNext();     
				delete temp;               
			}

			delete actual;

			root = nullptr;  
		}
		break;

	case LISTA_LINEAL_DLIGADA:

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		while (actual != NULL) {

			Nodo* next = actual->GetNext();
			delete actual;
			actual = next;
		}
		root = nullptr;

		break;

	case LISTA_CIRCULAR_DLIADA:

		if (actual == NULL) {
			std::cout << "No hay datos guardados" << std::endl;
			return;
		}

		if (root) {
			actual = root;

			if (root->GetNext() == NULL) {
				delete actual;
				root = nullptr;
				return;
			}

			next = actual->GetNext();

			if (next == root) {
				delete root;
				root = nullptr;
			}
			else {
				
				while (next != root) {
					temp = next;       
					next = next->GetNext();    
					delete temp;              
				}

				delete actual;
				root = nullptr;  
			}
		}
		break;

	default:
		break;
	}
}

// Funcion para borrar el ultimo nodo.
void List::pop()
{
	Nodo* nodoAEliminar;
	Nodo* actual = root;
	Nodo* second_last;

	int value; // Guardamos el valor del último nodo

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:

		if (root == nullptr) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		// Si solo hay un nodo
		if (root->GetNext() ==	nullptr) {
			value = root->GetValue();
			delete root;
			root = nullptr;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			return;
		}

		// Hay más de un nodo, buscamos el penúltimo
		actual = root;
		while (actual->GetNext()->GetNext() != nullptr) {
			actual = actual->GetNext();
		}

		value = actual->GetNext()->GetValue(); // Guardamos el valor del último nodo
		actual->DeleteNext();

		std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
		return;
		break;

	case LISTA_CIRCULAR_LIGADA:

		if (root == nullptr)
		{
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		if (root->GetNext() == root || root->GetNext() == NULL)
		{
			// Si solo hay un nodo
			value = root->GetValue();
			delete root;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			root = nullptr;
		}
		else
		{
			actual = root;

			// Recorrer hasta el último nodo
			while (actual->GetNext() != root)
			{
				actual = actual->GetNext();
			}

			// Eliminar el último nodo y actualizar el enlace
			nodoAEliminar = actual;
			actual = root;
			while (actual->GetNext() != nodoAEliminar)
			{
				actual = actual->GetNext();
			}

			actual->SetNextCircular(root);

			value = nodoAEliminar->GetValue();

			delete nodoAEliminar;

			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;

			
		}
		return;
		break;

	case LISTA_LINEAL_DLIGADA:

		if (root == nullptr) {
			std::cout << "La lista esta vacia" << std::endl;
			return;
		}

		// Si solo hay un nodo
		if (root->GetNext() == nullptr) {
			value = root->GetValue();
			delete root;
			root = nullptr;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			return;
		}

		// Hay más de un nodo, buscamos el penúltimo
		actual = root;
		while (actual->GetNext()->GetNext() != nullptr) {
			actual = actual->GetNext();
		}

		value = actual->GetNext()->GetValue(); // Guardamos el valor del último nodo
		actual->DeleteNext();

		std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
		return;
		break;

	case LISTA_CIRCULAR_DLIADA:

		if (root == nullptr)
		{
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		if (root->GetNext() == root || root->GetNext() == NULL)
		{
			// Si solo hay un nodo en la lista circular
			value = root->GetValue();
			delete root;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			root = nullptr;
		}
		else
		{
			actual = root->GetPrevious();  // El último nodo es el nodo anterior a root
			second_last = actual->GetPrevious(); 

			// El penúltimo nodo debe apuntar a root, ya que estamos eliminando el último nodo
			second_last->SetNextCircular(root);
			root->SetPrevValu(second_last);

			value = actual->GetValue();

			// Eliminar el último nodo
			delete actual;

			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
		}

		break;

	default:
		break;
	}
}

// Funcion para borrar el primer nodo.
void List::EraseFirst()
{
	int value;
	Nodo* temp = root;
	Nodo* inicio = root;

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:

		if (root == NULL) {
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		// Si solo hay un nodo
		if (root->GetNext() == nullptr) {
			value = root->GetValue();
			delete root;
			root = nullptr;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			return;
		}

		value = root->GetValue();
		temp = root;

		root = root->GetNext();
		delete temp;

		std::cout << "El valor del nodo eliminado era de: " << value << std::endl;

		break;

	case LISTA_CIRCULAR_LIGADA:

		if (root == nullptr)
		{
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		if (root->GetNext() == root || root->GetNext() == NULL)
		{
			// Si solo hay un nodo en la lista circular
			value = root->GetValue();
			delete root;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			root = nullptr;
		}
		else
		{
			temp = root;  
			inicio = root;

			// Encontrar el último nodo (aquel cuyo siguiente es root)
			while (inicio->GetNext() != root)
			{
				inicio = inicio->GetNext();
			}

			// El último nodo debe apuntar al siguiente nodo de root
			inicio->SetNextCircular(root->GetNext());

			// Ahora eliminamos el nodo raíz
			root = root->GetNext();  // Mover root al siguiente nodo

			value = temp->GetValue();
			delete temp;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;

			  
		}
			break;

	case LISTA_LINEAL_DLIGADA:

		if (root == nullptr) {
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		// Si solo hay un nodo
		if (root->GetNext() == nullptr) {
			value = root->GetValue();
			delete root;
			root = nullptr;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			return;
		}

		value = root->GetValue();
		temp = root;

		root = root->GetNext();
		delete temp;

		std::cout << "El valor del nodo eliminado era de: " << value << std::endl;

		break;

	case LISTA_CIRCULAR_DLIADA:

		if (root == nullptr)
		{
			std::cout << "La lista esta vacia." << std::endl;
			return;
		}

		if (root->GetNext() == root || root->GetNext() == NULL)
		{
			// Si solo hay un nodo en la lista circular
			value = root->GetValue();
			delete root;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
			root = nullptr;
		}
		else
		{
			inicio = root;

			temp = root->GetNext();  // Nodo siguiente al primer nodo

			
			temp->SetPrevValu(root->GetPrevious());

			root->GetPrevious()->SetNextCircular(temp);

			root = temp;

			value = inicio->GetValue();

			// Eliminar el nodo que era el primer nodo
			delete inicio;
			std::cout << "El valor del nodo eliminado era de: " << value << std::endl;
		}
		break;

	default:
		break;
	}
}

// Actualizar el enum.
void List::UpdateEnum(LIST_TYPE typeNew)
{
	this->type = typeNew;
}

// Revisar si root tiene algo.
bool List::CheckRoot()
{
	if (root) {
		return true;
	}
	else
	{
		return false;
	}
}

bool List::CheckRootNext()
{
	if (root->GetNext()) {
		return true;
	}
	else
	{
		return false;
	}
}

// Funcion + interfaz para moverse en la lista (Solo disponible en la circular doblemente ligada).
void List::MoveInlist()
{
	Nodo* temp = root;
	Nodo* newNode;
	Nodo* nextNode;

	if (root == nullptr)
	{
		std::cout << "La lista esta vacia." << std::endl;
		system("pause");
		return;
	}

	int value = root->GetValue();
	if (root->GetNext() == root || root->GetNext() == NULL)
	{
		// Si solo hay un nodo en la lista circular
		std::cout << "La lista solo tiene 1 valor, anade mas para moverte por la lista." << std::endl;
		system("pause");
		return;
	}

	std::string input;
	while (input != "4") {
		system("CLS");
		std::cout << "1 - Avanza." << std::endl;
		std::cout << "2 - Retrocede." << std::endl;
		std::cout << "3 - Anadir valor despues de el valor actual" << std::endl;
		std::cout << "4 - Salir." << std::endl << std::endl;

		std::cout << "Valor actual: " << value << std::endl;

		std::cin >> input;

		if (input == "1") {
			temp = temp->GetNext();
			value = temp->GetValue();
		}

		if (input == "2") {
			temp = temp->GetPrevious();
			value = temp->GetValue();
		}

		if (input == "3") {

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

			newNode = new Nodo(value, temp->GetNext(), temp);
			temp->GetNext()->SetPrevValu(newNode);
			temp->SetNextCircular(newNode);
			
			
		}
	}

	return;
}

// Funcion para rellenar de numeros random la lista.
void List::RandomList(int cantValue, int maxValue, int minValue)
{
	int randomValue = 0;

	// Reasignamos la semilla del random (Permitira obtener valores diferentes en cada ejecucion)
	srand(time(0));

	
	if (minValue > maxValue) {
		std::swap(minValue, maxValue);  // Intercambiamos por si acaso
	}

	for (int i = 0; i < cantValue; i++) {
		randomValue = rand() % (maxValue - minValue + 1) + minValue;
		Push(randomValue);
	}

	return;

}

// Algorimo de ordenamiento burbuja (Se puede simplificar)
void List::BubbleSort()
{
	bool salir = false;
	bool cambio = true;
	Nodo* current = root;

	switch (type)
	{
	case LISTA_LINEAL_LIGADA:
		
		while (!salir) {

			if (current->GetNext() == nullptr) {
				current = root;

				if (!cambio) {
					std::cout << "Lista ordenada" << std::endl;
					salir = true;
				}
				else {
					cambio = false; 
				}
			}

			// Comparaaramos y cambiamos si es necesario
			if (current->GetValue() > current->GetNext()->GetValue()) {
				Swap(current, current->GetNext());
				cambio = true;
			}

			if (current->GetNext()) {
				current = current->GetNext(); // Avanza el puntero
			}
			
		}
		break;

	case LISTA_CIRCULAR_LIGADA:
		while (!salir) {
			if (current->GetNext() == root) {
				current = root;

				if (!cambio) {
					std::cout << "Lista circular ligada ordenada" << std::endl;
					salir = true;
				}
				else {
					cambio = false;
				}
			}

			if (current->GetValue() > current->GetNext()->GetValue()) {
				Swap(current, current->GetNext());
				cambio = true;
			}

			if (current->GetNext() != root) {
				current = current->GetNext(); // Avanza el puntero
			}
		}
		break;


	case LISTA_LINEAL_DLIGADA:

		while (!salir) {
			if (current->GetNext() == nullptr) {
				current = root;

				if (!cambio) {
					std::cout << "Lista doblemente ligada ordenada" << std::endl;
					salir = true;
				}
				else {
					cambio = false;
				}
			}

			if (current->GetValue() > current->GetNext()->GetValue()) {
				Swap(current, current->GetNext());
				cambio = true;
			}

			if (current->GetNext() ) {
				current = current->GetNext(); // Avanza el puntero
			}
		}
		break;

	case LISTA_CIRCULAR_DLIADA:

		while (!salir) {
			if (current->GetNext() == root) {
				current = root;

				if (!cambio) {
					std::cout << "Lista circular doblemente ligada ordenada" << std::endl;
					salir = true;
				}
				else {
					cambio = false;
				}
			}

			if (current->GetValue() > current->GetNext()->GetValue()) {
				Swap(current, current->GetNext());
				cambio = true;
			}

			if (current->GetNext() != root) {
				current = current->GetNext(); // Avanza el puntero
			}
		}
		break;

	default:
		break;
	}
	ReadList();
}

void List::InsertionSort()
{
	bool salir = false;
	bool cambio = true;

	Nodo* current = root;
	Nodo* aux = root;
	Nodo* NodoAinsertar = root;

	int cantidadDeNodos = 0;
	int index = 0;


	switch (type)
	{
	case LISTA_LINEAL_LIGADA:
		// Mientras sea desigual a null avanza y suma, esto sera para saber con cuantos nodos contamos
		while (current->GetNext() != NULL) {
			current = current->GetNext();
			cantidadDeNodos++;
		}

		current = root;

		while (!salir) {

			aux = current;
			index = current->GetValue();
			
			for (int i = 0; i <= cantidadDeNodos; i++) {

				if (index > aux->GetValue()) {
					index = aux->GetValue();
					NodoAinsertar = aux;
				}
				
				aux = aux->GetNext();
			}

			Swap(current, NodoAinsertar);
			current = current->GetNext();
			cantidadDeNodos--;

			if (cantidadDeNodos == 0) {
				salir = true;
			}
		}
		break;

	case LISTA_CIRCULAR_LIGADA:
		break;


	case LISTA_LINEAL_DLIGADA:
		break;

	case LISTA_CIRCULAR_DLIADA:
		break;

	default:
		break;
	}
	ReadList();
}

//Recibe los nodos que se cambiaran y cambia el valor
void List::Swap(Nodo* _nodoIzquierda, Nodo* _nodoDerecha)
{
	int prov = 0;
	
	//Le damos el valor de nodo izquierda
	prov = _nodoIzquierda->GetValue();

	_nodoIzquierda->SetValue(_nodoDerecha->GetValue());
	_nodoDerecha->SetValue(prov);
}
	
