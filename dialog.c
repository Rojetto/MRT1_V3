/* Datei: v3_dialo.c            */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};


/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char InputChar ()
{
	char s[80];
  	fgets(s,sizeof(s), stdin);
  	return s[0];
};

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void InputDouble (double *value)
{
  	char *endptr;
  	char s[80];
  	fgets(s,sizeof(s), stdin);
  	if (s[0]!=10) *value=strtod (s, &endptr);
};


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void InputInt (int *value)
{
  char s[80];
  fgets(s,sizeof(s), stdin);
  if (s[0]!=10) *value=atoi (s);
};


/*--- Parameter Dialog ------------------------------------------------------*/

unsigned int ParamDialog(struct tParam *p, struct tComplex *c) {
	int t;
	double r;
	int imax;
	double xmin, xmax, ymin, ymax;
	int xpoints, ypoints;

	printf("\nFraktal-Typ (0=Apfelmaennchen, 1=Juliamenge): %d\n", p->ftype);
	printf("Radius: %f\n", p->r);
	printf("imax: %d\n", p->imax);
	printf("xmin: %f\n", p->xmin);
	printf("xmax: %f\n", p->xmax);
	printf("Anzahl x-Rasterpunkte: %i\n", p->xpoints);
	printf("ymin: %f\n", p->ymin);
	printf("ymax: %f\n", p->ymax);
	printf("Anzahl y-Rasterpunkte: %i\n", p->ypoints);
	printf("Re(Startwert): %f\n", c->a);
	printf("Im(Startwert): %f\n", c->b);
	printf("\nWerte aendern? 1=Ja, 0=Nein\n");
	int aendern;
	InputInt(&aendern);

	if(!aendern) {
		return TRUE;
	}

	printf("\nFraktal-Typ (0=Apfelmaennchen, 1=Juliamenge): %d\n", p->ftype);
	InputInt(&t);
	printf("\nRadius: %f\n", p->r);
	InputDouble(&r);
	printf("\nimax: %d\n", p->imax);
	InputInt(&imax);
	printf("\nxmin: %f\n", p->xmin);
	InputDouble(&xmin);
	printf("\nxmax: %f\n", p->xmax);
	InputDouble(&xmax);
	printf("\nAnzahl x-Rasterpunkte: %i\n", p->xpoints);
	InputInt(&xpoints);
	printf("\nymin: %f\n", p->ymin);
	InputDouble(&ymin);
	printf("\nymax: %f\n", p->ymax);
	InputDouble(&ymax);
	printf("\nAnzahl y-Rasterpunkte: %i\n", p->ypoints);
	InputInt(&ypoints);
	printf("\nRe(Startwert): %f\n", c->a);
	InputDouble(&(c->a));
	printf("\nIm(Startwert): %f\n", c->b);
	InputDouble(&(c->b));

	if (t != apfelmaennchen && t != juliamenge) {
		printf("Fraktal-Typ muss 0 oder 1 sein!\n");
		return FALSE;
	}

	if (r <= 0) {
		printf("Radius muss > 0 sein!\n");
		return FALSE;
	}

	if (imax <= 0) {
		printf("imax muss > 0 sein!\n");
		return FALSE;
	}

	if (xmin >= xmax  || ymin >= ymax) {
		printf("xmax/ymax muss > xmin/ymin sein!\n");
		return FALSE;
	}

	if (xpoints <= 0  || ypoints <= 0) {
		printf("Anzahl x/y-Rasterpunkte muss > 0 sein!\n");
		return FALSE;
	}

	p->ftype = (ftype) t;
	p->r = r;
	p->imax = imax;
	p->xmin = xmin;
	p->xmax = xmax;
	p->ymin = ymin;
	p->ymax = ymax;
	p->xpoints = xpoints;
	p->ypoints = ypoints;

	return TRUE;
}

/* v3_frakt.c */
