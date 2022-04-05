/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 7 - Stacks and Queues
*Percobaan        : -
*Hari dan Tanggal : Rabu, 6 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

struct QNode
{
	int key;
	struct QNode *next;
};

struct Queue
{
	struct QNode *front, *rear;
};

struct QNode *newNode(int k)
{
	struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue *createQueue()
{
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void tambah(struct Queue *q, int k)
{
	struct QNode *temp = newNode(k);
	if (q->rear == NULL)
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void hapus(struct Queue *q)
{
	if (q->front == NULL)
		return;
	struct QNode *temp = q->front;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
}

int main()
{
	struct Queue *q = createQueue();
	int x, m;

	printf("Pilihan Menu :\n1. Hapus\n2. Tambah\n99. Akhiri\n");
	do
	{
		printf("Masukan Pilihan: ");
		scanf("%d", &m);
		if (m == 1)
		{
			hapus(q);
			printf("1 Data terhapus\n");
		}
		else if (m == 2)
		{
			printf("Masukan angka : ");
			scanf("%d", &x);
			tambah(q, x);
		}
	} while (m != 99);

	printf("Angka Paling Depan : %d \n", q->front->key);
	printf("Angka Paling Belakang : %d", q->rear->key);
	return 0;
}
