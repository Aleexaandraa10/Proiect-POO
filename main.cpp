#include <iostream>
#include<string>
#include <utility>
#include<vector>

using namespace std;

class Mancare{
private:
   string Nume_Preparat;
   string Categorie_Preparat;
   int Gramaj;
   int Pret;

public:
    Mancare(string nume, string categorie, int gramaj, int pret): Nume_Preparat(std::move(nume)), Categorie_Preparat(std::move(categorie)), Gramaj(gramaj), Pret(pret){}

    string GetNume(){
        return Nume_Preparat;
    }
    string GetCategorie(){
        return Categorie_Preparat;
    }
    [[nodiscard]] int GetGramaj() const{
        return Gramaj;
    }
    [[nodiscard]] int GetPret() const {
        return Pret;
    }
};

class Rezervare{
private:
    int Nr_Persoane;
    string Ora;
    string Data;
    string Zona_Restaurant;
    string Nume_Rezervare;
public:
    explicit Rezervare(int nr_persoane = 0, string ora = "", string data = "", string zona_restaurant = "", string nume_rezervare =""):
    Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant(std::move(zona_restaurant)),Nume_Rezervare(std::move(nume_rezervare)){}                                                                              //atribuim informatiile care ni se dau despre Rezervare

    Rezervare(int nr_persoane, string ora, string data,string nume_rezervare):
    Nr_Persoane(nr_persoane), Ora(std::move(ora)), Data(std::move(data)), Zona_Restaurant("Parter"),Nume_Rezervare(std::move(nume_rezervare)){}

    Rezervare (const Rezervare& masa):
    Nr_Persoane(masa.Nr_Persoane),Ora(masa.Ora),Data(masa.Data), Zona_Restaurant(masa.Zona_Restaurant),Nume_Rezervare(masa.Nume_Rezervare){}

    Rezervare& operator=(Rezervare const& masa){
        this->Nume_Rezervare=masa.Nume_Rezervare;
        this->Nr_Persoane=masa.Nr_Persoane;
        this->Ora=masa.Ora;
        this->Data=masa.Data;
        this->Zona_Restaurant=masa.Zona_Restaurant;
        return *this;
    }
    ~Rezervare(){//destructor
        Nume_Rezervare="";
        Nr_Persoane=0;
        Ora="";
        Data="";
        Zona_Restaurant="";
    }
    friend istream& operator>>(istream& CIN, Rezervare& R); //operator de citire supraincarcat
    friend ostream& operator<<(ostream& COUT, const Rezervare& R); //operator de afisare supraincarcat
    friend int operator>(Rezervare& masa, const string& ora_limita); //operatorul> supraincarcat ca functie non-membra
    friend class Restaurant;

    int operator==(const Rezervare& masa) const {       //operator supraincarcat ca functie membra
        if(masa.Data==Data and Ora==masa.Ora)
            return 1;
        else
            return 0;
    }

    string GetData(){
        return Data;
    }
    string GetOra(){
        return Ora;
    }
    string GetZonaRestaurant(){
        return Zona_Restaurant;
    }
    string GetNumeRezervare(){
        return Nume_Rezervare;
    }
};

ostream& operator<<(ostream& COUT, const Rezervare& R){
    COUT<<"Numele pe care a fost facuta rezervarea este: "<<R.Nume_Rezervare<<endl;
    COUT<<"Nr de persoane care participa este: "<<R.Nr_Persoane<<endl;
    COUT<<"Ora la care masa a fost rezervata este: "<<R.Ora<<endl;
    COUT<<"Data rezervarii este: "<<R.Data<<endl;
    COUT<<"Zona restaurantului aleasa este: "<<R.Zona_Restaurant<<endl;
    return COUT;
}

istream& operator>>(istream& CIN, Rezervare& R){
    cout<<"Numele pe care a fost facuta rezervarea este: "<<endl;
    CIN>>R.Nume_Rezervare;
    cout<<"Nr de persoane care participa este: "<<endl;
    CIN>>R.Nr_Persoane;
    cout<<"Ora la care masa a fost rezervata este: "<<endl;
    CIN>>R.Ora;
    cout<<"Data rezervarii este: "<<endl;
    CIN>>R.Data;
    cout<<"Zona restaurantului aleasa este: "<<endl;
    CIN>>R.Zona_Restaurant;
    return CIN;
}

int operator>(Rezervare& masa, const string& ora_limita){ //operatorul supraincarcat >
                                                        // daca rezervarea este facuta dupa o anumita ora limita stabilita de restaurant, va fi refuzata
    if (masa.GetOra() > ora_limita) {
        return 0;
    } else
        return 1;
}

class Restaurant: Rezervare {
    vector<Rezervare> Detalii_Rezervari;
    vector<Mancare>Detalii_Preparate;
public:
    Restaurant(){
        Detalii_Rezervari.emplace_back(3,"18:30","18.03.2024","Terasa","Alexis");
        Detalii_Rezervari.emplace_back(10,"19:30","20.03.2024","Terasa","Andone");
        Detalii_Rezervari.emplace_back(2,"20:00","23.03.2024","Etaj","Banica");
        Detalii_Rezervari.emplace_back(3,"20:00","23.03.2024","Etaj","Bogza");
        Detalii_Rezervari.emplace_back(8,"21:00","23.03.2024","Parter","Chiriac");
        Detalii_Rezervari.emplace_back(10,"20:30","25.03.2024","Etaj","Dascalu");
        Detalii_Rezervari.emplace_back(6,"18:00","25.03.2024","Etaj","Alexandru");
        Detalii_Rezervari.emplace_back(4,"22:30","25.03.2024","Etaj","Matei");
        Detalii_Rezervari.emplace_back(3,"21:30","25.03.2024","Etaj","Davide");
        Detalii_Rezervari.emplace_back(10,"18:00","25.03.2024","Demisol","Danciu");
        Detalii_Rezervari.emplace_back(2,"19:00","12.03.2024","Demisol","Dediu");
        Detalii_Rezervari.emplace_back(10,"21:00","08.03.2024","Demisol","Irimia");
        Detalii_Rezervari.emplace_back(5,"19:30","13.03.2024","Parter","Flutur");
        Detalii_Rezervari.emplace_back(4,"21:00","27.03.2024","Parter","Iancu");
        Detalii_Rezervari.emplace_back(7,"22:30","14.03.2024","Parter","Lazar");
        Detalii_Rezervari.emplace_back(7,"23:00","21.03.2024","Parter","Lungu");
        Detalii_Preparate.emplace_back("Classic Nachos","Fara carne",600,59);
        Detalii_Preparate.emplace_back("Classic Nachos","Fara carne",600,59);
        Detalii_Preparate.emplace_back("The Big Cheesburger","Contine carne",335,59);
        Detalii_Preparate.emplace_back("Steak Salad","Fara carne", 580,89);
        Detalii_Preparate.emplace_back("Assian Noodle Bowl","Fara carne", 595,69);
        Detalii_Preparate.emplace_back("Grilled Salmon","Contine carne",530,99);
        Detalii_Preparate.emplace_back("Homemade Apple Cobbler","Desert",380,39);
        Detalii_Preparate.emplace_back("Craft Ice Cream","Desert",90,24);
        Detalii_Preparate.emplace_back("Cookies & Cream Milkshake","Desert",220,26);
    }

    void Creare_Rezervare(){ //clientul poate face o rezervare
        string data, ora, zona_client, nume;
        string datarez;
        int nr_pers, pozitie=0;
        bool ok_data=false, ok_ora=false;
        cout<<"Introduceti va rog data la care ati vrea sa faceti rezervarea:\n";
        cin>>data;
        cout<<"Introduceti va rog ora la care ati vrea sa faceti rezervarea tinand cont ca restuarantul nostru se deschide la 18:00!\n";
        cin>>ora;
        bool finish=true;
        while(finish)
        {
            for (int i = 0; i < int(Detalii_Rezervari.size()); i++)
                if (data == Detalii_Rezervari[i].GetData()) {
                    datarez = Detalii_Rezervari[i].GetData();
                    ok_data = true;
                    pozitie = i;
                    break;
                }
            for (auto & i : Detalii_Rezervari)
                if (ora == i.GetOra() and i.GetData() == datarez) {
                    ok_ora = true;
                    break;
                }
            if (ok_data and ok_ora){
                    cout <<"Avem deja o masa rezervata in data de " << data << " la ora " << ora << " in zona "
                         << Detalii_Rezervari[pozitie].GetZonaRestaurant() << endl;
                    cout << "Introduceti va rog o noua data si o noua ora la care va doriti sa rezervati:\n";
                    ok_data=false; ok_ora=false;
                    pozitie=0;
                    cin>>data>>ora;
                }
            else {
                cout << "Rezervarea poate fi facuta!" << endl;
                cout << "Introduceti nr de persoane:\n";
                cin >> nr_pers;
                cin.get();
                cout<< "In ce zona a restaurantului ati vrea sa stati?\nLa acest restaurant sunt disponibile urmatoarele zone:\nParter\nEtaj\nTerasa\nDemisol\n";
                cin >> zona_client;
                cout << "Perfect, totul este aproape gata, spuneti va rog pe ce nume sa fie facuta rezervarea.\n";
                cin >> nume;
                Detalii_Rezervari.emplace_back(nr_pers, ora, data, zona_client, nume);
                cout << "Multumim, rezervarea a fost facuta, aici puteti vedea detaliile ei:\n" << endl;
                cout << Detalii_Rezervari[Detalii_Rezervari.size() - 1];
                finish=false;
                cout<<"\nVa asteptam! ";
            }
        }
    }

    void Modificare_Detalii_Rezervare() { //clientul poate modifica complet rezervarea
        string data_rezervare;
        cout << "Va rog introduceti ziua in care ati facut rezervarea:\n";
        cin >> data_rezervare;
        cout << "Rezervarea poate fi modificata, urmati pasii de mai jos:\n";
        int optiune, pozitie_nume=0;
        string raspuns, nume;
        cout << "Introduceti numele pe care a fost facuta rezervarea:\n";
        cin >> nume;
        for (int i = 0; i < int(Detalii_Rezervari.size()); i++)
            if (Detalii_Rezervari[i].GetNumeRezervare() == nume) {
                pozitie_nume = i;
                break;
            }
        cout << "Ce doriti sa modificati mai exact la rezervare?" << endl;
        cout << "1. Data rezervarii." << endl;
        cout << "2. Ora rezervarii." << endl;
        cout << "3. Nr de persoane care participa." << endl;
        cin >> optiune;
        while (optiune != 0) {
            if (optiune==1) {
                string data_noua;
                cout << "Care este noua data pe care o doriti?\n";
                cin >> data_noua;
                Detalii_Rezervari[pozitie_nume].Data=data_noua;
                cout<<endl<<"Asa arata rezervarea dvs modificata in acest moment:\n\n";
                cout << Detalii_Rezervari[pozitie_nume];
            }
            if (optiune == 2) {
                string ora_noua;
                cout << "Care este noua ora pe care o doriti?" << endl;
                cin >> ora_noua;
                Detalii_Rezervari[pozitie_nume].Ora=ora_noua;
                cout<<endl<<"Asa arata rezervarea dvs modificata in acest moment:\n\n";
                cout << Detalii_Rezervari[pozitie_nume];
            }
            if (optiune == 3) {
                int nr_persoane_nou;
                cout << "Care este noul numar de persoane care vor participa?\n";
                cin >> nr_persoane_nou;
                Detalii_Rezervari[pozitie_nume].Nr_Persoane=nr_persoane_nou;
                cout<<endl<<"Asa arata rezervarea dvs modificata in acest moment:\n\n";
                cout << Detalii_Rezervari[pozitie_nume];
            }
            cout<<endl<<"Mai doriti sa modificati ceva la rezervarea dvs? Va rog raspundeti cu <<Da>> sau <<Nu>>\n";
            cin>>raspuns;
            if (raspuns=="Da")
            {
                cout<<"Ce anume? "<<endl;
                cout << "1. Data rezervarii" << endl;
                cout << "2. Ora rezervarii" << endl;
                cout << "3. Nr de persoane care participa" << endl;
                cin>>optiune;
            }
            else
                optiune=0;
        }
        cout<<"Multumim, rezervarea voastra a fost modificata cu succes! Va asteptam! ";
    }

    void OreDisponibile() { //functia va afisa toate orele disponibile dintr-o anumita zi
        string data_client, raspuns;
        vector<string> ore_disponibile;
        vector<string> ore_folosite;
        vector<string> ore_afisate;
        int optiune=1;
        cout << "Scrieti va rog ziua pentru care doriti sa aflati orele disponibile:\n";
        cin >> data_client;
        ore_disponibile.emplace_back("18:00");
        ore_disponibile.emplace_back("18:30");
        ore_disponibile.emplace_back("19:00");
        ore_disponibile.emplace_back("19:30");
        ore_disponibile.emplace_back("20:00");
        ore_disponibile.emplace_back("20:30");
        ore_disponibile.emplace_back("21:00");
        ore_disponibile.emplace_back("21:30");
        ore_disponibile.emplace_back("22:00");
        ore_disponibile.emplace_back("22:30");
        ore_disponibile.emplace_back("23:00");
        ore_disponibile.emplace_back("23:30");

        while (optiune != 2) {
            ore_folosite.clear();
            ore_afisate.clear();
            for (auto & i : Detalii_Rezervari)
                if (i.GetData() == data_client)
                    ore_folosite.emplace_back(i.GetOra());
            for (auto & i : ore_disponibile) {
                bool ok = true;
                for(auto &j: ore_folosite)
                    if (i == j) {
                        ok = false;
                        break;
                    }
                if (ok)
                    ore_afisate.emplace_back(i);
            }

            for (const auto & i : ore_afisate)
                cout << i << endl;
            cout << "Doriti sa vizualizati orele disponibile si in alta zi? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
            cout << "1. Da" << endl;
            cout << "2. Nu" << endl;
            cin>>raspuns;
            if(raspuns=="Da")
            {
                optiune=1;
                cout<<"Introduceti va rog noua data pe care doriti sa o vizualizati.\n";
                cin>>data_client;
            }
            else
                optiune=2;

        }
        cout<<"Multumim, va asteptam la restaurantul nostru! ";
    }

    void Recomandari_Culinare(){
        int optiune=0;
        string raspuns;
        cout<<"Ce doriti sa mancati?\n";
        cout << "1. Preparate cu carne\n";
        cout << "2. Preparate fara carne\n";
        cout << "3. Deserturi (cea mai buna alegere)\n";
        cin >> optiune;
        cout<<"Aici aveti detaliile despre fiecare preparate, speram sa va placa!\n";
        while(optiune){
            if (optiune == 1) {
                for (auto & i : Detalii_Preparate)
                    if (i.GetCategorie() == "Contine carne"){
                        cout<<"Denumire-->"<<i.GetNume()<<endl;
                        cout<<"Gramaj-->"<<i.GetGramaj()<<endl;
                        cout<<"Pret-->"<<i.GetPret()<<endl;
                        cout<<endl;
                    }
                cout<<"Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
                cin>>raspuns;
                if(raspuns=="Nu")
                    optiune=0;
                else{
                    cout<<"Ce anume?"<<endl;
                    cout << "1. Preparate cu carne\n";
                    cout << "2. Preparate fara carne\n";
                    cout << "3. Deserturi (cea mai buna alegere)\n";
                    cin>>optiune;
                }
            }
            if (optiune == 2) {
                for (auto & i : Detalii_Preparate)
                    if (i.GetCategorie() == "Fara carne") {
                        cout << "Denumire-->" << i.GetNume() << endl;
                        cout << "Gramaj-->" << i.GetGramaj() << endl;
                        cout << "Pret-->" << i.GetPret() << endl;
                        cout << endl;
                    }
                cout << "Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
                cin >> raspuns;
                if (raspuns == "Nu")
                    optiune = 0;
                else {
                    cout << "Ce anume?" << endl;
                    cout << "1. Preparate cu carne\n";
                    cout << "2. Preparate fara carne\n";
                    cout << "3. Deserturi (cea mai buna alegere)\n";
                    cin >> optiune;
                }
            }
            if (optiune == 3) {
                for (auto & i : Detalii_Preparate)
                    if (i.GetCategorie() == "Desert") {
                        cout << "Denumire-->" << i.GetNume() << endl;
                        cout << "Gramaj-->" << i.GetGramaj() << endl;
                        cout << "Pret-->" << i.GetPret() << endl;
                        cout << endl;
                    }
                cout << "Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
                cin >> raspuns;
                if (raspuns == "Nu")
                    optiune = 0;
                else {
                    cout << "Ce anume?\n" << endl;
                    cout << "1. Preparate cu carne\n";
                    cout << "2. Preparate fara carne\n";
                    cout << "3. Deserturi (cea mai buna alegere)\n";
                    cin >> optiune;
                }
            }
        }
    }
};


int main() {

     Restaurant restaurant;
     int continua=1, raspuns;
     cout<<"Bun venit la restaurantul nostru!\n";
     while(continua)
     {
         cout << "\nCe serviciu doriti sa folositi?\n";
         cout<<"1. Rezerva masa."<<endl;
         cout<<"2. Modifica o rezervare deja existenta."<<endl;
         cout<<"3. Verifica disponibilitate ore dintr-o anumita zi."<<endl;
         cout<<"4. Recomandarile bucatarului."<<endl;
         cout<<"9. Am vizualizat ce mi-am dorit."<<endl;
         cin>>raspuns;
         if(raspuns==1)
         {
             cout<<"Urmariti pasii--> ";
             restaurant.Creare_Rezervare();
         }
         if(raspuns==2)
         {
             cout<<"Urmariti pasii--> ";
             restaurant.Modificare_Detalii_Rezervare();
         }
         if(raspuns==3)
         {
             cout<<"Urmariti pasii--> ";
             restaurant.OreDisponibile();
         }
         if(raspuns==4)
         {
             cout<<"Mai jos puteti gasi cele mai bune preparate ale bucatarului in caz de aveti nevoie de inspiratie:"<<endl;
             restaurant.Recomandari_Culinare();
         }
         if(raspuns==9)
         {
             cout<<"Multumim ca ati ales restaurantul nostru! ";
             cout<<"Va dorim o zi minunata! ";
             continua=0;
         }
     }
     return 0;
}
