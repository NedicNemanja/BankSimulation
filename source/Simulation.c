/*************************************************
����������			: ������� ������� 30/3/2015
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"
#include "QueueElement.h"
#include "Clerk.h"

int main(void)
{	TOuras      	oura;						/*oura pelatwn*/
	float			pithanotita_afiksis; 		/*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;		/*xronos e3yphrethshs enos pelath*/
	unsigned int 	max_xronos_eksipiretisis; 	/*megistos dunatos xronos eksipiretisis pelath*/

	unsigned int	xronos;			 	 /*roloi prosomoiwshs*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs olws twn pelatwn*/
	unsigned int	xronos_leitourgias;	 /*xronos leitourgias trapezas*/
	unsigned int 	uperories;			 /*epipleon xronos leitourgias trapezas pera apo ton orismeno*/
	unsigned int	ArithmosPelaton;	/*sunolikos arithmos pelaton pou eksipiretise h trapeza*/

	TPelatis	Pelatis;		 	 /* o pelaths sthn oyra*/
	float		mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float		randomAfixi;
	time_t		t;

	printf("Input:\n"
					"Arrival probability for a customer [0,1]\n"
					"Max service time (>=1min)\n"
					"Operating time of the bank (=> 0min)\n");
	scanf("%f %u %u",&pithanotita_afiksis,&max_xronos_eksipiretisis,&xronos_leitourgias);
	getchar();
	//printf("\nH pi8anothta afikshs pelath se ena lepto einai: %4.2f.\n",pithanotita_afiksis);
	//printf("H diarkeia e3yphrethshs enos pelath einai to polu %u lepta.\n",max_xronos_eksipiretisis);
	//printf("H diarkeia leitourgias ths trapezas einai %u\n", xronos_leitourgias);

	OuraDimiourgia(&oura);
	xronos = 0;
	xronos_anamonis = 0;
	uperories = 0;
	ArithmosPelaton = 0;
	int Tameio = 0;	/*count of clerks that are occupied*/
	int i;
	srand(time(&t));

	TTamias	TamiesArray[TAMIES];	/*pinakas tamiwn*/
	ArrayDimiourgia(TamiesArray);	/*arxikopoihse olous tous tamies*/

	while( (xronos < xronos_leitourgias) || !(OuraKeni(oura)) || (Tameio != 0))
	{	//while bank is open or customers in queue or customers being served

		/* Pelatis - Customer*/
		randomAfixi = (float)rand()/(float)RAND_MAX;	//rand chance customer arrives

		if( xronos < xronos_leitourgias){											/*h trapeza anoixth*/
			if ( randomAfixi < pithanotita_afiksis ){
				PelatisSetXronoEisodou(&Pelatis, xronos);							/*enhmerwse Pelatis struct peri xronos_eisodou*/
				xronos_eksipiretisis = (rand() % max_xronos_eksipiretisis) + 1;		/*set 0 < random xronos_eksipiretisis < max_xronos_eksipiretisis*/
				PelatisSetXronoEksipiretisis(&Pelatis, xronos_eksipiretisis);		/*enhmerwse Pelatis struct peri xronos_eksipiretisis*/
				if (!OuraProsthesi(&oura, Pelatis)){								/*pros9ese sthn oura, an oxi: mhnuma la9ous kai telos*/
	                  		printf("The Queue is too small! Simulation is stopping.\n");
	                  		getchar();
	                  		return 0;
	        	}
	    	}
		}

    /* Tamias - Clerk*/
    for( i=0; i<TAMIES; i++)
		{	if(TamiesArray[i].paron)						/*tamias den sxolase akoma akoma*/
			{	if ( TamiesArray[i].enapomenonXronos == 0)		/*eley8eros tamias*/
				{	if (!OuraKeni(oura))							/*yparxei pelaths*/
					{	OuraApomakrynsh(&oura,&Pelatis);									/*phgainei sto tamio*/
						xronos_anamonis += xronos - PelatisGetXronoEisodou(&Pelatis);		/*ypologismos xronoy paramonhs sthn oura*/
						TamiasNewCustomer(&TamiesArray[i]);									/*au3ise ton ArithmoPelaton tou struct Tamias*/
						TamiasSetXrono(&TamiesArray[i], Pelatis.XronosEksipiretisis);		/*enhmerwse to struct Tamias gia enapomenonXronos*/
						TamiasBusy(&TamiesArray[i]);										/*pros9ese to trexon lepto apasxolhshs sto TimeBusy*/
						if( Pelatis.XronosEksipiretisis > 1)								/*den exei nohma na metrisoume to tameio ws kateillhmeno an o tamias tha teleiwsei sto idio lepto*/
							Tameio++;
					}
					else											/*den uparxei pelaths*/
						if( xronos < xronos_leitourgias)
							TamiesArray[i].TimeInactive++;
						else
							EleutheroseTamia(&TamiesArray[i]);				/*o tamias sxolase*/
				}
				else
				{	TamiesArray[i].enapomenonXronos--;			/*o tamias apasxolhmenos me pelath */
					TamiasBusy(&TamiesArray[i]);
					if ( TamiesArray[i].enapomenonXronos == 0)	/* an o tamias teleiwse me ton pelati*/
						Tameio--;
				}

				if( (xronos >= xronos_leitourgias)	&& TamiasParon(&TamiesArray[i]) )	/*an douleuei uperoria*/
							TamiesArray[i].uperoria++;
			}

		}

		xronos++; 								/*o xronos prosomoivshs ay3anetai kata 1 lepto*/
	}

	//count clerk overtime
	for( i=0; i<TAMIES; i++){
		if(TamiesArray[i].uperoria > uperories)
			uperories = TamiesArray[i].uperoria;			/*orise ws epipleon xrono leitourgias ths trapezas ton megisto epipleon xronos leitourgias tamia*/
		ArithmosPelaton += TamiesArray[i].ArithmoPelaton;	/*sunolikos arithmos pelaton*/
	}

	if (ArithmosPelaton == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)ArithmosPelaton);

	unsigned int telikos_xronos_leitourgias = xronos_leitourgias + uperories;

	printf("\nServed %u customers.\n",ArithmosPelaton);
	printf("%d customers were not served.\n",SizeOuras(oura));			/*meta to 4o erwthma panta 0*/
	printf("Average wait time was %4.2f min.\n",mesos_xronos);
	printf("Bank worked for %u min.\n", telikos_xronos_leitourgias);
	printf("The bank worked %u min overtime\n", uperories);

	for(i=0; i<TAMIES; i++){
		printf("\n Clerk%d:\n", i+1);
		printf("\t Served %d customers\n",  TamiesArray[i].ArithmoPelaton);
		printf("\t Was occupied for %d min\n", TamiesArray[i].TimeBusy);
		printf("\t Was inactive for %d min\n", TamiesArray[i].TimeInactive);
		printf("\t Worked %d min overtime\n", TamiesArray[i].uperoria);
	}
	return 0;
}
