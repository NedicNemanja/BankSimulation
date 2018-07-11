/**********************************************+**************************
������ ������������	: QArray.h
������					: ��������� �� ������ ���������� ����� ��������� ����
����������				:  ������� ������� 30/3/2015
**************************************************************************/
#ifndef __CH2_QARRAY__
#define __CH2_QARRAY__
#include "QueueElement.h"

/*�������� �����*/

#define PLITHOS 1000

typedef struct {
	int embros;		/*���� ��� ������ ��������� ��� �����*/
	int piso;		/*���� ��� ���������� ��������� ��� �����*/
	int metritis;	/*�������� ���� ����*/
	TPelatis pinakas[PLITHOS];	/*� ������� ���������*/
} TOuras;	   /*� ����� ��� �����*/

/*�������� �����������*/

/*����������*/
void OuraDimiourgia(TOuras *oura);

/*������� �������*/
int	OuraKeni	(TOuras oura);
int SizeOuras(TOuras oura);

/*������� ���������/������������*/
int OuraProsthesi	(TOuras *oura, TPelatis stoixeio);
int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio);

#endif /*#ifndef __CH2_QARRAY__ */
