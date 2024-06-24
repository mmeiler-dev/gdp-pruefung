#pragma once

#include "./utilities.hpp"

/*
 * \brief Datentyp zur Darstellung des mathematischen Objekt Vektor
 *
 * Die Vektor2 Klasse besteht aus einem Array der Größe 2
 * Sie besitzt einige Member-Funktionen, welche das rechnen mit ihr erleichtern
 * und den Zugriff auf die Elemente ermöglicht.
 *
 */
class Vektor2 {
    double vector[2];

public:
    Vektor2();
    Vektor2(double, double);

    double& operator()(size_t);
    double operator()(size_t) const;

    Vektor2 operator+(const Vektor2&);
    double operator*(const Vektor2&);
    double operator*(const Vektor2&) const;

    double normSquare() const;
};


/*
 * \brief Datentyp zur Darstellung des mathematischen Objektes Matrix
 * 
 * Die Matrix2 Klasse besteht aus einem Array der Größe 4
 * Sie besitzt einige Member-Funktions die Addition und Multiplikation durch Operator 
 * overloading, sowie den Zugriff auf die Elemente des Arrays ermöglichen.
 * Ihre Elemente sind in der row-major Form abgespeichert.
 * 
 */
class Matrix2 {
    double matrix[4];

public:
    Matrix2();
    Matrix2(double, double, double, double);

    double& operator()(size_t, size_t);
    double operator()(size_t, size_t) const;

    Matrix2 operator+(const Matrix2&);
    Matrix2 operator*(const Matrix2&);
    Vektor2 operator*(const Vektor2&);

    double normSquare() const;
};

Matrix2 operator*(const Matrix2&, const double&);

Matrix2 matrixExp(Matrix2);

std::ostream& operator<<(std::ostream&, const Vektor2&);
std::ostream& operator<<(std::ostream&, const Matrix2&);
std::istream& operator>>(std::istream&, Vektor2&);
std::istream& operator>>(std::istream&, Matrix2&);