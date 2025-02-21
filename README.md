# Proiect - Gestionarea Rezervărilor la Restaurant

## Descrierea Proiectului
Acest proiect este o **aplicație interactivă** dezvoltată în **C++**, care simulează un sistem complex de gestionare a rezervărilor într-un restaurant. Am utilizat concepte avansate de **Programare Orientată pe Obiecte (POO)** pentru a structura eficient aplicația și pentru a optimiza gestionarea rezervărilor, interacțiunea cu utilizatorul și funcționalitățile restaurantului.

## Funcționalități Implementate
- **Crearea, modificarea și anularea rezervărilor** (online și telefonice)  
- **Verificarea disponibilității meselor** și numărarea rezervărilor active  
- **Sistem de recomandări culinare** bazate pe preferințele utilizatorului  
- **Calcul automat al costului mesei** cu reduceri dinamice  
- **Sistem de evaluare a experienței clienților**, folosind **template-uri și STL**  
- **Crearea unui burger personalizat** cu **design pattern Builder**  
- **Tratarea excepțiilor și validarea datelor** (ex. identificarea rezervărilor incorecte)  
- **Utilizarea unor structuri eficiente din STL** (`vector`, `list`, `map`) pentru gestionarea rezervărilor  

## Arhitectura Proiectului
Proiectul este structurat pe mai multe clase, fiecare având un rol bine definit:

### Clase principale:
- `Meniu` - Gestionarea interactivă a restaurantului
- `Restaurant` - Administrarea rezervărilor și interacțiunea cu utilizatorii
- `Rezervare` (bază) - Definirea rezervărilor, cu derivări pentru `RezervareOnline` și `RezervareTelefonica`
- `BurgerBuilder` - Permite personalizarea unui burger prin **design pattern Builder**
- `Mancare` - Definirea meniului cu preparate specifice

### Clasa principală (`main.cpp`)
- Inițializează aplicația și gestionează fluxul de execuție
- Permite utilizatorului să navigheze prin opțiunile meniului
- Apelează metodele relevante pentru gestionarea rezervărilor

## Concepte POO Utilizate
- **Clase și obiecte** - Organizarea logică a aplicației  
- **Constructori și destructor** - Gestionarea resurselor  
- **Moștenire și polimorfism** - Extinderea funcționalităților rezervărilor  
- **Upcasting & Downcasting** - Conversii între tipurile de rezervare  
- **Operatori supraîncărcați** - `operator>>`, `operator<<`, `operator=`  
- **Funcții și atribute statice** - Centralizarea informațiilor despre rezervări  
- **Tratarea excepțiilor** - Validare ID-uri, gestionarea erorilor (`std::exception`)  
- **Clasa Singleton** - Gestionarea meniului ca o instanță unică  
- **Design Patterns:**  
  - **Builder** - Crearea unui burger personalizat
  - **Observer** - Actualizarea disponibilității meselor
  - **Factory** - Gestionarea tipurilor de rezervări  
- **STL - vector, list, map** - Gestionarea eficientă a rezervărilor și evaluărilor  

## Fluxul aplicației
Meniul aplicației oferă **13 opțiuni**, fiecare ilustrând un **concept POO**:

1. Creare rezervare  
2. Modificare rezervare  
3. Verificare disponibilitate  
4. Recomandări culinare  
5. Număr rezervări active (**Downcasting & atribut static**)  
6. Anulare rezervare (**Excepții & citire `n` obiecte**)  
7. Validare ID rezervare (**Upcasting & Downcasting**)  
8. Reducere automată la nota de plată (**Funcție statică**)  
9. Funcționalități avansate pentru angajați (**Polimorfism**)  
10. Evaluarea restaurantului (**Template-uri, RTTI, list, lambda**)  
11. Media evaluărilor clienților (**STL - map + clase template**)  
12. Creare burger personalizat (**Builder Pattern**)  
13. Ieșire din aplicație  

## Posibile Îmbunătățiri
- **Integrare cu o bază de date** pentru stocarea rezervărilor și evaluărilor clienților  
- **Interfață grafică (GUI)** pentru o experiență mai prietenoasă  
- **Extinderea meniului** cu noi opțiuni și funcționalități  

## Concluzie
Acest proiect demonstrează **competențe solide în C++ și Programare Orientată pe Obiecte**, utilizând atât **concepte avansate de arhitectură software**, cât și **un sistem interactiv și intuitiv** pentru utilizatori.


