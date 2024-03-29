#include <string>
#include <fstream>
#include <iostream>
using namespace std;
typedef int ItemType;
struct TreeNode;
#include "QueType.h"
#include "sorted.h"
#include "unsorted.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
public:
    TreeType();                     // constructor
   ~TreeType();                    // destructor
    TreeType(const TreeType& originalTree);
    void operator=(const TreeType& originalTree);
    // copy constructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem(ItemType& item, bool& found);
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetTree(OrderType order);
    void GetNextItem (ItemType& item, OrderType order,
         bool& finished);
    void Print(std::ofstream& outFile) const;

    void Ancestors_Iter(int value);
    void Ancestors_Recur(int value);

    ItemType Smaller(ItemType value);

//    void MakeTree_Trial(SortedType list);
    bool MatchingItem(UnsortedType list);
    void CallMakeTree(TreeType &tree, SortedType &list);


private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

