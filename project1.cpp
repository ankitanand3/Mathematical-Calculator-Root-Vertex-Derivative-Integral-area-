// ANKIT ANAND


#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Quadratic {

private:
    float a;
    float b;
    float c;
    friend string Overload(Quadratic);

public:
    Quadratic(float a2 = 0, float b2 = 0, float c2 = 0);
    ~Quadratic(); // Destructor
    float h;
    float k;
    float x1;
    float x2;
    float discriminant;
    float realPart;
    float imaginaryPart;
    string h_to_string;
    string k_to_string;
    string print_string_k_h;
    string x1_to_string;
    string x2_to_string;
    string real_Part_to_string;
    string imaginary_Part_to_string;
    string x1_x2_print;
    string real_imaginary_print;
    int two_a;
    int b_to_int;
    string two_a_to_string;
    string b_to_string;
    string derivative_print;
    float x_sum;
    float y_sum;
    float substract_x_y;
    string output;

    string print(string equation);
    string vertex();
    string roots();
    string derivative();
    float integral(float x, float y);
    string print();
    Quadratic larger_area(Quadratic, Quadratic);

    Quadratic operator+(Quadratic T) { // Overloading function
        Quadratic R;
        R.a = a + T.a; // adding a of both the equations
        R.b = b + T.b; // adding b of both the equations
        R.c = c + T.c; // adding c of both the equations
        return R;
    }
};

Quadratic::Quadratic(float a2, float b2, float c2) {
    a = a2;
    b = b2;
    c = c2;
}

Quadratic::~Quadratic() {} // Showing destructor call


string Quadratic::print() { // Creating a funcion to print equation
    int a_to_int = int(a);
    int b_to_int = int(b);
    int c_to_int = int(c);
    if (a_to_int < 0 && b_to_int < 0 && c_to_int < 0) { // If a < 0 and b < 0 and c < 0
        output = to_string(a_to_int) + "x^2" + to_string(b_to_int) + "x" + to_string(c_to_int);
        return output;
    }

    else if (a_to_int < 0 && b_to_int > 0 && c_to_int > 0) { // If a < 0 and b > 0 and c > 0
        output = to_string(a_to_int) + "x^2" + "+" + to_string(b_to_int) + "x" + "+" + to_string(c_to_int);
        return output;
    }

    else if (a_to_int < 0 && b_to_int < 0 && c_to_int > 0) { // If a < 0 and b < 0 and c > 0
        output = to_string(a_to_int) + "x^2" + to_string(b_to_int) + "x" + "+" + to_string(c_to_int);
        return output;
    }

    else if (a_to_int > 0 && b_to_int > 0 && c_to_int < 0) { // If a > 0 and b > 0 and c < 0
        output = to_string(a_to_int) + "x^2" + "+" + to_string(b_to_int) + "x" + to_string(c_to_int);
        return output;
    }
    else if (a_to_int > 0 && b_to_int < 0 && c_to_int < 0) { // If a > 0 and b < 0 and c < 0
        output = to_string(a_to_int) + "x^2" + to_string(b_to_int) + "x" + to_string(c_to_int);
        return output;
    }

    else if (a_to_int > 0 && b_to_int < 0 && c_to_int > 0) { // If a > 0 and b < 0 and c > 0
        output = to_string(a_to_int) + "x^2" + to_string(b_to_int) + "x" + "+" + to_string(c_to_int);
        return output;
    }
    else { // If a > 0 and b > 0 and c > 0
        output = to_string(a_to_int) + "x^2" + "+" + to_string(b_to_int) + "x" + "+" + to_string(c_to_int);
        return output;
    }


}


// Creating function roots to find the roots of Quadratic
string Quadratic::roots() {
    discriminant = b * b - 4 * a * c; // Getting discriminant of the equation
    if (discriminant > 0) { // Checking if discriminant is positive
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        x1_to_string = to_string(x1);
        x2_to_string = to_string(x2);
        x1_x2_print = x1_to_string + "0i" + ", " + x2_to_string + "+0i";
        return x1_x2_print;


    }

    else if (discriminant == 0) { // Checking if discriminant is equal to zero
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x1_to_string = to_string(x1);
        return x1_to_string;

    }

    else {
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        real_Part_to_string = to_string(realPart);
        imaginary_Part_to_string = to_string(imaginaryPart);
        real_imaginary_print =
            real_Part_to_string + "+" + imaginary_Part_to_string + "i" + ", " +
            real_Part_to_string + "-" + imaginary_Part_to_string + "i";


        return real_imaginary_print;
    }
}

string Quadratic::vertex() { // Creating function vertex to find the vertex of Quadratic
    h = (-b / (2 * a)); // Finding h
    h_to_string = to_string(h); // Converting h to string
    k = (a * (h * h) + (b * h) + c);// Finding k
    k_to_string = to_string(k); // Converting k to string
    print_string_k_h = h_to_string + ", " + k_to_string;
    return print_string_k_h;
}

string Quadratic::derivative() { // Creating function derivative to find the derivative of Quadratic
    two_a = 2 * a; // Getting 2*a
    two_a_to_string = to_string(two_a); // Converting it to string
    b_to_int = (int)b; // Storing b value as int in b_to_int
    b_to_string = to_string(b_to_int); // Converting int b to string
    derivative_print = two_a_to_string + "x" + b_to_string;
    return derivative_print;
}


float Quadratic::integral(float x, float y) { // Creating function integral to find the integral of Quadratic
    x_sum = ((a * (x * x * x)) / 3) + ((b * (x * x)) / 2) + (c * x);
    y_sum = ((a * (y * y * y)) / 3) + ((b * (y * y)) / 2) + (c * y);
    substract_x_y = y_sum - x_sum;
    return substract_x_y;
}

string Overload(Quadratic R) { // Creating function Overload to print two added equations
    int R_a_to_int = (int)R.a; // Converting a to integer
    int R_b_to_int = (int)R.b; // Converting b to integer
    int R_c_to_int = (int)R.c; // Converting c to integer
    string output; // Creating a string variable to store output equation

    if (R_a_to_int < 0 && R_b_to_int < 0 && R_c_to_int < 0) { // If a < 0 and b < 0 and c < 0
        output = to_string(R_a_to_int) + "x^2" + to_string(R_b_to_int) + "x" + to_string(R_c_to_int);
        return output;
    }

    else if (R_a_to_int < 0 && R_b_to_int > 0 && R_c_to_int > 0) { // If a < 0 and b > 0 and c > 0
        output = to_string(R_a_to_int) + "x^2" + "+" + to_string(R_b_to_int) + "x" + "+" + to_string(R_c_to_int);
        return output;
    }

    else if (R_a_to_int < 0 && R_b_to_int < 0 && R_c_to_int > 0) { // If a < 0 and b < 0 and c > 0
        output = to_string(R_a_to_int) + "x^2" + to_string(R_b_to_int) + "x" + "+" + to_string(R_c_to_int);
        return output;
    }

    else if (R_a_to_int > 0 && R_b_to_int > 0 && R_c_to_int < 0) { // If a > 0 and b > 0 and c < 0
        output = to_string(R_a_to_int) + "x^2" + "+" + to_string(R_b_to_int) + "x" + to_string(R_c_to_int);
        return output;
    }
    else if (R_a_to_int > 0 && R_b_to_int < 0 && R_c_to_int < 0) { // If a > 0 and b < 0 and c < 0
        output = to_string(R_a_to_int) + "x^2" + to_string(R_b_to_int) + "x" + to_string(R_c_to_int);
        return output;
    }

    else if (R_a_to_int > 0 && R_b_to_int < 0 && R_c_to_int > 0) { // If a > 0 and b < 0 and c > 0
        output = to_string(R_a_to_int) + "x^2" + to_string(R_b_to_int) + "x" + "+" + to_string(R_c_to_int);
        return output;
    }
    else { // If a > 0 and b > 0 and c > 0
        output = to_string(R_a_to_int) + "x^2" + "+" + to_string(R_b_to_int) + "x" + "+" + to_string(R_c_to_int);
        return output;
    }

}


Quadratic larger_area(Quadratic A, Quadratic B, float x, float y) { // Creating function larger_area to compare area two equations
    float integral_1 = A.integral(x, y); // Area of first equation
    float integral_2 = B.integral(x, y); // Area of second equation
    if (integral_1 > integral_2)
    {
        cout << integral_1 << endl;
        return A;
    }
    else
    {
        cout << integral_2 << endl;
        return B;
    }
}


int main() {
    Quadratic P(3, -7, 5);
    Quadratic Q(1, 8, -3);
    cout << P.print() << endl;
    cout << "P roots: " << P.roots() << endl;
    cout << "Q roots: " << Q.roots() << endl;
    cout << "P vertex: " << P.vertex() << endl;
    cout << "P derivative: " << P.derivative() << endl;
    cout << "P integral: " << P.integral(1, 4) << endl;
    cout << "Overload: " << Overload(P + Q) << endl;
    larger_area(P, Q, 1, 4);

    return 0;
}