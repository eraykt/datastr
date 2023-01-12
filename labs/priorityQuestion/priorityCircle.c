// datastr23@gmail.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Patient
{
    char name[20];
    char surname[20];
    int priorty;
} patient;

typedef struct PriorityQueue
{
    patient *data;
    struct PriorityQueue *next;
} pqueue;

pqueue *AddPatient(pqueue *head, int priority, char *name, char *surname)
{
    patient *newPatient = (patient *)malloc(sizeof(patient));
    strcpy(newPatient->name, name);
    strcpy(newPatient->surname, surname);
    newPatient->priorty = priority;

    pqueue *added = (pqueue *)malloc(sizeof(pqueue));
    added->data = newPatient;

    pqueue *iter = head;

    if (head == NULL)
    {
        head = (pqueue *)malloc(sizeof(pqueue));
        head = added;
        head->next = added;
        return head;
    }

    else if (head->data->priorty < newPatient->priorty)
    {
        if (iter->next != head)
        {
            while (iter->next != head)
                iter = iter->next;

            added->next = head;
            iter->next = added;
            head = added;

            return head;
        }

        else
        {
            added->next = head;
            head->next = added;
            head = added;
            return head;
        }
    }

    else
    {
        while (iter->next != head && iter->next->data->priorty > newPatient->priorty)
            iter = iter->next;

        if (iter->next == head)
        {
            added->next = head;
            iter->next = added;
        }

        else
        {
            pqueue *temp = iter->next;
            iter->next = added;
            added->next = temp;
        }

        return head;
    }
}

pqueue *RemovePatient(pqueue *head)
{
    if (head == NULL)
        return NULL;

    else if (head->next == head)
    {
        free(head);
        return NULL;
    }

    else
    {
        pqueue *removed = head;
        pqueue *iter = head;

        while (iter->next != head)
            iter = iter->next;

        iter->next = removed->next;

        head = head->next;
        free(removed);
        return head;
    }
}

patient *GetPatient(pqueue *head)
{
    if (head == NULL)
        return NULL;

    return head->data;
}

void printAll(pqueue *head)
{
    pqueue *iter = head;

    do
    {
        printf("%d %s %s\n", iter->data->priorty, iter->data->name, iter->data->surname);
        iter = iter->next;

    } while (iter != head);
}

void printPatient(patient *p)
{
    if (p != NULL)
        printf("oncelik->%d isim->%s soyisim->%s\n", p->priorty, p->name, p->surname);
}

int main(int argc, char const *argv[])
{
    pqueue *head = NULL;

    head = AddPatient(head, 1, "eray", "karatas");
    head = AddPatient(head, 8, "eray", "karatas");
    head = AddPatient(head, 2, "eray", "karatas");
    head = AddPatient(head, 5, "eray", "karatas");
    head = AddPatient(head, 4, "eray", "karatas");
    head = AddPatient(head, 9, "eray", "karatas");
    head = AddPatient(head, 7, "eray", "karatas");
    head = AddPatient(head, 3, "eray", "karatas");
    head = AddPatient(head, 6, "eray", "karatas");

    printAll(head);

    patient *p = GetPatient(head);
    head = RemovePatient(head);
    printPatient(p);

    printAll(head);

    return 0;
}
