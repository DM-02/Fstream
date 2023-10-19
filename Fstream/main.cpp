//
//  main.cpp
//  Fstream
//
//  Created by Дмитрий Сергеевич on 19.10.2023.
//

#include <iostream>
#include <fstream>
#include <string>

void print_file(std::string path) {
    static std::ifstream in;
    in.open(path);
    
    
    std::cout << "-------------------------\n";
    if (in.is_open()) {
        char sym;
        while (in.get(sym))
            std::cout << sym;
        in.close();
    }
    std::cout << "--------------------\n";
    
}


bool into_file(std::string path, std::string str, int pos){
    static std::fstream out;
    out.open(path, std::ios::in);
    
    if(!out.is_open())
        return false;
        
    std::string file;
    std::string tmp;
    while (std::getline(out, str))
        file += tmp + '\n';
    out.close();
        
    out.open(path, std::ios::out);
    if(!out.is_open())
        return false;
    
    for(size_t i = 0; i < file.length(); ++i){
        //unsigned long long - size_t
        if(i == pos)
            out << str;
        out << file[i];
    }
    out.close();
    return true;
}

    





int main() {
    setlocale (LC_ALL, "ru");
    int n;
    std::string path = "file.txt";
    
    
    
    //Класс fstream
    /*std::fstream fs;
    fs.open(path, std::ios::app | std::ios::in);
    // Запись данных в файл.
    if (fs.is_open()) {
        std::cout << "Файл открыт.\n";
        std::cout << "Введите строку ->";
        std::string msg;
        std::getline(std::cin, msg);
        fs << msg << '\n';
        
        fs.seekg(0, std::ios::beg);
      
        //Чтение данных в файле
        std::cout << "Содержимое файла";
        char sym;
        while (fs.get(sym));
        std::cout << sym;
        
        
        fs.close();
    }
    else
        std::cout << "Ошибка открытия файла.\n";*/
    
    
    //Задание "Запись в середину файла"
    std::cout << "Изначальный файл:\n ";
    print_file(path);
    std::cout << "Введите строку -> ";
    std::string str;
    std::getline(std::cin, str);
    std::cout << "Введите позицию ->";
    std::cin >> n;
    if (into_file( path,str, n)) {
        std::cout << "Запись вставлена. Итоговый файл:\n";
        print_file(path);
        std::cout << std::endl;
    }
    std::cout << "Ошибка";
    
    //Задача 1. Чтение даты из файла
    std::cout << "Задача 1.\nСодержимое файла: ";
    const char date_path[] = "date.txt";
    print_file(date_path);
    
    
    std::ifstream in;
    in.open(date_path);
    if (in.is_open()) {
        std::string date;
        in >> date;
        in.close();
        
        size_t m_index = date.find('.') + 1;
        size_t y_index = date.rfind('.') + 1;
        
        
        int day = std::stoi(date);
        int month = std::stoi(date.substr(m_index));
        int year = std::stoi(date.substr(y_index));
        
        std::cout << "День: " << day << std::endl;
        std::cout << "Месяц: " << month << std::endl;
        std::cout << "Год: " << year << std::endl;
        
        
        
        
        
        
    }
    
    
    
    
    return 0;
}
