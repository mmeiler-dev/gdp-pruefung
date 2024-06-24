#include "./mathLib.hpp"

/*
 * \brief Funktion zur Berechnung der Fakultät einer Zahl
 *
 * Diese Funktion ist eine rekursive Implementierung der Fakultätsfunktion,
 * welche bei der Eingabe 0, 1 zurückgibt und wenn n = 1 ist, n.
 * Wenn n nicht einer der beiden Zahlen entspricht wird der Basisfall durchgeführt,
 * welcher n mit der Fakultät n-1 multipliziert. Dies geht bis n = 1 wo dann
 * die Fakultät ausgegeben wird.
 *
 * @param n eine natürliche Zahl
 * @returns Fakultät von n
 */
double fac(int n) {
    if (n == 0) {
        return 1.0;
    }
    if (n == 1) {
        return n;
    }
    return n*fac(n-1);
}

Matrix2::Matrix2() = default;

Matrix2::Matrix2(double e00, double e01, double e10, double e11) : matrix{e00, e01, e10, e11} {};

/*
 * \brief Operator overloading vom ()-Operator, für den Zugriff auf die Elemente der Matrix2-Klasse.
 * 
 * Dieser overload nutzt die Formel 'colDim*row + col' (wobei colDim(Matrix2) = 2), um das richtige
 * Element der Matrix2 aus dem row-major Array zu bekommen. 
 *
 * @param row Zeile des Elements in der Matrix.
 * @param col Spalte des Elements in der Matrix. 
 * @returns Element von angegebener Zeile und Spalte
 */
double& Matrix2::operator()(size_t row, size_t col) {
    return matrix[2*row + col];
}

double Matrix2::operator()(size_t row, size_t col) const {
    return matrix[2*row + col];
}

/*
 * \brief Operator overloading vom +-Operator, welches die Summe von 2 Matrix2 Objekten berechnet.
 *
 * Dieser overload iteriert über die beiden Arrays der Matrix2-Objekte und addiert die
 * korrespondierenden Elemente, um dann am Ende diese einer neuen Matrix2 zuzuordnen,
 * welche die Summe der beiden darstellt.
 *
 * @param other Die andere Matrix, mit der die Matrix auf der linken Seite addiert wird.
 * @returns die elementenweise Summe der Matrizen
 */
Matrix2 Matrix2::operator+(const Matrix2& other) {
    Matrix2 a;
    for (int i = 0; i < 4; i++) {
        a.matrix[i] = matrix[i]+other.matrix[i];
    }
    return a;
}

/*
 * \brief Operator overloading vom *-Operator, welches das Produkt von 2 Matrix2 Objekten berechnet.
 *
 * Dieser overload ist eine hard gecodete Matrixmultiplikation, welche ein neues Matrix2 Objekt
 * als Produkt der beiden Matrizen ausgibt.
 *
 * @param other Die andere Matrix, mit der die linke Matrix multipliziert wird.
 * @returns das Produkt der Matrizen
 */
Matrix2 Matrix2::operator*(const Matrix2& other) {
    return Matrix2{
            matrix[0]*other.matrix[0]+matrix[1]*other.matrix[2],
            matrix[0]*other.matrix[1]+matrix[1]*other.matrix[3],
            matrix[2]*other.matrix[0]+matrix[3]*other.matrix[2],
            matrix[2]*other.matrix[1]+matrix[3]*other.matrix[3]
    };
}

/*
 * \brief Operator overloading vom *-Operator, welche das Produkt von einer Matrix und einem Vektor ausrechnet.
 *
 * Dieser overload bildet mit Hilfe von zwei hard gecodeten Skalarmultiplikationen ein neues Vektor2 Objekt,
 * welches das Produkt von Matrix und Vektor darstellt.
 *
 * @param other ein Vektor2
 * @returns die Matrixmultiplikation von Matrix und Vektor
 */
Vektor2 Matrix2::operator*(const Vektor2& other) {
    return Vektor2{matrix[0]*other(0)+matrix[1]*other(1), matrix[2]*other(0)+matrix[3]*other(1)};
}

/*
 * \brief Globaler operator overload vom *-Operator für die Klasse Matrix2 und einem double
 *
 * Dieser overload multipliziert elementweise das Matrix2 Objekt mit einer double Zahl und
 * gibt ein neues Matrix2 Objekt, welches das Produkt der beiden entspricht aus.
 *
 * @param num eine Zahl
 * @returns das elementweise Produkt aus Zahl und Matrix2 
 */
Matrix2 operator*(const Matrix2& A, const double& num) {
    return Matrix2{num*A(0,0), num*A(0,1), num*A(1,0), num*A(1,1)};
}

/*
 * \brief Funktion, um die Frobeniusnorm eines Matrix2 Objektes zu berechnen
 *
 * Diese Funktion berechnet die Norm des Matrix2 Objektes mit der Formel e00^2 + e01^2 + e10^2 + e11^2.
 *
 * @returns Norm der Matrix
 */
double Matrix2::normSquare() const {
    return matrix[0]*matrix[0]+matrix[1]*matrix[1]+matrix[2]*matrix[3]+matrix[3]*matrix[3];
}

/*
 * \brief Funktion, um den Ausdruck e^A zu berechnen
 *
 * Diese Funktion ist eine iterative Variante des exp(A)-Taylorpolynoms. 
 * Es werden immer weiter Terme zu der result-Matrix hinzuaddiert, bis 
 * das Produkt aus dem Inversen der Fakultät und der Norm der power-Matrix,
 * kleiner als die tolerance ist.
 *
 * @param A eine Matrix2
 * @returns Exponential von A
 */
Matrix2 matrixExp(Matrix2 A) {
    int k = 1;
    double tolerance = 0.00001;
    Matrix2 result = Matrix2{1, 0, 0, 1};
    Matrix2 power = Matrix2{1, 0, 0, 1};

    do {
        power = power * A;
        result = result + (power * (1.0 / fac(k)));
        k++;
    } while(1.0/fac(k) * power.normSquare() > tolerance);

    return result;
}


Vektor2::Vektor2() = default;

Vektor2::Vektor2(double e0, double e1) : vector{e0, e1} {};

/*
 * \brief Operator overloading vom ()-Operator für das Erhalten eines Elementes im Vektor2
 *
 * Dieser overload nutzt den index, um den Wert am Index des Arrays vector auszugeben.
 *
 * @param index eine unsigned int, welcher den Index eines Elements darstellt.
 * @returns Element mit dem Index, der angegeben wurde
 */
double& Vektor2::operator()(size_t index) {
    return vector[index];
}

double Vektor2::operator()(size_t index) const {
    return vector[index];
}

/*
 * \brief Operator overloading des +-Operator für die Klasse Vektor2 mit einem anderen Vektor2
 *  
 * Dieser overload berechnet die elementenweise Summe von zwei Vektor2 Objekten und gibt diese aus.
 * 
 * @param other das andere Vektor2 Objekt
 * @returns elementenweise Summe von zwei Vektor2
 */
Vektor2 Vektor2::operator+(const Vektor2& other) {
    return Vektor2{vector[0]+other.vector[0], vector[1]+other.vector[1]};
}

/*
 * \brief Operator overloading des *-Operator für zwei Vektor2 Objekte
 *
 * Dieser overload berechnet das Skalarprodukt zwischen zwei Vektor2 Objekten und gibt dieses aus.
 * 
 * @param other das andere Vektor2 Objekt
 * @returns Skalarprodukt von zwei Vektor2
 */
double Vektor2::operator*(const Vektor2& other) {
    return vector[0]*other.vector[0]+vector[1]*other.vector[1];
}

double Vektor2::operator*(const Vektor2& other) const {
    return vector[0]*other.vector[0]+vector[1]*other.vector[1];
}

/*
 * \brief Funktion, um das Quadrat der Vektornorm zu berechnen.
 *
 * Diese Funktion berechnet das Quadrat der Vektornorm (e0^2 + e1^2) 
 * mit dem overload des *-Operators. Dies ist im grundegenommen ein
 * Skalarprodukt vom Vektor2 Objekt mit sich selbst.
 *
 * @returns Quadrat der Vektornorm
 */
double Vektor2::normSquare() const {
    return *this * *this;
}

/*
 * \brief Globaler operator overload des <<-Operator für die Matrix2-Klasse zur Ausgabe der Matrixelemente
 *
 * Dieser overload schiebt die, Leertasten seperierten, Elemente eines Matrix2 Objektes in den ostream hinein,
 * damit diese in der Konsole ausgegeben werden können.
 *
 * @param A die Matrix, welche ausgegeben werden soll
 * @result die Ausgabe der Elemente
 */
std::ostream& operator<<(std::ostream& output, const Matrix2& A) {
    output << A(0,0) << " " << A(0,1) << std::endl << A(1,0) << " " << A(1,1) << std::endl;
    return output;
}

/*
 * \brief Globaler operator overload des <<-Operator für die Vektor2-Klasse zur Ausgabe der Vektorelemente
 *
 * Dieser overload schiebt die, Leertasten seperierten, Elemente eines Vektor2 Objektes in den ostream hinein,
 * damit diese in der Konsole ausgegeben werden können.
 *
 * @param v der Vektor, welcher ausgegeben werden soll
 * @result die Ausgabe der Elemente
 */
std::ostream& operator<<(std::ostream& output, const Vektor2& v) {
    output << v(0) << " " << v(1) << std::endl;
    return output;
}

/*
 * \brief Globaler operator overload des >>-Operator für die Matrix2-Klasse zum einlesen eines Stringstreams
 *
 * Einlese-overload für die Matrix2-Klasse, welcher erlaubt, dass ein Stringstream in ein Matrix2 Objekt
 * eingelesen werden kann. Ein String "1 2 3 4" wird durch den stream in 1, 2, 3, 4 aufgeteilt und 
 * iterativ in die jeweiligen Indezes des Matrix2 Objektes eingefügt.
 *
 * @pre Stringstream muss aus einem String der Form "a b c d", wobei a, b, c, d Zahlen sind, geformt werden 
 * @param A die Matrix, welche besetzt werden soll
 * @returns Eingabe der Matrix
 */
std::istream& operator>>(std::istream& input, Matrix2& A) {
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            input >> A(i, j);
        }
    }
    return input;
}

/*
 * \brief Globaler operator overload des >>-Operator für die Vektor2-Klasse zum einlesen eines Stringstreams
 *
 * Einlese-overload für die Vektor2-Klasse, welcher erlaubt, dass ein Stringstream in ein Vektor2 Objekt
 * eingelesen werden kann. Ein String "1 2" wird durch den stream in 1, 2 aufgeteilt und iterativ 
 * in die jeweiligen Indezes des Matrix2 Objektes eingefügt.
 *
 * @pre Stringstream muss aus einem String der Form "a b", wobei a, b Zahlen sind, geformt werden 
 * @param v der Vektor, welche besetzt werden soll
 * @returns Eingabe des Vektors
 */
std::istream& operator>>(std::istream& input, Vektor2& v) {
    for (size_t i = 0; i < 2; ++i) {
        input >> v(i);
    }
    return input;
}
