#ifndef TEXTBOX_H
#define TEXTBOX_H

class TextBox
{
private:
    //------Attribute------
    int X, Y;
    int W, H;
    char *szText;

public:
    //------Methoden------

    //------GET-Methoden------
    inline int GetX() const
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

    const char * GetText() const
    {
        return szText;
    }

    //------SET-Methoden------

    void SetX(int X)
    {
        TextBox::X=X;
    }
    void SetY(int Y)
    {
        TextBox::Y=Y;
    }
    void SetW(int W)
    {
        TextBox::W=W;
    }

    void SetH(int H)
    {
        TextBox::H=H;
    }
    void SetText(char *Text)
    {
        if(szText != NULL)
        {
        delete (szText);
        }

        TextBox::szText = new char(strlen(Text)+1);
        strcpy(TextBox::szText, Text);
    }

    //------Konstruktur/Destruktor------

    TextBox(char*Text, int X, int Y, int W, int H);
    TextBox(const TextBox&t);
    ~TextBox();

    void Show();

    int Contains(int nX, int nY);
};

#endif // TEXTBOX_H
