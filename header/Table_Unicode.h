#ifndef TABLE_UNICODE_H
#define TABLE_UNICODE_H

#include <string>

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
    const std::string top_left = u8"┌";
    const std::string top_right = u8"┐";
    const std::string bottom_left = u8"└";
    const std::string bottom_right = u8"┘";
    const std::string horizontal = u8"─";
    const std::string vertical = u8"│";
    const std::string intersect = u8"┼";
    const std::string top_intersect = u8"┬";
    const std::string bottom_intersect = u8"┴";
    const std::string left_intersect = u8"├";
    const std::string right_intersect = u8"┤";
#endif

#endif