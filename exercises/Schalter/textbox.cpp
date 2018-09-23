#include <iostream>
#include "WinAdapt.h"
#include "textbox.h"


TextBox::TextBox(char*Text, int X, int Y, int W, int H) //Konstruktor, weiﬂt beim erstellen der Klasse Werte zu
{
    szText = new char(strlen(Text)+1);                  //bei arrays muss man immer die L‰nge angeben (strlen), da sonst normaler char gemeint ist
    strcpy(szText, Text);

    TextBox::X=X;                                       //Namespace da sonst unklar welches x/y/...
    TextBox::Y=Y;
    TextBox::W=W;
    TextBox::H=H;
}

TextBox::TextBox(const TextBox&t)           //Copy Konstruktor erzeugt Tiefe Kopie
{
    X=t.X;
    Y=t.Y;
    W=t.W;
    H=t.H;

    szText = new char[strlen(t.szText)+1];
    strcpy(szText, t.szText);
}

TextBox::~TextBox()
{
    delete [] szText;                       //Speicher freigeben
}

void TextBox::Show()
{
    Rect(X, Y, X + W, Y + H);
    Text(X + 10, Y + 10, szText);
}

int TextBox::Contains(int X, int Y)
{
    if (TextBox::X<=X && X<=(TextBox::X+30)&&TextBox::Y<=Y && Y<=(TextBox::Y+30))
    {
        return 1;
    }

    return 0;
}
