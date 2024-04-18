#include <iostream>
#include<string>
#include <Restaurant.h>

using namespace std;

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
         cout<<"5. Vizualizare numar de rezervari la momentul actual. (Downcast+Folosire atribut static)"<<endl;
         cout<<"6. Anulare rezervare online/telefonica. (Citire si afisarea a n obiecte + ilustrare exceptii)\n";
         cout<<"7. Verifica daca id-ul rezervarii tale online a fost introdus corect de catre colegii nostrii! (Upcasting+Downcasting)\n";
         cout<<"8. Nota ta de plata depaseste 200 de lei? Noi va oferim o reducere (Folosire functie statica)\n";
         cout<<"9. Optiune valabila doar pentru departamentul de IT! (Ilustrare upcast intr-un bloc catch)\n";
         cout<<"10. Am vizualizat ce mi-am dorit.\n";
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
             rezervareptr->ValidareIdRezervare();  //va prelua functia ValidareIdRezervare() din clasa derivata Rezervare

             Rezervare* rptr=&rezervareOnline;
             auto *onlineptr=dynamic_cast<RezervareOnline*>(rptr);
             onlineptr->ValidareIdRezervare(); //va prelua functia ValidareIdRezervare() din clasa derivata Rezervare

         }
         if(raspuns==8)
         {
             int persoane;
             double pret;
             cout<<"Introduceti va rog nr. de persoana si aproximativ pretul per persoana:\n";
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
         }
         if(raspuns==10)
         {
             cout<<"Multumim ca ati ales restaurantul nostru! ";
             cout<<"Va dorim o zi minunata! ";
             continua=0;
         }
     }
     return 0;
}
