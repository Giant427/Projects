#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

const string separator = "========================================";
const string whitespace = " ";

const string volume_init = "Volume";
const string tsa_init = "T.S.A";
const string lsa_init = "L.S.A";
const string csa_init = "C.S.A";
const string fsa_init = "F.S.A";
const string edges_init = "Total length of edges";

const string pi_symbol = "π";
const string expo_square = "²";
const string expo_cube = "³";

const string type_cuboid = "cuboid";
const string type_cube = "cube";
const string type_cylinder = "cylinder";
const string type_hollow_cylinder = "hollow-cylinder";

string generateDuplicates (string duplicate, int duplicate_index) {
    string duplicated = duplicate;
    for (int i = 1; i < duplicate_index; i++) {
        duplicated = duplicated + duplicate;
    }
    return duplicated;
}

void cuboid () {
    double Length = 0;
    double Breadth = 0;
    double Height = 0;
    string volume = volume_init;
    string tsa = tsa_init;
    string lsa = lsa_init;
    string edges = edges_init;

    cout << "Length(l): ";
    cin >> Length;
    cout << "Breadth(b): ";
    cin >> Breadth;
    cout << "Height(h): ";
    cin >> Height;
    cout << "\n";

    // Volume

    volume = volume + " => l x b x h";
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(Length) + " x ";
    volume = volume + to_string(Breadth) + " x ";
    volume = volume + to_string(Height);
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(Length * Breadth * Height);
    cout << volume << "\n\n";

    // Total Surface Area

    tsa = tsa + " => 2(lb + bh + lh)";
    cout << tsa << "\n";
    
    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2((" + to_string(Length) + " x " + to_string(Breadth)+ ") + ";
    tsa = tsa + "(" + to_string(Breadth) + " x " + to_string(Height)+ ") + ";
    tsa = tsa + "(" + to_string(Length) + " x " + to_string(Height)+ "))";
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2(" + to_string(Length * Breadth) + " + ";
    tsa = tsa + to_string(Breadth * Height) + " + ";
    tsa = tsa + to_string(Length * Height) + ")";
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2(" + to_string((Length * Breadth) + (Breadth * Height) + (Length * Height)) + ")";
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + to_string(2 * ((Length * Breadth) + (Breadth * Height) + (Length * Height)));
    cout << tsa << "\n\n";

    // Lateral Surface Area

    lsa = lsa + " => 2(l + b)h";
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + "2(" + to_string(Length) + " + " + to_string(Breadth) + ")" + to_string(Height);
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + "2(" + to_string(Length + Breadth) + ")" + to_string(Height);
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + to_string(2 * (Length + Breadth)) + " x " + to_string(Height);
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + to_string((2 * (Length + Breadth)) * Height);
    cout << lsa << "\n\n";

    // Total length of edges

    edges = edges + " => 4(l + b + h)";
    cout << edges << "\n";

    edges = generateDuplicates(whitespace, edges_init.length()) + " => ";
    edges = edges + "4(" + to_string(Length) + " + ";
    edges = edges + to_string(Breadth) + " + ";
    edges = edges + to_string(Height) + ")";
    cout << edges << "\n";

    edges = generateDuplicates(whitespace, edges_init.length()) + " => ";
    edges = edges + "4(" + to_string(Length + Breadth + Height) + ")";
    cout << edges << "\n";

    edges = generateDuplicates(whitespace, edges_init.length()) + " => ";
    edges = edges+ to_string(4 * (Length + Breadth + Height));
    cout << edges << "\n";

    return;
}

void cube () {
    double Side = 0;
    string volume = volume_init;
    string tsa = tsa_init;
    string lsa = lsa_init;
    string edges = edges_init;

    cout << "Side(s): ";
    cin >> Side;
    cout << "\n";

    // Volume

    volume = volume + " => s" + expo_cube;
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(Side) + expo_cube;
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(pow(Side, 3));
    cout << volume << "\n\n";

    // Total Surface Area

    tsa = tsa + " => 6s" + expo_square;
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "6 x " + to_string(Side) + expo_square;
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "6 x " + to_string(pow(Side, 2));
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + to_string(6 * pow(Side, 2));
    cout << tsa << "\n\n";

    // Lateral Surface Area

    lsa = lsa + " => 4s" + expo_square;
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + "4 x " + to_string(Side) + expo_square;
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + "4 x " + to_string(pow(Side, 2));
    cout << lsa << "\n";

    lsa = generateDuplicates(whitespace, lsa_init.length()) + " => ";
    lsa = lsa + to_string(4 * pow(Side, 2));
    cout << lsa << "\n\n";

    // Total length of edges

    edges = edges + " => 12s";
    cout << edges << "\n";

    edges = generateDuplicates(whitespace, edges_init.length()) + " => ";
    edges = edges + "12 x " + to_string(Side);
    cout << edges << "\n";

    edges = generateDuplicates(whitespace, edges_init.length()) + " => ";
    edges = edges + to_string(12 * Side);
    cout << edges << "\n";

    return;
}

void cylinder () {
    double Height = 0;
    double Radius = 0;
    double pi_0 = 3.14;
    double pi_1 = 22;
    double pi_2 = 7;
    string decimal_pi = "";
    string volume = volume_init;
    string tsa = tsa_init;
    string csa = csa_init;
    string fsa = fsa_init;

    cout << "Pi(" + pi_symbol + "): 22\n       --\n       7\n";
    cout << "Consider pi as 3.14 (y/n): ";
    cin >> decimal_pi;
    if (decimal_pi == "y") {
        pi_1 = 3.14;
        cout << "Pi(" << pi_symbol << "): " << to_string(pi_1) << "\n";
    }

    cout << "Height(h): ";
    cin >> Height;
    cout << "Radius(r): ";
    cin >> Radius;
    cout << "\n";

    // Volume

    volume = volume + " => " + pi_symbol + "r" + expo_square + "h";
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(pi_1) + " x " + to_string(Radius) + expo_square + " x " + to_string(Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = volume.find(to_string(pi_1));
        volume = volume + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(pi_1) + " x " + to_string(pow(Radius, 2)) + " x " + to_string(Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = volume.find(to_string(pi_1));
        volume = volume + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << volume << "\n";

    volume = generateDuplicates(whitespace, volume_init.length()) + " => ";
    volume = volume + to_string(pi_0 * pow(Radius, 2) * Height) + "\n";
    cout << volume << "\n";

    // Total Surface Area

    tsa = tsa + " => 2" + pi_symbol + "r(r + h)";
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2 x " + to_string(pi_1) + " x " + to_string(Radius) + "(" + to_string(Radius) + " + " + to_string(Height) + ")";
    if (pi_1 == 22) {
        size_t pi_denominator_pos = tsa.find(to_string(pi_1));
        tsa = tsa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2 x " + to_string(pi_1) + " x " + to_string(Radius) + "(" + to_string(Radius + Height) + ")";
    if (pi_1 == 22) {
        size_t pi_denominator_pos = tsa.find(to_string(pi_1));
        tsa = tsa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + "2 x " + to_string(pi_1) + " x " + to_string(Radius * (Radius + Height));
    if (pi_1 == 22) {
        size_t pi_denominator_pos = tsa.find(to_string(pi_1));
        tsa = tsa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + to_string(pi_1) + " x " + to_string(2 * Radius * (Radius + Height));
    if (pi_1 == 22) {
        size_t pi_denominator_pos = tsa.find(to_string(pi_1));
        tsa = tsa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << tsa << "\n";

    tsa = generateDuplicates(whitespace, tsa_init.length()) + " => ";
    tsa = tsa + to_string(2 * pi_0 * Radius * (Radius + Height));
    cout << tsa << "\n\n";

    // Curved Surface Area

    csa = csa + " => 2" + pi_symbol + "rh";
    cout << csa << "\n";

    csa = generateDuplicates(whitespace, csa_init.length()) + " => ";
    csa = csa + "2 x " + to_string(pi_1) + " x " + to_string(Radius) + " x " + to_string(Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = csa.find(to_string(pi_1));
        csa = csa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << csa << "\n";

    csa = generateDuplicates(whitespace, csa_init.length()) + " => ";
    csa = csa + "2 x " + to_string(pi_1) + " x " + to_string(Radius) + " x " + to_string(Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = csa.find(to_string(pi_1));
        csa = csa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << csa << "\n";

    csa = generateDuplicates(whitespace, csa_init.length()) + " => ";
    csa = csa + "2 x " + to_string(pi_1) + " x " + to_string(Radius * Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = csa.find(to_string(pi_1));
        csa = csa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << csa << "\n";

    csa = generateDuplicates(whitespace, csa_init.length()) + " => ";
    csa = csa + to_string(pi_1) + " x " + to_string(2 * Radius * Height);
    if (pi_1 == 22) {
        size_t pi_denominator_pos = csa.find(to_string(pi_1));
        csa = csa + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + generateDuplicates("-", to_string(pi_1).length()) + "\n" + generateDuplicates(whitespace, pi_denominator_pos) + to_string(pi_2);
    }
    cout << csa << "\n";

    csa = generateDuplicates(whitespace, csa_init.length()) + " => ";
    csa = csa + to_string(2 * pi_0 * Radius * Height);
    cout << csa << "\n";

    return;
}

int main (int argc, char *argv[]) {
    SetConsoleOutputCP(65001);
    string type_object = argv[1];

    cout << "\n" << separator << "\n\n";

    // cuboid
    if (type_object == type_cuboid) {
        cuboid();
    }

    // cube
    if (type_object == type_cube) {
        cube();
    }

    // cylinder
    if (type_object == type_cylinder) {
        cylinder();
    }

    cout << "\n" << separator << "\n";

    return 0;
}