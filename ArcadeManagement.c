#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Player
{
    int token;
    char * name;
    // The pointer to the next node in list
    struct Player *next;
} Player;

void FreePlayer(Player *player)
{
    //just frees the player
    free(player->name);
    free(player);

}

Player *createPlayer(int Token, char *Name)//DONE
{
    //allocate space
    Player *new = (Player *)calloc(1, sizeof(Player));
    //similar to the usual create node function except
    //using a alloc for the name as well
    new->name = calloc(strlen(Name),sizeof(char));
    strcpy(new->name,Name);
    new->token = Token;
    new->next = NULL;
    return new;
}

Player *insertPlayer(Player *head,int Token,char *Name)//DONE
{
    // if list is null make new node
    if (head == NULL)
    {
        return createPlayer(Token,Name);
    }
    Player *new = createPlayer(Token,Name);
    // new nodes next is head
    new->next = head;
    // make what is in new, head
    //couldve made it = head but decided to just leave that line out
    return new;
}

Player * removePlayer(Player *head)//DONE
{
    // if list empty return
    if (head == NULL)
    {
        return NULL;
    }
    //free if list has element
    Player *current = head->next;
    FreePlayer(head);

    return current;
}

void maxPlayer(Player * head)//DONE
{
  Player * fistNode=head;
  while(head!=NULL)
  {
    //if first node head is less than token make first node head
    if(fistNode->token < head->token)
    {
        fistNode = head;
    }
    head = head->next;
  }
  printf("%s \n",fistNode->name);
}

int main()
{
  //make linked list and = to NULL
  Player * head = NULL;// current
  int choice;
  int token;
  char name [21];
  scanf("%d", &choice);
//While the choice we input is not 0 keep going because 0 kills program
while(choice!=0)
{
//using a switch statement so that i can go based off input easier than if statements
switch(choice)
{
      case 0 : //kill program
        return 0;
        break;

      case 1 ://get player info
      scanf("%d %s",&token,name);
      // add values to the front of the list
      head = insertPlayer(head,token,name);
      scanf("%d",&choice);
      break;

      case 2 ://player leaving POP
         head = removePlayer(head);
         scanf("%d",&choice);
         break;

      case 3 ://output most valuable player
         maxPlayer(head); //if current <max store it
         scanf("%d",&choice);
         break;

   }
}
    return 0;
}
