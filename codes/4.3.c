/*习题4.3 是否二叉搜索树 （25 分）
本题要求实现函数，判断给定二叉树是否二叉搜索树*/
//typedef struct TNode *Position;
//typedef Position BinTree;
//struct TNode{
//    ElementType Data;
//    BinTree Left;
//    BinTree Right;
//};

//使用中序遍历的方法实现：
//1）对树进行中序遍历，将结果保存在temp数组中；
//2）检测temp数组是否为升序排列，如果是，则为BST，反之则不是。
//此方法还可以进一步的优化，不用temp数组，避免使用额外的内存开销。在中序遍历时使用静态变量保存前驱节点，如果当前节点小于前驱节点，则该树不是BST。代码实现如下：
bool IsBST ( BinTree T ){
 	static BinTree P= NULL;
 	if(T){
 		if(!IsBST(T->Left)) return false;
 		if(P  && T->Data < P->Data) return false;// P==NULL,则是第一次判断，或者在中序中未第一个元素。 
 		P = T;
 		if(!IsBST(T->Right)) return false;
	 }
	 else return true;
}
