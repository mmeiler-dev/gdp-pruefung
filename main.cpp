#include "./mathLib.hpp"

void vectorTests();
void matrixTests();

/*
 * \pre Hauptmenü, das durch Eingabe der Zahl zum gewünschten Testmenü führt
 *
 * Diese Funktion schreibt das Hauptmenü für die Auswahl der Testmenüs aus. 
 * Durch eine valide Eingabe, kann man zu den anderen Testmenüs navigieren.
 */
int main() {
    std::string choice;
    
    std::cout << "\033[1;37mDies ist der Funktionalitätstester der Mathematikbibliothek!" << std::endl
              << "Geben Sie eine Zahl von 0..2 an, um die folgenden Funktionalitäten zu testen!\033[0m" << std::endl
              << "0 - \033[3mBeenden Sie das Programm\033[0m" << std::endl
              << "1 - \033[3mAuflistung verfügbarer Tests von der Vektor2-Klasse\033[0m" << std::endl
              << "2 - \033[3mAuflistung verfügbarer Tests von der Matrix2-Klasse\033[0m" << std::endl;
    
    choice = getChoice(choice, 0, 2);
    
    switch(std::stoi(choice)) {
        case 0: {
            exit(0);
        }
        case 1: {
            std::cout << std::endl;
            vectorTests();
            break;
        }
        case 2: {
            std::cout << std::endl;
            matrixTests();
            break;
        }
    }
}

/*
 * \brief Menüpunkt Vektoraddition, berechnet aus gegebenen Vektoren deren Summe.
 *
 * Diese Funktion fragt nach der Eingabe von zwei Vektor2 Objekten und gibt dann
 * die Summe der Vektoren als Ausgabe an die Konsole weiter und returned zum 
 * Vektortestmenü.
 */
void vectorAddition() {
    Vektor2 a,b;
    std::string inputA;
    std::string inputB;
    std::string tmp;
    
    std::istringstream(getVectorInput(inputA, tmp, "a")) >> a;
    std::istringstream(getVectorInput(inputB, tmp, "b")) >> b;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << a+b << std::endl;
    return;
}

/*
 * \brief Menüpunkt Skalarmultiplikation, berechnet aus gegebenen Vektoren deren Skalarprodukt.
 *
 * Diese Funktion fragt nach der Eingabe von zwei Vektor2 Objekten und gibt dann
 * das Skalarprodukt der Vektoren als Ausgabe an die Konsole weiter und returned zum 
 * Vektortestmenü.
 */
void dotProduct() {
    Vektor2 a,b;
    std::string inputA;
    std::string inputB;
    std::string tmp;

    std::istringstream(getVectorInput(inputA, tmp, "a")) >> a;
    std::istringstream(getVectorInput(inputB, tmp, "b")) >> b;
    
    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << a*b << std::endl;
    return;
}

/*
 * \brief Menüpunkt Normquadrat, berechnet aus einem Vektoren das Quadrat seiner Norm.
 *
 * Diese Funktion fragt nach der Eingabe von eimen Vektor2 Objekt und gibt dann
 * das Quadrat der Vektorennorm als Ausgabe an die Konsole weiter und returned zum 
 * Vektortestmenü.
 */
void normSquared() {
    Vektor2 a;
    std::string inputA;
    std::string tmp;

    std::istringstream(getVectorInput(inputA, tmp, "a")) >> a;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << a.normSquare() << std::endl;
    return;
}

/*
 * \brief Menüpunkt Matrixaddition, berechnet aus gegebenen Matrizen deren Summe.
 *
 * Diese Funktion fragt nach der Eingabe von zwei Matrix2 Objekten und gibt dann
 * die Summe der Matrizen als Ausgabe an die Konsole weiter und returned zum 
 * Matrixtestmenü.
 */
void matrixAddition() {
    Matrix2 A, B;
    std::string inputA;
    std::string inputB;
    std::string tmp;

    std::istringstream(getMatrixInput(inputA,tmp, "A")) >> A;
    std::cout << std::endl;
    std::istringstream(getMatrixInput(inputB,tmp, "B")) >> B;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << std::endl << A+B << std::endl;
    return;
}

/*
 * \brief Menüpunkt Matrixmultiplikation, berechnet aus gegebenen Matrizen deren Produkt.
 *
 * Diese Funktion fragt nach der Eingabe von zwei Matrix2 Objekten und gibt dann
 * das Produkt der Matrizen als Ausgabe an die Konsole weiter und returned zum 
 * Matrixtestmenü.
 */
void matrixMult() {
    Matrix2 A, B;
    std::string inputA;
    std::string inputB;
    std::string tmp;

    std::istringstream(getMatrixInput(inputA,tmp, "A")) >> A;
    std::cout << std::endl;
    std::istringstream(getMatrixInput(inputB,tmp, "B")) >> B;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << std::endl << A*B << std::endl;
    return;
}

/*
 * \brief Menüpunkt Matrix-Vektor-Mulitplikation, berechnet aus gegebener Matrix und Vektor deren Produkt.
 *
 * Diese Funktion fragt nach der Eingabe von einem Matrix2, sowie einem Vektor2 Objekt und gibt dann
 * das Produkt der Matrix und des Vektors als Ausgabe an die Konsole weiter und returned zum 
 * Matrixtestmenü.
 */
void matrixVectorMult() {
    Matrix2 A;
    Vektor2 v;
    std::string inputA;
    std::string inputV;
    std::string tmp;

    std::istringstream(getMatrixInput(inputA,tmp, "A")) >> A;
    std::cout << std::endl;
    std::istringstream(getVectorInput(inputV,tmp, "v")) >> v;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << A*v << std::endl;
    return;
}

/*
 * \brief Menüpunkt Exponential, berechnet aus gegebener Matrix deren Exponential.
 *
 * Diese Funktion fragt nach der Eingabe von einem Matrix2 Objekten und gibt dann
 * das Exponential der Matrix als Ausgabe an die Konsole weiter und returned zum 
 * Matrixtestmenü.
 */
void matrixExponential() {
    Matrix2 A;
    std::string inputA;
    std::string tmp;

    std::istringstream(getMatrixInput(inputA,tmp, "A")) >> A;

    std::cout << "\033[4;37m\033[1;37mErgebnis\033[0m\033[0m: " << std::endl << matrixExp(A) << std::endl;
    return;
}

/*
 * \pre Vektortestmenü, das durch Eingabe der Zahl zum gewünschten Test führt
 *
 * Diese Funktion schreibt das Vektortestmenü fürs testen aus. Durch eine valide Eingabe,
 * kann man zu Menüpunkten navigieren und deren Tests ausführen.
 */
void vectorTests() {
    while (true) {
        std::string choice;
        std::cout << "\033[1;37mWas wollen Sie testen?\033[0m" << std::endl
                << "0 - \033[3mZurück zum Hauptmenü\033[0m" << std::endl
                << "1 - \033[3mVektoraddition\033[0m" << std::endl
                << "2 - \033[3mSkalarprodukt\033[0m" << std::endl
                << "3 - \033[3mNormquadrat\033[0m" << std::endl;
            
        choice = getChoice(choice, 0, 3);

        switch(std::stoi(choice)) {
            case 0: 
                std::cout << std::endl;
                main();
                break;
            
            case 1: 
                vectorAddition();
                std::cout <<std::endl;
                break;
            
            case 2: 
                dotProduct();
                std::cout <<std::endl;
                break;
            
            case 3: 
                normSquared();
                std::cout <<std::endl;
                break;
            
            default: 
                std::cout <<std::endl;
                break;
            
        }
        choice = "";
    }
}

/*
 * \pre Matrixtestmenü, das durch Eingabe der Zahl zum gewünschten Test führt
 *
 * Diese Funktion schreibt das Matrixtestmenü fürs testen aus. Durch eine valide Eingabe,
 * kann man zu Menüpunkten navigieren und deren Tests ausführen.
 */
void matrixTests() {
    while (true) {
        std::string choice;
        std::cout << "\033[1;37mWas wollen Sie testen?\033[0m" << std::endl
                << "0 - \033[3mZurück zum Hauptmenü\033[0m" << std::endl
                << "1 - \033[3mMatrixaddition\033[0m" << std::endl
                << "2 - \033[3mMatrixmultiplikation\033[0m" << std::endl
                << "3 - \033[3mMatrix-Vektor Multiplikation\033[0m" << std::endl
                << "4 - \033[3mExponential\033[0m" << std::endl;
        
        choice = getChoice(choice, 0, 4);

        switch(std::stoi(choice)) {
            case 0: 
                std::cout << std::endl;
                main();
            
            case 1: 
                matrixAddition();
                break;
            
            case 2: 
                matrixMult();
                break;
            
            case 3: 
                matrixVectorMult();
                break;
            
            case 4: 
                matrixExponential();
                break;
            
            default: 
                break;
            
        } 
        choice = ""; 
    }  
}