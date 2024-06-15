#include "../header/Table.h"

void Table::set(int col, int row, const std::string& value)
{
    if (row >= 0 && row < y_size && col >= 0 && col < x_size) {
        table[row][col] = value;
    }
}

void Table::set(int col, int row, int value)
{
    //if (row >= 0 && row < n && col >= 0 && col < n) {
    if (row >= 0 && row < y_size && col >= 0 && col < x_size) {
        table_n[row][col] = value;
    }
}

void Table::draw() const {
    // 유니코드 문자를 사용하여 테이블 경계 그리기
    #ifdef _WIN32
        const std::string top_left = "+";
        const std::string top_right = "+";
        const std::string bottom_left = "+";
        const std::string bottom_right = "+";
        const std::string horizontal = "-";
        const std::string vertical = "|";
        const std::string intersect = "+";
        const std::string top_intersect = "+";
        const std::string bottom_intersect = "+";
        const std::string left_intersect = "+";
        const std::string right_intersect = "+";
    #elif defined(__linux__)
    #endif

    // 상단 경계 그리기
    std::cout << top_left;
    for (int i = 0; i < x_size - 1; ++i) {
        std::cout << horizontal << horizontal << horizontal << top_intersect;
    }
    std::cout << horizontal << horizontal << horizontal << top_right << std::endl;

    // 테이블 내용 및 수직 경계 그리기
    for (int i = 0; i < y_size; ++i) {
        for (int j = 0; j < x_size; ++j) {
            std::cout << vertical << " " << table[i][j] << " ";
        }
        std::cout << vertical << std::endl;

        // 중간 경계 그리기
        if (i < y_size - 1) {
            std::cout << left_intersect;
            for (int j = 0; j < x_size - 1; ++j) {
                std::cout << horizontal << horizontal << horizontal << intersect;
            }
            std::cout << horizontal << horizontal << horizontal << right_intersect << std::endl;
        }
    }

    // 하단 경계 그리기
    std::cout << bottom_left;
    for (int i = 0; i < x_size - 1; ++i) {
        std::cout << horizontal << horizontal << horizontal << bottom_intersect;
    }
    std::cout << horizontal << horizontal << horizontal << bottom_right << std::endl;
}

void Table::draw_n() const {
    for(int j=0; j<y_size; j++)
    {
        for(int i=0; i<x_size; i++)
        {
            std::cout << this->table_n[j][i];
        }
        std::cout << std::endl;
    }
}

void Table::clear(const std::string& value)
{
    for(int j=0; j<y_size; j++)
    {
        for(int i=0; i<x_size; i++)
        {
            this->set(i,j, value);
        }
    }
}

int Table::RemainCells()
{
    int sum=0;
    for(int j=0; j<y_size; j++)
    {
        for(int i=0; i<x_size; i++)
        {
            if(this->table_n[j][i]) sum++;
        }
    }
    return (x_size*y_size-sum);
}
