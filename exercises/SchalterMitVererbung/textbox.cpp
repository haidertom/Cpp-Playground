#include <iostream>
#include "WinAdapt.h"
#include "textbox.h"
#include "schalter.h"

using namespace std;

TextBox::TextBox(char * Text,int X, int Y, int W, int H):FarbRect(X, Y, W, H, 255, 255, 255) //Konstruktor, weiﬂt beim erstellen der Klasse Werte zu
{
    szText = new char[strlen(Text)+1];                  //bei arrays muss man immer die L‰nge angeben (strlen), da sonst normaler char gemeint ist
    strcpy(szText, Text);

//    FarbRect::SetX(X);
//    FarbRect::SetY(Y);
//    FarbRect::SetW(W);
//    FarbRect::SetH(H);
}

TextBox :: TextBox ( const TextBox & t): FarbRect ( t. GetX (), t. GetY (),
                                                    t. GetW (), t. GetH (),
                                                    t. GetFarbeR (), t. GetFarbeG (),
                                                    t. GetFarbeB ())
{
//    X=t.X;
//    Y=t.Y;
//    W=t.W;
//    H=t.H;

    szText = new char[strlen(t.szText)+1];
    strcpy(szText, t.szText);
}

TextBox::~TextBox()
{
    delete [] szText;                       //Speicher freigeben
}

void TextBox::Show()
{
        FarbRect::Show();
        Text(FarbRect::GetX()+2 , FarbRect::GetY()+3, szText);
}


//int TextBox::Contains(int X, int Y)
//{
//    if (TextBox::X<=X && X<=(TextBox::X+30)&&TextBox::Y<=Y && Y<=(TextBox::Y+30))
//    {
//        return 1;
//    }
//    else
//    return 0;
//}
