#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
typedef struct Three {
	int value;
	int row;
	int col;
} three;
typedef struct NodeThree {
	three t;
	struct nodeThree* node;
}  nodeThree;
typedef struct node {
	int num;
	struct node* node;
} node;
typedef struct nodeCh {
	char c;
	struct nodeCH* node;
} nodeCh;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();
void Ex7();

/* Declarations of other functions */
//EX1 Functions
unsigned int* PowerArray(int n);

//EX2 Functions
void neighborMaxMin(int** mat, int i, int j, int* min, int* max, int row, int col);
void printMatrix(int** mat, int row, int col);
int** matrixMaxNeighbor(int** mat, int row, int col);

//EX3 Functions
three createThree(int value, int row, int col);
nodeThree* createThreeNode(three t);
nodeThree* insert(nodeThree* n, three t);
three* createThreeArr(int** mat, int row, int col, int* counter);
nodeThree* createThreeList(three* arr, int n);
int createArrayAndList(int** mat, int row, int col, three** arr, nodeThree** list);

//EX4 Functions
node* createNode(int n);
node* insert2(node* head, int n);
node* deleteNode(node* head, node* n);
void createList(node** head, node** list);

//EX5 Functions
node* removeNode(node* head, node* n);
void createList2(node** head, node** list);

//EX6 Functions
nodeCh* createNode2(char c);
nodeCh* insert3(nodeCh* head, char c);
void deleteNode2(nodeCh** head, char c);
void removeDupList(nodeCh** head);
void removeDupArrayLists(nodeCh*** arr, int n);

//EX7 Functions
void removeNode2(nodeCh** head, char c);
nodeCh* disassemblyList(nodeCh* head, nodeCh** sList, nodeCh** bList, nodeCh** nList);

/* ------------------------------- */

int main()
{
	int selectt = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				selectt = 0;
				printf("please select 0-7 : ");
				scanf("%d", &selectt);
			} while ((selectt < 0) || (selectt > 7));
			switch (selectt)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			case 7: Ex7(); break;
			}
		} while (all_Ex_in_loop && selectt);
		return 0;
}


/* Function definitions */
//EX1 Functions
void Ex1() {
	int n, i;
	printf("Please enter a number of cells:\n");
	scanf_s("%d", &n);
	unsigned int* arr = PowerArray(n);

	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	free(arr);

}
unsigned int* PowerArray(int n) {
	unsigned int* arr = NULL;
	int i;
	unsigned int temp;
	arr = (unsigned int*)calloc(n, sizeof(int));
	if (arr == NULL)
	{
		printf("There is not enough memory");
		return NULL;
	}
	if (n == 32)
	{
		printf("There is not enough memory");
		return NULL;
	}
	else {
		for (i = 0; i < n; i++) {
			temp = i % 32;
			arr[i] = pow(2, temp);

		}
	}
	return arr;
}
//EX2 Functions
void Ex2() {
	int** mat, ** newmat, rows, i, j, col;

	printf("Enter number of rows\n");
	scanf_s("%d", &rows);
	printf("Enter number of columns\n");
	scanf_s("%d", &col);
	mat = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++) {
		mat[i] = (int*)calloc(col, sizeof(int));
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < col; j++) {
			printf("Enter a number to the cube [%d][%d]\n", i, j);
			scanf_s("%d", &mat[i][j]);
		}

	}
	printMatrix(mat, rows, col);
	printf("\n");
	newmat = matrixMaxNeighbor(mat, rows, col);
	printMatrix(newmat, rows, col);

	printf("\n");


}
void neighborMaxMin(int** mat, int i, int j, int* mini, int* maxi, int row, int col) {
	int min = 128, max = 0;
	if (i - 1 != -1) {
		if (mat[i - 1][j] > max)
			max = mat[i - 1][j];
		if (mat[i - 1][j] < min)
			min = mat[i - 1][j];
	}
	if (i + 1 != row) {
		if (mat[i + 1][j] > max)
			max = mat[i + 1][j];
		if (mat[i + 1][j] < min)
			min = mat[i + 1][j];
	}
	if (j - 1 != -1) {
		if (mat[i][j - 1] > max)
			max = mat[i][j - 1];
		if (mat[i][j - 1] < min)
			min = mat[i][j - 1];
	}
	if (j + 1 != col) {
		if (mat[i][j + 1] > max)
			max = mat[i][j + 1];
		if (mat[i][j + 1] < min)
			min = mat[i][j + 1];
	}
	*mini = min;
	*maxi = max;
}
void printMatrix(int** mat, int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d\t", mat[i][j]);
		}

		printf("\n");
	}
}
int** matrixMaxNeighbor(int** mat, int row, int col) {
	int** nmat;
	int i, j, max = 0, min = 0;
	int* pmax = &max;
	int* pmin = &min;
	nmat = (int**)calloc(row, sizeof(int*));
	for (i = 0; i < row; i++) {
		nmat[i] = (int*)calloc(col, sizeof(int));
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			neighborMaxMin(mat, i, j, pmin, pmax, row, col);
			nmat[i][j] = *pmax;

		}
	}
	return nmat;


}
//EX3 Functions
void Ex3() {
	nodeThree* head = NULL;

	three* arrayy = NULL;
	int** mat, rows, i, j, col, count;

	printf("Enter number of rows\n");
	scanf_s("%d", &rows);
	printf("Enter number of columns\n");
	scanf_s("%d", &col);
	mat = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++) {
		mat[i] = (int*)calloc(col, sizeof(int));
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < col; j++) {
			printf("Enter a number to the cube [%d][%d]\n", i, j);
			scanf_s("%d", &mat[i][j]);
		}

	}
	printMatrix(mat, rows, col);
	printf("\n");
	count = createArrayAndList(mat, rows, col, &arrayy, &head);
	for (i = 0; i < count; i++) // printing the array
	{
		printf("the value is: %4d ", arrayy[i].value);
		printf("[%d][%d]", arrayy[i].row, arrayy[i].col);
		printf("     \n");
	}
	printf("\n");
}
three createThree(int value, int row, int col) {
	three temp;
	temp.value = value;
	temp.row = row;
	temp.col = col;
	return temp;
}
nodeThree* createThreeNode(three t) {
	nodeThree* temp = (nodeThree*)malloc(sizeof(nodeThree));
	temp->t = t;
	temp->node = NULL;
}
nodeThree* insert(nodeThree* n, three t) {
	nodeThree* newnode = createThreeNode(t);
	if (n == NULL) {
		n = newnode;
	}
	else {
		nodeThree* temp = n;
		while (temp->node != NULL) {
			temp = temp->node;
		}
		temp->node = newnode;

	}
	return n;
}



three* createThreeArr(int** mat, int row, int col, int* counter) {
	int i, j, count = 0, max = 0, min = 0, k = 0;
	int* pmax = &max;
	int* pmin = &min;
	three temp;
	three* arr;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			neighborMaxMin(mat, i, j, pmin, pmax, row, col);
			if (mat[i][j] <= *pmin)
				count++;
		}
	}
	arr = (three*)malloc(count * sizeof(three));
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			neighborMaxMin(mat, i, j, pmin, pmax, row, col);
			if (mat[i][j] <= *pmin) {
				temp = createThree(mat[i][j], i, j);
				arr[k++] = temp;

			}

		}
	}


	*counter = k;
	return arr;

}
nodeThree* createThreeList(three* arr, int n) {
	int i;
	nodeThree* temp;

	temp = createThreeNode(arr[0]);
	nodeThree* head = temp;
	for (i = 1; i < n; i++) {
		head = insert(head, arr[i]);
	}
	return head;

}
int createArrayAndList(int** mat, int row, int col, three** arr, nodeThree** list) {
	nodeThree* head = NULL;
	three* arrr;

	int count = 0;
	int* counter = &count;
	arrr = createThreeArr(mat, row, col, counter);
	count = *counter;
	printf("\n");

	head = createThreeList(arr, count);
	*arr = arrr;
	*list = head;

	return count;


}

//EX4 Functions
void Ex4() {

	node* head = NULL, * temp = NULL;
	int num, i = 0;
	node* newList = NULL;
	node* newlist2 = NULL;
	printf("Enter a number to the list to stop enter -1: ");
	scanf_s("%d", &num);
	printf("\n");
	while (num != -1)
	{
		head = insert2(head, num);
		printf("Enter a number to the list to stop enter -1: ");
		scanf_s("%d", &num);
		printf("\n");
	}
	temp = head;
	if (temp != NULL) {
		while (temp->node != NULL)
		{
			printf("node %d is: %d\t", i, temp->num);
			i++;
			temp = temp->node;
		}
		printf("node %d is: %d\t", i, temp->num);
	}
	printf("\n");
	printf("\n");
	createList(&head, &newList);
	temp = newList;
	newlist2 = head;
	i = 0;
	while (temp->node != NULL)
	{
		printf("new node list %d is: %d\t", i, temp->num);
		i++;
		temp = temp->node;
	}
	printf("new node list %d is: %d\n", i, temp->num);
	printf("\n");
	i = 0;
	while (newlist2->node != NULL)
	{
		printf("deleted list %d is: %d\t", i, newlist2->num);
		i++;
		newlist2 = newlist2->node;
	}
	printf("deleted list %d is: %d\t", i, newlist2->num);
	printf("\n");

}
node* createNode(int n) {
	node* temp = (node*)malloc(sizeof(node));
	temp->num = n;
	temp->node = NULL;
	return temp;
}
node* insert2(node* head, int n) {
	node* newnode = createNode(n);
	if (head == NULL) {
		head = newnode;
	}
	else {
		node* temp = head;
		while (temp->node != NULL) {
			temp = temp->node;
		}
		temp->node = newnode;

	}
	return head;
}

node* deleteNode(node* head, node* n) {
	node* deleteNode, * temp = head;
	if (head == NULL) {
		printf("List is empty");
	}
	else if (temp->node == NULL) {
		if (temp == n) {
			deleteNode = temp;
			head = NULL;
			free(deleteNode);
		}
	}
	else if (temp == n) {
		deleteNode = n;
		temp = temp->node;
		free(deleteNode);

	}
	else {
		while (temp->node != n)
		{
			temp = temp->node;
		}
		if (temp->node->node == NULL) {
			deleteNode = temp->node;
			temp->node = NULL;
			free(deleteNode);
		}
		else {
			deleteNode = temp->node;
			temp->node = deleteNode->node;
			free(deleteNode);
		}
	}

	return head;

}
void createList(node** head, node** list) {
	node* newList = NULL;
	node* temp = *head;
	node* tempdel = *head;
	node* lastTemp = NULL;
	node* lastTemp2 = NULL;
	if (temp->num > temp->node->num) {
		newList = insert2(newList, temp->num);
	}
	while (temp->node->node->node != NULL)
	{
		if ((temp->num) < (temp->node->num) && (temp->node->num) > (temp->node->node->num)) {
			newList = insert2(newList, temp->node->num);
		}
		temp = temp->node;

	}
	if ((temp->node->node->num) < (temp->node->num) && (temp->num) < (temp->node->num))
		newList = insert2(newList, temp->node->num);
	if ((temp->node->node->num) > (temp->node->num))
		newList = insert2(newList, temp->node->node->num);
	*list = newList;

	lastTemp = tempdel;
	while (
		tempdel->node->node != NULL && tempdel->node->node->node != NULL) {
		if ((tempdel->num) < (tempdel->node->num) && (tempdel->node->num) > (tempdel->node->node->num)) {
			lastTemp = deleteNode(lastTemp, tempdel->node);
		}

		tempdel = tempdel->node;
	}
	if (tempdel->node->node == NULL) {
		if (tempdel->num < tempdel->node->num)
			lastTemp = deleteNode(lastTemp, tempdel->node);

	}
	else if (tempdel->node->node->node == NULL) {
		if ((tempdel->node->node->num) < (tempdel->node->num) && (tempdel->num) < (tempdel->node->num))
			lastTemp = deleteNode(lastTemp, tempdel->node);
		else if ((tempdel->node->node->num) > (tempdel->node->num))
			lastTemp = deleteNode(lastTemp, tempdel->node->node);
	}


	if (lastTemp->num > lastTemp->node->num) {
		lastTemp2 = lastTemp;
		lastTemp = lastTemp->node;
		free(lastTemp2);
	}
	*head = lastTemp;
}
//EX5 Functions
void Ex5() {

	node* head = NULL, * temp = NULL;
	int num, i = 0;
	node* newList = NULL;
	node* newlist2 = NULL;
	printf("Enter a number to the list to stop enter -1: ");
	scanf_s("%d", &num);
	printf("\n");
	while (num != -1)
	{
		head = insert2(head, num);
		printf("Enter a number to the list to stop enter -1: ");
		scanf_s("%d", &num);
		printf("\n");
	}
	temp = head;
	if (temp != NULL) {
		while (temp->node != NULL)
		{
			printf("node %d is: %d\t", i, temp->num);
			i++;
			temp = temp->node;
		}
		printf("node %d is: %d\t", i, temp->num);
	}
	printf("\n");
	printf("\n");
	createList2(&head, &newList);
	temp = newList;
	newlist2 = head;
	i = 0;
	while (temp->node != NULL)
	{
		printf("new node list %d is: %d\t", i, temp->num);
		i++;
		temp = temp->node;
	}
	printf("new node list %d is: %d\n", i, temp->num);
	printf("\n");
	i = 0;
	while (newlist2->node != NULL)
	{
		printf("deleted list %d is: %d\t", i, newlist2->num);
		i++;
		newlist2 = newlist2->node;
	}
	printf("deleted list %d is: %d\t", i, newlist2->num);

	printf("\n");

}
node* removeNode(node* head, node* n) {
	node* temp = head;
	if (head == NULL) {
		printf("List is empty");
	}
	else if (temp->node == NULL) {
		if (temp == n) {
			head = NULL;
		}
	}
	else if (temp == n) {
		temp = temp->node;

	}
	else {
		while (temp->node != n)
		{
			temp = temp->node;
		}
		if (temp->node->node == NULL) {
			temp->node = NULL;
		}
		else {
			temp->node = temp->node->node;
		}
	}

	return head;

}
void createList2(node** head, node** list) {
	node* newList = NULL;
	node* temp = *head;
	node* tempdel = *head;
	node* tempNew = *head;

	while (temp->node->node != NULL && temp->node->node->node != NULL) {
		if ((temp->num) < (temp->node->num) && (temp->node->num) > (temp->node->node->num)) {
			newList = insert2(newList, temp->node->num);
			tempNew = removeNode(tempNew, temp->node);
		}

		temp = temp->node;
	}
	if (temp->node->node == NULL) {
		if (temp->num < temp->node->num) {
			newList = insert2(newList, temp->node->num);
			tempNew = removeNode(tempNew, temp->node);
		}
	}
	else if (temp->node->node->node == NULL) {
		if ((temp->node->node->num) < (temp->node->num) && (temp->num) < (temp->node->num)) {
			newList = insert2(newList, temp->node->num);
			tempNew = removeNode(tempNew, temp->node);
		}
		else if ((tempdel->node->node->num) > (tempdel->node->num)) {
			newList = insert2(newList, temp->node->node->num);
			tempNew = removeNode(tempNew, temp->node->node);
		}
	}
	if (tempNew->num > tempNew->node->num) {
		newList = insert2(newList, tempNew->num);
		tempNew = tempNew->node;
	}
	*list = newList;
	*head = tempNew;
}

//EX6 Functions
void Ex6() {
	nodeCh* head = NULL, * temp = NULL;
	char ch = 'a';
	int num, i;
	nodeCh** arr;
	printf("Enter a number of array cells:\n ");
	scanf_s("%d", &num);
	printf("\n");
	arr = (nodeCh**)malloc(num * sizeof(nodeCh*));
	for (i = 0; i < num; i++) {
		head = NULL;
		printf("Enter a char to the list in arr[%d] to stop enter  ENTER: ", i);
		ch = getch();
		printf("\n");
		while (ch != '\r')
		{
			head = insert3(head, ch);
			printf("Enter a char to the list in arr[%d] to stop  ENTER: ", i);
			ch = getch();
			printf("\n");
		}
		arr[i] = head;
	}
	for (i = 0; i < num; i++) {
		temp = arr[i];
		printf("in arr[%d] the list node is\t", i);
		while (temp->node != NULL)
		{
			printf(" %c\t", temp->c);
			temp = temp->node;
		}
		printf(" %c\t", temp->c);
		printf("\n");
	}
	printf("\n\n");
	removeDupArrayLists(&arr, num);
	for (i = 0; i < num; i++) {
		temp = arr[i];
		printf("in arr[%d] the list node is\t", i);
		while (temp->node != NULL)
		{
			printf(" %c\t", temp->c);
			temp = temp->node;
		}
		printf(" %c\t", temp->c);
		printf("\n");
	}
	printf("\n");

}
nodeCh* createNode2(char c) {
	nodeCh* temp = (nodeCh*)malloc(sizeof(nodeCh));
	temp->c = c;
	temp->node = NULL;
	return temp;
}
nodeCh* insert3(nodeCh* head, char c) {
	nodeCh* newnode = createNode2(c);
	if (head == NULL) {
		head = newnode;
	}
	else {
		nodeCh* temp = head;
		while (temp->node != NULL) {
			temp = temp->node;
		}
		temp->node = newnode;

	}
	return head;
}
void deleteNode2(nodeCh** head, char c) {
	nodeCh* curr = *head;
	nodeCh* temp = curr;
	nodeCh* next = curr->node;
	nodeCh* nextNext;


	while (curr->node != NULL)
	{
		if (c == next->c)
		{
			if (next->node == NULL)
			{
				free(next);
				next->c = NULL;
				next = NULL;
				curr->node = NULL;
				return;
			}

			nextNext = next->node;
			curr->node = nextNext;
			free(next);
			next->c = NULL;
			next = NULL;
			return;
		}

		curr = curr->node;
		next = curr->node;
	}

}
void removeDupList(nodeCh** head) {
	int tav[26] = { 0 };
	nodeCh* newList = *head;
	nodeCh* curr = newList;

	nodeCh* prev = curr;
	nodeCh* next = curr->node;

	while (curr != NULL) {
		tav[curr->c - 'a']++;
		if (tav[curr->c - 'a'] > 1) {
			deleteNode2(&prev, curr->c);
			if (prev->node != NULL)
				curr = prev->node;
			else
				break;
		}
		if (curr->node != NULL)
			next = curr->node;
		else
			next = NULL;

		prev = curr;

		if (curr->node != NULL)
			curr = curr->node;
		else
		{
			curr = NULL;
			break;
		}
		if (curr->node != NULL)
			next = curr->node;
		else
			next = NULL;
	}


}
void removeDupArrayLists(nodeCh*** arr, int n) {
	int i;

	for (i = 0; i < n; i++) {

		removeDupList(&((*arr)[i]));

	}


}
//EX7 Functions
void Ex7() {
	nodeCh* head = NULL, * temp = NULL;
	char ch = 'a';

	nodeCh* sList = NULL;
	nodeCh* bList = NULL;
	nodeCh* nList = NULL;


	printf("Enter a char to the list to stop enter ENTER      ");
	ch = getch();
	printf("\n");
	while (ch != '\r')
	{
		head = insert3(head, ch);
		printf("Enter a char to the list to stop enter ENTER      ");
		ch = getch();
		printf("\n");
	}
	printf("\n\n");
	head = disassemblyList(head, &sList, &bList, &nList);

	temp = sList;
	printf("This is the small List: ");
	while (temp != NULL)
	{
		printf("%c \t ", temp->c);
		temp = temp->node;
	}

	printf("\n\n");

	temp = bList;
	printf("This is the Big List: ");
	while (temp != NULL)
	{
		printf("%c \t ", temp->c);
		temp = temp->node;
	}

	printf("\n\n");

	temp = nList;
	printf("This is the Num List: ");
	while (temp != NULL)
	{
		printf("%c \t ", temp->c);
		temp = temp->node;
	}

	printf("\n\n");

	temp = head;
	printf("This is the Other List: ");
	while (temp != NULL)
	{
		printf("%c \t ", temp->c);
		temp = temp->node;
	}

	printf("\n\n");
}
void removeNode2(nodeCh** head, char c) {
	nodeCh* curr = *head;
	nodeCh* temp = curr;
	nodeCh* next = curr->node;
	nodeCh* nextNext;


	while (curr->node != NULL)
	{
		if (c == next->c)
		{
			if (next->node == NULL)
			{
				next->c = NULL;
				next = NULL;
				curr->node = NULL;
				return;
			}

			nextNext = next->node;
			curr->node = nextNext;
			next->c = NULL;
			next = NULL;
			return;
		}

		curr = curr->node;
		next = curr->node;
	}

}
nodeCh* disassemblyList(nodeCh* head, nodeCh** sList, nodeCh** bList, nodeCh** nList) {

	nodeCh* smList = NULL;
	nodeCh* biList = NULL;
	nodeCh* nuList = NULL;
	nodeCh* list = head;
	nodeCh* temp = head;

	while (list != NULL) {
		if (list->c >= 65 && list->c <= 90) {
			biList = insert3(biList, list->c);
			removeNode2(&temp, list->c);
		}
		else if (list->c >= 97 && list->c <= 122) {
			smList = insert3(smList, list->c);
			removeNode2(&temp, list->c);
		}
		else if (list->c >= 48 && list->c <= 57) {
			nuList = insert3(nuList, list->c);
			removeNode2(&temp, list->c);
		}
		list = list->node;

	}
	*sList = smList;
	*bList = biList;
	*nList = nuList;
	if (temp != NULL)
		if ((temp->c >= 32 && temp->c <= 47) || (temp->c >= 58 && temp->c <= 64) || (temp->c >= 91 && temp->c <= 96) || (temp->c >= 123 && temp->c <= 126));
		else temp = temp->node;
	return temp;



}

/* ------------------- */
