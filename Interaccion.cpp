#include "..\..\include\comun\Interaccion.h"
#include <math.h>

Interaccion::Interaccion(void)
{
}

Interaccion::~Interaccion(void)
{
}

void Interaccion::Rebote(Hombre &h, Caja c)
{
	float xmax=c.suelo.limite2.x-h.altura/2;
	float xmin=c.suelo.limite1.x+h.altura/2;
	if (h.posicion.x > xmax) h.posicion.x=xmax;
	if (h.posicion.x < xmin) h.posicion.x=xmin;
}

bool Interaccion::Rebote(Esfera &e, Pared p)
{
	Vector2D dir;
	float dif=p.Distancia(e.posicion, &dir)-e.radio;
	if(dif<=0.0f)
	{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
	}
	return false;
}

void Interaccion::Rebote(Esfera &e, Caja c)
{
	Interaccion::Rebote(e, c.suelo);
	Interaccion::Rebote(e, c.techo);
	Interaccion::Rebote(e, c.pared_dcha);
	Interaccion::Rebote(e, c.pared_izq);
}

bool Interaccion::Rebote(Esfera &esfera1, Esfera &esfera2)
{
	//Vector que une los centros
	Vector2D dif=esfera2.posicion-esfera1.posicion;
	float d=dif.modulo();
	float dentro=d-(esfera1.radio+esfera2.radio);

	if(dentro<0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1=esfera1.velocidad.modulo();
		float ang1=esfera1.velocidad.argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2=esfera2.velocidad.modulo();
		float ang2=esfera2.velocidad.argumento();
	
		//el argumento del vector que une los centros
		float angd=dif.argumento();	
		
		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro/2*cos(angd),dentro/2*sin(angd));	
		esfera1.posicion=esfera1.posicion+desp;
		esfera2.posicion=esfera2.posicion-desp;

		angd=angd-3.14159f/2;//la normal al choque
	
		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1=ang1-angd;	
		float th2=ang2-angd;
		
		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x=v1*cos(th1);
		float u1y=v1*sin(th1);
		float u2x=v2*cos(th2);
		float u2y=v2*sin(th2);	
	
		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x=u1x;
		float v2x=u2x;

		//en el eje Y, rebote elastico
		float m1=esfera1.radio;
		float m2=esfera2.radio;
		float py=m1*u1y+m2*u2y;//Cantidad de movimiento inicial ejey
		float ey=m1*u1y*u1y+m2*u2y*u2y;//Energia cinetica inicial ejey
	
		//los coeficientes y discriminante de la ecuacion cuadrada
		float a=m2*m2+m1*m2;
		float b=-2*py*m2;
		float c=py*py-m1*ey;	
		float disc=b*b-4*a*c;
		if(disc<0)disc=0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y=(-b+sqrt(disc))/(2*a);
		float v1y=(py-m2*v2y)/m1;
		
		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1,modv2,fi1,fi2;
		modv1=sqrt(v1x*v1x+v1y*v1y);
		modv2=sqrt(v2x*v2x+v2y*v2y);
		fi1=angd+atan2(v1y,v1x);
		fi2=angd+atan2(v2y,v2x);
		
		//Velocidades en absolutas despues del choque en componentes
		esfera1.velocidad.x=modv1*cos(fi1);
		esfera1.velocidad.y=modv1*sin(fi1);
		esfera2.velocidad.x=modv2*cos(fi2);
		esfera2.velocidad.y=modv2*sin(fi2);	
	}
	return false;
}

bool Interaccion::Colision(Esfera e, Hombre h)
{
	Vector2D pos=h.getPos();
	pos.y+=h.getAltura()/2.0f;

	float distancia=(e.getPos()-pos).modulo();
	if(distancia<e.radio)
		return true;
	return false;
}

bool Interaccion::Colision(Disparo d, Pared p)
{
		Vector2D pos=d.getPos();
		
		if(pos.y >= p.getLimite1().y)
			return true;
			//d.setPos(pos.x, p.getLimite1().y);

		if(pos.x<0 && pos.x <= p.getLimite1().x)
			return true;
			//d.setPos(p.getLimite1().x, pos.y);

		if(pos.x>0 && pos.x >= p.getLimite1().x)
			return true;
			//d.setPos(p.getLimite1().x, pos.y);
		return false;
}

bool Interaccion::Colision(Disparo d, Caja c)
{
	if(Colision(d, c.pared_dcha) || Colision(d, c.pared_izq) || Colision(d, c.techo))
		return true;
	return false;
}
