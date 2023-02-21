#include <vector>
#include <iostream>

int getParent(int i)
{
    return (i - 1) / 2;
}

int getChildLeft(int i)
{
    return i * 2 + 1;
}

int getChildRight(int i)
{
    return i * 2 + 2;
}

void swapHeapUp(int i, std::vector<int> &heap)
{
    while (i > 0 && heap[i] > heap[getParent(i)])
    {
        std::swap(heap[i], heap[getParent(i)]);
        i = getParent(i);
    }
}

void swapHeapDown(int i, std::vector<int> &heap)
{
    while (getChildLeft(i) < (int)heap.size())
    {
        int maxChild = getChildLeft(i);
        if (getChildRight(i) < (int)heap.size() && heap[getChildRight(i)] > heap[maxChild])
        {
            maxChild = getChildRight(i);
        }
        if (heap[i] >= heap[maxChild])
        {
            break;
        }
        std::swap(heap[i], heap[maxChild]);
        i = maxChild;
    }
}

void heapInsert(int num, std::vector<int> &heap)
{
    heap.push_back(num);
    swapHeapUp((int)heap.size() - 1, heap);
}

int heapExtract(std::vector<int> &heap)
{
    int top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    swapHeapDown(0, heap);
    return top;
}

int main()
{
    std::vector<int> heap;
    int inputCount;
    int inputNum;
    std::cin >> inputCount;
    while (inputCount-- > 0)
    {
        std::cin >> inputNum;
        if (inputNum == 0)
        {
            std::cin >> inputNum;
            heapInsert(inputNum, heap);
        }
        else if (inputNum == 1) 
        {
            std::cout << heapExtract(heap) << "\n";
        }
    }


    return 0;
}
