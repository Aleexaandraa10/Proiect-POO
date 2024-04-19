#include "Restaurant.h"

Restaurant::Restaurant() {
    Detalii_Rezervari.emplace_back(new Rezervare(3,"18:30","18.03.2024","Terasa","Alexis")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(10,"19:30","20.03.2024","Terasa","Andone")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(2,"20:00","23.03.2024","Etaj","Banica")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(3,"20:00","23.03.2024","Etaj","Bogza")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(8,"21:00","23.03.2024","Parter","Chiriac")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(10,"20:30","25.03.2024","Etaj","Dascalu")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(6,"18:00","25.03.2024","Etaj","Alexandru")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(4,"22:30","25.03.2024","Etaj","Matei")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(3,"21:30","25.03.2024","Etaj","Davide")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(10,"18:00","25.03.2024","Demisol","Danciu")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(2,"19:00","12.03.2024","Demisol","Dediu")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(10,"21:00","08.03.2024","Demisol","Irimia")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(5,"19:30","13.03.2024","Parter","Flutur")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(4,"21:00","27.03.2024","Parter","Iancu")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(7,"22:30","14.03.2024","Parter","Lazar")); count++;
    Detalii_Rezervari.emplace_back(new Rezervare(7,"23:00","21.03.2024","Parter","Lungu")); count++;

    Detalii_Rezervari.emplace_back(new RezervareOnline(7,"20:00","23.04.2024","Demisol","Lungu","100")); count++;
    Detalii_Rezervari.emplace_back(new RezervareOnline(4,"22:00","16.04.2024","Terasa","Paun","101YT3")); count++;
    Detalii_Rezervari.emplace_back(new RezervareOnline(2,"18:00","27.04.2024","Parter","Nicusor","102")); count++;
    Detalii_Rezervari.emplace_back(new RezervareOnline(2,"23:30","15.04.2024","Demisol","Capitanu","103")); count++;
    Detalii_Rezervari.emplace_back(new RezervareOnline(6,"21:30","17.04.2024","Demisol","Popescu","104M")); count++;

    Detalii_Rezervari.emplace_back(new RezervareOnline(2,"23:30","15.04.2024","Demisol","Ciprian","103w")); count++;
    Detalii_Rezervari.emplace_back(new RezervareOnline(6,"20:30","16.04.2024","Demisol","Ciprian","1043")); count++;

    Detalii_Rezervari.emplace_back(new RezervareTelefonica(6,"20:30","20.04.2024","Etaj","Ciprian","0775434098")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(5,"20:00","28.04.2024","Etaj","Lungu","0775232042")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(10,"20:30","16.04.2024","Terasa","Nicoleta","0755019878")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(7,"19:00","15.04.2024","Demisol","Andrei","0773890454")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(3,"19:00","20.04.2024","Terasa","Dan","0770200779")); count++;

    Detalii_Rezervari.emplace_back(new RezervareTelefonica(5,"20:30","16.04.2024","Terasa","Cretu","0755018978")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(7,"19:00","15.04.2024","Demisol","Cretu","0755018978")); count++;
    Detalii_Rezervari.emplace_back(new RezervareTelefonica(3,"23:30","20.04.2024","Terasa","Cretu","0755018978")); count++;

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

Restaurant::~Restaurant(){
    for (auto& rezervare : Detalii_Rezervari) {
        delete rezervare;
    }
}

void Restaurant::Creare_Rezervare() {
    std::string data, ora, zona_client, nume, datarez;
    int nr_pers, pozitie=0;
    bool ok_data=false, ok_ora=false;
    std::cout<<"Introduceti va rog data la care ati vrea sa faceti rezervarea:\n";
    std::cin>>data;
    std::cout<<"Introduceti va rog ora la care ati vrea sa faceti rezervarea tinand cont ca restuarantul nostru se deschide la 18:00!\n";
    std::cin>>ora;
    bool finish=true;
    while(finish)
    {
        for (int i = 0; i < int(Detalii_Rezervari.size()); i++)
            if (data == Detalii_Rezervari[i]->GetData()) {
                datarez = Detalii_Rezervari[i]->GetData();
                ok_data = true;
                pozitie = i;
                break;
            }
        for (auto & i : Detalii_Rezervari)
            if (ora == i->GetOra() and i->GetData() == datarez) {
                ok_ora = true;
                break;
            }
        if (ok_data and ok_ora){
            std::cout <<"Avem deja o masa rezervata in data de " << data << " la ora " << ora << " in zona "
                 << Detalii_Rezervari[pozitie]->GetZonaRestaurant() << std::endl;
            std::cout << "Introduceti va rog o noua data si o noua ora la care va doriti sa rezervati:\n";
            ok_data=false; ok_ora=false;
            pozitie=0;
            std::cin>>data>>ora;
        }
        else {
            std::cout << "Rezervarea poate fi facuta!" << std::endl;
            std::cout << "Introduceti nr de persoane:\n";
            std::cin >> nr_pers;
            std::cin.get();
            std::cout<< "In ce zona a restaurantului ati vrea sa stati?\nLa acest restaurant sunt disponibile urmatoarele zone:\nParter\nEtaj\nTerasa\nDemisol\n";
            std::cin >> zona_client;
            std::cout << "Perfect, totul este aproape gata, spuneti va rog pe ce nume sa fie facuta rezervarea.\n";
            std::cin >> nume;
            Detalii_Rezervari.emplace_back(new Rezervare(nr_pers, ora, data, zona_client, nume));
            std::cout << "Multumim, rezervarea a fost facuta, aici puteti vedea detaliile ei:\n" << std::endl;
            std::cout << Detalii_Rezervari[Detalii_Rezervari.size() - 1];
            finish=false;
            std::cout<<"\nVa asteptam! ";
        }
    }
}

void Restaurant::Modificare_Detalii_Rezervare() {
    std::string data_rezervare;
    std::cout << "Va rog introduceti ziua in care ati facut rezervarea:\n";
    std::cin >> data_rezervare;
    std::cout << "Rezervarea poate fi modificata, urmati pasii de mai jos:\n";
    int optiune, pozitie_nume = 0;
    std::string raspuns, nume;
    std::cout << "Introduceti numele pe care a fost facuta rezervarea:\n";
    std::cin >> nume;
    for (int i = 0; i < int(Detalii_Rezervari.size()); i++)
        if (Detalii_Rezervari[i]->GetNumeRezervare() == nume) {
            pozitie_nume = i;
            break;
        }
    std::cout << "Ce doriti sa modificati mai exact la rezervare?" << std::endl;
    std::cout << "1. Data rezervarii." << std::endl;
    std::cout << "2. Ora rezervarii." << std::endl;
    std::cout << "3. Nr de persoane care participa." << std::endl;
    std::cin >> optiune;
    while (optiune != 0) {
        if (optiune == 1) {
            std::string data_noua;
            std::cout << "Care este noua data pe care o doriti?\n";
            std::cin >> data_noua;
            Detalii_Rezervari[pozitie_nume]->SetData(data_noua);
            std::cout << std::endl << "Asa arata rezervarea dvs modificata in acest moment:\n\n";
            std::cout << Detalii_Rezervari[pozitie_nume];
        }
        if (optiune == 2) {
            std::string ora_noua;
            std::cout << "Care este noua ora pe care o doriti?" << std::endl;
            std::cin >> ora_noua;
            Detalii_Rezervari[pozitie_nume]->SetOra(ora_noua);
            std::cout << std::endl << "Asa arata rezervarea dvs modificata in acest moment:\n\n";
            std::cout << Detalii_Rezervari[pozitie_nume];
        }
        if (optiune == 3) {
            int nr_persoane_nou;
            std::cout << "Care este noul numar de persoane care vor participa?\n";
            std::cin >> nr_persoane_nou;
            Detalii_Rezervari[pozitie_nume]->SetNrPersoane(nr_persoane_nou);
            std::cout << std::endl << "Asa arata rezervarea dvs modificata in acest moment:\n\n";
            std::cout << Detalii_Rezervari[pozitie_nume];
        }
        std::cout << std::endl << "Mai doriti sa modificati ceva la rezervarea dvs? Va rog raspundeti cu <<Da>> sau <<Nu>>\n";
        std::cin >> raspuns;
        if (raspuns == "Da") {
            std::cout << "Ce anume? " << std::endl;
            std::cout << "1. Data rezervarii" << std::endl;
            std::cout << "2. Ora rezervarii" << std::endl;
            std::cout << "3. Nr de persoane care participa" << std::endl;
            std::cin >> optiune;
        } else
            optiune = 0;
    }
    std::cout << "Multumim, rezervarea voastra a fost modificata cu succes! Va asteptam! ";
}

void Restaurant::OreDisponibile() {
    std::string data_client, raspuns;
    std::vector<std::string> ore_disponibile;
    std::vector<std::string> ore_folosite;
    std::vector<std::string> ore_afisate;
    int optiune = 1;

    std::cout << "Scrieti va rog ziua pentru care doriti sa aflati orele disponibile:\n";
    std::cin >> data_client;

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
        for (auto& i : Detalii_Rezervari)
            if (i->GetData() == data_client)
                ore_folosite.emplace_back(i->GetOra());
        for (auto& i : ore_disponibile) {
            bool ok = true;
            for (auto& j : ore_folosite)
                if (i == j) {
                    ok = false;
                    break;
                }
            if (ok)
                ore_afisate.emplace_back(i);
        }

        for (const auto& i : ore_afisate)
            std::cout << i << std::endl;
        std::cout << "Doriti sa vizualizati orele disponibile si in alta zi? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
        std::cout << "1. Da" << std::endl;
        std::cout << "2. Nu" << std::endl;
        std::cin >> raspuns;
        if (raspuns == "Da") {
            optiune = 1;
            std::cout << "Introduceti va rog noua data pe care doriti sa o vizualizati.\n";
            std::cin >> data_client;
        } else
            optiune = 2;
    }

    std::cout << "Multumim, va asteptam la restaurantul nostru! ";
}

void Restaurant::Recomandari_Culinare() {
    int optiune = 0;
    std::string raspuns;
    std::cout << "Ce doriti sa mancati?\n";
    std::cout << "1. Preparate cu carne\n";
    std::cout << "2. Preparate fara carne\n";
    std::cout << "3. Deserturi (cea mai buna alegere)\n";
    std::cin >> optiune;
    std::cout << "Aici aveti detaliile despre fiecare preparate, speram sa va placa!\n";
    while (optiune) {
        if (optiune == 1) {
            for (auto &i : Detalii_Preparate)
                if (i.GetCategorie() == "Contine carne") {
                    std::cout << "Denumire-->" << i.GetNume() << std::endl;
                    std::cout << "Gramaj-->" << i.GetGramaj() << std::endl;
                    std::cout << "Pret-->" << i.GetPret() << std::endl;
                    std::cout << std::endl;
                }
            std::cout << "Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
            std::cin >> raspuns;
            if (raspuns == "Nu")
                optiune = 0;
            else {
                std::cout << "Ce anume?" << std::endl;
                std::cout << "1. Preparate cu carne\n";
                std::cout << "2. Preparate fara carne\n";
                std::cout << "3. Deserturi (cea mai buna alegere)\n";
                std::cin >> optiune;
            }
        }
        if (optiune == 2) {
            for (auto &i : Detalii_Preparate)
                if (i.GetCategorie() == "Fara carne") {
                    std::cout << "Denumire-->" << i.GetNume() << std::endl;
                    std::cout << "Gramaj-->" << i.GetGramaj() << std::endl;
                    std::cout << "Pret-->" << i.GetPret() << std::endl;
                    std::cout << std::endl;
                }
            std::cout << "Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
            std::cin >> raspuns;
            if (raspuns == "Nu")
                optiune = 0;
            else {
                std::cout << "Ce anume?" << std::endl;
                std::cout << "1. Preparate cu carne\n";
                std::cout << "2. Preparate fara carne\n";
                std::cout << "3. Deserturi (cea mai buna alegere)\n";
                std::cin >> optiune;
            }
        }
        if (optiune == 3) {
            for (auto &i : Detalii_Preparate)
                if (i.GetCategorie() == "Desert") {
                    std::cout << "Denumire-->" << i.GetNume() << std::endl;
                    std::cout << "Gramaj-->" << i.GetGramaj() << std::endl;
                    std::cout << "Pret-->" << i.GetPret() << std::endl;
                    std::cout << std::endl;
                }
            std::cout << "Mai doriti sa vizualizati altceva? Raspundeti va rog cu <<Da>> sau <<Nu>>\n";
            std::cin >> raspuns;
            if (raspuns == "Nu")
                optiune = 0;
            else {
                std::cout << "Ce anume?" << std::endl;
                std::cout << "1. Preparate cu carne\n";
                std::cout << "2. Preparate fara carne\n";
                std::cout << "3. Deserturi (cea mai buna alegere)\n";
                std::cin >> optiune;
            }
        }
    }
}

void Restaurant::Numara_Rezervari(const std::string& ora) const {
    int ct_online = 0, ct_telefonic = 0, ct = 0;

    for (Rezervare* rezervare : Detalii_Rezervari) {
        if (dynamic_cast<RezervareOnline*>(rezervare)) {
            if (rezervare->GetOra() >= ora)
                ct_online++;
        } else if (dynamic_cast<RezervareTelefonica*>(rezervare)) {
            if (rezervare->GetOra() >= ora)
                ct_telefonic++;
        } else if (rezervare->GetOra() >= ora){
            ct++;
        }
    }
    std::cout << "Totalul nostru de rezervari facute la acest moment este: " << Detalii_Rezervari.size() << std::endl;
    std::cout << ct << " rezervari sunt facute personal dupa intervalul orar 20:00.\n";
    std::cout << "Dintre rezervarile noastre online, " << ct_online << " sunt dupa intervalul orar " << ora << std::endl;
    std::cout << "Dintre rezervarile noastre telefonice, " << ct_telefonic << " sunt dupa intervalul orar " << ora << std::endl;
}

void Restaurant::Anuleaza_Rezervare() const {
    std::string nume, data, ora, raspuns, telefon;
    int ct_rezervari = 0;
    std::cout << "Buna ziua, introduceti va rog numele pe care ati facut rezervarea\n";
    std::cin >> nume;
    for (auto *rezervare: Detalii_Rezervari) {
        if (dynamic_cast<RezervareOnline *>(rezervare) || dynamic_cast<RezervareTelefonica *>(rezervare)) {
            if (rezervare->GetNumeRezervare() == nume)
                ct_rezervari++;
        }
    }
    if (ct_rezervari == 0) {
        std::cout << "Ne pare rau, dar nu gasim nicio rezervare online sau telefonica pe numele " << nume << std::endl;
    } else {
        std::cout << "In acest moment aveti " << ct_rezervari
                  << " rezervari facute la restaurantul nostru. Cate doriti sa anulati?\n";
        std::cin >> ct_rezervari;
        if(ct_rezervari) {
            std::cout<< "In regula! Introduceti in aceasta ordine va rog data si ora la care a fost facuta fiecare rezervare\n";
            for (int i = 1; i <= ct_rezervari; i++) {
                if (i > 1)
                    std::cout << "Introduceti urmatoarea data si ora\n";
                bool date_corecte = false;
                while(!date_corecte) {
                    std::cin >> data >> ora;
                    for (Rezervare *rezervare: Detalii_Rezervari) {
                        if (auto *rezervareOnline = dynamic_cast<RezervareOnline *>(rezervare)) {
                            if (rezervareOnline->GetData() == data && rezervareOnline->GetOra() == ora &&
                                rezervareOnline->GetNumeRezervare() == nume) {
                                date_corecte=true;
                                std::cout
                                        << "Am gasit rezervarea, observam ca a fost facuta online, avand urmatorul id: "
                                        << rezervareOnline->GetId();
                                std::cout << "\nCelelalte detalii ale rezervarii sunt:\n";
                                std::cout << "Zona restaurant-> " << rezervareOnline->GetZonaRestaurant() << std::endl;
                                std::cout << "Numar persoane-> " << rezervareOnline->GetNrPersoane() << std::endl;
                                std::cout << "Sunteti sigur ca doriti sa o anulati?\n";
                                std::cout << "Da\nNu\n";
                                std::cin >> raspuns;
                                if (raspuns == "Da") {
                                    std::cout << "Anularea rezervarii de pe data " << data << " de la ora " << ora
                                              << " a fost realizata cu succes!\n";
                                }
                            }
                        }
                        if (auto *rezervareTelefonica = dynamic_cast<RezervareTelefonica *>(rezervare)) {
                            if (rezervareTelefonica->GetData() == data && rezervareTelefonica->GetOra() == ora &&
                                rezervareTelefonica->GetNumeRezervare() == nume) {
                                date_corecte=true;
                                std::cout
                                        << "Am gasit rezervarea, observam ca a fost facuta telefonic, pe urmatorul nr de telefon: "
                                        << rezervareTelefonica->GetTelefon();
                                std::cout << "\nCelelalte detalii ale rezervarii sunt:\n";
                                std::cout << "Zona restaurant-> " << rezervareTelefonica->GetZonaRestaurant()
                                          << std::endl;
                                std::cout << "Numar persoane-> " << rezervareTelefonica->GetNrPersoane() << std::endl;
                                std::cout << "Sunteti sigur ca doriti sa o anulati?\n";
                                std::cout << "Da\nNu\n";
                                std::cin >> raspuns;
                                if (raspuns == "Da") {
                                    std::cout << "Anularea rezervarii de pe data " << data << " de la ora " << ora
                                              << " a fost realizata cu succes!\n";
                                } else {
                                    std::cout
                                            << "Pentru rezervarile viitoare numarul de telefon mai este valabil?\nDa\nNu\n";
                                    std::cin >> raspuns;
                                    if (raspuns == "Da") {
                                        std::cout << "In regula!\n";
                                    } else {
                                        std::cout
                                                << "Introduceti un nou numar de telefon pentru a-l actualiza in baza noastra de date:\n";
                                        std::cin >> telefon;
                                        bool ok = false;
                                        while (!ok) {
                                            try {
                                                rezervareTelefonica->Schimba_NumarTelefon(telefon);
                                                ok = true;
                                            } catch (const std::invalid_argument &e) {
                                                std::cout << "Eroare: " << e.what() << std::endl;
                                                std::cout
                                                        << "Introduceti din nou numarul de telefon, asigurandu-va ca are exact 10 cifre:\n";
                                                std::cin >> telefon;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (!date_corecte) {
                        std::cout << "Data sau ora introdusa gresit. Va rugam sa introduceti din nou:\n";
                    }
                }
            }
        }
    }
    std::cout<<"Va mai asteptam la noi!\n";
}

int Restaurant::count = 0;

void Restaurant:: aruncaExceptie() {
    throw DataInvalidaException();
}

void Restaurant:: prindeExceptie() {
    try {
        aruncaExceptie();
    } catch(const RestaurantException& e) {
        std::cout << "A aparut o exceptie: " << e.what() << std::endl;
    } catch(const std::exception& e) {
        std::cout << "O alta exceptie a aparut: " << e.what() << std::endl;
    }
}
