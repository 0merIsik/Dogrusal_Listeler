#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct nodes {//struct of one node of lists that used in 1 and 2.
    struct nodes* next;
    int data;
};
typedef struct nodes node;

struct students {//struct of one node of student list.
    char name[30];
    int age;
    int no;
    struct students* next;
};
typedef struct students student;

//parameters
void listShow(node *head);// It is for print the lists in option 1 and option 2.
node* listCreate1(node *head);//for create the list in option 1.
void getInfo(node *temp);//option 1 and option 2 receive data.
node* listCreate2(node *head);//for create the list in option 2.
student* listCreateStudent(student *head2);//creates students list
void listShowAllStd(student *node);//show all student names.
void getInfoStudent(student *temp);//gets students names.
void ogrenciAra(student *head2,char aranan[]);//that searchs stutends with their name.
void dellNext(student *head2,char aranan[]);//that serch nmae and dell the next node.
void longestName(student *head2);//that search the logest name.

int main() {
    node *head = NULL;
    student *head2 = NULL;
    char c;
    char aranan[30];
    printf("Secim yapin secimler 1/2/3/4/5/6 sorulari temsil etmektedir.\n"
           "1-Klavyeden -1 girilinceye kadar, girilen tum tek sayilari listenin basina, cift sayilari listerin sonuna ekleyen fonksiyon\n"
           "2-Listeye rastgele uretilmis 100 sayi eklenir, girilen tum sayilari buyukten kucuge siralayan ve ekrana basan fonksiyon\n"
           "3-Ogrenci numarasi, isim ve yasinin sakli tutuldugu, listedeki tum dugumleri dolan, ogrenci bilgilerinin tumunu ekrana yazan ve sayan fonksiyon\n"
           "4-Listede ogrenci adina gore kayit arama yapan fonksiyon\n"
           "5-Listede aranan ogrenci adinin yer aldigi dugumden bir sonraki dugumu silen fonksiyon\n"
           "6-Listede en uzun ismin oldugu kayit\n");
    c = getchar();
    switch (c) {
        case '1':
            head = listCreate1(head);
            listShow(head);
            break;
        case '2':
            head = listCreate2(head);
            listShow(head);
            break;
        case '3':
            head2 = listCreateStudent(head2);
            listShowAllStd(head2);
            break;
        case '4':
        	head2 = listCreateStudent(head2);
        	fflush(stdin);
        	gets(aranan);
        	ogrenciAra(head2,aranan);
            break;
        case '5':
        	head2 = listCreateStudent(head2);
        	fflush(stdin);
        	gets(aranan);
        	dellNext(head2,aranan);
        	listShowAllStd(head2);
            break;
        case '6':
        	head2 = listCreateStudent(head2);
        	longestName(head2);
            break;
        default:
            printf("Gecersiz secim.");
            break;
    }
    return 0;
}

void longestName(student *head2){
	student longestN;
	longestN =* head2;
	head2 = head2 -> next;
	while(head2 != NULL){
		if(strlen(head2 -> name) > strlen(longestN. name)){//copare the nodes and find the longest name.
			longestN =* head2;//save the longest names data.
		}
		head2 = head2 -> next;
	}
	printf("%s %d %d\n", longestN.name, longestN.age, longestN.no);
}

void dellNext(student *head2,char aranan[]){
	while(head2 != NULL && strcmp(head2 -> name, aranan) != 0)//search all list if it find the wanted node head2 show it. if wnated name dosent exist head show NULL.
		head2 = head2 -> next;
	if(head2 == NULL)
		printf("Aranan isim listede yok");
	else if(head2 -> next == NULL){
		printf("Aranan isimden sonraki dugum null");
	}
	else{
		student *willDell;
		willDell = head2 -> next;
		head2 -> next=willDell -> next;//this part delate the wanted name.
		free(willDell);
	}
}

void ogrenciAra(student *head2,char aranan[]){
	while(head2 != NULL && strcmp(head2->name,aranan)!=0)//search all list if it find the wanted node head2 show it. if wnated name dosent exist head show NULL.
		head2=head2->next;
	if(head2 == NULL)
		printf("Aranan isim listede yok\n");
	else{
		printf("%s %d %d\n", head2->name, head2->age, head2->no);
	}
}

student* listCreateStudent(student* head2) {
    int numberOfStudents, i;
    student* temphead;
    printf("Lutfen ogrenci sayisini girin: ");
    scanf("%d", &numberOfStudents);
    for (i = 0; i < numberOfStudents; i++) {
        if (head2 == NULL) {
            head2 = (student*)malloc(sizeof(student));//create first node.
            getInfoStudent(head2);
            head2->next = NULL;
            temphead = head2;
        } else {
            temphead->next = (student*)malloc(sizeof(student));//create rest of the node.
            temphead = temphead->next;
            getInfoStudent(temphead);
            temphead->next = NULL;
        }
    }
    return head2;
}

node* listCreate2(node* head) {
    srand(time(NULL));
    head = (node*)malloc(sizeof(node));
    node* temphead = head;
    int i1, i2, i3;
    for (i1 = 0; i1 < 100; i1++) {
        temphead->data = rand();
        if (i1 == 99) {
            temphead->next = NULL;
        } else {
            temphead->next = (node*)malloc(sizeof(node));
            temphead = temphead->next;
        }
    }
    temphead = head;
    for (i1 = 0; i1 < 99; i1++) {
        for (i2 = 0; i2 + i1 < 99; i2++) {
            if (temphead->data < temphead->next->data) {
                node* temp;
                temp = temphead->next;
                temphead->next = temphead->next->next;
                temp->next = temphead;
                if (i2 == 0) {
                    head = temp;
                } else {
                    node* temp2 = head;
                    for (i3 = 0; i3 < i2 - 1; i3++)
                        temp2 = temp2->next;
                    temp2->next = temp;
                }
            }
            temphead = temphead->next;
        }
        temphead = head;
    }
    return head;
}

node* listCreate1(node* head) {
    node* temp = (node*)malloc(sizeof(node));
    getInfo(temp);
    while (temp->data != -1) {
        if (head == NULL) {
            temp->next = NULL;
            head = temp;
        } else if (temp->data % 2 != 0) {//this paart chose where the new node will be add.
            temp->next = head;
            head = temp;
        } else {
            temp->next = NULL;
            node* temphead = head;
            while (temphead->next != NULL)
                temphead = temphead->next;
            temphead->next = temp;
        }
        temp = (node*)malloc(sizeof(node));
        getInfo(temp);
    }
    free(temp);
    return head;
}

void listShow(node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void listShowAllStd(student* node) {
    int i = 1;
    while (node != NULL) {
        printf("%d - %s %d %d\n", i++, node->name, node->age, node->no);
        node = node->next;
    }
}

void getInfo(node* temp) {
    printf("Lutfen data girin: ");
    scanf("%d", &temp->data);
}

void getInfoStudent(student* temp) {
    printf("Isim girin: ");
    fflush(stdin);
    scanf("%s", temp->name);
    printf("Yas girin: ");
    scanf("%d", &temp->age);
    printf("No girin: ");
    scanf("%d", &temp->no);
}

