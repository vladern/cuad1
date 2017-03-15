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
/*
    Empieza la clase
    TListaCom
*/
/*
----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------
*/
// Constructor por defecto
TListaCom::TListaCom()
{
    this->primero=NULL;
    this->ultimo=NULL;
}
// Constructor de copia
TListaCom::TListaCom(const TListaCom& lista)
{
    this->Copia(lista);// depende de Copia
}
void TListaCom::Copia(const TListaCom& lista)
{
    //depende de Insertar
    TListaPos posicion = TListaPos(lista.primero);
    while(posicion.Siguiente()!=NULL)
    {
        this->InsCabeza(posicion.pos);
        poscion.pos=posicion.Siguiente();
    }
}
// Inserta el elemento en la cabeza de la lista
bool TListaCom::InsCabeza(const TComplejo& complejo)
{
    TListaNodo nodo = TListaNodo(complejo);
    TListaNodo *aux = new TListaNodo();
    aux=this->primero;
    if(&nodo==NULL)
    {
        return false;
    }else
    {
        //si el primero es vacio el primero y ultimo apuntan al nodo
        //sino reapuntamos todos los punteros   
        if(this->primero!=NULL)
        {
            //el el anterior del primer nodo apuntará a mi nodo
            this->primero->anterior=&nodo;
            //mi  nodo se convierte en el primero
            this->primero=nodo;
            //el siguiente de mi nodo será el nodo que antes era el primero
            nodo.siguiente=aux;
        }else
        {
            this->primero = nodo;
            this->ultimo = nodo;
        }
        return true;     
    }
}





