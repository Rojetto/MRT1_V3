/* Datei: v3_dialo.h              */
/* P. Rieger; TUD/PLT 4.10.2001   */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Programm-Modul "Parameterdialog"

*****************************************************************************/

#ifndef __dialog
#define __dialog

#include "fraktal.h"

/*--- Parameter Dialog Prototyp --------------------------------------------*/

unsigned int ParamDialog(struct tParam *p, struct tComplex *c);

/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char InputChar();

void InputInt(int *value);

#endif

/* v3_dialo.h */
