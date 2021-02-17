# include "Cell.h"
# include "Circuit.h"
using namespace std;

int main() {
    string path = "../test_files";
    string testFile1 = "e64.txt";
    Circuit circuit;
    circuit.loadCircuit(path + "/" + testFile1);
    // circuit.printCircuit();
    circuit.updateAllBoundingBoxes();
    // circuit.printBoundingBoxes();
    cout << circuit.getCost() << endl;
    circuit.annealingPlacement();

    return 0;
}