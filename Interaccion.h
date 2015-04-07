#pragma once

#include "Pared.h"

class Interaccion
{
public:
	Interaccion(void);
	virtual ~Interaccion(void);
	static void Rebote(Hombre &h, Caja c);
	static bool Rebote(Esfera &e, Pared p);
	static void Rebote(Esfera &e, Caja c);
	static bool Rebote(Esfera &e, Esfera &f);
	static bool Colision(Esfera e, Hombre h);
	static bool Colision(Disparo d, Pared p);
	static bool Colision(Disparo d, Caja c);
};
