#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include<string>
using namespace std;

/// This macro definition denotes the maximum number of logical operators the program can handle.
#define z 100000

/// @brief Number of unique propositional atoms
int h;

/// @brief This string is used to store the postorder notation of the logic formula via parse tree
///
/// @see postorder() main() 
string final="";

/// Class which defines each node and each leaf on the binary tree
///
/// ###variable
/// char d stores the data of the unit in the tree
///
/// Maketree *l *r they store the address of the left and right leaf of the current node respectively
class MakeTree 
{
   public: char d; 
   MakeTree *l, *r; 
   MakeTree(char d){ 
      this->d = d;
      this->l = NULL;
      this->r = NULL;
   }
};

/// Class which defines stack formation particularly for the prefix to binary tree convertion 
///
/// ###Variable
///
/// MakeTree *treeN It creates a object to class MakeTree which can be used to point each unit in Binary Tree
///
/// MakeStack *n It creates local object to the MakeStack class
class MakeStack
{
   public: MakeTree *treeN;
   MakeStack *n;
   MakeStack(MakeTree*treeN)
   {
      this->treeN = treeN;
      n = NULL;
   }
};

/// class which defines the binary tree and envolves all functions which convert prefix expresion to binary tree
/// ###variable
///
/// MakeStack *top stores address of topmost unit in the tree
///
/// MakeTree *ptr usual pointer used to point a unit in the tree
///
/// MakeStack *nptr usual pointer used to point a unit in the tree 
///
///int lDepth length of thr left side of the tree
///
///int rDepth length of thr right side of the tree
class SecondaryTree {
   private: MakeStack *top;
   public: SecondaryTree() {
      top = NULL;
   }
   /// function to clear the stack 
   void clear() {
      top = NULL;
   }
    /// function to push the value in the stack
    /// @param ptr which is address of the value which has to be added
    /// function checks if the top is null which means currently stack is empty and then adds the value otherwise just replaces top address with the new value address.
   /// @see pop()
   void push(MakeTree *ptr) {
      if (top == NULL)
        { top = new MakeStack(ptr);
         }
      else {
         MakeStack *nptr = new MakeStack(ptr);
         nptr->n = top;
         top = nptr;

      }
   }
    /// function to pop out the uppermost value in the stack
    /// @returns ptr which is the top most value in the stack currently.
    ///
    /// checks if the stack is empty and if its empty prints underflow.
    ///
    /// otherwise just pops out the topmost value and deletes it from stack.
    /// @see push()
   MakeTree *pop() {
      if (top == NULL) {
         cout<<"Underflow"<<endl;
      } else {
         MakeTree *ptr = top->treeN;
         top = top->n;

         return ptr;
      }
   }
    /// function to find the address of the root of tree
    ///
    /// @returns address of the root
   MakeTree *seek() {

      return top->treeN;
   }

    /// @param val its the bit by bit value in the given expression
    ///
    /// function checks if the the current alphabet is atom or operator and adds them in the tree like their respective properties
    ///
    /// else returns Invalid Expression
    ///
    /// @see FormTree() the function gets each string letter from the loop in FormTree function 
    /// @see push() 
    /// @see pop()
   void insert(char val) {
      if (if_Digit(val)) {
         MakeTree *nptr = new MakeTree(val);
         push(nptr);
      } else if (if_Operator(val)) {
         MakeTree *nptr = new MakeTree(val);
        if(val=='~'){
        nptr->l=NULL;
        nptr->r=pop();
        push(nptr);
        }
        else
         {nptr->l = pop();
         nptr->r= pop();
         push(nptr);
      } }


      else {
         cout<<"Invalid Expression"<<endl;
         return;
      }
   }

    /// function checks if the current alphabet is an atom or not
    ///
    /// @returns boolean value 
    ///
    /// @see if_operator(char ch) both have the same feature
   bool if_Digit(char ch) {
      return ((ch >= 65 && ch <= 90)||(ch>=97 && ch<=122));
   }

    /// function checks if the current alphabet is an operator or not
    ///
    /// @returns boolean value 
    ///
    /// @see if_Digit(char ch) both have the same feature
   bool if_Operator(char ch) {
      return ch == '+' || ch == '~' || ch == '*' || ch == '>';
   }
    /// function converts characters to digits in ASCII values
    ///
    /// @param ch which is to converted to digit
    ///
    /// @returns digit value 
   int toDigit(char ch) {
      return ch - '0';
   }

    /// function runs a loop to insert each alphabet sequentially as its properties into the binary tree
    ///
    /// @see insert()
   void FormTree(string eqn) {
      for (int i = eqn.length() - 1; i >= 0; i--)
         insert(eqn[i]);
   }

   /// function calls another function which converts binary tree to infix
   ///
   /// @see inOrder(MakeTree *ptr)
   void infix() {
      inOrder(seek());
   }

    ///@param ptr 
    ///
    /// function converts binary tree to infix by inorder transversal
    ///@see infix()
   void inOrder(MakeTree *ptr) {
      if (ptr != NULL) {
         inOrder(ptr->l);
         cout<<ptr->d;
         inOrder(ptr->r);
}}

/// @param node which is the address of the root
///
/// @returns height of the tree
///
/// the function takes input as the root input then traverses in both directions with use of recursion to find the longest path and hence determines height of the tree.
int Height_Tree(MakeTree* node)
{
    if (node == NULL)
        return 0;
    else {
       
        int lDepth = Height_Tree(node->l);
        int rDepth = Height_Tree(node->r);

        
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}};

/// @brief Class Stack
///
///This class implements stack data structure using a 1-d array.
///### Variable 
/// int* arr : It points to the array using which we'll be implementing stack
///
/// int top : It points to the top value of the stack.

class stack
{
    int* arr;
    int top;

    public:

    /// @brief Constructor
    ///
    /// It constructs an object of class stack with initialization of an array and giving default value -1 to the top pointer.
    stack()
    {
        arr = new int[z];
        top=-1;
    }

    /// @brief Push Function
    ///
    /// This function is used to push a value at the top of the stack when called.
    /// It returns as it is when the stack is full.
    /// @param a The value required to be pushed.
    void push(int a)
    {
        if(top==z-1)
        {
            return;
        }
        top++;
        arr[top]=a;
    }

    /// @brief Pop Function
    ///
    /// This function is used to remove the topmost value of the stack when called.
    /// It returns as it is when the stack is empty.
    void pop()
    {
        if(top==-1)
        {
            return;
        }
        top--;
    }

    /// @brief atTheTop Function
    ///
    /// This function is used to get the value present at the top of stack.
    /// It returns -1 when the stack is empty.
    /// @return Stack's top value
    int atTheTop()
    {
        if(top==-1)
        {
            return -1;
        }
        return arr[top];
    }

    /// @brief isEmpty Function
    ///
    /// This function is used to check whether our stack is empty. 
    /// @return true if empty and false when atleast one element lies in the stack.
    bool isEmpty()
    {
        return top==-1;
    }
};

/// @brief Defines the Precedence of Operators.
///
/// It assigns precedence to each logical connective of Propositional formulas.
/// @param operator_ Either of the operators ~,+,*,> as character.
/// @return a number which acts as opposite to the notion of a rank i.e., the more the number returned, higher is the precedence.
int precedence(char operator_)
{
    if(operator_ == '~')
        return 4;
    else if(operator_ == '*')
        return 3;
    else if(operator_ == '+')
        return 2;
    else if(operator_ == '>')
        return 1;
    else
        return 0;

}

/// @brief Task:I (Conversion from infix to Prefix notation)
///
/// This function converts a logical expression from Infix to Prefix using precedence and stack.
/// @param st An object reference/instance of class stack to keep track of all the operators along with parenthesis and executing its push, pop functions as per the algorithm.
/// @param input A string taken from the user which is an infix representation of a well formed logical formula.
/// @return A string which is a prefix notation of the formula inputted.
/// @see precedence()   stack()
///
/// ### Variable
/// *string output* : With each passing iteration we'll keep adding characters to this string to finally store the prefix notation in this.
///
/// *int size* : Stores size of the input string
/// 
/// *char temp* : Temporary variable used in swapping the elements of string during reversal.
///
/// ### Working
/// 1. The input string is reversed first of all. 
///
/// 2. Then string is iterated to check if the character is an operand or an operator.
///
/// 3. If an operand is found, then add it into the output string
/// 
/// 4. If an operator is found, push it onto the stack if stack is empty. if the stack is filled already, then add the operators at the top of stack to the ouput string till the stage where precedence of current operator becomes greater than that of the operator on top of stack. 
///
/// 5. If a closing parenthesis is found, simply push it in the stack. if an opening parenthesis is encountered, then add the operators at the top of stack to the string till the stage where it encounters closing parenthesis in the stack.
///
/// 6. Now empty the stack and add the operators to the ouput string.
///
/// 7. Finally, Reverse the output string to generate prefix notation.

string Infix_to_Prefix(stack st, string input)
{
    string output;
    int size = input.length();
    for(int i=0;i<size/2;i++)
    {
        char temp = input[i];
        input[i]=input[size-1-i];
        input[size-1-i] = temp;
    }

    for(int i=0;i<input.length();i++)
    {
        if((input[i]>=65 && input[i]<=90) || (input[i]>=97 && input[i]<=122))
        {
            output += input[i];
        }

        else if(input[i]==')')
        {
            st.push(input[i]);
        }

        else if(input[i]=='(')
        {
            while(st.atTheTop() != ')')
            {
                output += st.atTheTop();
                st.pop();
            }

            st.pop();
        }

        else if(input[i] == '~' || input[i] == '+' || input[i] == '*' || input[i] == '>')
        {
            if(st.isEmpty())
            {
                st.push(input[i]);
            }
            else
            {
                if(precedence(input[i])<precedence(st.atTheTop()))
                {
                    while(precedence(input[i])<precedence(st.atTheTop()))
                    {
                        output += st.atTheTop();
                        st.pop();
                    }
                    st.push(input[i]);
                }
                else
                {
                    st.push(input[i]);
                }
            }

        }
    }

    while(!st.isEmpty())
    {
        output += st.atTheTop();
        st.pop();
    }

    for(int i=0;i<output.length()/2;i++)
    {
        char temp = output[i];
        output[i]=output[output.length()-1-i];
        output[output.length()-1-i] = temp;
    }

    return output;
}

///This function finds the post order String of the binary Tree.
///
///This function also assigns values to the individual corresponding atoms in the binary tree to either O (False) or 1 (True). The function is called recursively to traverse the entire binary tree.
/// \param root This is the root pointer that points to the top node of the parse tree.
/// \param arr This is the character array that has 0 and 1 values of the corresponding atoms.
/// \param cha This is the character array that has the name of individual atoms.
/// \note The function stores the output in global String variable 'final'.

void postorder(MakeTree* root,char* arr,char* cha)
{if (root==NULL)
        return;
    for(int i=0;i<h;i++)
    {if(root->d==cha[i])
            root->d=arr[i];
    }
    postorder(root->l,arr,cha);
    postorder(root->r,arr,cha);
    final+=root->d;
}

///This function checks whether the character in the string is an operator or not.
/// \param ch Parameter that gets a single character from the postorder string.
/// \return It has boolean return type.
/// \see Truth_value_evaluator
bool isAnOperator(char ch)
{
    return (ch=='~' || ch=='*' || ch=='+' || ch=='>');
}

///This function imparts meaning to the operator characters.
///
/// \param subformula The input parameter of this function is the truncated string at each step to generate truth value
/// \return The return type of this function is String. It computes the operation on the two operands and finally return the truth value as either 0 or 1.
/// \see Truth_value_evaluator
string subformula_truth_value_generator(string subformula)
{
    if(subformula[2] == '*')
    {
        return to_string((subformula[0]-'0') && (subformula[1]-'0'));
    }
    else if(subformula[2] == '+')
    {
        return to_string((subformula[0]-'0') || (subformula[1]-'0'));
    }
    else if(subformula[2] == '>')
    {
        return to_string((!(subformula[0]-'0')) || (subformula[1]-'0'));
    }
    else if(subformula[2] == '~')
    {
        return to_string(subformula[0]-'0') + to_string(!(subformula[1]-'0'));
    }
}

///This function find the truth value of the logical expression.
///
///The function iteratively finds the three consecutive characters from the string array in postorder form so that the first two characters are operands and the last one is an operator.
/// It then simplifies the three characters to give either 0 and 1. The process then repeats till one final value is obtained.
/// \param postfix The parameter is the postfix String expression of the parse tree.
/// \return The return type is string.
///
///
/// ![](example.png)
///
/// \note In the example above we take a parse tree and calculate the value of its propositional logic in bottom to up manner.
string Truth_value_evaluator(string postfix)
{
    while(postfix.length()!=1)
    {
        if(postfix.length()<3)
        {
            postfix = "1" + postfix + "*";
        }
        for(int i=0;i<postfix.length()-2;i++)
        {
            if((postfix[i]=='0' || postfix[i]=='1') && (postfix[i+1]=='0' || postfix[i+1]=='1') && isAnOperator(postfix[i+2]))
            {
                postfix.replace(i,3,subformula_truth_value_generator(postfix.substr(i,3)));
                break;
            }
            else if((postfix[i]=='0' || postfix[i]=='1') && postfix[i+1]=='~')
            {
                postfix.replace(i,2,to_string(!(postfix[i]-'0')));
            }
        }
    }
    return postfix;
}

/// This is the main function of our program, that calls the other functions and takes input values from the user.
/// ### Variables/Objects
/// s (String) : Takes the infix notation from the user.
///
/// mp (object) : Object of the class SecondaryTree.
///
/// arr[h]: Character Array of size h (input by the user), that stores the value of propositional atoms.
///
///cha[h]: Character Array of size h (input by the user), that stores individual propositional atoms.
///
/// \see Infix_to_Prefix
/// \see postorder
/// \see Truth_value_evaluator
int main() {
    string s;
    SecondaryTree mp;
    stack st;
    cout<<"Enter propositional logic expression in the infix notation: "<<endl;
    cin>>s;
    cout<<"(TASK I) - In prefix notation, it is represented as:"<<Infix_to_Prefix(st,s)<<endl;
    string kt =Infix_to_Prefix(st,s);
    mp.FormTree(kt);
    MakeTree* k =mp.seek();
    cout<<"(TASK III) - Inorder traversal of the tree is : ";
    mp.infix();
    cout<<endl;
    cout<<"(TASK IV) - Depth of the tree is  "<<mp.Height_Tree(k)<<endl;
    cout<<"(TASK V) - Enter the no. of individual atoms: ";
    cin>>h;
    char arr[h]; ///Declaration of two arrays arr and cha with size h. arr stores the value of the expression.
    char cha[h];///cha stores the name of individual atoms.
    for(int i=0;i<h;i++)
    {
        cout<<"Enter the atoms and their values (0 for False and 1 for True): ";
        cin>>cha[i];
        cin>>arr[i];
    }
    postorder(mp.seek(),arr,cha);
    cout<<"Truth value of the propositional logic expression is: "<<Truth_value_evaluator(final)<<endl;
    return 0;

}