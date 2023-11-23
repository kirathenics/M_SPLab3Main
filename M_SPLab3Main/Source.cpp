#include <iostream>
#include <Windows.h>

int main() 
{
    setlocale(0, "");

    std::string libName = "StringFunctionsDll.dll";
    HMODULE hDLL = LoadLibrary((LPCSTR)libName.c_str());  // ��������� ����������

    if (hDLL == NULL)
    {
        std::cout << "�� ������� ��������� ���������� DLL!" << std::endl;
        exit(-1);
    }

    // �������� ��������� �� �������������� ������� �� ����������
    int (*countChar)(const char*, char) = (int (*)(const char*, char))GetProcAddress(hDLL, "countChar");
    char (*mostFrequentChar)(const char*) = (char (*)(const char*))GetProcAddress(hDLL, "mostFrequentChar");

    if ((!countChar) && (!mostFrequentChar))
    {
        std::cout << "�� ������� �������� ��������� �� ������� ���������� DLL!" << std::endl;
        exit(-1);
    }

    std::string text = "������ ������ ��� �������� ��������";
    char target = '�';

    int charCount = countChar(text.c_str(), target);
    std::cout << "������ '" << target << "' ����������� " << charCount << " ���(�)." << std::endl;

    char mostFrequent = mostFrequentChar(text.c_str());
    std::cout << "C���� ����� ������������� ������ '" << mostFrequent << "'." << std::endl;

    FreeLibrary(hDLL);  // ��������� ����������

    return 0;
}