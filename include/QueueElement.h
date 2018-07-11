/*************************************************************************
������					: Diepafi typou stoixeiou Pelatis ths oyras
����������				: ������� ������� 30/3/2015
**************************************************************************/

#ifndef __TStoixeioOuras__
#define __TStoixeioOuras__

typedef struct {
	int XronosEisodou;
	int XronosEksipiretisis;
} TPelatis;

void PelatisSetXronoEisodou(TPelatis *stoixeioPtr, int xronos);
int PelatisGetXronoEisodou(TPelatis *stoixeioPtr);

void Pelatis_setValue(TPelatis *stoixeioPtr, TPelatis testdata);

void Pelatis_printValue(TPelatis testdata);
int  Pelatis_readValue(TPelatis *testdata);

void PelatisSetXronoEksipiretisis(TPelatis *stoixeioPtr, int duration);
int PelatisGetXronoEksipiretisis(TPelatis *stoixeioPtr);

#endif
