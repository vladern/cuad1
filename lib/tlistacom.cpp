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
// Destructor
TListaCom::~TListaCom()
{
    if(this!=NULL)
    {
        TListaPos pos = TListaPos();
        TListaNodo *aux;
        while(pos.Siguiente()!=NULL)
        {
            aux=pos.pos;
            pos.pos=pos.Siguiente();
            delete aux;
        }
        this->primero=NULL;
        this->ultimo=NULL;
    }
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
// Sobrecarga del operador asignación
TListaCom & TListaCom::operator=(const TListaCom& lista)
{
    if(this=!lista)
    {
        (*this).~TListaCom();
        this->Copia(lista);
    }
}
//Sobrecarga del operador igualdad
bool TListaCom::operator==(TListaCom& lista)
{
    if(this->Longitud()!=lista.Longitud())
    {
        return false;
    }
    TListaPos miPos = TListaPos(this->primero);
    TListaPos suPos = TListaCom(lita.primero);
    //recorro la lista
    while(miPos.Siguiente()!=NULL)
    {
        //si mi complejo  es distinto de su complejo 
        if(miPos.pos->getE() != suPos.pos->getE())
        {
            return false;
        }
        miPos.pos = miPos.Siguiente();
        suPos.pos = suPos.Siguiente();
    }
    return true;
}
//Sobrecarga del operador desigualdad
bool TListaCom::operator!=(TListaCom& lista)
{
    return !((*this)==lista); 
}
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCom::EsVacia()
{
    if(this->primero==NULL)
    {
        return true;
    }
    return false;
}
// Devuelve true si el elemento está en la lista, false en caso contrario
bool Buscar(const TComplejo& com)
{
    TListaPos miPos = TListaPos(this->primero);
    //recorro la lista
    while(miPos.Siguiente()!=NULL)
    {
        //si mi complejo  es igual de su complejo 
        if(miPos.pos->getE() == com)
        {
            return true;
        }
        miPos.pos = miPos.Siguiente();
    }
    return false;    
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
            this->primero=&nodo;
            //el siguiente de mi nodo será el nodo que antes era el primero
            nodo.siguiente=aux;
        }else
        {
            this->primero = &nodo;
            this->ultimo = &nodo;
        }
        return true;     
    }
}
// Devuelve la longitud de la lista
int TListaCom::Longitud()
{
    if(this->primero!=NULL)
    {
        return 0
    }
    TListaPos pos = TListaPos(this->primero);
    int a = 0;
    while(pos.Siguiente() != NULL)
    {
        a++;
        pos=pos.Siguiente();
    }
    retur a;
}
// Inserta el elemento a la izquierda de la posición indicada
bool InsertarI(const TComplejo& e,const TListaPos& pos)
{
    if(pos.pos!=NULL)
    {
       TListaNodo nodo = TListaNodo(e);
       //si la posición que me pasan apunta al primer nodo
       if(this->primero == pos.pos)
       {
           //hago que mi primer nodo me apunte como su anterior
           this->primero->anterior=&nodo;
           //apunto al siguiente nodo 
           nodo.siguiente=this->primero;
           //cambio el puntero del primero y hago que me apunte a mi
           this->primero=&nodo;
           return true;
       }else
       {
           //consigo la posicion del nodo anterior 
          TListaPos aux = TListaPos(pos.Anterior());
          //hago que el nodo anterior me apunte como su siguiente
          aux.pos->siguiente = &nodo;
          //hago que el nodo del que me pasarón la pos me apunte como su anterior
          pso.pos->anterior=&nodo;
          return true;
       }
    }else
    {
        return false;
    }
}