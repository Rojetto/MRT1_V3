/* Datei: v3_frakt.c              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Fraktal-Analyse"

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"


/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/

unsigned int GetItera(struct tComplex *c, struct tComplex *z, struct tParam *p) {
	struct tComplex zi = *z;

	unsigned int i = 0;
	while (i < p->imax) {
		struct tComplex newzi;
		newzi.a = c->a + zi.a * zi.a - zi.b * zi.b;
		newzi.b = c->b + 2 * zi.a * zi.b;

		zi = newzi;
		i++;

		if (zi.a * zi.a + zi.b * zi.b > (p->r) * (p->r))
			break;
	}

	return i;
}

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/

tColor GetColorValue(unsigned int i, unsigned int imax) {
	unsigned int colorNumber = i % 16;
	tColor c;

	switch (colorNumber) {
	case 0: c = black; break;
	case 1: c = blue; break;
	case 2: c = green; break;
	case 3: c = cyan; break;
	case 4: c = red; break;
	case 5: c = magenta; break;
	case 6: c = brown; break;
	case 7: c = white; break;
	case 8: c = gray; break;
	case 9: c = lightblue; break;
	case 10: c = lightgreen; break;
	case 11: c = lightcyan; break;
	case 12: c = lightred; break;
	case 13: c = lightmagenta; break;
	case 14: c = lightyellow; break;
	case 15: c = brightwhite; break;
	default: c = black; break;
	}

	if (i == imax) {
		c = black;
	}

	return c;
}

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/

void Fraktal(struct tComplex *c, struct tComplex *z, struct tParam *p) {
	double x, y;
	for (x = p->xmin; x <= p->xmax; x += (p->xmax - p->xmin) / p->xpoints) {
		for (y = p->ymin; y <= p->ymax; y += (p->ymax - p->ymin) / p->ypoints) {
			struct tComplex point;
			point.a = x;
			point.b = y;

			unsigned int i;
			if (p->ftype == apfelmaennchen) {
				i = GetItera(&point, z, p);
			} else if (p->ftype == juliamenge) {
				i = GetItera(c, &point, p);
			}

			SetPoint(x, y, GetColorValue(i, p->imax));
		}
	}
}

/* v3_frakt.c */
