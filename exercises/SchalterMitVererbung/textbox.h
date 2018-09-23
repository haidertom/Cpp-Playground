#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "FarbRect.h"
#include "WinAdapt.h"

class TextBox : public FarbRect
{
private:
    //------Attribute------
    char *szText;

public:
    //------Methoden------
    void Show();
    //------GET-Methoden------
    const char * GetText() const
    {
        return szText;
    }

    //------SET-Methoden------

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
};
#endif // TEXTBOX_H
