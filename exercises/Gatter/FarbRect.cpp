#include <iostream>
#include "WinAdapt.h"

#include "textbox.h"
#include "FarbRect.h"

using namespace std;

FarbRect::FarbRect(int X, int Y, int W, int H, int R, int G, int B)
{
    FarbRect::X=X;
    FarbRect::Y=Y;
    FarbRect::W=W;
    FarbRect::H=H;
    FarbeR = R;
    FarbeG = G;
    FarbeB = B;
}

FarbRect::FarbRect(const FarbRect&t)        //tiefe Kopie
{
    X=t.X;
    Y=t.Y;
    W=t.W;
    H=t.H;
    FarbeR=t.FarbeR;
    FarbeG=t.FarbeG;
    FarbeB=t.FarbeB;
}

void FarbRect::Show()
{
    FillCol(FarbeR, FarbeG, FarbeB);
    Rect(X, Y, X + W, Y + H);
}

int FarbRect::Contains(int X,int Y)
{
    if (FarbRect::X<=X && X<=(FarbRect::X+W)&&FarbRect::Y<=Y && Y<=(FarbRect::Y+H))
    {
        return 1;
    }
    else
    return 0;
}
