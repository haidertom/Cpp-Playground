#include "WinAdapt.h"
#include "cstdio"
#include "textbox.h"
#include "FarbRect.h"
#include "Verbindung.h"
#include "Gatter.h"


//------------------------ Defines ------------------------

//---------------------------------------------------------

//------------------------ Defines ------------------------

//---------------------------------------------------------

//--------------------------------- Globale Variablen ---------------------------------
//Verbindung Verb1( 100, 100, 200, 200 );

Gatter Gat1( "Gatter1", 70, 110, NULL, NULL );
Gatter Gat2( "Gatter2", 70, 190, NULL, NULL );

Gatter Gat3( "Gatter3", 150, 150, &Gat1, &Gat2 );
Gatter Gat4( "Gatter4", 70, 250, NULL, NULL );
Gatter Gat4_5( "Gatter5", 150, 230, &Gat4, NULL );

Gatter Gat5( "Gatter6", 230, 190, &Gat3, &Gat4_5 );
//-------------------------------------------------------------------------------------


void VtlZyk(void)
{
}

void VtlMouse(int X, int Y)
{

}

void VtlKeyHit(int key)
{
}

void VtlInit(void)
{

}

void VtlPaint(int xl, int yo, int xr, int yu)
{
	Gat5.Show();
}
