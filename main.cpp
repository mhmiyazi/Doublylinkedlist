#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct nod {
   int info;
   struct nod *n;
   struct nod *p;
}*start, *last;

int count = 0;
class circulardoublylist {
   public:
      nod *create_node(int);
      void create_node_success();
      void display();
      void insert_begin();
      void insert_end();
      void insert_position();
      void delete_begin();
      void delete_end();
      void delete_position();

      circulardoublylist() {
         start = NULL;
         last = NULL;
      }
};
int main() {
   int c;
   circulardoublylist cdll;
   while (1)
    {
      cout<<"***** MAIN MENU *****"<<endl;
      cout<<"1: Create a list"<<endl;
      cout<<"2: Display the list"<<endl;
      cout<<"3: Add a node at the begining"<<endl;
      cout<<"4: Add a node at the end"<<endl;
      cout<<"5: Add a node before a given node"<<endl;
      cout<<"6: Delete a node from the begining"<<endl;
      cout<<"7: Delete a node from the end"<<endl;
      cout<<"8: Delete a given node"<<endl;
      cout<<"9: Exit"<<endl;
      cout<<"Enter your option : ";
      cin>>c;
      switch(c) {
         case 1:
             //List creation messege
             cdll.create_node_success();
         break;
         case 2:
             //display list
             cdll.display();
         break;
         case 3:
             //insert at begin
             cdll.insert_begin();
         break;
         case 4:
             //insert at end
            cdll.insert_end();
         break;
         case 5:
             //insert at position
            cdll.insert_position();
         break;
         case 6:
             //delete begin
             cdll.delete_begin();
         break;
         case 7:
            // delete end
            cdll.delete_end();
         break;
         case 8:
             //delete at position
             cdll.delete_position();
         break;
         case 9:
             //successful termination
            exit(1);
         default:
            cout<<"!!!!!!!!!!!!!"<<endl;
            cout<<"Wrong choice"<<endl;
            cout<<"!!!!!!!!!!!!!"<<endl;
      }
    }
      return 0;
   }


//Create list
//Menu No 1

nod* circulardoublylist::create_node(int v) {
   count++;
   struct nod *t;
   t = new(struct nod);
   t->info = v;
   t->n = NULL;
   t->p = NULL;
   return t;
}

void circulardoublylist::create_node_success() {
    cout<<"-----------------------------------"<<endl;
    cout<<"\n Success : List created.\n"<<endl;
    cout<<"-----------------------------------"<<endl;
}

//display list
//Menu No 2

void circulardoublylist::display() {
   int i;
   struct nod *s;
   if (start == last && start == NULL) {
      cout<<"-----------------------------------"<<endl;
      cout<<"The List is empty, nothing to display"<<endl;
      cout<<"-----------------------------------"<<endl;
      return;
   }
   s = start;
   cout<<"--------------------------------------"<<endl;
   for (i = 0;i < count-1;i++) {
      cout<<s->info<<"<->";
      s = s->n;
   }
   cout<<s->info<<endl;
   cout<<"--------------------------------------"<<endl;
}

//insert at begin
//Menu No 3

void circulardoublylist::insert_begin() {
   int v;
   cout<<"----------------------------------------------"<<endl;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<"----------------------------------------------"<<endl;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
      cout<<"-----------------------------------------------------------"<<endl;
      cout<<"Success : Element inserted in empty list at Begin position"<<endl;
      cout<<"----------------------------------------------------------"<<endl;
      start = last = t;
      start->n = last->n = NULL;
      start->p = last->p = NULL;
   } else {
      t->n = start;
      start->p = t;
      start = t;
      start->p = last;
      last->n = start;
      cout<<"----------------------------------------------"<<endl;
      cout<<"Success : Element inserted at Begin position."<<endl;
      cout<<"----------------------------------------------"<<endl;
   }
}

//Insert at end
//Menu No 4

void circulardoublylist::insert_end() {
   int v;
   cout<<"--------------------------------------------"<<endl;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<"--------------------------------------------"<<endl;
   struct nod *t;
   t = create_node(v);
   if (start == last && start == NULL) {
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Element inserted in empty list at End position"<<endl;
    cout<<"----------------------------------------------"<<endl;
      start = last = t;
      start->n= last->n = NULL;
      start->p = last->p= NULL;
   } else {
      last->n= t;
      t->p= last;
      last = t;
      start->p = last;
      last->n= start;
   }
}

//Insert at node position
//Menu No 5

void circulardoublylist::insert_position() {
   int v, pos, i;
   cout<<"---------------------------------------------------------------"<<endl;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the node position of element to be inserted: ";
   cout<<"---------------------------------------------------------------"<<endl;
   cin>>pos;
   struct nod *t, *s, *ptr;
   t = create_node(v);
   if (start == last && start == NULL) {
      if (pos == 1) {
         start = last = t;
         start->n = last->n = NULL;
         start->p = last->p = NULL;
      } else {
          cout<<"------------------------"<<endl;
          cout<<"Position out of range"<<endl;
          cout<<"------------------------"<<endl;
          count--;
          return;
      }
   } else {
      if (count < pos) {
          cout<<"------------------------"<<endl;
          cout<<"Position out of range"<<endl;
          cout<<"------------------------"<<endl;
          count--;
          return;
      }
      s = start;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->n;
         if (i == pos - 1) {
            ptr->n = t;
            t->p= ptr;
            t->n= s;
            s->p = t;
            cout<<"---------------------------------------------"<<endl;
            cout<<"Success : Element inserted at given position."<<endl;
            cout<<"---------------------------------------------"<<endl;
            break;
         }
      }
   }
}

//Delete at begin
//Menu No 6

void circulardoublylist::delete_begin() {
   int pos, i;
   nod *ptr, *s;
    s = start;
   if (start == last && start == NULL) {
      cout<<"------------------------------------"<<endl;
      cout<<"List is empty, nothing to delete"<<endl;
      cout<<"------------------------------------"<<endl;
   }
   else{
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
      cout<<"-----------------------------------"<<endl;
      cout<<"Warning! : Element Deleted at Begin!"<<endl;
      cout<<"-----------------------------------"<<endl;
      return;
   }
}

//Delete at end
//Menu No 7

void circulardoublylist::delete_end() {
   int pos, i;
   nod *ptr, *l;
    l = last;
   if (start == last && start == NULL) {
      cout<<"-----------------------------------"<<endl;
      cout<<"List is empty, nothing to delete"<<endl;
      cout<<"-----------------------------------"<<endl;
   }
   else{
      count--;
      last->n = l->n;
      l->n->p = last;
      start = l->n;
      free(l);
      cout<<"-----------------------------------"<<endl;
      cout<<"Warning! : Element Deleted at End!"<<endl;
      cout<<"-----------------------------------"<<endl;
      return;
   }
}

//Delete at node position
//Menu No 8

   void circulardoublylist::delete_position() {
   int pos, i;
   nod *ptr, *s;
   if (start == last && start == NULL) {
      cout<<"-----------------------------------"<<endl;
      cout<<"List is empty, nothing to delete"<<endl;
      cout<<"-----------------------------------"<<endl;
      return;
   }
   cout<<"-------------------------------------------------------------"<<endl;
   cout<<endl<<"Enter the node position of element to be deleted: ";
   cin>>pos;
   cout<<"-------------------------------------------------------------"<<endl;
   if (count < pos) {
      cout<<"------------------------"<<endl;
      cout<<"Position out of range"<<endl;
      cout<<"------------------------"<<endl;
      return;
   }
   s = start;
   if(pos == 1) {
      count--;
      last->n = s->n;
      s->n->p = last;
      start = s->n;
      free(s);
      cout<<"----------------------------------------------"<<endl;
      cout<<"Warning! : Element Deleted at given position!"<<endl;
      cout<<"----------------------------------------------"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->n;
      ptr = s->p;
   }
   ptr->n = s->n;
   s->n->p = ptr;
   if (pos == count) {
      last = ptr;
   }
   count--;
   free(s);
   cout<<"----------------------------------------------"<<endl;
   cout<<"Warning! : Element Deleted at given position!"<<endl;
   cout<<"----------------------------------------------"<<endl;
}
