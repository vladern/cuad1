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
TListaCom::~TListaCom()
{
    if(this != NULL)
    {
        this->primero=NULL;
        this->ultimo=NULL;
    }
}
// Sobrecarga del operador asignación
TListaCom& TListaCom::operator=(const TListaCom& lista)
{
    if(this != &lista)
    {
        (*this).~TListaCom();
        this->Copia(lista);
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