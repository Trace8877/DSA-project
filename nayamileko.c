#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[100];
    float per;
    struct node *prev; // points towards prev
    struct node *next; // points toward next
};

struct node *head = NULL;

void create(void)
{
    int n;
    char name[100];
    float a, b, c, d, e;
    float per;
    fflush(stdin);
    printf("Enter name: ");
    fgets(name,100,stdin);
   
    printf("Enter marks of 5 subjects:\n");
    n= scanf("%f%f%f%f%f",&a, &b, &c, &d, &e);
    
    per = (a + b + c + d + e) / 5;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Failed to allocate memory\n");
        return;
    }
    strcpy(newNode->name, name);
    newNode->per = per;
    newNode->next = newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->roll=1;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
 
}
void display(void)
{
    struct node *ptr;
    ptr=head;
    if (ptr == NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
    else
    {
        printf("Name\t\tRoll No.\tPercentage\n");
        while (ptr != NULL)
        {
            printf("%-20s%-20d%-20.2f%%\n", ptr->name, ptr->roll, ptr->per);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void sorting_alpha(void) {
    if (head == NULL) {
        printf("\nList is Empty!!\n");
        return;
    }
  
    struct node *i, *j;
    char tempName[100];
    int tempRoll;
    float tempPercentage;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                strcpy(tempName, i->name);
                tempRoll = i->roll;
                tempPercentage = i->per;
                strcpy(i->name, j->name);
                i->roll = j->roll;
                i->per = j->per;
                strcpy(j->name, tempName);
                j->roll = tempRoll;
                j->per = tempPercentage ;
            }
        }
    }

}
void roll(void)
{
    int k=1;
   struct node * ptr=head;
      while (ptr!=NULL)
      {
       ptr->roll= k;
     ptr=ptr->next;
       k++;
      }
}
void search_roll(void)
{
    int k=1,r,test=0;
    struct node* ptr=head;

    if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    printf("Enter the roll no. to search: ");
    scanf("%d",&r);
    
    while(ptr!=NULL)
    {
        if (k==r)
        {
        printf("Name\t\tRoll No.\tPercentage\n");
        printf("%-20s%-20d%-20.2f%%\n", ptr->name, ptr->roll, ptr->per);
            test++;
        }
        ptr=ptr->next;
        k++;
    if(test==1)
    {
        return;
    }
    }
    if(test==0)
    {
        printf("The roll no. could not be found.\n");
        return;
    }
}
void search_name(void)
{
    int test=0;
    char tempname[100] ;
    struct node * ptr;
    ptr= head;
   if (ptr == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }
    fflush(stdin);
    printf("Enter the name of student to search:\n");
    fgets(tempname,100,stdin);
    while(ptr!=NULL){
        if (strcmp(ptr->name,tempname)==0){
            printf("Name\t\tRoll No.\tPercentage\n");
            printf("%-20s%-20d%-20.2f%%\n", ptr->name, ptr->roll, ptr->per);
            test++;
        }
        ptr=ptr->next;
        if(test==1)
        {
            return;
        }
    }
    if (test==0)
    {
        printf("The name could not be found.\n");
        return;
    }
}
void del_pos(void)
{
    struct node *ptr = head;
    int i, pos;
    printf("enter the position");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(ptr);
        printf("Student deleted successfully.\n");
        return;
    }
    for (i = 1; i < pos && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Position not found.\n");
        return;
    }
    ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = ptr->prev;
    }
    free(ptr);
    printf("Student deleted successfully.\n");
    
}


    void overview(void)
    {
        struct node *ptr;
        ptr = head;
        int i, count = 0;
        float avg = 0, pass_rate = 0, total = 0, per,pass_num=0;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        ptr = head;
        for (i = 0; i < count; i++)
        {
            if ((ptr->per) >= 40)
            {
                pass_num++;
            }
            ptr=ptr->next;
        }
       
        ptr = head;
        for (i=0;i<count;i++)
        {
            total = total + ptr->per;
            ptr = ptr->next;
        }
        avg = total / count;
        pass_rate = (pass_num / count) * 100;
        printf("\n======CLASS OVERVIEW======\n");
        printf("Total number of students=%d\n", count);
        printf("The pass num is %f\n",pass_num);
        printf("The average percentage of the students is=%.2f\n", avg);
        printf("The pass rate of the students is=%.2f%%\n", pass_rate);
    }

int main()
{
    int choice;
    char c;
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Add a student to the list\n");
        printf("2. Display the list of students\n");
        printf("3. Delete a student from the list\n");
        printf("4. Search for a specific students' details:\n");
        printf("5. Print the overview of the students.\n");
        printf("6. Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
                roll();
            sorting_alpha();
            break;
        case 2:
                roll();
                sorting_alpha();
            display();
            
            break;
        case 3:
           del_pos();
          break;
               
            case 4:
                printf("Do you want to search using roll no. or name?\n Press 'R' for roll no. and 'N' for name: ");
                scanf("%s", &c);
                roll();
                sorting_alpha();

                if(c=='R'|| c=='r')
                {
                    search_roll();
                    break;
                }
             else if(c=='N'|| c=='n')
               {
                    search_name();
                    break;
               }
                else{
                    printf("Invalid option.\n");
                    break;
                }
        case 5:
            overview();
            break;
      
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

