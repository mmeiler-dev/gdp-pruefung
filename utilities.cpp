#include "./utilities.hpp"

/*
 * Ein Regex-Pattern, welches aus einem String Zahlen filtert
 */
std::regex numPattern("^[-+]?[0-9]+\\.?[0-9]*$");

/*
 * \brief Funktion, um eine valide Zahl aus der Eingabe des Nutzers zu bekommen. 
 *
 * Diese Funktion fragt so lange nach einer Eingabe, bis der Nutzer ihr einen String übergibt,
 * welcher nach dem output von isNumber valide ist. Falls eine falsche Eingabe geschieht, schreibt 
 * sie dies in die Konsole und fragt nach einer neuen Eingabe. 
 *
 * @param tmp ein String, welcher temporär die eingelesene Zahl beinhalten soll
 * @returns einen String mit einer Zahl als Inhalt.
 */
std::string getTmp(std::string tmp) {
    do {
        std::cin >> tmp;
        if (!isNumber(tmp)) {
            std::cout << "\033[0;31mGeben Sie eine valide Zahl an!\033[0m" << std::endl;
        }
    } while(!isNumber(tmp));
    return tmp;
}

/*
 * \brief Funktion, um eine valide Zahl in einem intervall aus der Eingabe des Nutzers zu bekommen.
 *
 * Diese Funktion fragt so lange nach einer Eingabe, bis der Nutzer ihr einen String übergibt,
 * welcher nach dem output von isNumber valide ist und die Zahl im gegebenen Intervall ist.
 * Falls eine falsche Eingabe geschieht, schreibt sie dies in die Konsole und fragt nach einer
 * neuen Eingabe.
 *
 * @param choice ein String, welcher die eingelesene Zahl beinhalten soll
 * @param start der Anfang des gewollten Intervalls
 * @param end das Ende des gewollten Intervalls
 * @returns einen String mit einer Zahl, welche im Intervall von start bis end liegt
 */
std::string getChoice(std::string choice, int start, int end) {
     do {
        std::getline(std::cin, choice);
        if (!isNumber(choice) || !((start <= std::stoi(choice)) && (std::stoi(choice) <= 2))) {
            std::cout << "\033[0;31mGeben Sie eine valide Zahl im Interval " << start << ".." << end << " an!\033[0m" << std::endl;
        }
    } while(!isNumber(choice) || !((start <= std::stoi(choice)) && (std::stoi(choice) <= end)));
    return choice;
}

/*
 * \brief Funktion, um einen validen String aus der Texteingabe zu erstellen für die Matrix2-Klasse.
 * 
 * Diese Funktion fragt nach jedem einzelnen Element, welches in die Matrix eingefügt werden soll.
 * Sie nutzt die getTmp Funktion, um eine Zahl zu garantieren, damit der Ausgabestring input richtig
 * in die Matrix2-Klasse eingelesen werden kann.
 * 
 * @param input der String, welcher modifiziert wird und in dem der "Matrix-String" gespeichert wird
 * @param tmp temporärer Speicher für die Eingaben
 * @param name Bezeichnung der Matrix (z.B. "A")
 * @returns String der Form "3 6 7 1" zur Einlesung in die Matrix2-Klasse
 */
std::string getMatrixInput(std::string input, std::string tmp, std::string name) {
    std::cout << "Geben Sie das \033[3merste\033[0m Element der Matrix " << name << " an! \033[1;37m" << std::endl << name << "(1,1)\033[0m: ";
    tmp = getTmp(tmp);
    input += tmp + " ";
    std::cout << std::endl;

    std::cout << "Geben Sie das \033[3mzweite\033[0m Element der Matrix " << name << " an! \033[1;37m" << std::endl << name << "(1,2)\033[0m: ";
    tmp = getTmp(tmp);
    input += tmp + " ";
    std::cout << std::endl;
    
    std::cout << "Geben Sie das \033[3mdritte\033[0m Element der Matrix " << name << " an! \033[1;37m" << std::endl << name << "(2,1)\033[0m: ";
    tmp = getTmp(tmp);
    input += tmp + " ";
    std::cout << std::endl;
    
    std::cout << "Geben Sie das \033[3mvierte\033[0m Element der Matrix " << name << " an! \033[1;37m" << std::endl << name << "(2,2)\033[0m: ";
    tmp = getTmp(tmp);
    input += tmp;
    std::cout << std::endl;

    return input;
}

/*
 * \brief Funktion, um einen validen String durch Texteingabe zu erstellen für die Vektor2-Klasse.
 *
 * Diese Funktion fragt nach zwei Texteingaben vom Nutzer, um daraus einen String zu erstellen, welcher
 * von der Klasse Vektor2 korrekt eingelesen werden kann. Dazu nutzt sie die getTmp-Funktion um einen
 * String, welcher aus Zahlen und Leerzeichen besteht zu erstellen.
 *
 * @param input der String, welcher modifiziert wird und in dem der "Vektor-String" gespeichert wird
 * @param tmp temporärer Speicher für die Eingaben
 * @param name Bezeichnung des Vektors (z.B. "a")
 * @returns String der Form "3 6" zur Einlesung in die Vektor2-Klasse
 */
std::string getVectorInput(std::string input, std::string tmp, std::string name) {
    std::cout << "Geben Sie das \033[3merste\033[0m Element des Vektors " << name << " an! \033[1;37m" << std::endl << name << "(1)\033[0m: ";
    tmp = getTmp(tmp);
    input = tmp + " ";
    std::cout << std::endl;

    std::cout << "Geben Sie das \033[3mzweite\033[0m Element des Vektors " << name << " an! \033[1;37m" << std::endl << name << "(2)\033[0m: ";
    tmp = getTmp(tmp);
    input += tmp;
    std::cout << std::endl;
    
    return input;
}

/*
 * \brief Funktion, um herauszufinden, ob ein String eine Zahl enthält.
 *
 * Diese Funktion nutzt das numPattern, um mit Hilfe von RegEx herauszufinden,
 * ob es sich bei dem input String um eine valide Zahl handelt oder nicht.
 *
 * @param input String, welcher vielleicht eine Zahl enthält
 * @returns Wahrheitswert, ob der String eine Zahl enthält
 */
bool isNumber(const std::string& input) {
    return std::regex_match(input, numPattern);
}