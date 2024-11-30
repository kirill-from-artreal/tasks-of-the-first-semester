#include "Header.h"

double safe_input_double(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������: ������� ���������� �����\n";
        }
        else if (value <= 0) {
            std::cout << "������: �������� ������ ���� ������ 0\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}


int  task1(void) {
   
    double room_length      = safe_input_double("������� ����� ������� (�): ");            // ("Enter the length of the room (m): ");
    double room_width       = safe_input_double("������� ������ ������� (�): ");           // ("Enter the width of the room (m): ");
    double room_height      = safe_input_double("������� ������ ������� (�): ");           // ("Enter the height of the room (m): ");
    double wallpaper_length = safe_input_double("������� ����� ������ ����� (�): ");       // ("Enter the length of the wallpaper roll (m): ");
    double wallpaper_width  = safe_input_double("������� ������ ������ ����� (�): ");      // ("Enter the width of the wallpaper roll (m): ");

    double perimeter = 2 * (room_length + room_width);

    int stripes_per_roll = static_cast<int>(wallpaper_length / room_height);

    if (stripes_per_roll == 0) {
        std::cout << "����� ������� �������� ��� ������ �����" << std::endl;               // "The roll is too short for the height of the wall"
        return 1; 
    }

    int total_stripes_needed = static_cast<int>(std::ceil(perimeter / wallpaper_width));

    double last_stripe_width = perimeter - ((total_stripes_needed - 1) * wallpaper_width);

    bool last_stripe_cut = (last_stripe_width < wallpaper_width);

    int rolls_needed = static_cast<int>(std::ceil(static_cast<double>(total_stripes_needed) / stripes_per_roll));

    double total_wallpaper_used = total_stripes_needed * room_height;

    if (last_stripe_cut) {
        total_wallpaper_used -= (wallpaper_width - last_stripe_width) * room_height / wallpaper_width;
    }

    double total_wallpaper_available = rolls_needed * wallpaper_length;

    double leftover_wallpaper = total_wallpaper_available - total_wallpaper_used;

    double waste_percentage = (leftover_wallpaper / total_wallpaper_available) * 100;

    std::cout << "���������� �������: "     << rolls_needed       << std::endl;              // "It is necessary to roll: "
    std::cout << "������� ����� � ������: " << leftover_wallpaper << std::endl;              // "Remaining wallpaper in meters: "
    std::cout << "������� �������: "        << waste_percentage   << std::endl;              // "Percentage of remaining: "
    
    return 0;
}
