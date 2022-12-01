#include "List.h"

List::List(size_t type)
{
    bytes = align(type);
}

void List::push_back(char item)
{
    // TODO: Que se pueda almacenar diferentes tipos
    size_t total_size = sizeof(Header) + bytes;

    intptr_t *address = (intptr_t *) malloc(total_size);

    Header *header = (Header *) address;
    header->position = counter;
    header->size = bytes;
    header->next = NULL;

    counter += 1;

    if(firstAddress == NULL)
    {
        firstAddress = address;
        lastAddress = address;
    }
    else
    {
        ((Header *) lastAddress)->next = address;
        lastAddress = address;
    }
    cout << "Alloc IN " <<  address << " ";
    cout << "Data IN " << address + sizeof(Header) << endl;
    intptr_t *data = address - sizeof(Header);
    *data = item;
}

void List::print()
{
    cout << endl;
    intptr_t *current_address = firstAddress;
    Header *current_header = (Header*) current_address;
    char *data;
    for(int i = 0;i < 10; ++i)
    {
        data = (char*) (current_address - sizeof(Header));
        cout << "In " << i << " Value " << data << endl;
        if(current_header->next == 0x0)
        {
            return;
        }
        else
        {
            current_address = current_header->next;
            current_header = (Header*) current_address;
        }
    }

}
size_t List::align(size_t n)
{
    return (n + sizeof(intptr_t) - 1) & ~(sizeof(intptr_t) - 1);
}
