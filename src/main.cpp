# include "Cell.h"
# include "Circuit.h"
# include <filesystem>
using namespace std;

int main(int argc, char *argv[]) {
    string path = "../test_files";
    string testFile = argv[1] + string(".txt");

    cout << "Start doing placement on " << testFile << endl;

    Circuit circuit;
    circuit.loadCircuit(path + "/" + testFile);
    // circuit.printCircuit();
    circuit.updateAllBoundingBoxes();
    // circuit.printBoundingBoxes();
    cout << circuit.getCost() << endl;
    circuit.annealingPlacement();

    return 0;
}