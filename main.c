#include "shoppingmall.c"

//Function:     main_menu
//Description:  displays the main menu
//Input param:  NULL
//Return Type:  NULL
void main_menu()
{
    printf("\n");
    printf("\n");
    printf("-------------------------------Main menu-------------------------------");
    printf("\n");
    printf("\n");
    printf("0 -> Exit\n");
    printf("1 -> Employee menu\n");
    printf("2 -> Customer menu\n");
    printf("3 -> Shop menu\n");
    printf("4 -> Parking menu\n");
}


//Function:     employee_menu
//Description:  displays the employee menu
//Input param:  NULL
//Return Type:  NULL
void employee_menu()
{

    printf("\n");
    printf("\n");
    printf("-------------------------------Employee menu-------------------------------");
    printf("\n");
    printf("\n");

    printf("0 -> Exit\n");
    printf("1 -> Search employee\n");
}


//Function:     customer_menu
//Description:  displays the customer menu
//Input param:  NULL
//Return Type:  NULL
void customer_menu()
{

    printf("\n");
    printf("\n");
    printf("-------------------------------customer menu-------------------------------");
    printf("\n");
    printf("\n");

    printf("0 -> Exit\n");
    printf("1 -> Search customer detail through transaction id\n");
}


//Function:     shop_menu
//Description:  displays the shop menu
//Input param:  NULL
//Return Type:  NULL
void shop_menu()
{

    printf("\n");
    printf("\n");
    printf("-------------------------------Shop menu-------------------------------");
    printf("\n");
    printf("\n");

    printf("0 -> Exit\n");
    printf("1 -> Search shop\n");
    printf("2 -> Print all shop details\n");
}


//Function:     parking_menu
//Description:  displays the parking menu
//Input param:  NULL
//Return Type:  NULL
void parking_menu()
{

    printf("\n");
    printf("\n");
    printf("-------------------------------Parking menu-------------------------------");
    printf("\n");
    printf("\n");

    printf("0 -> Exit\n");
    printf("1 -> Generate parking ticket\n");
    printf("2 -> Verify parking ticket");
}


/// This function was for debugging

void print_all()
{
    for(int i=0;i<employee_row;i++)
    {
        for(int j=0;j<employee_col;j++)
        {
            printf("%s ",employee_str[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<customer_row;i++)
    {
        for(int j=0;j<customer_col;j++)
        {
            printf("%s ",customer_str[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<shop_row;i++)
    {
        for(int j=0;j<shop_col;j++)
        {
            printf("%s ",shop_str[i][j]);
        }
        printf("\n");
    }
}

int main() {

    status = load();
    if (!status)
    {
        printf("\n");
        printf("Could not find file....");
        printf("\n");
        printf("Try changing path of the files....");
        printf("\n");
        return 0;
    }

    printf("\n");
    printf("\n");
    printf("If you want to take input make modification in respective txt file.");
    printf("\n");
    printf("Only parking managemment is real time....");
    printf("\n");
    printf("\n");

//    print_all();
//    printf("%d\n",KMPSearch("12","12"));
    while (1)
    {
        main_menu();
        scanf("%d", &choice1);
        switch (choice1)
        {
            case 0:
                return 0;
                break;

            case 1:
                employee_menu();
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 0:
                        return 0;

                    case 1:
                        employee_root=load_to_struct_employee(employee_root,employee_str,employee_row);
                        search_employee();
                        break;

                }
                break;

            case 2:
                customer_menu();
                customer_root=load_to_struct_customer(customer_root,customer_str,customer_row);
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 0:
                        return 0;

                    case 1:
                        search_customer_trans_id();
                        break;

                }
                break;

            case 3:
                shop_menu();
                scanf("%d",&choice2);
                group_shops();
                switch(choice2)
                {
                    case 0:
                        return 0;

                    case 1:
                        search_shop();
                        break;

                    case 2:
                        print_shop_details();
                        break;

                }
                break;

            case 4:
                parking_menu();
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 0:
                        return 0;

                    case 1:
                        generate_parking_ticket();
                        break;

                    case 2:
                        verify_parking_ticket();
                        break;

                }
                break;

            default:
                printf("\n");
                printf("Wrong choice...try again");
                printf("\n");

        }
    }
    return 0;
}