#include"tvectorcom.h"

TVectorCom::TVectorCom()
{
    this->tamano=0;
    this->c=NULL;
}
TVectorCom::TVectorCom(int a)
{
    if(a<0)
    {
        this->tamano=0;
        this->c=NULL;
    }else
    {
        this->tamano=a;
        this->c = new TComplejo();
    }
}
//constructor de copia
TVectorCom::TVectorCom(const TVectorCom& vec)
{
	this->Copia(vec);
}
TVectorCom::~TVectorCom()//falta por hacer
{

}
//Copia el objeto en profundidad
void TVectorCom::Copia(const TVectorCom& vec)
{
	this->tamano=vec.Tamano();
	for(int i=0;i<this->Tamano();i++)
	{
		this[i]=vec[i];
	}
}
//sobrecarga del operador de asignacion
TVectorCom& TVectorCom::operator=(const TVectorCom& vec)
{
    if(this != &vec)
    {
        //lo destruyo
        this->~TComplejo();
        // y lo copio
        this->Copia(vec);
    }
    return *this;
}
//sobrecarga del operador de igualdad
bool TVectorCom::operator==(const TVectorCom& vec)
{
	if(vec.Tamano()!=this->Tamano())
	{
		return false;
	}
	for(int i=0;i<this->Tamano();i++)
	{
		if(this->c[i]!=vec[i])
		{
			return false;
		}
	}
	return true;
}
//sobrecarga del operador de desigualdad
bool TVectorCom::operator!=(const TVectorCom& vec)
{
	return !(this==vec);
}
//sobrecarga del operador de [] de izquierda
TComplejo& TVectorCom::operator[](int num)
{
	if(num>=1 && num<=this->Tamano())
	{
		return *this->c[num-1];
	}
	return *this->error; //hay que mirar como se implementa ++++++++++++++++++
}
//sobrecarga del operador de [] de izquierda
TComplejo TVectorCom::operator[](int num)const
{
	if(num>=1 && num<=this->Tamano())
	{
		TComplejo nuevo = this->c[num-1];
	}
	return this->error;
}
//devuelve el tamaño del vector
int TVectorCom::TVectorCom()const
{
	return this->tam;
}
//numero de TComplojos no vacios
int TVectorCom::Ocupadas() const //añadir el caso de que este vacio el vector y apunte a null
{
  int cont = 0;
  if(this->c == NULL )
	  return cont;
  for(int i=0;i<this->Tamano();i++)
  {
	 if(!this->c[i].EsVacio())
	 {
		 cont++;
	 }
  }
  return cont;
}
bool ExisteCom(const TComplejo& com)
{
	if(this->c==NULL)
		return false;
	for(int i=0;i<this->Tamano();i++)
	{
		if(this->c[i]==com)
			return true;
	}
	return false;
}
// Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL O POSTERIOR al argumento
void TVectorCom::MostrarComplejos(double re)
{
	if(this->c==NULL)
	{
		cout<<""<<endl;
	}
	for(int i=0;i<this->Tamano();i++)
	{
		if(this->c[i].Re()>=re)
		{
			cout<<this->c[i];
		}
	}
}
// REDIMENSIONAR el vector de TComplejo
bool TVectorCom::Redimensionar(int num)
{
	this->tamano = num;
	return true;
}
// Sobrecarga del operador salida
friend ostream & operator<<(ostream& os,const TVectorCom& vec) //mirar y comprobar que este todo bien
{
	for(int i=0;i<vec.Tamano();i++)
	{
		os<<vec[i];
	}
	return os;
}

