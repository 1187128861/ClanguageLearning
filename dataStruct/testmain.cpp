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

	////�������
	//printf("VLR: ");
	//BinTreeVLR_Nor(bt);
	//printf("\n");

	////�������
	//printf("LVR: ");
	//BinTreeLVR_Nor(bt);
	//printf("\n");

	////�������
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

	//�������
	printf("VLR: ");
	BinTreeVLR(bt);
	printf("\n");

	//�������
	printf("LVR: ");
	BinTreeLVR(bt);
	printf("\n");

	//�������
	printf("LRV: ");
	BinTreeLRV(bt);
	printf("\n");

	//��α���
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
		printf("%d ��ջ.\n", top_val);
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

		printf("��ѡ��:>");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("������Ҫ���ӵ�����<��-1����>:");
			while (scanf("%d", &item), item != -1){
				//SeqListPushBack(&list, item);
				//SListPushBack(&list, item);
				//DCListPushBack(&list, item);
			}
			printf("β���������ݳɹ�......\n");
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1){
				//SeqListPushFront(&list, item);
				//SListPushFront(&list, item);
				//SCListPushFront(&list, item);
			}
			printf("ͷ���������ݳɹ�......\n");
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
			printf("β��ɾ�����ݳɹ�...\n");
			break;
		case 5:
			//SeqListPopFront(&list);
			//SListPopFront(&list);
			//DCListFront(&list);
			break;
		case 6:
			printf("������Ҫ�����λ��# ");
			scanf("%d", &pos);
			printf("������Ҫ���������# ");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			if (flag){
				printf("����ɹ�...\n");
			}
			else{
				printf("����ʧ��....\n");
			}
			break;
		case 7:
			printf("������Ҫ���������: > ");
			scanf("%d", &item);
			//SeqListSort(&list);
			//SeqListInsertByVal(&list, item);
			//SListSort(&list);
			//SListInsertByVal(&list, item);
			//DCListSort(list);
			//DCListInsertByVal(&list, item);
			printf("�������ݳɹ�.\n");
			break;
		case 8:
			printf("������Ҫɾ��Ԫ�ص��±�# ");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &item);
			//SeqListEraseByVal(&list, item);
			//SListEraseByVal(&list, item);
			//DCListEraseByVal(&list, item);
			printf("ɾ�����ݳɹ�.\n");
			break;
		case 10:
			printf("������Ҫ���ҵ���ֵ:>");
			scanf("%d", &item);
			//p = SListFind(list, item);
			//p = DCListFind(list, item);
			if (p == NULL){
				printf("���ݲ���ʧ��!\n");
			}
			else{
				printf("���ݲ��ҳɹ�!\n");
			}
			//pos = SeqListFind(&list, item);
			//if (pos == -1){
			//	printf("˳���Ϊ��!\n");
			//}
			//else if (pos == -2){
			//	printf("Ҫ���ҵ���ֵ����˳�����!\n");
			//}
			//else{
			//	printf("Ҫ���ҵ���ֵ %d ���±��� %d \n", item, pos);
			//}
			break;
		case 11:
			//printf("����ĳ����� %d\n", SListLength(list));
			//printf("����ĳ����� %d\n", DCListLength(list));
			break;
		case 13:
			//SeqListSort(&list);
			//SListSort(&list);
			//DCListSort(list);
			printf("˳�������ɹ�.\n");
			break;
		case 14:
			//SeqListReverse(&list);
			//SListReverse(&list);
			//DCListReverse(list);
			printf("˳���ת�óɹ�.\n");
			break;
		case 15:
			//SeqListClear(&list);
			//SListClear(&list);
			//DCListClear(&list);
			break;
		case 16:
			//printf("��ͷԪ��Ϊ:>%d\n", SListFront(list));
			/printf("������Ҫ�޸�λ�õ��±�# ");
			scanf("%d", &pos);
			printf("�������޸ĺ����ֵ#");
			scanf("%d", &item);	
			//SeqListMod(&list, pos, item);
			//printf("��ͷԪ��Ϊ:%d\n", DCListFront(list));
			break;
		case 17:
			//printf("��βԪ��Ϊ:>%d\n", SListBack(list));
			//printf("��βԪ��Ϊ:%d\n", DCListBack(list));
			break;
		case 18:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &item);
			//SeqListSort(&list);
			//pos = SeqListBinaryFind(&list, item);
			printf("Ҫ���ҵ����� %d ���±��� %d \n", item, pos);
			break;
		case 19:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &item);
			//SListEraseAll(&list, item);
			break;
		case 0:
			break;
		default:
			printf("������������������...\n");
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







//˳�����ز���

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
//		printf("��ѡ��:>");
//		scanf("%d", &select);
//
//		switch (select)
//		{
//		case 1:
//			printf("������Ҫ���ӵ�����<��-1����>:");
//			while (scanf("%d", &item), item != -1){
//				SeqListPushBack(&list, item);
//			}
//			printf("ͷ���������ݳɹ�......\n");
//			break;
//		case 2:
//			printf("������Ҫ���������<��-1����>:");
//			while (scanf("%d", &item), item != -1){
//				SeqListPushFront(&list, item);
//			}
//			printf("β���������ݳɹ�......\n");
//			break;
//		case 3:
//			SeqListShow(&list);
//			break;
//		case 4:
//			SeqListPopBack(&list);
//			printf("β��ɾ�����ݳɹ�...\n");
//			break;
//		case 5:
//			SeqListPopFront(&list);
//			printf("ͷ��ɾ�����ݳɹ�.\n");
//			break;
//		case 6:
//			printf("������Ҫ�����λ��# ");
//			scanf("%d", &pos);
//			printf("������Ҫ���������# ");
//			scanf("%d", &item);
//			flag = SeqListInsertByPos(&list, pos, item);
//			if (flag){
//				printf("����ɹ�...\n");
//			}
//			else{
//				printf("����ʧ��....\n");
//			}
//			break;
//		case 7:
//			printf("������Ҫ���������: > ");
//			scanf("%d", &item);
//			SeqListSort(&list);
//			SeqListInsertByVal(&list, item);
//			printf("�������ݳɹ�.\n");
//			break;
//		case 8:
//			printf("������Ҫɾ��Ԫ�ص��±�# ");
//			scanf("%d", &pos);
//			SeqListEraseByPos(&list, pos);
//			break;
//		case 9:
//			printf("������Ҫɾ��������:>");
//			scanf("%d", &item);
//			SeqListEraseByVal(&list, item);
//			printf("ɾ�����ݳɹ�.\n");
//			break;
//		case 10:
//			printf("������Ҫ���ҵ���ֵ...");
//			scanf("%d", &item);
//			pos = SeqListFind(&list, item);
//			if (pos == -1){
//				printf("˳���Ϊ��!\n");
//			}
//			else if (pos == -2){
//				printf("Ҫ���ҵ���ֵ����˳�����!\n");
//			}
//			else{
//				printf("Ҫ���ҵ���ֵ %d ���±��� %d \n", item, pos);
//			}
//			break;
//		case 13:
//			SeqListSort(&list);
//			printf("˳�������ɹ�.\n");
//			break;
//		case 14:
//			SeqListReverse(&list);
//			printf("˳���ת�óɹ�.\n");
//			break;
//		case 15:
//			SeqListClear(&list);
//			break;
//		case 16:
//			printf("������Ҫ�޸�λ�õ��±�# ");
//			scanf("%d", &pos);
//			printf("�������޸ĺ����ֵ#");
//			scanf("%d", &item);
//			SeqListMod(&list, pos, item);
//			break;
//		case 18:
//			printf("������Ҫ���ҵ�ֵ:>");
//			scanf("%d", &item);
//			SeqListSort(&list);
//			pos = SeqListBinaryFind(&list, item);
//			printf("Ҫ���ҵ����� %d ���±��� %d \n", item, pos);
//			break;
//		case 0:
//			break;
//		default:
//			printf("������������������...\n");
//			break;
//		}
//		system("pause");
//		system("cls");
//	}
//	SeqListDestory(&list);
//	return 0;
//}


