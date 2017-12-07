#include "project1_LinkedList.hpp"

Node::Node()
{
    m_ptrPrev = nullptr;
    m_ptrNext = nullptr;
}

LinkedList::LinkedList()
{
    m_ptrFirst = nullptr;
    m_ptrLast = nullptr;
    m_itemCount = 0;
}

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Clear()
{
    while (m_itemCount != 0)
    {
        PopFront();
    }
}

void LinkedList::PushFront( CustomerData newData )
{
    Node* newNode = new Node;
    newNode->m_data = newData;

    if (IsEmpty() == true)
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
        m_itemCount++;
    }
    else
    {
        m_ptrFirst->m_ptrPrev = newNode;
        newNode->m_ptrNext = m_ptrFirst;
        m_ptrFirst = newNode;
        m_itemCount++;
    }
}

void LinkedList::PushBack( CustomerData newData )
{
    Node* newNode = new Node;
    newNode->m_data = newData;

    if (IsEmpty() == true)
    {
        m_ptrFirst = newNode;
        m_ptrLast = newNode;
        m_itemCount++;
    }
    else
    {
        m_ptrLast->m_ptrNext = newNode;
        newNode->m_ptrPrev = m_ptrLast;
        m_ptrLast = newNode;
        m_itemCount++;
    }
}

void LinkedList::PopFront() noexcept
{
    if (m_ptrFirst == m_ptrLast)
    {
        delete m_ptrFirst;
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount--;
    }
    else
    {
        Node* ptrSecond = m_ptrFirst->m_ptrNext;
        ptrSecond->m_ptrPrev = nullptr;
        delete m_ptrFirst;
        m_ptrFirst = ptrSecond;
        m_itemCount--;
    }
}

void LinkedList::PopBack() noexcept
{
    if (m_ptrFirst == m_ptrLast)
    {
        delete m_ptrLast;
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount--;
    }
    else
    {
        Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
        ptrSecondToLast->m_ptrNext = nullptr;
        delete m_ptrLast;
        m_ptrLast = ptrSecondToLast;
        m_itemCount--;
    }
}

CustomerData LinkedList::GetFront()
{
    if (IsEmpty() == true)
    {
        throw logic_error("List is empty!");
    }
    
    return m_ptrFirst->m_data;
}

CustomerData LinkedList::GetBack()
{
    if (IsEmpty() == true)
    {
        throw logic_error("List is empty!");
    }

    return m_ptrLast->m_data;
}

CustomerData& LinkedList::operator[](const int index)
{
    int counter = 0;
    Node* ptrCurrent = m_ptrFirst;

    if (index < 0 || index >= m_itemCount)
    {
        throw out_of_range("Index is not valid!");
    }

    while (counter != index && ptrCurrent != nullptr)
    {
        ptrCurrent = ptrCurrent->m_ptrNext;
        counter++;
    }
        
    return (ptrCurrent->m_data);
}

bool LinkedList::IsEmpty()
{
    return (m_itemCount == 0);
}

int LinkedList::Size()
{
    return m_itemCount;
}
