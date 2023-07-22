
#include<windows.h>
#include <iostream>

using namespace std;

void insertFirst(int data, char foodname[25], int quantity, float price);
void insertMid(int pos, int data, char foodname[25], int quantity, float price);
void insertEnd(int data, char foodname[25], int quantity, float price);
void updateFood(int udata, int uquantity);
void foodList();
void orderView(int order, int quantity, int orderNo);
void mainmenu();
void deleteFood(int serialNo);
int countItem();

void cls();
void echo(char print[]);
void line(int line);
void tab(int tab);
void space(int space);
void color(int color);
void welcome();

struct Node{
    char foodname[50];
    int quantity;
    float price;
    int data;
    Node *next;
};
typedef struct Node node;
node *head, *list;

int main() {

    welcome();
    
    int c = 0;
    int any;
    int cardNo[100];
    float cardMoney[100];
    float totalMoney = 0;
    int totalOrder[100];
    int orderQuantity[100];
    int order = 0;
    int uQuantity;
    int citem;
    
    head = NULL;
    
	insertFirst(1,"Cookies",8,720.83);
	insertEnd(2,"Coffee  ",46,70.23);
	insertEnd(3,"Brownies   ",46,70.23);
	insertEnd(4,"Hot Pudding  ",34,60.23);    
  	insertEnd(5,"Birthday Cakes",23,120.23);
	insertEnd(6,"Pancakes    ",13,100.67);
	insertEnd(7,"Chocolate Ice cream",7,520.29);
	insertEnd(8,"Grain Breads",121,35.13);
	insertEnd(9,"Cold drinks",73,20.13);
	
	MainMenu:
	line(1);
	mainmenu();
	int mainmenuOpt;
	
	line(1);
	tab(4);
	fflush(stdin);
	cin>>mainmenuOpt;
	if (mainmenuOpt >= 1 && mainmenuOpt <= 3){
		if (mainmenuOpt == 1){
			
			FoodList:
				
				cls();
				printf(">> 0.Main Menu");
				foodList();
		}else if (mainmenuOpt == 2){
			AdminPanel:
				int adminpanelOpt;
				cls();
				tab(4);
				printf("1. MainMenu \n\n\t");
				Sleep(300);
				printf("Enter PassWord or Press 1 to Back in MainMenu : ");
				
				fflush(stdin);
				cin>>adminpanelOpt;
				
				if (adminpanelOpt == 1234){
					
					node *temp;
					temp = list;
					
					AdminChoice:
						
						cls();
						line(3);
						tab(4);
						printf(">>>>> Admin Panel <<<<  \n\n");
						tab(4);
						printf(" 1. Total Cash Today \n\n");Sleep(250);
						tab(4);
						printf(" 2. View Card Pay \n\n");Sleep(250);
						tab(4);
						printf(" 3. Add Bakery Item \n\n");Sleep(250);
						tab(4);
						printf(" 4. Delete Item \n\n");Sleep(250);
						tab(4);
						printf(" 5. Instant Item List \n\n");Sleep(250);
						tab(4);
						printf(" 6. Item Counter \n\n");Sleep(250);
						tab(4);
						printf(" 7. Instant Order Preview\n\n");Sleep(250);
						tab(4);
						printf(" 0. Main Menu \n\n");
						printf("Enter Your From 1-0: ");
						
						int adminchoice;
						
						fflush(stdin);
						
						cin>>adminchoice;
						
						if (adminchoice == 1){
							cls();
							tab(4);
							printf("Todays Total Cash : %0.2f  \n", totalMoney);
							Sleep(1000);
							goto AdminChoice;
						}else if(adminchoice == 2){
							if (c != 0){
								cls();
								line(4);
								tab(4);
								printf(" ____________________________\n");
								tab(4);
								printf("|   Card NO.   |   Money Rs   |\n");
								tab(4);
								printf("------------------------------\n");
								tab(4);
								for (int i = 1; i <= c; i++){
								printf("|  %d  | %0.2f |\n",cardNo[i],cardMoney[i]);
								tab(4);
								printf("------------------------------\n");
								tab(4);
								Sleep(150);
								}
							}
							if (c == 0){
								cls();
								tab(4);
								printf("No Card History\n");
								}
								Sleep(1000);
								goto AdminChoice;
							}
							else if(adminchoice == 3){
								
								FoodAdd:
									cls();
									char foodname[25];
									int foodquantity;
									int fooddata;
									float foodprice;
									int foodpos;
									line(3);
									tab(4);
									printf("Enter Bakery Item :");
									fflush(stdin);
									cin>>foodname;
									
									FoodQuantity:
										fflush(stdin);
										line(2);
										tab(4);
										printf("Enter Item Quantity :");
										cin>>foodquantity;
										fflush(stdin);
										
										FoodSerial:
											line(2);
											tab(4);
											printf("Enter Serial No ");
											cin>>fooddata;
											node *exist;
											exist = list;
											while(exist->data != fooddata){
												if (exist->next == NULL){
													break;
												}
												exist = exist->next;
											}
											if (exist->data == fooddata){
												cls();
												line(5);
												tab(3);
												printf(" Bakery Item Serial Already Exist, Please Re-Enter  ");
												Sleep(1000);
												goto FoodSerial;
											}
											FoodPrice:
												fflush(stdin);
												line(2);
												tab(4);
												printf(" Enter Item Price :  ");
												fflush(stdin);
												cin>>foodprice;
												line(2);
												tab(4);
												printf("Submitting your data");
												for (int i = 0; i < 4 ; i++){
													printf(" .");
													Sleep(300);
												}
												insertEnd(fooddata, foodname, foodquantity, foodprice);
												line(2);
												tab(4);
												printf("Item Added........\n");
												Sleep(1000);
												goto AdminChoice;
							}else if (adminchoice == 4){
								cls();
								tab(2);
								printf("Enter serial No of item to delete : ");
								FoodDelete:
								int fooddelete;
								fflush(stdin);
								cin>>fooddelete;
								node *temp;
								temp = list;
								while (temp->data != fooddelete){
									temp = temp->next;
								}
								if (temp->data = fooddelete){
									temp=NULL;
									
								}else{
									line(2);
									tab(2);
									printf("Enter correct no :");
									Sleep(100);
									goto FoodDelete;
								}
								goto AdminChoice;
							}
							else if (adminchoice == 5){
								cls();
								foodList();
								Sleep(500);
								goto AdminChoice;
							}
							else if (adminchoice == 6){
								citem = countItem();
								cls();
								for (int i = 1; i <= citem; i++){
									tab(4);
									printf("Item counting");
									printf(" %d ", i);
									Sleep(50);
									cls();
								}
								cls();
								tab(4);
								printf("Total Items are ---> %d \n", citem);
								Sleep(1000);
								goto AdminChoice;
							}
							else if (adminchoice == 7){
								cls();
								line(2);
								tab(2);
								printf("______________________________________________________ ");
								printf("|  Order No.  |   Item Name   |  Quantity |  In Stock |");
								printf("------------------------------------------------------");
								for (int i =1; i<=order;i++){
								orderView(totalOrder[i], orderQuantity[i], i);
								}
								line(2);
								tab(4);
								Sleep(2000);
								goto AdminChoice;
							}
							else if (adminchoice == 0){
								goto MainMenu;
							}
							else{
								line(2);
								tab(4);
								printf("Please select from list : ");
								Sleep(500);
								goto AdminChoice;
							}
							
							
						}
						else if (adminpanelOpt == 1){
							goto MainMenu;
						}	
						else{
							line(2);
								tab(4);
								printf("Please select from list : ");
								Sleep(500);
								goto AdminPanel;
						}
				}else if (mainmenuOpt == 3){
					cls();
					tab(3);
					printf("Thank You for using our system. \n");
					Sleep(1000);
					exit(1);
				}
		}else{
			line(2);
			tab(4);
			printf("Please select from list : ");
			Sleep(500);
			goto MainMenu;
		}
		
		int foodChoice;
		
		line(2);
		tab(4);
		printf("Place your order");
		fflush(stdin);
		cin>>foodChoice;
		
		
		if (foodChoice == 0){
			goto MainMenu;
		}
		
		node *temp;
		temp = list;
		
		while(temp->data != foodChoice){
			
			temp = temp->next;
			if (temp == NULL){
				line(2);
				tab(4);
				printf("Please choose from list");
				line(2);
				Sleep(500);
				goto FoodList;
			}
		}
		if (foodChoice == temp->data){
			FoodChoiceQuantity:
				line(2);
				tab(4);
				printf("Enter Item Quantity");
				
				int foodQuantity;
				fflush(stdin);
				cin>>foodQuantity;
				cls();
				
				if (foodQuantity == 0){
					cls();
					tab(4);
					printf("Quantity cant be zero");
					Sleep(1000);
					cls();
					goto FoodList;
				}
				else if (foodQuantity>temp->quantity){
					cls();
					tab(4);
					printf("Out of Stock");
					goto FoodList;
				}
				
				tab(4);
				printf("Choice item %s its price is %0.2f \n\n", temp->foodname, temp->price * foodQuantity);
				tab(4);
				printf("1. Confirm to buy this \n\n");
				tab(4);
				printf("2. Item List \n\n");
				
				Confirm:
					int confirm;
					fflush(stdin);
					cin>>confirm;
					
					if (confirm == 1){
						line(2);
						tab(4);
						printf("1. Cash");
						line(2);
						tab(4);
						printf("2. Credit");
						Payment:
							int payment;
							fflush(stdin);
							cin>>payment;
							if (payment == 1){
								totalMoney += temp->price*foodQuantity;
								order++;
								totalOrder[order]=foodChoice;
								orderQuantity[order]=foodQuantity;
								uQuantity = temp->quantity - foodQuantity;
				
								updateFood(foodChoice ,uQuantity);
				
				
								cls();
								tab(4);  
								printf("===>THANK YOU<===");
								line(2);
								tab(4);  
								printf("Item Ordered Successfully ...");
								line(2);
								tab(4);  
								printf("1. Wanna Buy Another Item ? ");
								line(2);
								tab(4);  
								printf("2. Main Menu \n");
								line(2);
								tab(4);  
								 printf("Select: ");
								PSMenu:
								int psmenu;
								fflush(stdin);
								cin>>psmenu;
				
								if(psmenu==1){
								goto FoodList;
								}
								else if(psmenu==2){
								goto MainMenu;
								}
								else{
								printf("Please Choice from list : "); 
								goto PSMenu;
								}
							}
							else if (payment == 2){
								int cardNumber[100];
								c++;
								cls();
								tab(4);
								printf("Enter Your Card No : ");
								fflush(stdin);
								cin>>cardNumber[c];
								cardNo[c] = cardNumber[c];
				
								int pin;
				
								line(2);
								tab(4);  
								printf("Enter Your Card Pin [we never save your pin]  : ");
								fflush(stdin);
								cin>>pin;
				
								cardMoney[c] = temp->price*foodQuantity;
								totalMoney += temp->price*foodQuantity;
								order++;
								totalOrder[order]=foodChoice;
								orderQuantity[order]=foodQuantity;
								uQuantity = temp->quantity - foodQuantity;
				
								updateFood(foodChoice ,uQuantity);
				
				
								cls();
								tab(4);  
								printf("===>THANK YOU<===");
								line(2);
								tab(4);  
								printf("Item Ordered Successfully ...");
								line(2);
								tab(4);  
								printf("1. Wanna Buy Another Item ? ");
								line(2);
								tab(4);  
								printf("2. Main Menu \n");
								line(2);
								tab(4);  
								 printf("Select: ");
								PSMenu2:
								int psmenu2;
								fflush(stdin);
								cin>>psmenu2;
				
								if(psmenu2==1){
								goto FoodList;
								}
								else if(psmenu2==2){
								goto MainMenu;
								}
								else{
								printf("Please Choice from list : "); 
								goto PSMenu2;
								}
							}
							else{
								printf("Choose from list");
								goto Payment;
							}
					}
					else if (confirm == 2){
						goto FoodList;
					}
					else{
						line(2);
						tab(4);
						printf("Choose from List");
						goto Confirm;
					}
			}else{
						line(2);
						tab(4);
						printf("Choose from List");
						goto FoodList;
			}
			
}

void cls(){
    system("cls");
}
void echo(char print[]){
    printf("&s", print);
}
void line(int line){
    for (int i = 0; i < line; i++){
        cout<<"\n";
    }
}
void tab(int tab){
    for (int i = 0; i < tab; i++){
        cout<<"\t";
    }
}
void space(int space){
    for (int i = 0; i < space; i++){
        cout<<" ";
    }
}
void mainmenu(){
    cls();
    line(5);
    tab(3);
    cout<<">> 1. Bakery Item List";
    Sleep(400);
    line(2);
    tab(3);
    cout<<">> 2. Admin";
    Sleep(400);
    line(2);
    tab(3);
    cout<<">> 3. Exit";
    Sleep(400);
}
void welcome(){
    //color(26);
    
    char welcome[8] ="Welcome";
    char welcome2[3] = "To";
    char welcome3[7] = "Bakery";
    cout<<"\n\n\n\n\n\n\t\t\t";
    for (int i = 0; i < strlen(welcome); i++){
        printf(" %c", welcome[i]);
        Sleep(50);
    }
    cout<<"\n\n\n\t\t\t";
    for (int i = 0; i < strlen(welcome2); i++){
        printf(" %c", welcome2[i]);
        Sleep(50);
    }
    cout<<"\n\n\n\t\t      ";
    for (int i = 0; i < strlen(welcome3); i++){
        printf(" %c", welcome3[i]);
        Sleep(50);
    }
}

void insertFirst(int data, char foodname[25], int quantity, float price){
	node *temp;
	
	//temp = NULL;
	temp = (node *)malloc(sizeof(node));
	
	temp->data = data;
	temp->price = price;
	temp->quantity = quantity;
	strcpy(temp->foodname, foodname);
	
	temp->next = head;
	head = temp;
	list = head;
}
void insertEnd(int data, char foodname[25], int quantity,  float price){
	node *temp;
	
//	temp = NULL;
	temp = (node *)malloc(sizeof(node));
	
	temp->data = data;
	temp->price = price;
	temp->quantity = quantity;
	strcpy(temp->foodname, foodname);
	temp->next = NULL;
	
	if (head == NULL){
		head = temp;
		list = head;
	}else{
		while (head->next != NULL){
			head = head->next;
		}
		head->next = temp;
	}
}
void insertMid(int pos, int data, char foodname[25], int quantity, float price){
	Node *temp;
	
	temp = NULL;
	
	temp->data = data;
	temp->price = price;
	temp->quantity = quantity;
	strcpy(temp->foodname, foodname);
	
	while(head->next->data != pos){
		head = head->next;
	}
	
	temp->next = head->next;
	head->next = temp;
}
void foodList(){
	printf("\n\t\t");
	printf("_______________________________________________________________  ");
	printf("\n\t\t");
	printf("|  Item No.  |   Item Name   |  Price  |   In Stock   |");
	printf("\n\t\t");
	printf("---------------------------------------------------------------  ");
	
	Node *temp;
	
	temp = list;
	
	while(temp != NULL){
		printf("\n\t\t");
		printf("|     %d     |     %s     |   %0.2f    |    %d      | ", temp->data, temp->foodname, temp->price, temp->quantity);
		printf("\n\t\t");
		printf("---------------------------------------------------------------  ");
		temp = temp->next;
		Sleep(50);
	}
}
void updateFood(int uData, int uQuantity){
	node *temp;
	temp = list;
	
	while (temp->data!=uData){
		temp=temp->next;
	}
	
	if (temp->data == uData){
		temp->quantity = uQuantity;
	}
}
int countItem(){
	node *temp;
	temp= list;
	int countItem;
	
	if (temp==NULL){
		countItem = 0;
	}else{
		countItem = 1;
		while(temp->next != NULL){
			countItem++;
			temp= temp->next;
		}
	}
	return countItem;
}
void orderView(int order, int quantity, int orderNo){
	node *temp;
	temp = list;
	
	while(temp->data == order){
		
		printf("\n\t\t");
		printf("|     %d      |    %s  |     %d     |     %d     |",orderNo,temp->foodname,quantity,temp->quantity);
		printf("\n\t\t"); 
		Sleep(100);
	}
}

