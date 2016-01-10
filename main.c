/* Datei v3_main.c              */
/* P. Rieger; TUD/PLT 4.10.2001 */

/*****************************************************************************

  Praktikumsversuch: Einführung in die Sprache C
  Main-Programm

*****************************************************************************/

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>

int main (void)
{
	/*--- Variablendeklaration ---------------------------------------------*/
	struct tParam p;
	struct tComplex c1;
	struct tComplex z1;

  	/*--- Initialwerte -----------------------------------------------------*/
	p.ftype = apfelmaennchen;
	p.r = 2;
	p.imax = 75;
	p.xmin = -2;
	p.xmax = 2;
	p.xpoints = 640;
	p.ymin = -1.5;
	p.ymax = 1.5;
	p.ypoints = 480;

	c1.a = 0.4;
	c1.b = 0.4;

	z1.a = 0;
	z1.b = 0;
	
	while(1) {
		printf("Beenden? 1=Ja, 0=Nein\n");
		int antwort;
		InputInt(&antwort);
		if (antwort) {
			break;
		}

		/*----------------------------------------------------------------------*/
		/*--- Parameter über Dialog abfragen                                  --*/
		/*----------------------------------------------------------------------*/
		unsigned int parameterKorrekt;
		struct tComplex c;
		if (p.ftype == apfelmaennchen) {
			c = z1;
		} else if (p.ftype == juliamenge) {
			c = c1;
		}
		parameterKorrekt = ParamDialog(&p, &c);

		if (p.ftype == apfelmaennchen) {
			z1 = c;
		} else if (p.ftype == juliamenge) {
			c1 = c;
		}

		if (parameterKorrekt) {
			InitGraph (p.xmin, p.xmax, p.ymin, p.ymax); 	// Initialisierung der Grafik

			LockScreen(); // Bildschirm muss zum Setzen von Pixeln gesperrt sein
			/*----------------------------------------------------------------------*/
			/*--- Fraktale berechnen und ausgeben                                 --*/
			/*----------------------------------------------------------------------*/
			Fraktal(&c1, &z1, &p);
			UnlockScreen(); // Alle Änderungen auf Bildschirm ausgeben

			printf("Enter um Grafik zu schliessen.\n");
			/*Aufrufen von InputChar() um das Programm nach dem öffnen der Graphik   */
			/*anzuhalten. Erst wenn in der Konsole eine Taste gedrückt wird, schließt*/
			/*sich das Fenster wieder. */
			InputChar();
			CloseGraph();
		}

	}

	return 0;
}
