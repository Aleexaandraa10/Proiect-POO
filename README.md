# **Restaurant Reservation Management - C++ Project**  

This project is an **interactive application** developed in **C++**, simulating a **complex restaurant reservation system**.  
Advanced **Object-Oriented Programming (OOP)** concepts have been implemented to efficiently structure the application, optimize reservation management, user interaction, and restaurant functionalities.  

## **Implemented Features**  
- **Create, modify, and cancel reservations** (both online and phone-based)  
- **Check table availability** and count active reservations  
- **Personalized food recommendations** based on user preferences  
- **Automatic meal cost calculation** with dynamic discounts  
- **Customer experience rating system** using **templates and STL**  
- **Custom burger creation** using the **Builder design pattern**  
- **Exception handling and data validation** (e.g., detecting incorrect reservations)  
- **Efficient data structures from STL** (`vector`, `list`, `map`) for managing reservations  

## **Project Architecture**  
The project is structured into multiple classes, each with a well-defined role:  

### **Main Classes:**  
- `Menu` - Manages interactive restaurant operations  
- `Restaurant` - Handles reservations and user interaction  
- `Reservation` (base) - Defines reservations, with derived classes `OnlineReservation` and `PhoneReservation`  
- `BurgerBuilder` - Enables custom burger creation via **Builder pattern**  
- `Food` - Defines the menu with specific dishes  

### **Main Program (`main.cpp`)**  
- Initializes the application and manages the execution flow  
- Allows users to navigate through the menu options  
- Calls relevant methods for reservation management  

## **OOP Concepts Used**  
- **Classes and Objects** - Logical structuring of the application  
- **Constructors and Destructors** - Resource management  
- **Inheritance and Polymorphism** - Extending reservation functionalities  
- **Upcasting & Downcasting** - Converting between reservation types  
- **Overloaded Operators** - `operator>>`, `operator<<`, `operator=`  
- **Static Functions and Attributes** - Centralizing reservation data  
- **Exception Handling** - Validating IDs, handling errors (`std::exception`)  
- **Singleton Pattern** - Ensuring a unique instance of the menu  
- **Design Patterns:**  
  - **Builder** - Custom burger creation  
  - **Observer** - Table availability updates  
  - **Factory** - Managing reservation types  
- **STL (`vector`, `list`, `map`)** - Efficient reservation and review management  

## **Application Flow**  
The menu provides **13 options**, each demonstrating an **OOP concept**:  

1. Create a reservation  
2. Modify a reservation  
3. Check table availability  
4. Food recommendations  
5. Count active reservations (**Downcasting & static attributes**)  
6. Cancel a reservation (**Exceptions & reading `n` objects**)  
7. Validate reservation ID (**Upcasting & Downcasting**)  
8. Automatic discount on the bill (**Static function**)  
9. Advanced functionalities for employees (**Polymorphism**)  
10. Restaurant rating (**Templates, RTTI, `list`, lambda**)  
11. Average customer ratings (**STL - `map` + template classes**)  
12. Custom burger creation (**Builder Pattern**)  
13. Exit the application  

## **Potential Improvements**  
- **Database integration** to store reservations and customer reviews  
- **Graphical User Interface (GUI)** for a more user-friendly experience  
- **Expanded menu** with additional options and functionalities  

## **Conclusion**  
This project showcases **strong skills in C++ and Object-Oriented Programming**, implementing **advanced software architecture concepts** in an **interactive and user-friendly system**.
