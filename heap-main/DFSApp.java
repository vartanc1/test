
////////////////////////////////////////////////////////////////
class StackX
   {
   private final int SIZE = 20;
   private int[] st;
   private int top;
// ------------------------------------------------------------
   public StackX()           // constructor
      {
      st = new int[SIZE];    // make array
      top = -1;
      }
// ------------------------------------------------------------
   public void push(int j)   // put item on stack
      { st[++top] = j; }
// ------------------------------------------------------------
   public int pop()          // take item off stack
      { return st[top--]; }
// ------------------------------------------------------------
   public int peek()         // peek at top of stack
      { return st[top]; }
// ------------------------------------------------------------
   public boolean isEmpty()  // true if nothing on stack
      { return (top == -1); }
// ------------------------------------------------------------
   }  // end class StackX
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
class Graph
   {
   private final int MAX_VERTS = 20;
   private Link vertLinkList[]; // list of vertices
   private  Link adjLink[][];      // adjacency link
   private int nVerts;          // current number of vertices
   private StackX theStack;
   public char words[] = new char[MAX_VERTS];
   public LinkList[] myList = new LinkList[MAX_VERTS];
   int i=0;
   int UnvisitVertVar = 0;
// ------------------------------------------------------------
   public Graph()               // constructor
      {
      vertLinkList = new Link[MAX_VERTS];
                                          // adjacency matrix
      adjLink = new Link[MAX_VERTS][MAX_VERTS];
      nVerts = 0;
      for(int y=0; y<MAX_VERTS; y++)      // set adjacency
         for(int x=0; x<MAX_VERTS; x++) {  //    matrix to 0
            adjLink[x][y] = new Link(' ');
         }
         for(int i=0; i < vertLinkList.length;++i){
            myList[i] = new LinkList();
         }
      theStack = new StackX();
      }  // end constructor
// ------------------------------------------------------------
   public void addVertex(char lab)
   
      {  
         vertLinkList[nVerts++] = new Link(lab);
         words[i] = lab;
         ++i;
      }
// ------------------------------------------------------------
   public void addEdge(int start, int end)
      {
         
         adjLink[start][end].wasVisited = true;
         adjLink[end][start].wasVisited = true;

         myList[start].insertFirst(words[end]); //add to link list
   
      }
// ------------------------------------------------------------
   public void displayVertex(int v)
      {
         System.out.print(vertLinkList[v].label);
         
      }

   public void printConnections()
      {
         System.out.println("VERTEX LinkedList with Adjacent Vertices");
         
         for(int i = 0; i < words.length;++i){

            if(words[i] == 0){
               continue;
            }
            else{
               System.out.print(words[i]+": ");
               myList[i].reverse();
               myList[i].displayList();
               System.out.println();
            }
           
         }
         
      }
// ------------------------------------------------------------
   public void dfs()  // depth-first search
      {                                 // begin at vertex 0
      vertLinkList[0].wasVisited = true;  // mark it
      displayVertex(0);                 // display it
      theStack.push(0);                 // push it

      while( !theStack.isEmpty() )      // until stack empty,
         {
         // get an unvisited vertex adjacent to stack top
         int v = getAdjUnvisitedVertex( theStack.peek());
         if(v == -1)                    // if no such vertex,
            theStack.pop();
         else                           // if it exists,
            {
            vertLinkList[v].wasVisited = true;  // mark it
            displayVertex(v);                 // display it
            theStack.push(v);                 // push it
            }
         }  // end while

      // stack is empty, so we're done
      for(int j=0; j<nVerts; j++)          // reset flags
         vertLinkList[j].wasVisited = false;
      }  // end dfs
// ------------------------------------------------------------
   // returns an unvisited vertex adj to v
   public int getAdjUnvisitedVertex(int v)
      {
      for(int j=0; j<nVerts; j++)
         if(adjLink[v][j].wasVisited && vertLinkList[j].wasVisited==false)
            return j;
      return -1;
      }  // end getAdjUnvisitedVertex()
// ------------------------------------------------------------
   // public int getAdjUnvisitedVertex(int v)
   //    {
         
   //       for(int j=0; j<nVerts; j++){

   //          Link adjlest = adjLink[v][j];
   //          Link current = vertLinkList[j];

   //          if(adjlest.wasVisited && current.wasVisited==false){
   //          return j;
   //          }
   //          else{
   //             if(current.next!=null){
   //                current = current.next;
   //             }
              
   //          }
   //    }
   //    return -1;
   //    }  // end getAdjUnvisitedVertex()   

      

   }  // end class Graph
////////////////////////////////////////////////////////////////
class DFSApp
   {
   public static void main(String[] args)
      {
      Graph theGraph = new Graph();
      theGraph.addVertex('A');    // 0  (start for dfs)
      theGraph.addVertex('B');    // 1
      theGraph.addVertex('C');    // 2
      theGraph.addVertex('D');    // 3
      //theGraph.addVertex('E');    // 4

      theGraph.addEdge(0, 2); // AB
      theGraph.addEdge(2, 1); //AC 
      //theGraph.addEdge(0, 3); //AD

      // theGraph.addEdge(1, 0); //BA
      // theGraph.addEdge(1, 3); //BD

      // theGraph.addEdge(2, 0); // CA
      // theGraph.addEdge(3, 0); // DA
      // theGraph.addEdge(3, 1); 
  

      System.out.print("Visits: ");
      theGraph.dfs();             // depth-first search
      System.out.println();
      theGraph.printConnections();
      }  // end main()
   }  // end class DFSApp
////////////////////////////////////////////////////////////////

