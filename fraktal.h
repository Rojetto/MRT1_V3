/* Datei: v3_frakt.h            */
/* P. Rieger; TUD/PLT 20.8.1999 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#ifndef __fraktal
#define __fraktal

#include "graphic.h"

/*--- Datentypvereinbarungen -----------------------------------------------*/

typedef enum { apfelmaennchen, juliamenge } ftype;

struct tParam {
	double r;
	unsigned int imax;
	ftype ftype;
	double xmin, xmax, ymin, ymax;
	unsigned int xpoints, ypoints;
};

struct tComplex {
	double a, b;
};

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

unsigned int GetItera(struct tComplex *c, struct tComplex *z, struct tParam *p);

tColor GetColorValue(unsigned int i, unsigned int imax);

void Fraktal(struct tComplex *c, struct tComplex *z, struct tParam *p);

#endif

/* v3_frakt.h */
