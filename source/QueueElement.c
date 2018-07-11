/*************************************************************************
��o���				: Ylopoihsh typou stoixeiou Pelati ths oyras
����������			: ������� ������� 30/3/2015
**************************************************************************/
#include <stdio.h>
#include "QueueElement.h"

void PelatisSetXronoEisodou(TPelatis *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TPelatis *stoixeioPtr)
{
	return stoixeioPtr->XronosEisodou;
}
void Pelatis_setValue(TPelatis *stoixeioPtr, TPelatis testdata)
{
	stoixeioPtr->XronosEisodou = testdata.XronosEisodou;
	stoixeioPtr->XronosEksipiretisis = testdata.XronosEksipiretisis;
}
void Pelatis_printValue(TPelatis testdata)
{ printf("|Xronos Eisodou = %d|", testdata.XronosEisodou);
}

int Pelatis_readValue(TPelatis *testdata)
{
	if (scanf("%d", &(testdata->XronosEisodou))!= 1)
		return 0;
	else return 1;
}

void PelatisSetXronoEksipiretisis(TPelatis *stoixeioPtr, int duration)
{
	stoixeioPtr->XronosEksipiretisis = duration;
}

int PelatisGetXronoEksipiretisis(TPelatis *stoixeioPtr)
{
	return stoixeioPtr->XronosEksipiretisis;
}
