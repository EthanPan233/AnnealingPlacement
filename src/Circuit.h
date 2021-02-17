# pragma once
# include "Cell.h"
# include "geo.h"
# include <limits>
using namespace std;

class Circuit : public Cell {
public:
    Circuit() {}
    Circuit(const int& xxSize, const int& yySize, const int& numNets) 
        : xSize(xxSize), ySize(yySize), 
        cellIds(vector<vector<int>>(xxSize, vector<int>(yySize, -1))),
        nets(vector<vector<int>>(numNets)),
        boundingBoxes(vector<utils::BoxT<int>>(numNets)),
        wireLength(numeric_limits<double>::max()) { }

    void loadCircuit(const string& filename);
    void addCell(Cell& cell) { cells.push_back(cell); cellIds[cell.getX()][cell.getY()]=cell.cellId; }
    void addCell(Cell& cell, const int& x, const int& y) { 
        cell.moveCellTo(x, y);
        cells.push_back(cell);
        cellIds[x][y] = cell.cellId;
    }
 
    void addCell(const int& x, const int& y, const int& cellId) { 
        cells.push_back(Cell(x,y,cellId));
        cellIds[x][y] = cellId;
    }

    void moveCellTo(Cell& cell, const int& x, const int& y);
    void randomMove();
    void swapCells(Cell& cell1, Cell& cell2);
    void swapCells(const int& cellId1, const int& cellId2);
    
    // void randomInitCells();

    void updateAllBoundingBoxes(); // can update wirelength automatically
    void updateTargetBoundingBox(const vector<int>& netIds); // can update wire length automatically
    double updateWL(); // compute wire length of ALL nets from scratch, time consuming

    void annealingPlacement();

    // printers
    const void printBoundingBoxes();
    const void printCircuit();

    // getters
    const utils::PointT<int> getCellLocation(const int& cellId);
    const utils::PointT<int> getCellLocation(Cell& cell) { return cell.getLocation(); }
    const double getCost() { return wireLength; }

private:
    vector<Cell> cells;
    vector<vector<int>> nets; //nets[netId][cellId]
    vector<utils::BoxT<int>> boundingBoxes; // [netId]
    int xSize;
    int ySize;
    double wireLength;
    vector<vector<int>> cellIds;
};