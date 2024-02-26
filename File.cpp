#include "File.h"

Block File::getBlock(int index) const
{
	/* TODO */
    // Complete
    // Check if index is in bounds
    if(index > blocks.getSize()-1 || index < 0)
    {
        return Block();
    }
    // else return the corresponding block
    else
    {
        return blocks.getNodeAtIndex(index)->data;
    }
}

size_t File::fileSize() const
{
	/* TODO */
    // Complete
    // Check if file is empty
    size_t total_size = 0;
    int block_size = blocks.getSize();
    if(block_size == 0)
    {
        return 0;
    }
    else
    {
        Node<Block> * block_ptr = blocks.getFirstNode();
        for(int i = 0; i < block_size; i++)
        {
            total_size += block_ptr->data.getSize();
            block_ptr = block_ptr->next;
        }
        return total_size;
    }
}

int File::numBlocks() const
{
	/* TODO */
    // Complete
    return blocks.getSize();
}

bool File::isEmpty() const
{
	/* TODO */
    // Complete
    return blocks.getSize() == 0;
}

bool File::operator==(const File &rhs) const
{
	/* TODO */
    // Complete
    Node<Block> *block_ptr1 = blocks.getFirstNode();
    Node<Block> *block_ptr2 = rhs.blocks.getFirstNode();
    // Compare contents across the list
    while ((block_ptr1 != nullptr) && (block_ptr2 != nullptr))
    {
        if (block_ptr1->data.getContent() != block_ptr2->data.getContent())
        {
            return false;
        }
        else
        {
            block_ptr1 = block_ptr1->next;
            block_ptr2 = block_ptr2->next;
        }
    }
    // When loop condition fails, to be equal they both need to point NULL
    if ((block_ptr1 == nullptr) && (block_ptr2 == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void File::newBlock(const Block &block)
{
	/* TODO */
    // Complete
    blocks.append(block);
}

void File::removeBlock(int index)
{
	/* TODO */
    // Complete
    blocks.removeNodeAtIndex(index);
}

void File::mergeBlocks(int sourceIndex, int destIndex)
{
	/* TODO */
    // Complete
    blocks.mergeNodes(sourceIndex, destIndex);
}

void File::printContents() const{
	if(isEmpty()){
		std::cout << "File is empty" << std::endl;
	}
	else{
		for(int i = 0; i < blocks.getSize(); i++){
			Node<Block> *block = blocks.getNodeAtIndex(i);
			std::cout << block->data.getContent();
		}
		std::cout << std::endl << fileSize() << std::endl;
	}
}
