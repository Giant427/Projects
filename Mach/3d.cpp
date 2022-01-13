#include <iostream>
#include <string>
using namespace std;

const string separator = "========================================";

const string volume_init = "Volume";
const string tsa_init = "T.S.A";
const string lsa_init = "L.S.A";
const string edges_init = "Total length of edges";

const string pi = "pi";
const string expo_square = " ^ 2 ";
const string expo_cube = " ^ 3 ";

const string type_cuboid = "cuboid";
const string type_cube = "cube";
const string type_cylinder = "cylinder";
const string type_hollow_cylinder = "hollow-cylinder";

string generateWhitespace(int whitespace_index) {
    string whitespace = " ";
    for (int i = 1; i < whitespace_index; i++) {
        whitespace = whitespace + " ";
    }
    return whitespace;
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

    volume = generateWhitespace(volume_init.length()) + " => ";
    volume = volume + to_string(Length) + " x ";
    volume = volume + to_string(Breadth) + " x ";
    volume = volume + to_string(Height);
    cout << volume << "\n";

    volume = generateWhitespace(volume_init.length()) + " => ";
    volume = volume + to_string(Length * Breadth * Height);
    cout << volume << "\n\n";

    // Total Surface Area

    tsa = tsa + " => 2(lb + bh + lh)";
    cout << tsa << "\n";
    
    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + "2((" + to_string(Length) + " x " + to_string(Breadth)+ ") + ";
    tsa = tsa + "(" + to_string(Breadth) + " x " + to_string(Height)+ ") + ";
    tsa = tsa + "(" + to_string(Length) + " x " + to_string(Height)+ "))";
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + "2(" + to_string(Length * Breadth) + " + ";
    tsa = tsa + to_string(Breadth * Height) + " + ";
    tsa = tsa + to_string(Length * Height) + ")";
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + "2(" + to_string((Length * Breadth) + (Breadth * Height) + (Length * Height)) + ")";
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + to_string(2 * ((Length * Breadth) + (Breadth * Height) + (Length * Height)));
    cout << tsa << "\n\n";

    // Lateral Surface Area

    lsa = lsa + " => 2(l + b)h";
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + "2(" + to_string(Length) + " + " + to_string(Breadth) + ")" + to_string(Height);
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + "2(" + to_string(Length + Breadth) + ")" + to_string(Height);
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + to_string(2 * (Length + Breadth)) + " x " + to_string(Height);
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + to_string((2 * (Length + Breadth)) * Height);
    cout << lsa << "\n\n";

    // Total length of edges

    edges = edges + " => 4(l + b + h)";
    cout << edges << "\n";

    edges = generateWhitespace(edges_init.length()) + " => ";
    edges = edges + "4(" + to_string(Length) + " + ";
    edges = edges + to_string(Breadth) + " + ";
    edges = edges + to_string(Height) + ")";
    cout << edges << "\n";

    edges = generateWhitespace(edges_init.length()) + " => ";
    edges = edges + "4(" + to_string(Length + Breadth + Height) + ")";
    cout << edges << "\n";

    edges = generateWhitespace(edges_init.length()) + " => ";
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

    volume = generateWhitespace(volume_init.length()) + " => ";
    volume = volume + to_string(Side) + expo_cube;
    cout << volume << "\n";

    volume = generateWhitespace(volume_init.length()) + " => ";
    volume = volume + to_string(pow(Side, 3));
    cout << volume << "\n\n";

    // Total Surface Area

    tsa = tsa + " => 6s" + expo_square;
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + "6 x " + to_string(Side) + expo_square;
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + "6 x " + to_string(pow(Side, 2));
    cout << tsa << "\n";

    tsa = generateWhitespace(tsa_init.length()) + " => ";
    tsa = tsa + to_string(6 * pow(Side, 2));
    cout << tsa << "\n\n";

    // Lateral Surface Area

    lsa = lsa + " => 4s" + expo_square;
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + "4 x " + to_string(Side) + expo_square;
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + "4 x " + to_string(pow(Side, 2));
    cout << lsa << "\n";

    lsa = generateWhitespace(lsa_init.length()) + " => ";
    lsa = lsa + to_string(4 * pow(Side, 2));
    cout << lsa << "\n\n";

    // Total length of edges

    edges = edges + " => 12s";
    cout << edges << "\n";

    edges = generateWhitespace(edges_init.length()) + " => ";
    edges = edges + "12 x " + to_string(Side);
    cout << edges << "\n";

    edges = generateWhitespace(edges_init.length()) + " => ";
    edges = edges + to_string(12 * Side);
    cout << edges << "\n";

    return;
}

int main (int argc, char *argv[]) {
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

    cout << "\n" << separator << "\n";

    return 0;
}