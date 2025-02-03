//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head,x ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    struct node d;
    b.next = &d; //add value that next to b
    d.value = 11;
    b.next->value = 11;
    //*d.value = 11;
    //a.next->next->value = 11;
    //head->next->next->value = 11;
    //เขียนแบบไหนก็ได้ ความหมายเหมือนกัน 
    d.next = NULL;


/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */

    printf("%d\n", head->value); //what value for 5
    printf("%d\n", head->next->value ); //what value for 8
    printf("%d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)        
*/

    struct node f;
    f.next = &a;
    head = &f;
    f.value = 2;

    printf("%d\n", head->value); //what value for 2
    printf("%d\n", head->next->value); //what value for 5
    printf("%d\n", head->next->next->value); //what value for 8
    printf("%d\n", head->next->next->next->value); //what value for 11

    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
   int i,n=4;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
            tmp = tmp->next; //จะชี้ไปที่ next ของ tmp
        }
        printf("\n");
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
   tmp=head; //reset ค่าของ tmp
   while(tmp!=NULL){
    printf("%3d", tmp->value);
    tmp = tmp->next;
   }
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */

    head=(NodePtr) malloc(sizeof(struct node));
    tmp=head;
    
    printf("\n\n");
    for(i=0;i<3;i++)
    {
        //ใส่ค่า i+3 ใน value
        tmp->value=i+3;
        tmp->next=(NodePtr) malloc(sizeof(struct node));
        tmp=tmp->next;
    }
    tmp->value=i+3;
    tmp->next=NULL;

    tmp=head; //reset ค่าของ tmp
    while(tmp!=NULL){
        head=head->next;
        printf("Free %d\n",tmp->value);
        free(tmp);
        tmp=head;
    }

    return 0;
}