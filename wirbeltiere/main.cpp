#include <iostream>
#include <cstring>

using namespace std;

/*     -----     W i r b e l t i e r     -----     */
class Wirbeltier
{
private:
    int Alter;
    int Gewicht;
protected:
    
    int PaarHufer;
public:
    
    Wirbeltier(int Alter, int Gewicht)
    {
        Wirbeltier::Gewicht = Gewicht;
        Wirbeltier::Alter   = Alter;
    };
    
    int GetAlter()const
    {
        return Alter;
    };
    int GetGewicht() const
    {
        return Gewicht;
    };
    
    virtual void LautGeben() =0;

};



/*     -----     H u n d     -----     */
class Hund : public Wirbeltier
{
private:
    int SteuerMarke;
    int Wuermer;
protected:
    float UeberZuechtFaktor;
public:
    
    Hund(int Alter, int Gewicht,
         float UeberZuechtFaktor, int Wuermer)
    : Wirbeltier(Alter, Gewicht),
    Wuermer(Wuermer),
    UeberZuechtFaktor(UeberZuechtFaktor)
    {
        SteuerMarke = 1;
        PaarHufer = 0;
    };
    
    int GetSteuerMarke()const
    {
        return SteuerMarke;
    };
    int GetWuermer()const
    {
        return Wuermer;
    };
    
    void LautGeben()
    {
        if(GetGewicht()>10) cout<<"Wau!\n";
        else cout<<"Keif!\n";
        cout.flush();
    };
};

/*     -----     S t r e i c h e l t i e r     -----     */
class Streicheltier : public Hund
{
public:
    Streicheltier(int Alter, int Gewicht,
                  float UeberZuechtFaktor)
    : Hund(Alter, Gewicht,
           UeberZuechtFaktor, 100)
    { };
};

/*     -----     Z o o     -----     */
#define MAX_ANZ 128

class Zoo
{
private:
    int AnzahlBewohner;
    char name[20];
    Wirbeltier *Bewohner[MAX_ANZ];
public:
    Zoo(const char *n)
    {
        strcpy(name, n);
        AnzahlBewohner=0;
    };
    
    void AddWirbeltier(Wirbeltier *pWi)
    {
        if(AnzahlBewohner<MAX_ANZ)
            Bewohner[AnzahlBewohner++] = pWi;
    };
    
    void LautGeben()
    {
        cout<<"Die Tiere im Zoo "<<name<<" machen:"<<endl;
        for(int i=0; i<AnzahlBewohner; i++)
            Bewohner[i]->LautGeben();
    };
};


/*     -----     V o g e l     -----     */
class Vogel : public Wirbeltier
{
public:
    Vogel(int Alter, int Gewicht)
    : Wirbeltier(Alter, Gewicht)
    { };
    void LautGeben()
    {
        cout<<"Piep!\n";
        cout.flush();
    };
};

/*     -----     E l e f a n t     -----    */
class Elefant : public Wirbeltier
{
public:
    Elefant(int Alter, int Gewicht)
    : Wirbeltier(Alter, Gewicht)
    { };
    
    void LautGeben()
    {
        cout<<"Tˆrˆˆh!\n";
        cout.flush();
    };
};

// Test von Zoo!

/*     -----     m a i n     -----     */
int main()
{
    
    
//    Zoo *pZoo = new Zoo();
//
//    pZoo->AddWirbeltier(
//                        new Hund(5, 10, 1.7, 30));
//    pZoo->AddWirbeltier(
//                        new Streicheltier(5, 20, 1.5));
//    pZoo->AddWirbeltier(
//                        new Vogel(3, 2));
//    pZoo->AddWirbeltier(
//                        new Elefant(5, 5));
//    
//    cout<<"\nund jetzt der ganze Zoo:\n";
//    pZoo->LautGeben();
//    
//    Hund carsten(20, 20, 10.3, 10);
//    cout<<endl<<carsten.GetAlter()<<endl<<carsten.GetWuermer();
//
    char zooname[20];
    
    cout<<"Zooname eingeben: "<<endl;
    cin>>zooname;
    
    Zoo neuerZoo(zooname);
    
    neuerZoo.AddWirbeltier(new Hund(1, 2, 3, 4));
    neuerZoo.AddWirbeltier(new Elefant(1, 20));
    neuerZoo.AddWirbeltier(new Streicheltier(1,20,3));
    neuerZoo.LautGeben();
    
    
    
    return 0;
}
