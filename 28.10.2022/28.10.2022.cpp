#include <iostream>
#include <sstream>
#include <tchar.h>
#include <string>

#include <memory>

//#define _UNICODE

using namespace std;

int main()
{
    wstring test = _TEXT("test1 test2 2tset 1tset");
    wcout << test << endl;

    // task 1
    {
        for (auto i = test.begin(); i != test.end(); i++)
            if (*i == ' ') *i = '\t';
        wcout << test << endl << endl;
    }

    //task 2
    {
        unsigned int nums = 0;
        unsigned int letts = 0;
        unsigned int others = 0;

        for (auto i = test.begin(); i != test.end(); i++)
            if (*i >= '0' && *i <= '9') ++nums;
            else if (*i >= 'a' && *i <= 'z' || *i >= 'A' && *i <= 'Z') ++letts;
            else ++others;

        wcout << _TEXT("Nums: ") << nums << endl;
        wcout << _TEXT("Letts: ") << letts << endl;
        wcout << _TEXT("Others: ") << others << endl;
        wcout << endl;
    }

    //task 3
    {
        wstringstream m_stream(test);
        istream_iterator<wstring, wchar_t> it(m_stream);
        wcout << "Words: " << distance(it, istream_iterator<wstring, wchar_t>()) << endl << endl;
    }

    //task 5
    {
        bool palind = true;
        for (size_t i = 0; i < test.size() / 2; i++)
            if (test[i] != test[test.size() - i - 1])
            {
                palind = false;
                break;
            }

        wcout  << "This is " << (palind ? "palindrome" : "not palindrome") << endl << endl;
    }

    //task 6
    {
        size_t ind;

        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> ind;

                if (!wcin.good())
                {
                    wcin.clear();
                    wcin.ignore(32767, '\n');
                }

                else break;
            }

        } while (ind >= test.size());

        test.erase(test.begin() + ind);
        wcout << test << endl;
    }

    //task 7
    {
        wchar_t ch;

        while (true)
        {
            wcout << "Enter char: ";
            wcin >> ch;

            if (!wcin.good())
            {
                wcin.clear();
                wcin.ignore(32767, '\n');
            }

            else break;
        }

        auto i = test.begin();
        if (*i == ch) test.erase(i);

        while (i != test.end())
        {
            if (*i == ch) test.erase(i--);
            else ++i;
        }

        wcout << test << endl;
    }

    //task 8 
    {
        size_t ind;

        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> ind;

                if (!wcin.good())
                {
                    wcin.clear();
                    wcin.ignore(32767, '\n');
                }

                else break;
            }

        } while (ind >= test.size());

        wchar_t ch;

        while (true)
        {
            wcout << "Enter char: ";
            wcin >> ch;

            if (!wcin.good())
            {
                wcin.clear();
                wcin.ignore(32767, '\n');
            }

            else break;
        }

        test.insert(test.begin() + ind, ch);
        wcout << test << endl;
    }
}