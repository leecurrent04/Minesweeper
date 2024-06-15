#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <iomanip>

class Table {
public:
    Table(int x, int y)
    : x_size(x), y_size(y), table(y, std::vector<std::string>(x, " ")) {}
    
    Table(int x, int y, int value)
    : x_size(x), y_size(y), table_n(y, std::vector<int>(x, value)) {}

    void set(int col, int row, const std::string& value);
    void set(int col, int row, int value);

    void draw() const;
    void draw_n() const;
    void clear(const std::string& value);
    int RemainCells();
    int move(int& x, int& y, int event);

    std::vector<std::vector<int>> table_n;

private:
    int x_size;
    int y_size;
    std::vector<std::vector<std::string>> table;
};

#endif 