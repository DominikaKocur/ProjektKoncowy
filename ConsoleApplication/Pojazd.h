#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <string_view>
using namespace std;

class Pojazd
{
public:
    virtual void print() = 0;
    virtual string get_typ() = 0;
    virtual string get_marka() = 0;
    virtual string get_model() = 0;
    virtual int get_rok() = 0;
    Pojazd() : model{ "default" } {}
    Pojazd(string m) :model{ m } {}
    virtual ~Pojazd() = default;
    string model;

};

class Osobowy : public Pojazd
{
public:
    void print() override
    {
        cout << "Samochod osobowy " << marka << " " << model << rok << '\n';
    }

    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    int get_rok() override { return rok; }
    Osobowy(string marka_, string model_, int rok_) :
        marka{ marka_ }, model{ model_ }, rok{ rok_ }{}

private:
    string typ = "Osobowy";
    string  marka, model;
    int rok;
};


class Ciezarowy : public Pojazd
{
public:
    void print() override
    {
        cout << "Samochod ciê¿arowy " << marka << " " << model << rok << '\n';
    }

    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    int get_rok() override { return rok; }
    Ciezarowy(string marka_, string model_, int rok_) :
        marka{ marka_ }, model{ model_ }, rok{ rok_ }{}

private:
    string typ = "Ciezarowy";
    string  marka, model;
    int rok;
};


class Motocykl : public Pojazd
{
public:
    void print() override
    {
        cout << " motocykl " << marka << " " << model << rok << '\n';
    }

    string get_typ()  override { return typ; }
    string get_marka() override { return marka; }
    string get_model() override { return model; }
    int get_rok() override { return rok; }
    Motocykl(string marka_, string model_, int rok_) :
        marka{ marka_ }, model{ model_ }, rok{ rok_ }{}

private:
    string typ = "Motocykl";
    string  marka, model;
    int rok;
};