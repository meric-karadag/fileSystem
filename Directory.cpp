#include "Directory.h"

File Directory::getFile(int index) const
{
	/* TODO */
    // Check if index is valid
    // Complete
    if(index > static_cast<int>(files.size())-1 || index < 0)
    {
        return File();
    }
    else
    {
        return files[index];
    }
}

size_t Directory::directorySize() const
{
	/* TODO */
    // Complete
    size_t total_size = 0;
    int num_files = static_cast<int>(files.size());
    if (num_files == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 0; i < num_files; i++)
        {
            total_size += static_cast<int>(files[i].fileSize());
        }
        return total_size;
    }
}

bool Directory::isEmpty() const
{
	/* TODO */
    // Complete
    return files.empty();
}

size_t Directory::numFiles() const
{
	/* TODO */
    // Complete
    return files.size();
}

void Directory::newFile(const File &file)
{
	/* TODO */
    // Complete
    files.push_back(file);
}

void Directory::removeFile(int index)
{
	/* TODO */
    // Complete
    // Check if index is valid
    if(!(index > static_cast<int>(files.size())-1 || index < 0))
    {
        files.erase(files.begin()+index);
    }
}

void Directory::removeFile(File &file)
{
	/* TODO */
    // Complete
    // Finds and removes the first occurrence of file, if not find does nothing
    for(int i = 0; i<static_cast<int>(files.size()); i++)
    {
        if(files[i]==file)
        {
            removeFile(i);
            break;
        }
    }
}

void Directory::removeBiggestFile()
{
    /* TODO */
    int max_size = 0;
    int remove_index = 0;
    for(int i = 0; i < static_cast<int>(files.size()); i++)
    {
        if(static_cast<int>(files[i].fileSize()) > max_size)
        {
            max_size = static_cast<int>(files[i].fileSize());
            remove_index = i;
        }
    }
    files.erase(files.begin()+remove_index);
}
