#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <iomanip>

class Table 
{
public:
    Table(int x, int y)
    : x_size(x), y_size(y), table(y, std::vector<std::string>(x, " ")) {}
    
    Table(int x, int y, int value)
    : x_size(x), y_size(y), table_n(y, std::vector<int>(x, value)) {}

    void set(int col, int row, const std::string& value);
    void setNum(int col, int row, int value);

    void draw() const;
    void drawNum() const;
    void clear(const std::string& value);
    int move(int& x, int& y, int event);
    int getNum(int x, int y);

private:
    int x_size;
    int y_size;

protected:
    std::vector<std::vector<std::string>> table;
    std::vector<std::vector<int>> table_n;
};

class List : protected Table
{
public:
    List(int size)
    :size(size), Table(2,size) {}

    void append(const char* []);

private:
    int size;
};

#endif 