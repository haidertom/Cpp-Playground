#ifndef FARBRECT_H
#define FARBRECT_H

class FarbRect
{
private:
    int X, Y, W, H, FarbeR, FarbeG, FarbeB;

public:

//------Konstruktor------
FarbRect(int X, int Y, int W, int H, int R, int G, int B);
FarbRect(FarbRect&t);

void Show();

int Contains(int X,int Y);

//------GET------
int GetX() const
{
    return X;
}
int GetY() const
{
    return Y;
}
int GetW() const
{
    return W;
}
int GetH() const
{
    return H;
}
int GetFarbeR() const
{
    return FarbeR;
}
int GetFarbeG() const
{
    return FarbeG;
}
int GetFarbeB() const
{
    return FarbeB;
}


//------SET------
void SetX(int X)
{
    FarbRect::X=X;
}
void SetY(int Y)
{
    FarbRect::Y=Y;
}
void SetW(int W)
{
    FarbRect::W=W;
}
void SetH(int H)
{
    FarbRect::H=H;
}
void SetFarbe(int R, int G,int B)
{
    FarbeR = R;
    FarbeG = G;
    FarbeB = B;
}

};
#endif // FARBRECT_H
