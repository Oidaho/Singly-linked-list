#include <iostream>


using namespace std;



class DynList final
{

    struct Node
    {
        int data;
        Node* next;
    };

    private:
            
        Node* head;

    public:

        DynList() 
        {
            head = NULL; 
        };

        void Clear_List()
        {
            if (head != NULL)
            {
                Node* temp;

                while (head->next != head)
                {
                    temp = head->next->next;
                    delete head->next;
                    head->next = temp;
                }

                delete head;
                head = NULL;
            }
        };

        void Delete_Node(int data)
        {
            Node* current = head;

            if (current != NULL)
            {
                while (current->next->data != data && current->next != head)
                {
                    current = current->next;
                }

                if (current->next->data == data)
                {
                    Node* temp = current->next->next;
                    if (current->next == head)
                    {
                        head = current->next->next;
                    }
                    delete current->next;
                    current->next = temp;
                }
            }
        };

        bool Find_Node(int data)
        {

            Node* current = head;

            bool flag = false;

            if (current == NULL)
            {
                return false;
            }
            else
            {
                if (current->data == data)
                {
                    return true;
                }
                else
                {
                    while (current->next != head && current->next->data != data)
                    {
                        current = current->next;
                    }

                    if (current->next->data == data)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        };

        void Add_Node(int data)
        { 
            Node* current = head;

            bool flag = false;

            if (current == NULL)
            {
                Node* cn = new Node;
                cn->data = data;
                cn->next = NULL;

                head = cn;
                head->next = head;
            }
            else
            {
                if (data < current->data && data != current->data)
                {
                    while (current->next != head)
                    {
                        current = current->next;
                    }

                    Node* cn = new Node;
                    cn->data = data;
                    cn->next = head;

                    current->next = cn;
                    head = cn;
                }
                else if (data > current->data)
                {
                    while (current->next != head && current->next->data < data)
                    {
                        current = current->next;
                    }

                    if (current->next->data != data)
                    {
                        Node* cn = new Node;
                        cn->data = data;
                        cn->next = current->next;

                        current->next = cn;
                    }
                }
            }
        };

        void Print_List()
        {
            cout << "------------------------------" << endl;
            
            Node* current = head;

            if (current == NULL)
            {
                cout << "DynList is empty." << endl;
            }
            else
            {
                do
                {
                    cout << "adress: " << current << "  ";
                    cout << "data: " << current->data << "  ";
                    cout << "next: " << current->next << endl;

                    current = current->next;
                } 
                while (current != head);
            }
            cout << "------------------------------" << endl;
        };

        void Merge(DynList List1, DynList List2)
        {
            Node* current1 = List1.head;
            Node* current2 = List2.head;

            if (current1 != NULL)
            {
                do
                {
                    Add_Node(current1->data);

                    current1 = current1->next;

                } while (current1 != List1.head);
            }

            if (current2 != NULL)
            {
                do
                {
                    Add_Node(current2->data);

                    current2 = current2->next;

                } while (current2 != List2.head);
            }
             
        };
};


int main()
{
    DynList List_One;

    List_One.Add_Node(32);
    List_One.Add_Node(2);
    List_One.Add_Node(2);
    List_One.Add_Node(2);
    List_One.Add_Node(7);
    List_One.Add_Node(10);
    List_One.Add_Node(240);
    List_One.Add_Node(1);
    List_One.Add_Node(66);
   
    List_One.Print_List();

    cout << "------------------------------" << endl;
    cout << "Find node 22: " << List_One.Find_Node(22) << endl;
    cout << "Find node 7: " << List_One.Find_Node(7) << endl;
    cout << "------------------------------" << endl;

    List_One.Delete_Node(1);

    List_One.Print_List();

    //List_One.Clear_List();

    List_One.Print_List();
    
    DynList List_Two;

    List_Two.Add_Node(4);
    List_Two.Add_Node(5);
    List_Two.Add_Node(61);
    List_Two.Add_Node(544);

    List_Two.Print_List();

    DynList Merged;

    Merged.Merge(List_One, List_Two);

    Merged.Print_List();

    return 0;
};
