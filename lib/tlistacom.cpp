#include "tlistacom.h"

TListaNodo* TListaNodo::getAnterior()
{
    return this->anterior;
}
//getter del siguiente
TListaNodo* TListaNodo::getSiguiente()
{
    return this->siguiente;
}
//getter del complejo
TComplejo TListaNodo::getE()
{
    return this->e;
}
TListaNodo::TListaNodo():e()
{
    this->anterior=NULL;
    this->siguiente=NULL;
}
void TListaNodo::Copia(const TListaNodo& miNodo)
{
    this->e=miNodo.e;
	this->anterior=NULL;
	this->siguiente=NULL;
}
TListaNodo::TListaNodo(const TListaNodo& n)
{
    this->Copia(n);
}

TListaNodo::~TListaNodo()
{
    if(this!=NULL)
    {
        this->siguiente=NULL;
        this->anterior=NULL;
    }
}

TListaNodo& TListaNodo::operator=(const TListaNodo& nod)
{
    if(this != &nod)
    {
        (*this).~TListaNodo();
        Copia(nod);
    }
    return *this;
}

// Constructor por defecto
TListaPos::TListaPos()
{
    this->pos = NULL;
}
// Constructor de copia
TListaPos::TListaPos (const TListaPos& lista)
{
    this->Copia(lista);
}
TListaPos::TListaPos(TListaNodo *nodo)
{
    this->pos=nodo;
}
// Destructor
TListaPos::~TListaPos ()
{
    if(this != NULL)
    {
        this->pos=NULL;
    }
}
// Sobrecarga del operador asignación
TListaPos& TListaPos::operator=(const TListaPos& lista)
{
    if(this != &lista)
    {
        (*this).~TListaPos();
        this->Copia(lista);
    }
    return *this;
}
// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos& pos)
{
    if(this->pos == pos.pos)
    {
        return true;
    }
    return false;
}
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos& pos)
{
    return !((*this)==pos);
}
// Devuelve la posición anterior
TListaPos TListaPos::Anterior()
{
    TListaPos pos = TListaPos(this->pos->getAnterior());
    return pos;
}
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente()
{
    TListaPos pos = TListaPos(this->pos->getSiguiente());
    return pos;
}
// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPos::EsVacia()
{
    if(this->pos==NULL)
	{
		return true;
	}
    return false;
}
//copia
void TListaPos::Copia(const TListaPos& pos)
{
    this->pos = pos.pos;
}

// Constructor por defecto
TListaCom::TListaCom()
{
    this->primero=NULL;
    this->ultimo=NULL;
}
// Constructor de copia
TListaCom::TListaCom(const TListaCom& lista)
{
    this->Copia(lista);
}
// Destructor
// Destructor
TListaCom::~TListaCom()
{
	if(this!=NULL)
	{
		TListaNodo *aux0;
		TListaNodo *aux1;
		aux0=this->primero;
		while(aux0!=NULL)
		{
			aux1=aux0;
            aux0=aux0->getSiguiente();
			delete aux1;
		}
		this->primero=NULL;
		this->ultimo=NULL;
	}
}
// Sobrecarga del operador asignación
TListaCom& TListaCom::operator=(const TListaCom& lista)
{
    TListaNodo* aux;
    if(!(this!=lista))
    {
        (*this).~TListaPoro();
        aux = lista.getPrimero();
        while(aux!=NULL)
        {
            this->Insertar(lista.getE());
            aux=lista.getSiguiente();
        }
    }
    return *this;
}
//copia
void TListaCom::Copia(const TListaCom& lista)
{
    this->primero = lista.getPrimero();
    this->ultimo = lista.getUltimo();
}
//get primero
TListaNodo* TListaCom::getPrimero()const
{
    return this->primero;
}
//get ultimo
TListaNodo* TListaCom::getUltimo()const
{
    return this->ultimo;
}
bool TListaCom::operator==(TListaCom& lista)const
{
	TListaNodo *aux0;
	TListaNodo *aux1;
	aux0=this->primero;
    aux1=lista.getPrimero();
	int a=this->Longitud(),b=lista.Longitud();
	bool devuelvo;
	if(a!=b)
	{
		devuelvo=false;
	}else
	{
		devuelvo=true;
		while(aux0!=NULL and devuelvo==true)
		{
			if(aux0->e==aux1->e)
			{
				aux0=aux0->siguiente;
				aux1=aux1->siguiente;
			}else
			{
				devuelvo=false;
			}
		}
	}
	return devuelvo;
}
bool TListaCom::operator!=(TListaCom& lista)const
{
    return !((*this)==lista);
}
// Sobrecarga del operador suma
TListaCom TListaCom::operator+(const TListaCom& lista)
{
   TListaNodo* aux0 = this->getUltimo();
   TListaNodo* aux1 = lista->getPrimero();
   aux0->siguiente= aux1;
   aux1->anterior=aux0;
}


