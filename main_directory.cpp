#ifndef DIRECTORY_MAIN_H
#define DIRECTORY_MAIN_H

#include "Node.h"
#include "Block.h"
#include "LinkedList.h"
#include "File.h"
#include "Directory.h"

int main()
{
	// You can test your implementations here
    std::cout << std::boolalpha;
    File myFile = File();
    Block block1("Hello");
    Block block2("World");
    //std::cout << "Is file empty in the beginning? " << myFile.isEmpty() << '\n';
    myFile.newBlock(block1);
    myFile.newBlock(block2);
    myFile.newBlock(block1);
    //myFile.removeBlock(0);
    myFile.mergeBlocks(0,3);
    myFile.printContents();
    std::cout << myFile.numBlocks() << '\n';
    //std::cout << " Is file empty in the end " << myFile.isEmpty() << '\n';
    //Block retrieval = myFile.getBlock(-1);
    //std::cout << "Testing getBlock :" <<  retrieval;

    File comparison = File();
    comparison.newBlock(block1);
    comparison.newBlock(block2);
    comparison.newBlock(block1);
    comparison.newBlock(block2);
    comparison.printContents();
    std::cout << "Are myFile and comparison equal: "<< (myFile == comparison) << '\n';

    Directory myDirectory = Directory();
    std::cout << "Is directory empty in the beginning? " << myDirectory.isEmpty() << '\n';
    myDirectory.newFile(myFile);
    myDirectory.newFile(comparison);

    std::cout << "Directory size: " << myDirectory.directorySize()<<'\n';
    std::cout << "Number of files in directory: " << myDirectory.numFiles() << '\n';

    //File retrieveFile = myDirectory.getFile(2);
    //retrieveFile.printContents();

    // myDirectory.removeFile(2);
    File emptyFile = File();
    myDirectory.removeFile(emptyFile);
    std::cout << myDirectory.numFiles();

    myDirectory.removeBiggestFile();
    myDirectory.getFile(0).printContents();

    //std::cout << "Is directory empty after insertion " << myDirectory.isEmpty() << '\n';
    return 0;
}

#endif //DIRECTORY_MAIN_H
