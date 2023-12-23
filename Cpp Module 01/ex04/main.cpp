#include <iostream>
#include <fstream>

std::string Replace_Word(std::string Buffer, std::string replace, size_t i, size_t len)
{
    std::string new_line;
    size_t index = 0;
    size_t index_replace = 0;
    while(index < i)
        new_line += Buffer[index++];
    index += len;
    while(replace[index_replace])
        new_line += replace[index_replace++];
    if (index < Buffer.size())
    {
        while(Buffer[index])
            new_line += Buffer[index++];
    }
    else
    {
        new_line += "\0";
    }
    return (new_line);
}

std::string File_Data(char **av, std::string word, std::string replace)
{
    std::fstream FileName;
    std::string Buffer;
    std::string Data;
    size_t  i;
    size_t index;

    FileName.open(av[1], std::ios::in);
    if (!FileName)
    {
        std::cout << "Error while reading from the file" << std::endl;
        exit(1);
    }
    while(getline(FileName, Buffer))
    {
        index = 0;
        while (!word.empty() && (i = Buffer.find(word, index)) < Buffer.size())
        {
            index = i + replace.size();
            Buffer = Replace_Word(Buffer, replace, i, word.size());
        }
        Data += Buffer + "\n";
    }
    FileName.close();
    return (Data);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Put 3 param (FileName, Word, ReplaceWord)" << std::endl;
        exit(1);
    }
    std::string FileData;
    std::string Buffer;
    std::fstream FileName;
    FileData = File_Data(av, av[2], av[3]);
    Buffer = (std::string) av[1];
    FileName.open(Buffer + ".replace", std::ios::out);
    if (!FileName)
    {
        std::cout << "Error while creating file" << std::endl;
        exit(1);
    }
    FileName << FileData;
    FileName.close();
    return (0);
}