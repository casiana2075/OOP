#include <iostream>
#include <string>
#include <vector>

class Enumerare {
  public:
    enum class TipContact { Prieten, Cunoscut, Coleg };

    static std::string getStringFromTipContact(TipContact tipContact) {
        switch (tipContact) {
        case TipContact::Prieten:
            return "Prieten";
        case TipContact::Cunoscut:
            return "Cunoscut";
        case TipContact::Coleg:
            return "Coleg";
        default:
            return "Necunoscut";
        }
    }
};

class Contact {
  
   public:
    std::string nume;
    Enumerare::TipContact tipContact;
    Contact(const std::string& nume, Enumerare::TipContact tipContact) : nume(nume), tipContact(tipContact) {
    }

    virtual void afisareDetalii() const = 0;
};

class Prieten : public Contact {
  private:
    std::string dataNastere;
    std::string numarTelefon;
    std::string adresa;

  public:
    Prieten(
          const std::string& nume,
          const std::string& dataNastere,
          const std::string& numarTelefon,
          const std::string& adresa)
        : Contact(nume, Enumerare::TipContact::Prieten), dataNastere(dataNastere), numarTelefon(numarTelefon),
          adresa(adresa) {
    }

    void afisareDetalii() const override {
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Tip contact: " << Enumerare::getStringFromTipContact(tipContact) << std::endl;
        std::cout << "Data de nastere: " << dataNastere << std::endl;
        std::cout << "Numar de telefon: " << numarTelefon << std::endl;
        std::cout << "Adresa: " << adresa << std::endl;
    }
};

class Cunoscut : public Contact {
  private:
    std::string numarTelefon;

  public:
    Cunoscut(const std::string& nume, const std::string& numarTelefon)
        : Contact(nume, Enumerare::TipContact::Cunoscut), numarTelefon(numarTelefon) {
    }

    void afisareDetalii() const override {
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Tip contact: " << Enumerare::getStringFromTipContact(tipContact) << std::endl;
        std::cout << "Numar de telefon: " << numarTelefon << std::endl;
    }
};

class Coleg : public Contact {
  private:
    std::string numarTelefon;
    std::string firma;
    std::string adresa;

  public:
    Coleg(const std::string& nume, const std::string& numarTelefon, const std::string& firma, const std::string& adresa)
        : Contact(nume, Enumerare::TipContact::Coleg), numarTelefon(numarTelefon), firma(firma), adresa(adresa) {
    }

    void afisareDetalii() const override {
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Tip contact: " << Enumerare::getStringFromTipContact(tipContact) << std::endl;
        std::cout << "Numar de telefon: " << numarTelefon << std::endl;
        std::cout << "Firma: " << firma << std::endl;
        std::cout << "Adresa: " << adresa << std::endl;
    }
};

class Agenda {
  private:
    std::vector<Contact*> contacte;

  public:
    void cautareContact(const std::string& nume) const {
        for (const auto& contact : contacte) {
            if (contact->nume == nume) {
                contact->afisareDetalii();
                return;
            }
        }
        std::cout << "Contactul \"" << nume << "\" nu a fost gasit." << std::endl;
    }

    void adaugaContact(Contact* contact) {
        contacte.push_back(contact);
    }

    void stergeContact(const std::string& nume) {
        for (auto it = contacte.begin(); it != contacte.end(); ++it) {
            if ((*it)->nume == nume) {
                delete *it;
                contacte.erase(it);
                std::cout << "Contactul \"" << nume << "\" a fost sters." << std::endl;
                return;
            }
        }
        std::cout << "Contactul \"" << nume << "\" nu a fost gasit." << std::endl;
    }

    void afisarePrieteni() const {
        std::cout << "Lista prieteni:" << std::endl;
        for (const auto& contact : contacte) {
            if (contact->tipContact == Enumerare::TipContact::Prieten) {
                std::cout << "- " << contact->nume << std::endl;
            }
        }
    }

    ~Agenda() {
        for (const auto& contact : contacte) {
            delete contact;
        }
    }
};

int main() {
    Agenda agenda;

    // Adaugare contacte
    agenda.adaugaContact(new Prieten("John", "01/01/1990", "123456789", "Adresa 1"));
    agenda.adaugaContact(new Cunoscut("Jane", "987654321"));
    agenda.adaugaContact(new Coleg("Mike", "555555555", "Firma XYZ", "Adresa 2"));

    // Cautare contact dupa nume
    agenda.cautareContact("John");
    agenda.cautareContact("Jane");
    agenda.cautareContact("Mike");

    // Stergere contact
    agenda.stergeContact("Jane");

    // Afisare lista de prieteni
    agenda.afisarePrieteni();

    return 0;
}
