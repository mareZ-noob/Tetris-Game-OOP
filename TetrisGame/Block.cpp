#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::Move(int rows, int cols)
{
	rowOffset += rows;
	colOffset += cols;
}

void Block::Rotate()
{

}

void Block::UndoRotate()
{

}