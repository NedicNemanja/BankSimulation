/*************************************************************************
��o���				: ��o�o���� �� ������ ��������o� ���o� ���o�����, ����
����������			: ������� ������� 30/3/2015
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*o������ �����������*/

void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
}

int OuraKeni(TOuras oura)
{
	return ( oura.metritis == 0);
}

int OuraGemati(TOuras oura) /* OXI sthn diepafi-edv bohthitikh */
{
	return( oura.metritis == PLITHOS);
}

int OuraProsthesi(TOuras *oura, TPelatis stoixeio)
{
	if (OuraGemati(*oura))
		return 0;
	else
	{
		Pelatis_setValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction of = for any type */
		oura->piso = ( oura->piso + 1 )% PLITHOS;
		oura->metritis++;
		return 1;
	}
}

int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio)
{
	if (OuraKeni(*oura))
		return 0;
	else
	{
		Pelatis_setValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction of = for any type */
		oura->embros = ( oura->embros + 1 )% PLITHOS;
		oura->metritis--;
		return 1;
	}
}

int SizeOuras(TOuras oura)
{
	return oura.metritis;
}
