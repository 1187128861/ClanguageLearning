//#include "seqlist.h"
//#include "slist.h"
//#include "dclist.h"
//#include "test.h"
//#include "stack.h"
//#include "queue.h"
//#include "dcclist.h"
//#include "bintree.h"
//#include "heap.h"
#include "sort.h"

#include  "bst.h"

int main()
{
	int a = 4;
	printf("%d\n", ++(a++));
	system("pause");
	return 0;
}


//int main()
//{
//	int arr[] = { 0, 49, 38, 65, 97, 76, 13, 27, 49 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	PrintArray(arr, 1, n);
//	TestSort(arr, 1, n);
//	PrintArray(arr, 1, n);
//
//
//	system("pause");
//}


//int main()
//{
//	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	BSTree bst;
//	BstInit(&bst);
//	BSTNode *p = BstFind(bst, 37);
//	BstErase(&bst, p);
//
//
//	system("pause");
//}




/*
void main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MinHeap mhp;
	HeapCreate(&mhp, arr, n);
	HeapShow(&mhp);
	HeapSort(&mhp, arr, n);

	//MinHeap mhp;
	//HeapInit(&mhp);

	//for (int i = 0; i < n; ++i)
	//	HeapInsert(&mhp, arr[i]);

	//HeapShow(&mhp);

	//HeapInsert(&mhp, 17);
	//HeapShow(&mhp);

	//HeapErase(&mhp);
	//HeapShow(&mhp);
	system("pause");
}
*/

//ABC##DE##F##G#H##
/*
int main()
{
	const char *vlr = "ABCDEFGH";
	const char *lvr = "CBEDFAGH";
	const char *lrv = "CEFDBHGA";

	BinTree bt;
	BinTreeInit(&bt);

	//bt = BinTreeCreate_3(vlr, lvr, strlen(vlr));
	bt = BinTreeCreate_4(lvr, lrv, strlen(vlr));


	//const char *str = "ABC##DE##F##G#H##";
	//BinTree bt;
	//BinTreeInit(&bt);
	//int index = 0;
	//bt = BinTreeCreate_2(str, &index);

	////先序遍历
	//printf("VLR: ");
	//BinTreeVLR_Nor(bt);
	//printf("\n");

	////中序遍历
	//printf("LVR: ");
	//BinTreeLVR_Nor(bt);
	//printf("\n");

	////后序遍历
	//printf("LRV: ");
	//BinTreeLRV_Nor(bt);
	//printf("\n");
	system("pause");

}
*/

/*
int main()
{
	const char *str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);
    //BinTreeCreate(&bt);
	//bt = BinTreeCreate_1();

	int index = 0;
	bt = BinTreeCreate_2(str, &index);
	//BinTree bt1 = BinTreeClone(bt);

	char key = 'G';
	BinTreeNode *p = BinTreeFind(bt, key);
	BinTreeNode *pr = BinTreeParent(bt, p);
	BinTreeNode *pc = BinTreeClone(bt);

	//先序遍历
	printf("VLR: ");
	BinTreeVLR(bt);
	printf("\n");

	//中序遍历
	printf("LVR: ");
	BinTreeLVR(bt);
	printf("\n");

	//后序遍历
	printf("LRV: ");
	BinTreeLRV(bt);
	printf("\n");

	//层次遍历
	printf("Level: ");
	BinTreeLevel(bt);
	printf("\n");

	printf("Size: %d\n", BinTreeNodeSize(bt));
	printf("Height: %d\n", Height(bt));

	system("pause");
	return 0;
}
*/




/*
void main()
{
	CycleSeqQueue Q;
	CycleSeqQueueInit(&Q);
	CycleSeqQueueEn(&Q, 1);
	CycleSeqQueueEn(&Q, 2);
	CycleSeqQueueEn(&Q, 3);
	CycleSeqQueueEn(&Q, 4);
	CycleSeqQueueEn(&Q, 5);
	CycleSeqQueueEn(&Q, 6);
	CycleSeqQueueEn(&Q, 7);
	CycleSeqQueueEn(&Q, 8);

	CycleSeqQueueEn(&Q, 9);
	CycleSeqQueueShow(&Q);

	//CycleSeqQueueDe(&Q);
	//CycleSeqQueueShow(&Q);
	//CycleSeqQueueEn(&Q, 9);
	//CycleSeqQueueShow(&Q);

	system("pause");
}

*/


/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);
	SeqQueueEn(&Q, 1);
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 5);
	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);
	SeqQueueEn(&Q, 9);
	SeqQueueShow(&Q);

	SeqQueueDe(&Q);
	SeqQueueShow(&Q);
	printf("front = %d\n", SeqQueueFront(&Q));

	SeqQueueEn(&Q, 9);
	system("pause");
}
*/






/*
void main()
{
	SeqStack st;
	SeqStackInit(&st);

	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);

	int top_val;
	while (!SeqStackIsEmpty(&st))
	{
		top_val = SeqStackTop(&st);
		SeqStackTop(&st);
		SeqStackPop(&st);
		printf("%d 出栈.\n", top_val);
	}
	SeqStackDestroy(&st);
	system("pause");
}

*/

/*
void main()
{
	LinkStack st;
	LinkStackInit(&st);

	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackShow(st);

	LinkStackPop(&st);
	LinkStackPop(&st);
	LinkStackShow(st);

	printf("top = %d\n", LinkStackTop(st));
	printf("size = %d\n", LinkStackSize(st));

	LinkStackDestroy(&st);
	system("pause");

}

*/


/*
int main()
{
	//SeqList list;
	//SeqListInit(&list);

	//SListNode* list;
	//SListInit(&list);
	//SListNode *p = NULL;

	ListCreate();
	//DCList list;
	//DCListInit(&list);
	//DCListNode *p = NULL;

	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while (select){
		printf("*********************************************\n");
		printf("*  [1] push_back           [2] push_front   *\n");
		printf("*  [3] show_list           [0] quit_system  *\n");
		printf("*  [4] pop_back            [5] pop_front    *\n");
		printf("*  [6] insert_pos          [7] insert_val   *\n");
		printf("*  [8] erase_pos           [9] erase_val    *\n");
		printf("*  [10] find               [11] length      *\n");
		printf("*  [12] capacity           [13] sort        *\n");
		printf("*  [14] reverse            [15] clear       *\n");
		printf("*  [16] front              [17] back        *\n");
		printf("*  [18] binary_find        [19] erase_all   *\n");
		printf("*********************************************\n");

		printf("请选择:>");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("请输入要增加的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1){
				//SeqListPushBack(&list, item);
				//SListPushBack(&list, item);
				//DCListPushBack(&list, item);
			}
			printf("尾部插入数据成功......\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1){
				//SeqListPushFront(&list, item);
				//SListPushFront(&list, item);
				//SCListPushFront(&list, item);
			}
			printf("头部插入数据成功......\n");
			break;
		case 3:
			//SeqListShow(&list);
			//SListShow(list);
			//DCListShow(list);
			break;
		case 4:
			//SeqListPopBack(&list);
			//SListPopBack(&list);
			//DCListPopBack(&list);
			printf("尾部删除数据成功...\n");
			break;
		case 5:
			//SeqListPopFront(&list);
			//SListPopFront(&list);
			//DCListFront(&list);
			break;
		case 6:
			printf("请输入要插入的位置# ");
			scanf("%d", &pos);
			printf("请输入要插入的数据# ");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			if (flag){
				printf("插入成功...\n");
			}
			else{
				printf("插入失败....\n");
			}
			break;
		case 7:
			printf("请输入要插入的数据: > ");
			scanf("%d", &item);
			//SeqListSort(&list);
			//SeqListInsertByVal(&list, item);
			//SListSort(&list);
			//SListInsertByVal(&list, item);
			//DCListSort(list);
			//DCListInsertByVal(&list, item);
			printf("插入数据成功.\n");
			break;
		case 8:
			printf("请输入要删除元素的下标# ");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &item);
			//SeqListEraseByVal(&list, item);
			//SListEraseByVal(&list, item);
			//DCListEraseByVal(&list, item);
			printf("删除数据成功.\n");
			break;
		case 10:
			printf("请输入要查找的数值:>");
			scanf("%d", &item);
			//p = SListFind(list, item);
			//p = DCListFind(list, item);
			if (p == NULL){
				printf("数据查找失败!\n");
			}
			else{
				printf("数据查找成功!\n");
			}
			//pos = SeqListFind(&list, item);
			//if (pos == -1){
			//	printf("顺序表为空!\n");
			//}
			//else if (pos == -2){
			//	printf("要查找的数值不在顺序表内!\n");
			//}
			//else{
			//	printf("要查找的数值 %d 的下标是 %d \n", item, pos);
			//}
			break;
		case 11:
			//printf("链表的长度是 %d\n", SListLength(list));
			//printf("链表的长度是 %d\n", DCListLength(list));
			break;
		case 13:
			//SeqListSort(&list);
			//SListSort(&list);
			//DCListSort(list);
			printf("顺序表排序成功.\n");
			break;
		case 14:
			//SeqListReverse(&list);
			//SListReverse(&list);
			//DCListReverse(list);
			printf("顺序表转置成功.\n");
			break;
		case 15:
			//SeqListClear(&list);
			//SListClear(&list);
			//DCListClear(&list);
			break;
		case 16:
			//printf("表头元素为:>%d\n", SListFront(list));
			/printf("请输入要修改位置的下标# ");
			scanf("%d", &pos);
			printf("请输如修改后的数值#");
			scanf("%d", &item);	
			//SeqListMod(&list, pos, item);
			//printf("表头元素为:%d\n", DCListFront(list));
			break;
		case 17:
			//printf("表尾元素为:>%d\n", SListBack(list));
			//printf("表尾元素为:%d\n", DCListBack(list));
			break;
		case 18:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			//SeqListSort(&list);
			//pos = SeqListBinaryFind(&list, item);
			printf("要查找的数据 %d 的下标是 %d \n", item, pos);
			break;
		case 19:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			//SListEraseAll(&list, item);
			break;
		case 0:
			break;
		default:
			printf("命令有误，请重新输入...\n");
			break;
		}
		system("pause");
		system("cls");
	}
	//SeqListDestory(&list);
	//DCListDestory(&list);
	SListDestory(&list);
	return 0;
}

*/







//顺序表相关操作

//int main()
//{
//	SeqList list;
//	SeqListInit(&list);
//
//	ElemType item;
//	int pos;
//	bool flag;
//	int select = 1;
//	while (select){
//		printf("*********************************************\n");
//		printf("*  [1] push_back           [2] push_front   *\n");
//		printf("*  [3] show_list           [0] quit_system  *\n");
//		printf("*  [4] pop_back            [5] pop_front    *\n");
//		printf("*  [6] insert_pos          [7] insert_val   *\n");
//		printf("*  [8] erase_pos           [9] erase_val    *\n");
//		printf("*  [10] find               [11] length      *\n");
//		printf("*  [12] capacity           [13] sort        *\n");
//		printf("*  [14] reverse            [15] clear       *\n");
//		printf("*  [16] front              [17] back        *\n");
//		printf("*  [18] binary_find        [19] erase_all   *\n");
//		printf("*********************************************\n");
//
//		printf("请选择:>");
//		scanf("%d", &select);
//
//		switch (select)
//		{
//		case 1:
//			printf("请输入要增加的数据<以-1结束>:");
//			while (scanf("%d", &item), item != -1){
//				SeqListPushBack(&list, item);
//			}
//			printf("头部插入数据成功......\n");
//			break;
//		case 2:
//			printf("请输入要插入的数据<以-1结束>:");
//			while (scanf("%d", &item), item != -1){
//				SeqListPushFront(&list, item);
//			}
//			printf("尾部插入数据成功......\n");
//			break;
//		case 3:
//			SeqListShow(&list);
//			break;
//		case 4:
//			SeqListPopBack(&list);
//			printf("尾部删除数据成功...\n");
//			break;
//		case 5:
//			SeqListPopFront(&list);
//			printf("头部删除数据成功.\n");
//			break;
//		case 6:
//			printf("请输入要插入的位置# ");
//			scanf("%d", &pos);
//			printf("请输入要插入的数据# ");
//			scanf("%d", &item);
//			flag = SeqListInsertByPos(&list, pos, item);
//			if (flag){
//				printf("插入成功...\n");
//			}
//			else{
//				printf("插入失败....\n");
//			}
//			break;
//		case 7:
//			printf("请输入要插入的数据: > ");
//			scanf("%d", &item);
//			SeqListSort(&list);
//			SeqListInsertByVal(&list, item);
//			printf("插入数据成功.\n");
//			break;
//		case 8:
//			printf("请输入要删除元素的下标# ");
//			scanf("%d", &pos);
//			SeqListEraseByPos(&list, pos);
//			break;
//		case 9:
//			printf("请输入要删除的数据:>");
//			scanf("%d", &item);
//			SeqListEraseByVal(&list, item);
//			printf("删除数据成功.\n");
//			break;
//		case 10:
//			printf("请输入要查找的数值...");
//			scanf("%d", &item);
//			pos = SeqListFind(&list, item);
//			if (pos == -1){
//				printf("顺序表为空!\n");
//			}
//			else if (pos == -2){
//				printf("要查找的数值不在顺序表内!\n");
//			}
//			else{
//				printf("要查找的数值 %d 的下标是 %d \n", item, pos);
//			}
//			break;
//		case 13:
//			SeqListSort(&list);
//			printf("顺序表排序成功.\n");
//			break;
//		case 14:
//			SeqListReverse(&list);
//			printf("顺序表转置成功.\n");
//			break;
//		case 15:
//			SeqListClear(&list);
//			break;
//		case 16:
//			printf("请输入要修改位置的下标# ");
//			scanf("%d", &pos);
//			printf("请输如修改后的数值#");
//			scanf("%d", &item);
//			SeqListMod(&list, pos, item);
//			break;
//		case 18:
//			printf("请输入要查找的值:>");
//			scanf("%d", &item);
//			SeqListSort(&list);
//			pos = SeqListBinaryFind(&list, item);
//			printf("要查找的数据 %d 的下标是 %d \n", item, pos);
//			break;
//		case 0:
//			break;
//		default:
//			printf("命令有误，请重新输入...\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	SeqListDestory(&list);
//	return 0;
//}


