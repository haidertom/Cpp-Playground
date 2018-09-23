#include "Gatter.h"


//---------------------------- Konstruktoren/Destruktoren ----------------------------
Gatter::Gatter( const char* szText, int nX, int nY, Gatter* pgEin1, Gatter* pgEin2 ) : textbox( szText, nX, nY, GATTER_WIDTH, GATTER_HEIGHT ),pgEin1(pgEin1), pgEin2(pgEin2)
{
	SetFarbe( GATTER_R, GATTER_G, GATTER_B );

	if( pgEin1 )
		pvEin1 = new Verbindung( pgEin1->GetX()+GATTER_WIDTH, pgEin1->GetY()+GATTER_HEIGHT/2, nX, nY+10 );

	if( pgEin2 )
		pvEin2 = new Verbindung( pgEin2->GetX()+GATTER_WIDTH, pgEin2->GetY()+GATTER_HEIGHT/2, nX, nY+GATTER_HEIGHT-10 );
}


Gatter::Gatter( const Gatter& g ) :textbox( g )
{
	pgEin1 = new Gatter( *g.pgEin1 );
	pgEin2 = new Gatter( *g.pgEin2 );
	pvEin1 = new Verbindung( *g.pvEin1 );
	pvEin2 = new Verbindung( *g.pvEin2 );
}


Gatter::~Gatter( void )
{
		delete( pvEin1 );
		delete( pvEin2 );
}
//------------------------------------------------------------------------------------

//---------------------------- Methoden ----------------------------
void Gatter::Show( void )
{
	textbox::Show();
	if( pgEin1 )
		pgEin1->Show();

	if( pgEin2 )
		pgEin2->Show();

	if( pvEin1 )
		pvEin1->Show();

	if( pvEin2 )
		pvEin2->Show();
}
//------------------------------------------------------------------
