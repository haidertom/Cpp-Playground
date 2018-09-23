#ifndef PROTECT_GATTER
#define PROTECT_GATTER

#include "textbox.h"
#include "WinAdapt.h"
#include "Verbindung.h"

//------------------------ Defines ------------------------
#define GATTER_WIDTH							60
#define GATTER_HEIGHT							40
#define GATTER_R								200
#define GATTER_G								200
#define GATTER_B								200
//---------------------------------------------------------

class Gatter: public textbox
{
protected:
	//------------------------- Attribute -------------------------
	Verbindung* pvEin1;
	Verbindung* pvEin2;
	Gatter* pgEin1;
	Gatter* pgEin2;
	//-------------------------------------------------------------

public:
	//------------------------- Methoden -------------------------
	void Show( void );
	//------------------------------------------------------------

	//------------------------- Konstruktoren/Destruktoren -------------------------
	Gatter( const char* szText, int nX, int nY, Gatter* pgEin1, Gatter* pgEin2 );
	Gatter( const Gatter& g );
	~Gatter( void );
	//------------------------------------------------------------------------------
};

#endif
