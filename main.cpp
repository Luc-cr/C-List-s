#include "list.cpp"

int main()
{
    char a;
    List myList(1);
    myList.push_back('A');
    myList.push_back('B');
    myList.push_back('C');
    myList.push_back('D');
    myList.push_back('F');
    myList.push_back('H');
    myList.push_back('G');
    myList.print();
    cout << "Presione cualquier tecla para salir del programa..." << endl;
    cin >> a;
    return 0;
}