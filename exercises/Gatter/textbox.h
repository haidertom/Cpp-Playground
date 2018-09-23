#ifndef PROTECT_TEXTBOX
#define PROTECT_TEXTBOX

#include "FarbRect.h"
#include "iostream"
#include "WinAdapt.h"

//------------------------ Defines ------------------------
#define TEXTBOX_WIDTH				60
#define TEXTBOX_HEIGHT				30
//---------------------------------------------------------

class textbox : public FarbRect
{	//------------------------ Attribute ------------------------
	private:
		char* szText;	//Inhalt
	//-----------------------------------------------------------

	public:
	//------------------------ Konstruktor/Destruktor ------------------------
		textbox( const char* Text, int X, int Y, int W, int H );
		textbox( const textbox & t );
		~textbox( void );
	//------------------------------------------------------------------------

	//------------------------ Bearbeitungsmethoden ------------------------
		const char* GetText( void ) const;
		void SetText( const char* Text );
		void Show( void );
	//----------------------------------------------------------------------
};
#endif
