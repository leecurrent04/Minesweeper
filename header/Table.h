#ifndef TABLE_H
#define TABLE_H

#include "Common.h"
#include <iostream>
#include <vector>
#include <iomanip>

class Table 
{
public:
    Table(Pos size)
    : size(size.x, size.y), table(size.y, std::vector<std::string>(size.x, " ")) {}
    
    Table(Pos size, int value)
    : size(size.x, size.y), table_n(size.y, std::vector<int>(size.x, value)) {}

    void set(Pos position, const std::string& value);
    void setNum(Pos position, int value);
    int getNum(Pos position);
    void draw(const std::string& title = "") const;
    void drawNum() const;
    void clear(const std::string& value);
    int move(Pos& position, int event);

private:
    Pos size;

protected:
    std::vector<std::vector<std::string>> table;
    std::vector<std::vector<int>> table_n;
};

class List : protected Table
{
public:
    List(int size)
    :size(size), Table(Pos(2,size)) {}

    void append(const std::string& label = "");
    void set(int num, const std::string& value);
    void setLabel(int num, const std::string& label);
    void setLabel(const std::vector<std::string>& labels);
    void draw(const std::string& title = "") const;
    int move(int& num, int event);
    int moveDial(int& num, int& values, int& min, int& max, int event);

private:
    int size;
};

#endif 