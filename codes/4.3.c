/*ϰ��4.3 �Ƿ���������� ��25 �֣�
����Ҫ��ʵ�ֺ������жϸ����������Ƿ����������*/
//typedef struct TNode *Position;
//typedef Position BinTree;
//struct TNode{
//    ElementType Data;
//    BinTree Left;
//    BinTree Right;
//};

//ʹ����������ķ���ʵ�֣�
//1������������������������������temp�����У�
//2�����temp�����Ƿ�Ϊ�������У�����ǣ���ΪBST����֮���ǡ�
//�˷��������Խ�һ�����Ż�������temp���飬����ʹ�ö�����ڴ濪�������������ʱʹ�þ�̬��������ǰ���ڵ㣬�����ǰ�ڵ�С��ǰ���ڵ㣬���������BST������ʵ�����£�
bool IsBST ( BinTree T ){
 	static BinTree P= NULL;
 	if(T){
 		if(!IsBST(T->Left)) return false;
 		if(P  && T->Data < P->Data) return false;// P==NULL,���ǵ�һ���жϣ�������������δ��һ��Ԫ�ء� 
 		P = T;
 		if(!IsBST(T->Right)) return false;
	 }
	 else return true;
}
