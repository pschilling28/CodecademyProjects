#include <iostream>
#include <vector>
#include "functions.hpp"


void intro_screen() {
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                           W   W   AAA   N   N  N   N   AAA                                  |\n";
    std::cout << "|                           W   W  A   A  NN  N  NN  N  A   A                                 |\n";
    std::cout << "|                           W   W  A   A  N N N  N N N  A   A                                 |\n";
    std::cout << "|                           W W W  AAAAA  N  NN  N  NN  AAAAA                                 |\n";
    std::cout << "|                           WW WW  A   A  N   N  N   N  A   A                                 |\n";
    std::cout << "|                           WW WW  A   A  N   N  N   N  A   A                                 |\n";
    std::cout << "|                           W   W  A   A  N   N  N   N  A   A                                 |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                    W   W  RRRR   EEEEE   SSS   TTTTT  L      EEEEE   ???                    |\n";
    std::cout << "|                    W   W  R   R  E      S   S    T    L      E      ?   ?                   |\n";
    std::cout << "|                    W   W  R   R  E      S        T    L      E          ?                   |\n";
    std::cout << "|                    W W W  RRRR   EEEEE   SSS     T    L      EEEEE   ???                    |\n";
    std::cout << "|                    WW WW  R R    E          S    T    L      E        ?                     |\n";
    std::cout << "|                    WW WW  R  R   E      S   S    T    L      E                              |\n";
    std::cout << "|                    W   W  R   R  EEEEE   SSS     T    LLLLL  EEEEE    ?                     |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                           A HIGH SCHOOL-STYLE WRESTLING SIMULATION                          |\n";
    std::cout << "|                                    PRESS ENTER TO CONTINUE                                  |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cout << "|                                                                                             |\n";
    std::cin.ignore();
}

class Wrestler {
    public:
        std::string name, style, background;
        int weight_class, agility, strength, stamina, technique;
        std::vector<std::string> technique_list;
};

void coach_intro() {
    std::cout << "???: \"Welcome to the first day of practice, 9th-graders. My name is Pat. You can call me      \n";
    std::cout << "\'COACH\'\".                                                                                   \n";
    std::cout << "\n";
    std::cout << "                                                                        PRESS ENTER TO CONTINUE\n";
    std::cin.ignore();
    std::cout << "COACH: \"Wrestling is a grueling sport. And though we will have fun, we will also work very    \n";
    std::cout << "hard every practice to build your agility, strength, stamina, and technique.\"                 \n";
    std::cout << "\n";
    std::cout << "                                                                        PRESS ENTER TO CONTINUE\n";
    std::cin.ignore();
    std::cout << "COACH: \"First, I need to know more about my new squad! You there: tell us about yourself.\"   \n";
    std::cout << "\n";
    std::cout << "                                                                        PRESS ENTER TO CONTINUE\n";
    std::cin.ignore();

}

void create_wrestler() {
    std::string player_name;
    char name_choice;
    char weight_choice;
    int weight_class;
    std::cout << "???: \"... Well, my name is...\"\n";
    std::cout << "                                                              TYPE YOUR NAME, FOLLOWED BY ENTER\n";
    std::cin >> player_name;
    while (name_choice != 'Y') {
        std::cout << "COACH: \"" << player_name << ", is that right?\"\n";
        std::cout << "                                                             TYPE 'Y' OR 'N', FOLLOWED BY ENTER\n";
        std::cin >> name_choice;
        if (name_choice == 'N') {
            std::cout << "COACH: \"Oh, sorry. Cauliflower ear must be messing with my hearing. What is your name?\"\n";
            std::cout << "                                                              TYPE YOUR NAME, FOLLOWED BY ENTER\n";
            std::cin >> player_name;
        } else if (name_choice == 'Y') {
            break;
        } else {
            std::cout << "                                      INVALID CHOICE. TYPE EITHER 'Y' OR 'N', FOLLOWED BY ENTER\n";
        }
    }
    std::cout << "COACH: \"Alright, " << player_name << ", in what weight class do you plan to wrestle? In case  \n";
    std::cout << "you didn't know, there are fourteen weight classes this season. They are as follows in pounds: \n";
    std::cout << "106, 113, 120, 126, 132, 138, 145, 152, 160, 170, 182, 195, 220, 285.                          \n";
    std::cout << "                                                                                               \n";
    std::cout << player_name << ": \"I think I can make...\"\n";
    std::cout << "                                                     CHOOSE YOUR WEIGHT CLASS, THEN PRESS ENTER\n";
    std::cin >> weight_class;
    while (weight_class == 106 || weight_class == 113 || weight_class == 120 || weight_class == 126 || weight_class == 132 || weight_class == 138 || weight_class == 145 || weight_class == 152 || weight_class == 160 || weight_class == 170 || weight_class == 182 || weight_class == 195 || weight_class == 220 || weight_class == 285) {
        while (weight_choice != 'Y') {
            std::cout << "COACH: \"" << weight_class << ", looks like you could make that. Are you sure\"?\n";
            std::cout << "                                                             TYPE 'Y' OR 'N', FOLLOWED BY ENTER\n";
            std::cin >> weight_choice;
            if (weight_choice == 'N') {
                std::cout << "COACH: \"Speak up! What weight class? 106, 113, 120, 126, 132, 138, 145, 152, 160, \n";
                std::cout << "170, 182, 195, 220, or 285?\"\n";
                std::cout << "                                                              TYPE YOUR NAME, FOLLOWED BY ENTER\n";
                std::cin >> player_name;
            } else if (weight_choice == 'Y') {
                break;
            } else {
                std::cout << "                                      INVALID CHOICE. TYPE EITHER 'Y' OR 'N', FOLLOWED BY ENTER\n";
            }
        }
    }
    //switch (weight_class)
    //{
    //case 106:
        //std::cout << "COACH: \"We've got a "
        //break;
    
    //default:
        //break;
    //}
}