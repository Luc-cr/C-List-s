#include "List.h"

template <class var>
List<var>::List()
{
    bytes = align(sizeof(var));
}

template <class var>
void List<var>::push_back(var item)
{
    size_t total_size = sizeof(Header) + bytes;

    intptr_t *address = (intptr_t *) malloc(total_size);

    Header *header = (Header *) address;
    header->position = index; // Guardar el indice
    header->size = sizeof(var); // Guardar el peso
    header->next = NULL; // Guardar el siguiente elemento

    index += 1;// Incrementar el contador Indice

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
    // Debug Data
    // cout << "Alloc IN " <<  address << "Data IN " << address + sizeof(Header) << endl;

    intptr_t *data = address - sizeof(Header);
    *data = item; // Guardar el item en la posicion de memoria
}
template <class var>
void List<var>::print()
{
    cout << endl;
    intptr_t *current_address = firstAddress;
    Header *current_header = (Header*) current_address;
    var *data;
    for(int i = 0;i < 10; ++i)
    {
        data = (var*) (current_address - sizeof(Header));
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
template <class var>
var List<var>::get(int position) // TODO: Hacer que se puede obtener N en la posicion X
{

    return;
}

template <class var>
size_t List<var>::align(size_t n)
{
    return (n + sizeof(intptr_t) - 1) & ~(sizeof(intptr_t) - 1);
}
