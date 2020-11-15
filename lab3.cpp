// jak zniszczyc ostatni obiekt klasy WektorFigur w metodzie pop? zadanie 19
// jak napisac FabrykaFigur? zadanie 20
#include <iostream>

class BytGeometryczny
{
public:
    virtual void id() = 0;
};

class Figura : public BytGeometryczny
{
public:
    Figura()
    {
        pole = 0;
        std::cout << "Figura domyslna"
                  << "\n";
    }
    Figura(double p)
    {
        pole = p;
        std::cout << "Figura parametryczna"
                  << "\n";
    }
    virtual ~Figura()
    {
        std::cout << "Figura zniszczona"
                  << "\n";
    }

    double       get() { return pole; };
    virtual void id() { std::cout << "Typ: figura. Pole: " << this->get() << "\n"; }

private:
    double pole;
};

class Kolo : public Figura
{
public:
    Kolo() : Figura()
    {
        std::cout << "Kolo domyslne"
                  << "\n";
    }
    Kolo(double r) : Figura(2 * 3.14 * r)
    {
        std::cout << "Kolo parametryczne"
                  << "\n";
    }
    virtual ~Kolo()
    {
        std::cout << "Kolo zniszczone"
                  << "\n";
    }

    void id() override { std::cout << "Typ: kolo. Pole: " << this->get() << "\n"; }
};

class Kwadrat : public Figura
{
public:
    Kwadrat() : Figura()
    {
        std::cout << "Kwadrat domyslny"
                  << "\n";
    }
    Kwadrat(double a) : Figura(a * a)
    {
        std::cout << "Kwadrat parametryczny"
                  << "\n";
    }
    virtual ~Kwadrat()
    {
        std::cout << "Kwadrat zniszczony"
                  << "\n";
    }

    void id() override { std::cout << "Typ: kwadrat. Pole: " << this->get() << "\n"; }
};

class WektorFigur
{
public:
    WektorFigur() : licznik(0) { PtrF = new Figura[10]; };
    ~WektorFigur() { delete[] PtrF; }

    void push(Figura f)
    {
        PtrF[licznik] = f;
        std::cout << "licznik: " << licznik << "\nget z figury: " << PtrF[licznik].get() << "\n";
        f.id();
        PtrF[licznik].id();
        licznik = licznik + 1;
    };

    void idWszystkie()
    {
        for (int i = 0; i < licznik; i++) {
            PtrF[i].id();
        }
    };

    Figura* PtrF;
    int     licznik;
    Figura* operator[](int);
};

Figura* WektorFigur::operator[](int index)
{
    if (index >= licznik) {
        return nullptr;
    }
    else {
        return &PtrF[index];
    }
}

/*
class FabrykaFigur
{
public:
    Figura* operator()(const std::string&, double);
};

Figura* FabrykaFigur::operator()(const std::string& t, double p)
{
    if (t == "kwadrat") {
        Kwadrat tmp{p};
        return &tmp;
    }
    else if (t == "kolo") {
        Kolo tmp{p};
        return &tmp;
    }
    else {
        return nullptr;
    }
}
*/

void f(Figura& tmp)
{
    std::cout << "Funkcja wolnostojaca"
              << "\n";
    tmp.id();
}

int main()
{
    Figura  a;
    Figura  b{4};
    Kwadrat c{5};

    Figura*  f  = new Kwadrat{};
    Kwadrat* kw = new Kwadrat{};
    Kolo*    ko = new Kolo{};
    if (f) {
        std::cout << f << "\n";
    }

    f = dynamic_cast< Kwadrat* >(f);
    if (f) {
        std::cout << f << "\n";
    }
    f = dynamic_cast< Kolo* >(f);
    if (f) {
        std::cout << f << "\n";
    }

    Figura* ptr = nullptr;
    if (ptr) {
        std::cout << f << "\n";
    }
    else {
        std::cout << "False"
                  << "\n";
    }
    
    delete f;
    delete kw;
    delete ko;

    // f = dynamic_cast< Kolo* >(f);
    // f->id();
    /*
        WektorFigur WF;
        WF.push(a);
        WF.push(b);
        WF.push(c);
        */
    // WF.idWszystkie();
}
