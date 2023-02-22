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
    while (i > 0 && heap[i] < heap[getParent(i)])
    {
        std::swap(heap[i], heap[getParent(i)]);
        i = getParent(i);
    }
}

void swapHeapDown(int i, std::vector<int> &heap)
{
    while (getChildLeft(i) < (int)heap.size())
    {
        int minChild = getChildLeft(i);
        if (getChildRight(i) < (int)heap.size() && heap[getChildRight(i)] < heap[minChild])
        {
            minChild = getChildRight(i);
        }
        if (heap[i] <= heap[minChild])
        {
            break;
        }
        std::swap(heap[i], heap[minChild]);
        i = minChild;
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
        heapInsert(inputNum, heap);
    }

    while (heap.size() > 0)
    {
        std::cout << heapExtract(heap) << ' ';
    }


    return 0;
}
