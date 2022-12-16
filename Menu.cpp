#include "Menu.h"
#include "Entertainment.h"
#include "Movie.h"
#include "Series.h"
#include "OutOfBoundsException.h"
#include "InvalidInputException.h"
#include <iostream>
#include <vector>
#include <string>

// Aici a fost implementat meniul interactiv unde user-ul poate sa adauge filme sau seriale, sa le stearga, sa calculeze
// timpul de vizionare pentru un film/serial sau sa vizualizeze elementele pe care le-a adaugat.
// Metoda watchTime() imi da o eroare pe care nu am reusit sa o rezolv inca; desi se apeleaza si afiseaza ce trebuie,
// cateodata programul se opreste brusc dupa aceasta.


Menu::Menu() {}

Menu::Menu(const vector<Entertainment*> &ent) : ent(ent) {}

int Menu::option() {
    int op;
    cin >> op;
    while (op < 1 || op > 5) {
        cout << "Optiunea aleasa nu este valida! Alegeti un numar de la 1 la 5!" << endl;
        cin >> op;
    }
    return op;
}

void Menu::option1() {
    cout << "In lista de redare aveti " << ent.size() << " filme si seriale." << endl;
    for (int i = 0; i < ent.size(); i++)
    {
        Movie *m = dynamic_cast<Movie*>(ent[i]);
        if(m!=nullptr) {
            cout << *m;
            delete m;
        }
        else {
            Series *s = dynamic_cast<Series*>(ent[i]);
            cout << *s;
            delete s;
        }
    }
}

void Menu::option2() {
    //cout << ent.size();
    if (ent.size() > 20)
        throw OutOfBoundsException("Out of bounds!");
    else {
        int input;
        cout << "Pentru a adauga un film apasati 1, pentru a adauga un serial apasati 2.";
        cin >> input;
        while (input < 1 || input > 2) {
            cout << "Optiunea aleasa nu este valida! Alegeti 1 pentru a adauga un film sau 2 pentru un serial!";
            cin >> input;
        }

        switch (input) {

            case 1: {
                cout << "Introduceti numele filmului: ";
                string name;
                cin >> name;
                cout << endl << "Introduceti durata filmului in minute: ";
                int duration;
                cin >> duration;
                cout << endl << "Introduceti anul aparitiei: ";
                try {
                    int releaseYear;
                    cin >> releaseYear;
                    Entertainment *f = new Movie(name, duration, releaseYear);
                    ent.push_back(f);
                    cout << "Filmul a fost adaugat!";
                    break;
                }
                catch(InvalidInputException &x){
                    cout << endl << "Anul adaugat nu este valid!" << endl;
                }
                break;

            }

            case 2: {

                cout << "Introduceti numele serialului: ";
                string name;
                cin >> name;
                cout << endl << "Introduceti numarul de episoade al serialului: ";
                int nrOfEps;
                cin >> nrOfEps;
                cout << endl << "Introduceti durata unui episod in minute: ";
                int duration;
                cin >> duration;
                Entertainment *s = new Series(name, duration, nrOfEps);
                ent.push_back(s);
                cout << "Serialul a fost adaugat!";
                break;
            }
        }
    }
}

void Menu::option3() {
    string elem;
    int found = 0;
    int i;
    cout << "Introduceti numele filmului sau serialului pentru care doriti sa calculati timpul de vizionare: " << endl;
    cin >> elem;
    for (i = 0; i < ent.size(); i++) {
        if (ent[i]->getName() == elem) {
            found = 1;
            //cout<<"gasit!"<<endl;
            Series *s = dynamic_cast<Series*>(ent[i]);
            if(s!=nullptr){
                s->watchTime();
                delete s;
            }
            else
                delete s;
            ent[i]->watchTime();
            break;
        }
    }

    if (found == 0)
        cout << "Elementul nu se afla in lista! Incercati din nou." << endl;
}

void Menu::option4() {
    string elem;
    int found = 0;
    int i;
    cout << "Introduceti numele filmului sau serialului pe care doriti sa il stergeti:" << endl;
    cin >> elem;
    for (i = 0; i < ent.size(); i++) {
        if (ent[i]->getName() == elem) {
            ent.erase(ent.begin() + i);
            found = 1;
            break;
        }
    }
    if (found == 1) cout << "Elementul a fost sters cu succes!";
    else cout << "Elementul nu a fost gasit! Incercati din nou!";
}

void Menu::interactiveMenu() {
    while (true) {
        cout << endl;
        cout << "1. Vizualizeaza lista de redare;" << endl;
        cout << "2. Adauga un film sau un serial in lista de redare;" << endl;
        cout << "3. Calculeaza timpul de vizionare pentru un film sau serial." << endl;
        cout << "4. Sterge un element din lista de redare;" << endl;
        cout << "5. Paraseste meniul interactiv." << endl;
        int input = option();
        switch (input) {

            case 1:
                option1();
                break;

            case 2:
                try {
                    option2();
                }
                catch(OutOfBoundsException &x){
                    cout<<"Valoare maxima depasita!";
                }
                break;

            case 3:
                option3();
                break;

            case 4:
                option4();
                break;

            case 5:
                cout << "La revedere!";
                //for (auto ptr : ent) {
                //delete ptr; }
                exit(0);
        }


    }
}

Menu::~Menu() {
    ent.clear();
}


