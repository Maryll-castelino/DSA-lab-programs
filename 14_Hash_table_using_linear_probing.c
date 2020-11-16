#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE];

void insert()
{

    int key, index, i, flag = 0, hkey;
    printf("\nEnter a value to insert into hash table : ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for(i = 0; i < TABLE_SIZE; i++)
        {
            index = (hkey + i) % TABLE_SIZE;

            if(h[index] == 0)
            {
                h[index] = key;
                flag = 1;
                break;
            }

        }

        if(flag == 0)
        {
            printf("\nElement cannot be inserted\n");
        }else{
            printf("\nElement is inserted\n");
            flag = 0;
        }
}
void search()
{

    int key, index, i, flag = 0, hkey;
    printf("\nEnter search element : ");
    scanf("%d", &key);
    hkey = key % TABLE_SIZE;
    for(i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        if(h[index] == key)
        {
            printf("value is found at index %d",index);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("\n value is not found\n");
        flag = 0;
    }
}
void display()
{
    int i;

    printf("\nElements in the hash table are \n");
    for(i=0;i< TABLE_SIZE; i++)
    {
        printf("\nat index %d \t value =  %d",i,h[i]);
    }
    printf("\n");

}
void main()
{
    int opt,i;
    while(1)
    {
        printf("\nChoose an option: \n1.Insert\n2.Display\n3.Search\n4.Exit\n->");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);
        }
    }
}
