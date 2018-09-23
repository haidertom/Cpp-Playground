#include "textbox.h"
#include "FarbRect.h"


//---------------------- Konstruktoren/Destruktoren ----------------------
textbox::textbox( const char* Text, int X, int Y, int W, int H ) : FarbRect( X, Y, W, H, 255, 255, 255 )
{
	textbox::szText = new char[ strlen( Text ) + 1 ] ;
	strcpy( textbox::szText, Text );
}

textbox::textbox( const textbox & t ) : FarbRect( t )
{
	textbox::szText = new char[ strlen( t.szText ) + 1 ];
	strcpy( textbox::szText, t.szText );
}

textbox::~textbox()
{
	delete []szText;
}
//------------------------------------------------------------------------


//---------------------- Bearbeitungsmethoden ----------------------
const char* textbox:: GetText( ) const
{
	return( szText );
}


void textbox::SetText( const char* Text )
{
		delete []szText;

	szText = new char[ strlen( Text ) + 1 ] ;
	strcpy( szText, Text );
}


void textbox::Show(  )
{
	FillCol( GetFarbeR(), GetFarbeG(), GetFarbeB() );
	Rect( GetX(), GetY(), GetX() + GetW(), GetY() + GetH() );
	Text( GetX() + 5, GetY() + 7, szText );
}
//---------------------------------------------
