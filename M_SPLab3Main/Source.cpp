#include <iostream>
#include <Windows.h>

int main() 
{
    setlocale(0, "");

    std::string libName = "StringFunctionsDll.dll";
    HMODULE hDLL = LoadLibrary((LPCSTR)libName.c_str());  // загрузить библиотеку

    if (hDLL == NULL)
    {
        std::cout << "Не удалось загрузить библиотеку DLL!" << std::endl;
        exit(-1);
    }

    // получить указатели на экспортируемые функции из библиотеки
    int (*countChar)(const char*, char) = (int (*)(const char*, char))GetProcAddress(hDLL, "countChar");
    char (*mostFrequentChar)(const char*) = (char (*)(const char*))GetProcAddress(hDLL, "mostFrequentChar");

    if ((!countChar) && (!mostFrequentChar))
    {
        std::cout << "Не удалось получить указатели на функции библиотеки DLL!" << std::endl;
        exit(-1);
    }

    std::string text = "Пример текста для подсчета символов";
    char target = 'т';

    int charCount = countChar(text.c_str(), target);
    std::cout << "Символ '" << target << "' встречается " << charCount << " раз(а)." << std::endl;

    char mostFrequent = mostFrequentChar(text.c_str());
    std::cout << "Cамый часто встречающийся символ '" << mostFrequent << "'." << std::endl;

    FreeLibrary(hDLL);  // выгрузить библиотеку

    return 0;
}