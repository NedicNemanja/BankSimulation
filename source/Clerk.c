#include "Clerk.h"

void TamiasDimiourgia(TTamias *tamias)
{
	tamias->TimeBusy = 0;
	tamias->TimeInactive = 0;
	tamias->ArithmoPelaton = 0;
	tamias->enapomenonXronos = 0;
	tamias->uperoria = 0;
	tamias->paron = 1;
}

void TamiasNewCustomer(TTamias *tamias)
{
	tamias->ArithmoPelaton++;
}

void TamiasSetXrono(TTamias *tamias, int Duration)
{
	tamias->enapomenonXronos = Duration - 1; /*to -1 kaluptei to trexon lepto*/
}

void TamiasNoWork(TTamias *tamias)
{
	tamias->TimeInactive++;
}

void TamiasBusy(TTamias *tamias)
{
	tamias->TimeBusy++;
}

int TamiasFree(TTamias tamias)
{
	return (tamias.enapomenonXronos == 0);
}

int TamiasGetArithmosPelatwn(TTamias *tamias)
{
	return tamias->ArithmoPelaton;
}

int TamiasGetEnapomenonXronos(TTamias *tamias)
{
	return tamias->enapomenonXronos;
}

int TamiasGetInactiveXronos(TTamias *tamias)
{
	return tamias->TimeInactive;
}

int TamiasGetBusyXronos(TTamias *tamias)
{
	return tamias->TimeBusy;
}

void ArrayDimiourgia(TTamias *stoixeio)
{
	int i;
	for( i=0; i<TAMIES; i++){
		TamiasDimiourgia(stoixeio+i);
	}
}

void EleutheroseTamia(TTamias *tamias)
{
	tamias->paron = 0;
}

int TamiasParon(TTamias *tamias)
{
	return tamias->paron;
}
