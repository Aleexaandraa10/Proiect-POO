#include "Meniu.h"
#include "Restaurant.h"
#include "Burger.h"

#include<iostream>

using namespace std;

Meniu& Meniu:: get_meniu() {
    static Meniu menu;
    return menu;
}

void Meniu::ControlPanel(){

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
         cout<<"5. Vizualizare numar de rezervari la momentul actual. (Downcast+Folosire atribut static)"<<endl;
         cout<<"6. Anulare rezervare online/telefonica. (Citire si afisarea a n obiecte + downcast + ilustrare exceptii)\n";
         cout<<"7. Verifica daca id-ul rezervarii tale online a fost introdus corect de catre colegii nostrii! (Upcasting+Downcasting)\n";
         cout<<"8. Nota ta de plata depaseste 200 de lei? Noi va oferim o reducere (Folosire functie statica)\n";
         cout<<"9. Optiune valabila doar pentru departamentul de IT! (Ilustrare upcast intr-un bloc catch + functionalitate RezervareAbonament)\n";
         cout<<"10. Vrei sa ne evaluezi? Acum este sansa ta! (Ierarhii clase template, RTTI, list, fct lambda-->sort)\n";
         cout<<"11. Afla care este parerea celorlalti clienti! Aici poti vedea media evaluarilor a ultimelor 10 rezervari facute. (Folosire map + Clase template)\n";
         cout <<"12. NOU!! Creeaza-ti propriul burger! (Utilizare design pattern builder)\n" ;
         cout<<"13. Am vizualizat ce mi-am dorit.\n";
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
         if(raspuns==5)
         {
             string ora;
             cout<<"Va rog introduceti ora dupa care doriti sa aflati cate rezervari au fost facute:"<<endl;
             cin>>ora;
             restaurant.Numara_Rezervari(ora);
         }
         if(raspuns==6)
         {
             cout<<"Urmariti pasii--> ";
             restaurant.Anuleaza_Rezervare();
         }
         if(raspuns==7)
         {
             RezervareOnline rezervareOnline(4, "19:00", "15.04.2024", "Parter", "Andrei","101A");
             Rezervare* rezervareptr=&rezervareOnline;
             rezervareptr->ValidareIdRezervare();

             Rezervare* rptr=&rezervareOnline;
             auto *onlineptr=dynamic_cast<RezervareOnline*>(rptr);
             onlineptr->ValidareIdRezervare();

         }
         if(raspuns==8)
         {
             int persoane;
             double pret;
             cout<<"Introduceti va rog numarul de persoane si aproximativ pretul per persoana:\n";
             cin>>persoane>>pret;
             double costTotal = Rezervare::CalculeazaCostTotal(persoane, pret);
             if(costTotal>=200){
                 string zi;
                 cout<<"Super, ai parte de reducere!\n";
                 cout<<"Introduceti in ce zi a saptamanii suntem:\n";
                 cin>>zi;
                 if(zi=="Luni" || zi=="Marti" || zi=="Miercuri"){
                     cout<<"Pentru ca va apreciem ca va faceti timp sa va relaxati in timpul saptamanii, noi va oferim o reducere de 20%\n";
                     costTotal=costTotal-0.20*costTotal;
                     cout<<"Noua nota de plata este: "<<costTotal<<endl;
                     cout<<"Speram ca v-am facut ziua mai buna!\n";
                 }
                 else
                     cout<<"Ne pare rau, noi oferim reduceri doar de Luni pana Miercuri.\n";
             }
             else{
                 cout<<"Ne pare rau, nota dvs de plata nu a depasit 200 de lei.\n";
             }
         }
         if(raspuns==9)
         {
             cout<<"Bine ai venit, aceasta optiune a meniului este doar pentru ilustrarea upcasting-ului intr-un bloc catch\n";
             Restaurant::prindeExceptie();
             cout << "In plus, mai jos se va ilustra functionalitatea derivatei RezervareAbonament\n" << std::endl;
             RezervareAbonament rAbonament(4, "19:00", "15.04.2024", "Parter", "Andrei",true);
             rAbonament.ValidareIdRezervare();
         }
         if(raspuns==10){
             string nume, data;
             cout<<"Ne poti da note legate de servire, mancare si atmosfera! Te rugam ca nota sa reflecte cat mai bine realitatea \n serviciilor oferite pentru a sti ce sa imbunatatim in viitor.\n";
             cout << "--------------------------------------------------------------\n\n";
             cout << "Te rog introdu numele pe care a fost facuta rezervarea si ziua in care ati venit la noi: " << std::endl;
             cout << "****Mentiune: data trebuie introdusa sub forma dd.mm.yyy pentru a o recunoaste sistemul nostru****\n";
             cin >> nume >> data;
             restaurant.Evaluare_Clienti(nume, data);
         }
         if(raspuns==11){
            restaurant.Medie_Evaluari();
         }
         if(raspuns==12){
             string carne, branza, sos, legume;
             Burger_builder bb;
             cout << "Creeaza-ti un burger exact pe gustul tau!\n";
             cout << "Introduceti va rog:\n";
             cout <<" Tipul de carne-->\n";
             cin >> carne;
             cout <<" Tipul de branza-->\n";
             cin >> branza;
             cout <<" Tipul de sos-->\n";
             cin >> sos;
             cout <<" Tipul de legume-->\n";
             cin >> legume;

             Burger b = bb.tip_carne(carne).tip_branza(branza).tip_sos(sos).tip_legume(legume).build();

             cout << "Asa arata optiunile dvs:\n";
             cout << b << endl;
             cout << "---------------------------------------------------------------------------------------------------\n";
             cout << "Gata, comanda a fost inregistrata, va rugam sa asteptati, burgerul dvs va fi gata in cateva momente.\n";

         }
         if(raspuns==13)
         {
             cout<<"Multumim ca ati ales restaurantul nostru! ";
             cout<<"Va dorim o zi minunata! ";
             continua=0;
         }
     }
}
