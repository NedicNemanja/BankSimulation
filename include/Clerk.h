/*************************************************************************
����������				: Nemanja Nedic 30/3/2015
������					: Diepafi typou stoixeiou Tamias
����������				: ������� �������-30/3/2015
**************************************************************************/

#ifndef __tamias__
#define __tamias__

#define TAMIES 2

/* �������� �����*/
typedef struct {
	int TimeBusy;		/*sunolikos xronos apasxolhshs tamia*/
	int TimeInactive;	/*sunolikos xronos adraneias tamia*/
	int ArithmoPelaton;	/*arithmos pelaton pou eksipiretise o tamias*/
	int enapomenonXronos;	/*xronos mexri na teleiwsei thn trexousa ergasia*/
	int uperoria;		/*o xronos pou leitourgise o tamias pera apo ton kathorismeno xrono leitourgias ths trapezas*/
	int paron;			/*0 an o tamias apwn(sxolase)*/
} TTamias;

/*�������� �����������*/
void TamiasDimiourgia(TTamias *tamias);				/*arxikopoiei ta melh tou struct TTamias)*/

void TamiasSetXrono(TTamias *tamias, int Duration);	/*arxikopoiei ton enapomenonXronos me ton xronos_ekspiretisis*/

int TamiasFree(TTamias tamias);						/*elegxei an o tamias diatheshmos*/

void TamiasNewCustomer(TTamias *tamias);			/*au3anei t�n ArithmosPelaton*/
void TamiasNoWork(TTamias *tamias);					/*au3anei ton TimeInactive*/
void TamiasBusy(TTamias *tamias);					/*au3anei ton TimeBusy*/

int TamiasGetArithmosPelatwn(TTamias *tamias);		/*epistrefei ton ArithmoPelaton*/
int TamiasGetEnapomenonXronos(TTamias *tamias);		/*epistrefei ton enapomenonXronos*/
int TamiasGetInactiveXronos(TTamias *tamias);		/*epistrefei ton TimeInactive*/
int TamiasGetBusyXronos(TTamias *tamias);			/*epistrefei ton TimeBusy*/

void ArrayDimiourgia(TTamias *stoixeio);			/*arxikopoiei olous tous tamies tou pinaka*/

void EleutheroseTamia(TTamias *tamias);				/*o tamias den einai pia paron*/
int TamiasParon(TTamias *tamias);					/*elegxei an o tamias paron (return 1), an oxi return 0*/


#endif
