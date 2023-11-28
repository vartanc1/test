// demonstrates linked list
// linkList2.java
// to run this program: C>java LinkList2App
////////////////////////////////////////////////////////////////
class Link
   {
   public int iData;              // data item (key)
   //public double dData;           // data item
   public Link next;              // next link in list
   public char label;
   public boolean wasVisited;
// -------------------------------------------------------------
   public Link(char label1) // constructor
      {
      //iData = id;
      wasVisited = false;
      label = label1;
      
      
      }
// -------------------------------------------------------------
   }  // end class Link
////////////////////////////////////////////////////////////////
class LinkList
   {
   private Link first;            // ref to first link on list

// -------------------------------------------------------------
   public LinkList()              // constructor
      {
      first = null;               // no links on list yet
      }
// -------------------------------------------------------------
   public void insertFirst(char label)
      {                           // make new link
      Link newLink = new Link(label);
      newLink.next = first;       // it points to old first link
      first = newLink;            // now first points to this
      }
// -------------------------------------------------------------
   public Link find(char key)      // find link with given key
      {                           // (assumes non-empty list)
      Link current = first;              // start at 'first'
      while(current.label != key)        // while no match,
         {
         if(current.next == null)        // if end of list,
            return null;                 // didn't find it
         else                            // not end of list,
            current = current.next;      // go to next link
         }
      return current;                    // found it
      }
// -------------------------------------------------------------
   public Link delete(int key)    // delete link with given key
      {                           // (assumes non-empty list)
      Link current = first;              // search for link
      Link previous = first;
      while(current.iData != key)
         {
         if(current.next == null)
            return null;                 // didn't find it
         else
            {
            previous = current;          // go to next link
            current = current.next;
            }
         }                               // found it
      if(current == first)               // if first link,
         first = first.next;             //    change first
      else                               // otherwise,
         previous.next = current.next;   //    bypass it
      return current;
      }

   public void reverse(){
      Link previous = null;
      Link current = first;
      Link next  = null;

      while (current != null) {
            next = current.next;      // store next node
            current.next = previous;  // reverse the link
            previous = current;       // move previous forward
            current = next;           // move current forward
        }

        first = previous;             // update head to the new front
    }

   
// -------------------------------------------------------------
   public void displayList()      // display the list
      {
      //System.out.print("List (first-->last): ");
      Link current = first;       // start at beginning of list
      while(current != null)      // until end of list,
         {
            if(current.next == null){
               System.out.print("{" + current.label+"}  ");
               current = current.next;

            }
            else{
               System.out.print("{" + current.label+"} -> ");
               current = current.next;  // move to next link 
            }
         }
      //System.out.println("");
      }
// -------------------------------------------------------------
   }  // end class LinkList
////////////////////////////////////////////////////////////////
class LinkList2App
   {
   public static void main(String[] args)
      {
      LinkList theList = new LinkList();  // make list

      
      theList.displayList();              // display list
      }  // end main()
   }  // end class LinkList2App
////////////////////////////////////////////////////////////////
