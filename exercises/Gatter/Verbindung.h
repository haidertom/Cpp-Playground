#ifndef PROTECT_VERBINDUNG
#define PROTECT_VERBINDUNG

#include "textbox.h"
#include "WinAdapt.h"

class Verbindung
{
private:
	//---------------------- Attribute ----------------------
	int nXa;
	int nYa;
	int nXe;
	int nYe;
	//-------------------------------------------------------

public:
	//---------------------- Methoden ----------------------
	int GetXa() const { return( nXa ); }
	int GetYa() const { return( nYa ); }
	int GetXe() const { return( nXe ); }
	int GetYe() const { return( nYe ); }
	void Show() const;
	//------------------------------------------------------

	//---------------------- Konstruktor/Destruktor ----------------------
	Verbindung( int nXa, int nYa, int nXe, int nYe );
	//--------------------------------------------------------------------
};

#endif
