#include "Verbindung.h"

//---------------------------- Konstruktoren/Destruktoren ----------------------------
Verbindung::Verbindung( int nXa, int nYa, int nXe, int nYe )
{
	Verbindung::nXa = nXa;
	Verbindung::nYa = nYa;
	Verbindung::nXe = nXe;
	Verbindung::nYe = nYe;
}


//------------------------------------------------------------------------------------


//---------------------------- Methoden ----------------------------
void Verbindung::Show( void ) const
{
	//Erste Waagrechte
	int Lower_X = nXa;
	int Lower_Y = nYa;
	int Upper_X = Lower_X + (nXe - nXa) /2;
	int Upper_Y = nYa;
	Line( Lower_X, Lower_Y, Upper_X, Upper_Y );

	//Senkrechte
	Lower_X = Upper_X;
	Lower_Y = nYa;
	Upper_X = Lower_X;
	Upper_Y = nYe;
	Line( Lower_X, Lower_Y, Upper_X, Upper_Y );

	//Zweite Waagrechte
	Lower_X = Upper_X;
	Lower_Y = Upper_Y;
	Upper_X = Lower_X + (nXe - nXa) /2;
	Upper_Y = Lower_Y;
	Line( Lower_X, Lower_Y, Upper_X, Upper_Y );
}
//--------------------------------------------------
