#pragma once
#include <vector>
#include <type_traits>

template<typename T, int SIZE>
class MemoryBlock {
	static_assert(sizeof T > 0, "MemoryBlock Assert Exception: Size of T has to be bigger than 0 bytes");
	static_assert(SIZE > 0, "MemoryBlock Assert Exception: Memory block reserved size has to be bigger than 0");


	T* const blockPtr; //const pointer naar het begin van de blok
	unsigned int currentSize;

	//static_assert(sizeof T > 0, "MemoryBlock Assert Exception: Size of T has to be bigger than 0 bytes");
	//static_assert(SIZE > 0, "MemoryBlock Assert Exception: Memory block reserved size has to be bigger than 0");

public:
	inline T* begin() const { //pak het adres van de begin van de memoryblock/het eerste element
		return blockPtr;
	}

	inline T* end() const { //pak adres van het einde van de geheugenblok (niet de laatste element) voor iteratie
		return blockPtr + currentSize;
	}
	
	inline T* last() const { //pak het laatste element
		return (currentSize != 0) ? blockPtr + currentSize - 1 : this->end();
	}

	//Default constructor, alloceer geheugen voor de 
	MemoryBlock() : blockPtr((T*)malloc(SIZE * sizeof(T))), currentSize(0){
		
	}

	template<typename... ARG_T>
	MemoryBlock(unsigned int startItemCount, ARG_T ... args) 
		: blockPtr((T*)malloc(SIZE * sizeof(T))), 
		currentSize((startItemCount > SIZE) ? SIZE : startItemCount)
	{

		for (T* it = blockPtr; it != blockPtr + currentSize; ++it) {
			new(it) T(&args...);
		}
	}

	~MemoryBlock() {
		T* endPtr = this->end();
		for (T* it = this->begin(); it != endPtr; ++it) {
			it->~T();
		}
		std::free(blockPtr);
	}

	template<typename... ARG_T>
	void push(ARG_T ... args) {
		if (currentSize < SIZE) {
			new(blockPtr + currentSize++) T(&args...);
		}
	}

	void pop() {
		if (currentSize > 0) {
			(blockPtr + --currentSize)->~T();
		}
	}

	unsigned int getCurrentSize() const {
		return currentSize;
	}

	void remove(unsigned int index) {
		if (index < currentSize) {
			if (index < currentSize - 1) {
				T* temp = (T*)malloc(sizeof T);

				memcpy(temp, last(), sizeof T());
				memcpy(last(), blockPtr + index, sizeof T);
				memcpy(blockPtr + index, temp, sizeof T);

				pop();
				free(temp);
			}
			else {
				pop();
			}
		}
	}

	T* get(unsigned int index) const {
		if (index < currentSize) {
			return (blockPtr + index);
		}
	}

};




template<typename T, int BLOCKSIZE>
class MemoryBlockList {
	std::vector<MemoryBlock<T, BLOCKSIZE>*> memoryBlocks;

	static_assert(sizeof T > 0, "MemoryBlockList Assert Exception: Size of T has to be bigger than 0 bytes");
	static_assert(BLOCKSIZE > 0, "MemoryBlockList Assert Exception: Memory block reserved size has to be bigger than 0");

	void indexConversion(const unsigned int in_index, unsigned int& out_blockIndex, unsigned int& out_itemIndex) const {
		unsigned int passedItems = 0;

		for (int v = 0; v < memoryBlocks.size(); v++) {
			int blockSize = memoryBlocks[v]->getCurrentSize();
			int nextVecStartIndex = passedItems + blockSize;

			if (nextVecStartIndex > in_index) {
				out_blockIndex = v;
				out_itemIndex = in_index - passedItems;
				return;
			}

			passedItems = nextVecStartIndex;
		}
	}

public:
	MemoryBlockList() {

	}

	~MemoryBlockList() {
		for (int i = 0; i < memoryBlocks.size(); i++) {
			MemoryBlock<T, BLOCKSIZE>* ptr = memoryBlocks[i];
			delete ptr;
		}
	}

	std::vector<MemoryBlock<T, BLOCKSIZE>> getBlocks() const {
		return this->memoryBlocks;
	}


	template<typename... ARG_T>
	void addNewBlock(unsigned int startItemCount, ARG_T ... args) {
		MemoryBlock<T, BLOCKSIZE>* block = new MemoryBlock<T, BLOCKSIZE>(startItemCount, &args...);
		memoryBlocks.emplace_back(block);
	}

	void addNewBlock() {
		MemoryBlock<T, BLOCKSIZE>* block = new MemoryBlock<T, BLOCKSIZE>();
		memoryBlocks.emplace_back(block);
	}

	
	template<typename... ARG_T>
	void push(ARG_T ... args) {
		unsigned int blocksize = memoryBlocks.size();
		bool newBlockShouldBeAdded = blocksize == 0 || memoryBlocks[blocksize - 1]->getCurrentSize() >= BLOCKSIZE;

		if (newBlockShouldBeAdded) {
			addNewBlock();
		}

		memoryBlocks[blocksize + newBlockShouldBeAdded - 1]->push(&args...);
	}

	T* get(unsigned int index) const {
		unsigned blockIndex, itemIndex;
		this->indexConversion(index, blockIndex, itemIndex);
		return this->get(blockIndex, itemIndex);
	}

	T* get(unsigned int blockIndex, unsigned int itemIndex) const {
		return memoryBlocks[blockIndex]->get(itemIndex);
	}

	void pop(unsigned int blockIndex) {
		memoryBlocks[blockIndex]->pop();
	}

	void remove(unsigned int blockIndex, unsigned int itemIndex) {
		memoryBlocks[blockIndex]->remove(itemIndex);
	}

	void remove(unsigned int index) {
		unsigned blockIndex, itemIndex;
		this->indexConversion(index, blockIndex, itemIndex);
		remove(blockIndex, itemIndex);
	}

	unsigned int getTotalItemCount() const {
		unsigned int count = 0;

		unsigned int size = memoryBlocks.size();
		for (int i = 0; i < size; i++) {
			count += memoryBlocks[i]->getCurrentSize();
		}

		return count;
	}

	unsigned int getBlockCount() const {
		return this->memoryBlocks.size();
	}

	MemoryBlock<T, BLOCKSIZE>* getBlock(unsigned int blockIndex) const {
		return memoryBlocks[blockIndex];
	}
};