#include "../header/Table.h"
#include "../header/Table_Unicode.h"

void Table::set(Pos position, const std::string& value)
{
    int col = position.x;
    int row = position.y;

    if (row >= 0 && row < size.y && col >= 0 && col < size.x) {
        table[row][col] = value;
    }
}

void Table::setNum(Pos position, int value)
{
    int col = position.x;
    int row = position.y;

    if (row >= 0 && row < size.y && col >= 0 && col < size.x) {
        table_n[row][col] = value;
    }
}

int Table::getNum(Pos position)
{
    return this->table_n[position.y][position.x];
}

void Table::draw(const std::string& title) const {
    if(std::string("").compare(title)!=0)
        std::cout << "[ " << title << " ]" << std::endl << std::endl;

    // 상단 경계 그리기
    std::cout << top_left;
    for (int i = 0; i < size.x - 1; ++i) {
        std::cout << horizontal << horizontal << horizontal << top_intersect;
    }
    std::cout << horizontal << horizontal << horizontal << top_right << std::endl;

    // 테이블 내용 및 수직 경계 그리기
    for (int i = 0; i < size.y; ++i) {
        for (int j = 0; j < size.x; ++j) {
            std::cout << vertical << " " << table[i][j] << " ";
        }
        std::cout << vertical << std::endl;

        // 중간 경계 그리기
        if (i < size.y - 1) {
            std::cout << left_intersect;
            for (int j = 0; j < size.x - 1; ++j) {
                std::cout << horizontal << horizontal << horizontal << intersect;
            }
            std::cout << horizontal << horizontal << horizontal << right_intersect << std::endl;
        }
    }

    // 하단 경계 그리기
    std::cout << bottom_left;
    for (int i = 0; i < size.x - 1; ++i) {
        std::cout << horizontal << horizontal << horizontal << bottom_intersect;
    }
    std::cout << horizontal << horizontal << horizontal << bottom_right << std::endl;
}

void Table::drawNum() const {
    for(int j=0; j<size.y; j++)
    {
        for(int i=0; i<size.x; i++)
        {
            std::cout << this->table_n[j][i];
        }
        std::cout << std::endl;
    }
}

void Table::clear(const std::string& value)
{
    for(int j=0; j<size.y; j++)
    {
        for(int i=0; i<size.x; i++)
        {
            this->set(Pos(i,j), value);
        }
    }
}

int Table::move(Pos& position, int event)
{
    switch (event)
    {
    case 'a':
        if(position.x > 0) --position.x;
        this->set(position, "X");
        break;
    case 's':
        if(position.y < this->size.y-1) ++position.y;
        this->set(position, "X");
        break;
    case 'w':
        if(position.y > 0) --position.y;
        this->set(position, "X");
        break;
    case 'd':
        if(position.x < this->size.x-1) ++position.x;
        this->set(position, "X");
        break;
    default:
        return event;
    }
    return 0;
}

void List::append(const std::string& label)
{
}

void List::set(int num, const std::string& value)
{
    this->Table::set(Pos(0,num),value);
}

void List::setLabel(int num, const std::string& label)
{
    this->Table::set(Pos(1,num),label);
}

void List::setLabel(const std::vector<std::string>& labels)
{
    int num_labels = labels.size();
    int num_tables = this->table.size();
    int max = num_labels >= num_tables?num_tables:num_labels;
    for(int i=0; i<max; i++)
    {
        this->setLabel(i, labels[i]);
    }
}

void List::draw(const std::string& title) const {

    if(std::string("").compare(title)!=0)
        std::cout << "[ " << title << " ]" << std::endl << std::endl;

    // 상단 경계 그리기
    std::cout << top_left;
    std::cout << horizontal << horizontal << horizontal << top_right << std::endl;

    // 테이블 내용 및 수직 경계 그리기
    for (int i = 0; i < size; ++i) {
        std::cout << vertical << " " << this->table[i][0] << " ";
        std::cout << vertical << " " << this->table[i][1] << std::endl;

        // 중간 경계 그리기
        if (i < size - 1) {
            std::cout << left_intersect;
            std::cout << horizontal << horizontal << horizontal << right_intersect << std::endl;
        }
    }

    // 하단 경계 그리기
    std::cout << bottom_left;
    std::cout << horizontal << horizontal << horizontal << bottom_right << std::endl;
}

int List::move(int& num, int event)
{
    switch (event)
    {
    case 'w':
        if(num > 0) --num;
        this->set(num, "X");
        break;
    case 's':
        if(num < this->size-1) ++num;
        this->set(num, "X");
        break;
    default:
        return event;
    };
    return 0;
}

int List::moveDial(int& num, int& values, int& min, int& max, int event)
{
    switch(this->move(num, event))
    {
    case 'a':
        if(values > min) --values;
        break;
    case 'd':
        if(values < max) ++values;
        break;
    default:
        return event;
    }
    return 0;
}