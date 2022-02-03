//
// Created by suvom on 17-02-2021.
//

#include "shoppingmall.h"
#include "settings.h"
#include "locals.h"


///-------------------------------------------File management---------------------------------------------------------------


//Function:     file_empty_check
//Description:  checks if a given file is empty or not
//Input param:  char*
//Return Type:  int
int file_empty_check(char *filename)
{
    // Declaring "stat" a system call to know about content of file.
    struct stat filestat;
    stat(filename, &filestat);
    //check size of file and return appropriate status.
    if (filestat.st_size == 0)
    {
        return FILE_EMPTY_ERROR;
    }
    else
    {
        return SUCCESS;
    }
}


//Function:     load
//Description:  load all the given txt files into respective strings
//Input param:  NULL
//Return Type:  int
int load()
{


    ///----------------------------------------Start of load of employee----------------------------------------------


    // Use a file pointer to open various files to load the values
    FILE *fp;

    //Local variables
    int index = 0;
    int key_index = 0;
    int status = 0;
    int file_status = 0;


    //check whether employee.txt file is empty or not.
    file_status = file_empty_check("employee.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether employee_prop.txt file is empty or not.
    file_status = file_empty_check("employee_prop.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether employee_number.txt file is empty or not
    file_status = file_empty_check("employee_number.txt");
    if (file_status  ==  FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    // Open the employee_number file to read the number of keywords
    fp = fopen("employee_number.txt","r");
    if (fp == NULL)
    {
        return FAILURE;
    }


    fscanf(fp, "%d", &employee_row);
    if (employee_row <= 0)
    {
        return FAILURE;
    }
    fclose(fp);

    // Open the employee_prop file to read the number of properties
    fp = fopen("employee_prop.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    fscanf(fp, "%d", &employee_col);
    if (employee_col <= 0)
    {
        return FAILURE;
    }
    fclose(fp);


    // Open the employee to read the available inventory details
    fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }


    key_index=0;
    // Load the details from file to employee_str
    while (!feof(fp))
    {
        for (index = 0; index < employee_col; index++)
        {
            fscanf(fp, "%s ", employee_str[key_index][index]);
        }
        key_index++;
    }
    key_index=0;
    fclose(fp);
//    printf("1\n");



    ///-------------------------------------------------End of load of employee-----------------------------------------



    ///------------------------------------------------Start of load of shop--------------------------------------------

    //check whether shop.txt file is empty or not.
    file_status = file_empty_check("shop.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether shop_prop.txt file is empty or not.
    file_status = file_empty_check("shop_prop.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether shop_number.txt file is empty or not
    file_status = file_empty_check("shop_number.txt");
    if (file_status  ==  FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    // Open the shop_number file to read the number of keywords
    fp = fopen("shop_number.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    fscanf(fp, "%d", &shop_row);
    if (shop_row <= 0)
    {
        return FAILURE;
    }
    fclose(fp);

    // Open the shop_prop file to read the number of properties
    fp = fopen("shop_prop.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    fscanf(fp, "%d", &shop_col);
    if (shop_col <= 0)
    {
        return FAILURE;
    }
    shop_col=6;
    fclose(fp);


    // Open the shop to read the available inventory details
    fp = fopen("shop.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    // Load the details from file to shop_str
    while (!feof(fp))
    {
        for (index = 0; index < shop_col; index++) {
            fscanf(fp, "%s ", shop_str[key_index][index]);
        }
        key_index++;
    }
    key_index=0;
    fclose(fp);

//    printf("1\n");


    ///------------------------------------------------------End of shop-------------------------------------------------


    ///------------------------------------------------------End of customer-------------------------------------------------


    //check whether customer.txt file is empty or not.
    file_status = file_empty_check("customer.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether customer_prop.txt file is empty or not.
    file_status = file_empty_check("customer_prop.txt");
    if (file_status == FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    //check whether customer_number.txt file is empty or not
    file_status = file_empty_check("customer_number.txt");
    if (file_status  ==  FILE_EMPTY_ERROR)
    {
        return FAILURE;
    }

    // Open the customer_number file to read the number of keywords
    fp = fopen("customer_number.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    fscanf(fp, "%d", &customer_row);
    if (customer_row <= 0)
    {
        return FAILURE;
    }
    fclose(fp);

    // Open the customer_prop file to read the number of properties
    fp = fopen("customer_prop.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    fscanf(fp, "%d", &customer_col);
    if (customer_col <= 0)
    {
        return FAILURE;
    }
    fclose(fp);


    // Open the customer to read the available inventory details
    fp = fopen("customer.txt", "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    // Load the details from file to main memory
    while (!feof(fp))
    {
        for (index = 0; index < customer_col; index++)
        {
            fscanf(fp, "%s ", customer_str[key_index][index]);
        }
        key_index++;
    }
    key_index=0;
    fclose(fp);

//    printf("1\n");

    ///----------------------------------------------------End of customer----------------------------------------------

    return SUCCESS;
}




//Function:     employee_memory_deallocation
//Description:  deallocates all the memory allocated for employee string
//Input param:  NULL
//Return Type:  NULL
void employee_memory_deallocation()
{
    // Local variables
    int index1;
    int index2;

    key_size = key_size + employee_row;
    property_size = property_size + employee_col;
    for (index1 = 0; index1 < property_size; index1++)
    {
        for (index2 = 0; index2 < key_size; index2++)
        {
            free(employee_str[index1][index2]);
        }
        free(employee_str[index1]);
    }
    free(employee_str);
}


//Function:     shop_memory_deallocation
//Description:  deallocates all the memory allocated for shop string
//Input param:  NULL
//Return Type:  NULL
void shop_memory_deallocation()
{
    // Local variables
    int index1;
    int index2;

    key_size = key_size + shop_row;
    property_size = property_size + shop_col;
    for (index1 = 0; index1 < property_size; index1++)
    {
        for (index2 = 0; index2 < key_size; index2++)
        {
            free(shop_str[index1][index2]);
        }
        free(shop_str[index1]);
    }
    free(shop_str);
}


//Function:     customer_memory_deallocation
//Description:  deallocates all the memory allocated for customer string
//Input param:  NULL
//Return Type:  NULL
void customer_memory_deallocation()
{
    // Local variables
    int index1;
    int index2;

    key_size = key_size + customer_row;
    property_size = property_size + customer_col;
    for (index1 = 0; index1 < property_size; index1++)
    {
        for (index2 = 0; index2 < key_size; index2++)
        {
            free(customer_str[index1][index2]);
        }
        free(customer_str[index1]);
    }
    free(customer_str);
}




//Function:     dump
//Description:  dumps all the string values back to their respective files
//Input param:  NULL
//Return Type:  NULL
int dump()
{
    // Local variables
    int spec_index;
    int key_index;

    // File pointer
    FILE *fp;
    FILE *tfp;

    // Open the file in write mode and dump the latest key count
    fp = fopen("employee_number.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "employee_number.txt\n");
        fprintf(tfp, "%d", employee_row);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", employee_row);
    fclose(fp);

    // Open the file in write mode and dump the latest properties count
    fp = fopen("employee_prop.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "employee_prop.txt\n");
        fprintf(tfp, "%d", employee_col);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", employee_col);
    fclose(fp);

    // Open the inventory file and update the values from the main memory
    // Into the secondary storage
    fp = fopen("employee.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "inventory_file.txt\n");
        for (spec_index = 0; spec_index <= employee_row; spec_index++)
        {
            for (key_index = 0; key_index <= employee_col; key_index++)
            {
                fprintf(tfp, "%s ", employee_str[spec_index][key_index]);
            }
            fprintf(tfp, "%s", "\n");
        }
        fclose(tfp);
        return FAILURE;
    }

    for (spec_index = 0; spec_index <= employee_row; spec_index++)
    {
        for (key_index = 0; key_index <= employee_col; key_index++)
        {
            fprintf(fp, "%s ", employee_str[spec_index][key_index]);
        }
        fprintf(fp, "%s", "\n");
    }
    fclose(fp);

    // Free the memory for inventory
    employee_memory_deallocation();

    ///------------------------------------------------------------------------


    // Open the file in write mode and dump the latest key count
    fp = fopen("shop_number.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "shop_number.txt\n");
        fprintf(tfp, "%d", shop_row);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", shop_row);
    fclose(fp);

    // Open the file in write mode and dump the latest properties count
    fp = fopen("shop_prop.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "shop_prop.txt\n");
        fprintf(tfp, "%d", shop_col);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", shop_col);
    fclose(fp);

    // Open the inventory file and update the values from the main memory
    // Into the secondary storage
    fp = fopen("shop.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "shop.txt\n");
        for (spec_index = 0; spec_index <= shop_row; spec_index++)
        {
            for (key_index = 0; key_index <= shop_col; key_index++)
            {
                fprintf(tfp, "%s ", shop_str[spec_index][key_index]);
            }
            fprintf(tfp, "%s", "\n");
        }
        fclose(tfp);
        return FAILURE;
    }

    for (spec_index = 0; spec_index <= shop_row; spec_index++)
    {
        for (key_index = 0; key_index <= shop_col; key_index++)
        {
            fprintf(fp, "%s ", shop_str[spec_index][key_index]);
        }
        fprintf(fp, "%s", "\n");
    }
    fclose(fp);

    // Free the memory for inventory
    shop_memory_deallocation();

    ///------------------------------------------------------------------------


    // Open the file in write mode and dump the latest key count
    fp = fopen("customer_number.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "customer_number.txt\n");
        fprintf(tfp, "%d", customer_row);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", customer_row);
    fclose(fp);

    // Open the file in write mode and dump the latest properties count
    fp = fopen("customer_prop.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "customer_prop.txt\n");
        fprintf(tfp, "%d", customer_col);
        fclose(tfp);
        return FAILURE;
    }
    fprintf(fp, "%d", customer_col);
    fclose(fp);

    // Open the inventory file and update the values from the main memory
    // Into the secondary storage
    fp = fopen("customer.txt", "w+");
    if (fp == NULL)
    {
        tfp = fopen("tempfile.txt", "a+");
        fprintf(tfp, "%s", "\nFollowing contents to be added in said file");
        fprintf(tfp, "%s", "customer.txt\n");
        for (spec_index = 0; spec_index <= customer_row; spec_index++)
        {
            for (key_index = 0; key_index <= customer_col; key_index++)
            {
                fprintf(tfp, "%s ", customer_str[spec_index][key_index]);
            }
            fprintf(tfp, "%s", "\n");
        }
        fclose(tfp);
        return FAILURE;
    }

    for (spec_index = 0; spec_index <= customer_row; spec_index++)
    {
        for (key_index = 0; key_index <= customer_col; key_index++)
        {
            fprintf(fp, "%s ", customer_str[spec_index][key_index]);
        }
        fprintf(fp, "%s", "\n");
    }
    fclose(fp);

    // Free the memory for inventory
    customer_memory_deallocation();


    return SUCCESS;
}






///-------------------------------------------File management---------------------------------------------------------------

///-------------------------------------------Start of algo---------------------------------------------------------------


//Function:     dsuroot
//Description:  returns the parent of a given node
//Input param:  int
//Return Type:  int
int dsuroot(int a)
{
    while(arr[a]!=a)
    {
        arr[a]=arr[arr[a]];
        a=arr[a];
    }
    return a;
}


//Function:     dsufind
//Description:  finds if the two nodes have the same parent or not
//Input param:  int , int
//Return Type:  int
int dsufind(int a,int b)
{
    if(dsuroot(a)==dsuroot(b))
    {
        return 1;
    }
    return 0;
}


//Function:     dsuinitialize
//Description:  initializes the dsu array and dsu size array
//Input param:  NULL
//Return Type:  NULL
void dsuinitialize()
{
    int i=0;
    for(i=0;i<SIZE;i++)
    {
        arr[i]=i;
        dsusize[i]=1;
    }
}


//Function:     dsuunion
//Description:  performs union operation between the given nodes
//Input param:  int , int
//Return Type:  NULL
void dsuunion(int a,int b)
{
    int root_a=dsuroot(a);
    int root_b=dsuroot(b);
    if(dsusize[root_a]>dsusize[root_b])
    {
        arr[root_b]=arr[root_a];
        dsusize[root_a]+=dsusize[root_b];
    }
    else
    {
        arr[root_a]=arr[root_b];
        dsusize[root_b]+=dsusize[root_a];
    }
}


//Function:     KMPsearch
//Description:  Performs kmp string search algorithm and returns if string pat is present in string txt
//Input param:  char* , char*
//Return Type:  int
int KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *) malloc(sizeof(int) * M);
    int j = 0;
    computeLPSArray(pat, M, lps);
    int i = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            return 1;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
    free(lps);
    return 0;
}


//Function:     computeLPSArray
//Description:  computes the lps array required to perform kmp search
//Input param:  char* , int , int*
//Return Type:  NULL
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    int i;
    lps[0] = 0;
    i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}





///-------------------------------------------End of algo---------------------------------------------------------------

///---------------------------------------------Start of employee-------------------------------------------------------



//Function:     new_employee
//Description:  creates a new employee node and fills its data and returns the node created
//Input param:  char* , char*
//Return Type:  struct employee*
struct employee* new_employee(char* ename,char* id)
{
    struct employee* temp=(struct employee*)malloc(sizeof(struct employee));
    strcpy(temp->name,ename);
    strcpy(temp->employee_id,id);

    temp->next=NULL;
    return temp;
}

//Function:     load_to_struct_employee
//Description:  inserts all the values of employees from the employee string to a linked list
//Input param:  struct* employee , char[][][] , int
// Return Type: struct employee*
struct employee* load_to_struct_employee(struct employee* employee_root_fun,char employee_database[][2][40],int employee_number)
{
    for(int i=0; i<employee_number; i++)
    {
        char employee_name_fun[40];
        char id[40];

        strcpy(employee_name_fun,employee_database[i][0]);
        strcpy(id,employee_database[i][1]);

        employee_root_fun=employee_insert(employee_root_fun,employee_name_fun,id);
//        printf("1\n");
    }
    return employee_root_fun;
}


//Function:     employee_insert
//Description:  adds the value to the front of the linked list
//Input param:  struct employee* , char* , char*
//Return Type:  struct employee*
struct employee* employee_insert(struct employee* node, char* name, char* id)
{
    struct employee* temp=new_employee(name,id);
    temp->next=node;
    return temp;
}


//Function:     search_employee
//Description:  displays the details of the employee by searching using employee id and performing KMP search on it
//Input param:  NULL
//Return Type:  NULL
void search_employee()
{
    char s[10];     /// First 2 shop_id and last 4 employee id
    printf("\n");
    printf("Enter the employee id : ");
    char x;
    scanf("%s",s);
    struct employee* node=employee_root;
    while(node!=NULL)
    {
        if(KMPSearch(s,node->employee_id))
        {
            printf("\n");
            printf("Employee name : %s",node->name);
            printf("\n");
            printf("Employee id : %s",node->employee_id);
            printf("\n");
            printf("Shop id : %c%c",node->employee_id[0],node->employee_id[1]);
            printf("\n");
            printf("Verification done sucessfully\n");
            return;
        }
        node=node->next;
    }
    printf("\n");
    printf("Employee not found");
    printf("\n");
}


///---------------------------------------------End of employee-------------------------------------------------------


///--------------------Start of Customer------------------------------------------------------------------

//Function:     new_customer
//Description:  creates and returns a node of type struct customer* to insert in the AVL tree
//Input param:  char* , ling long int , char* , char* , float
//Return Type:  struct customer*
struct customer* new_customer(char* name,long long int id_trans, char* date, char* id_shop,float amount)
{
    struct customer* temp=malloc(sizeof(struct customer));
    strcpy(temp->customer_name,name);
    temp->trans_id = id_trans;
    strcpy(temp->date,date);
    strcpy(temp->shop_id,id_shop);
    temp->amount=amount;

    temp->height=1;
    temp->lchild=temp->rchild=NULL;
    return temp;
}


//Function:     height
//Description:  returns the height of a specific node
//Input param:  struct customer*
//Return Type:  int
int height(struct customer* c)
{
    if(c==NULL)
    {
        return 0;
    }
    else
    {
        return c->height;
    }
}


//Function:     max
//Description:  find the maximum between two functions
//Input param:  int , int
//Return Type:  int
int max(int a, int b)
{
    return (a>b)? a : b;
}


//Function:     lr
//Description:  It performs lr rotation on the AVL tree
//Input param:  struct customer*
//Return Type:  struct customer*
struct customer* lr(struct customer* c)
{
    struct customer *y = c->rchild;
    struct customer *temp = y->lchild;

    y->lchild = c;
    c->rchild = temp;
    c->height = max(height(c->lchild), height(c->rchild))+1;
    y->height = max(height(y->lchild), height(y->rchild))+1;

    return y;
}

//Function:     rr
//Description:  it performs rr rotation on the AVL tree
//Input param:  struct* customer
//Return Type:  struct* customer
struct customer* rr(struct customer* c)
{
    struct customer *x = c->lchild;
    struct customer *temp = x->rchild;

    x->rchild = c;
    c->lchild = temp;
    c->height = max(height(c->lchild), height(c->rchild))+1;
    x->height = max(height(x->lchild), height(x->rchild))+1;
    return x;
}


//Function:     get_balance
//Description:  it computes the balance factor of a given nodo
//Input param:  struct customer*
//Return Type:  int
int get_balance(struct customer* c)
{
    if(c==NULL)
    {
        return 0;
    }
    return height(c->lchild)-height(c->rchild);
}


//Function:     customer_insert
//Description:  it inserts a new node in the AVL tree
//Input param:  struct customer* , char* , long long int , char* , char* , float
//Return Type:  struct customer*
struct customer* customer_insert(struct customer* node, char* name,long long int id_trans, char* date, char* id_shop,float amount)
{
    if (node == NULL)
    {
        return (new_customer(name, id_trans, date, id_shop, amount));
    }

    if (id_trans < node->trans_id)
    {
        node->lchild = customer_insert(node->lchild, name, id_trans, date, id_shop, amount);
    }
    else if (id_trans > node->trans_id)
    {
        node->rchild = customer_insert(node->rchild, name, id_trans, date, id_shop, amount);
    }
    else
    {
        return node;
    }


    node->height = 1 + max(height(node->lchild),height(node->rchild));


    int balance = get_balance(node);


    if (balance > 1 && id_trans < node->lchild->trans_id)
    {
        return rr(node);
    }


    if (balance < -1 && id_trans > node->rchild->trans_id)
    {
        return lr(node);
    }


    if (balance > 1 && id_trans > node->lchild->trans_id)
    {
        node->lchild =  lr(node->lchild);
        return rr(node);
    }


    if (balance < -1 && id_trans < node->rchild->trans_id)
    {
        node->rchild = rr(node->rchild);
        return lr(node);
    }

    return node;
}


//Function:     string_to_ll
//Description:  it converts the given string to long long int and returns it
//Input param:  char*
//Return Type:  long long int
long long int string_to_ll(char* string)
{
    int size=strlen(string);
    long long int t=1,ans=0;
    for(long long int i=size-1;i>=0;i--)
    {
        ans+=t*(string[i]-'0');
        t*=10;
    }
    return ans;
}


//Function:     string_to_float
//Description:  it converts a given string to float and returns it
//Input param:  char*
//Return Type:  float
float string_to_float(char* string)
{
    char* pend;

    float f=strtof(string,&pend);   //inbuilt c11 function to convert string representation of float to float

    return f;
}



//Function:     load_to_struct_customer
//Description:  it loads all the values of the customer string to the AVL tree
//Input param:  struct customer* , char[][][] , int
//Return Type:  struct customer*
struct customer* load_to_struct_customer(struct customer* customer_root_fun,char customer_database[][5][30],int customer_number)
{
    for(int i=0; i<customer_number; i++)
    {
        char customer_name[30];
        long long int trans_id;
        char date[30];
        char shop_id[30];
        float amount;

        strcpy(customer_name,customer_database[i][0]);
        trans_id=string_to_ll(customer_database[i][1]);
        strcpy(date,customer_database[i][2]);
        strcpy(shop_id,customer_database[i][3]);
        amount=string_to_float(customer_database[i][4]);

        customer_root_fun=customer_insert(customer_root_fun,customer_name,trans_id,date,shop_id,amount);
    }
    return customer_root_fun;
}



//Function:     binary_search
//Description:  it searches the element in the balanced binary tree and displays the informations
//Input param:  struct customer* , long long int
//Return Type:  NULL
void binary_search(struct customer* node,long long int id)
{
    if(node==NULL)
    {
        printf("\n");
        printf("Wrong transaction id");
        printf("\n");
        return;
    }
    else if(node->trans_id==id)
    {
        printf("\n");
        printf("Customer with transaction id:%lld",id);
        printf("\n");
        printf("Customer Name : %s",node->customer_name);
        printf("\n");
        printf("Date : %s",node->date);
        printf("\n");
        printf("Amount : %f",node->amount);
        printf("\n");
        printf("Shop id : %s",node->shop_id);
        printf("\n");
        return;
    }
    else if(node->trans_id<id)
    {
        binary_search(node->rchild,id);
    }
    else
    {
        binary_search(node->lchild,id);
    }
}


//Function:     search_customer_trans_id
//Description:  it takes the transaction id that is to be searched and calls the binary search function on it
//Input param:  NULL
//Return Type:  NULL
void search_customer_trans_id()
{
    long long int tran=0;
    printf("\n");
    printf("Enter the transaction id to be searched:");
    scanf("%lld",&tran);
    binary_search(customer_root,tran);
}
///--------------------End of Customer------------------------------------------------------------------



///---------------------------------------------Start of Shop-------------------------------------------------------



//Function:     group_shops
//Description:  it groups the shops using dsu union
//Input param:  NULL
//Return Type:  NULL
void group_shops()
{
    dsuinitialize();
    dsuunion(1,2);
    dsuunion(1,3);
    dsuunion(1,4);
    dsuunion(1,5);
    dsuunion(1,6);
    dsuunion(1,7);
    dsuunion(1,8);
    dsuunion(1,9);
    dsuunion(1,10);
    dsuunion(11,12);
    dsuunion(11,13);
    dsuunion(11,14);
    dsuunion(11,15);
    dsuunion(11,16);
    dsuunion(11,17);
    dsuunion(11,18);
    dsuunion(11,19);
    dsuunion(11,20);
    dsuunion(21,22);
    dsuunion(21,23);
    dsuunion(21,24);
    dsuunion(21,25);
    dsuunion(21,26);
    dsuunion(21,27);
    dsuunion(21,28);
    dsuunion(21,29);
    dsuunion(21,30);
    dsuunion(31,32);
    dsuunion(31,33);
    dsuunion(31,34);
    dsuunion(31,35);
    dsuunion(31,36);
    dsuunion(31,37);
    dsuunion(31,38);
    dsuunion(31,39);
    dsuunion(31,40);
    dsuunion(41,42);
    dsuunion(41,43);
    dsuunion(41,44);
    dsuunion(41,45);
    dsuunion(41,46);
    dsuunion(41,47);
    dsuunion(41,48);
    dsuunion(41,49);
    dsuunion(41,50);

    load_to_direct_adressing_table();
}


//Function:     load_to_direct_addressing_table
//Description:  it allots the block of its parent of each set and strore it in an array
//Input param:  NULL
//Return Type:  NULL
void load_to_direct_adressing_table()
{
    block_number[1]=1;
    block_number[2]=11;
    block_number[3]=21;
    block_number[4]=31;
    block_number[5]=41;
}


//Function:     search_shop
//Description:  Searches the shop using dsu by finding the block of the shop number of its parent
//Input param:  NULL
//Return Type:  NULL
void search_shop()
{
    int number;
    int res_block=0;
    int parent=0;
    printf("\n");
    printf("Enter the shop to be searched : ");
    scanf("%d",&number);
    printf("\n");
    parent=dsuroot(number);
    for(int i=1;i<=5;i++)
    {
        if(parent==dsuroot(block_number[i]))
        {
            res_block=i;
            break;
        }
    }
    if(res_block==0)
    {
        printf("\n");
        printf("Wrong shop number entered");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Shop located in block : %d",res_block);
        printf("\n");
    }
}



//Function:     Print shop details
//Description:  It prints the information about all the shops in the mall
//Input param:  void
//Return Type:  void
void print_shop_details()
{
    printf("\n");
    printf("Shop name    Shop ID    Block    Type    Contract start from    contract upto");
    printf("\n");
    for(int i=0;i<shop_row;i++)
    {
        for(int j=0;j<shop_col;j++)
        {
            printf("%s    ",shop_str[i][j]);
        }
        printf("\n");
    }
}





///---------------------------------------------End of Shop-------------------------------------------------------



///---------------------------------------------Start of Parking-------------------------------------------------------


//Function:     initialize_hash
//Description:  it initializes the value of all the hash table flags with 0 making them empty
//Input param:  NULL
//Return Type:  NULL
void initialize_hash()
{
    int i=0;

    for(i=0;i<SIZE_P;i++)
    {
        parking_hash[i].flag=0;
    }

}



//Function:     string_to_int
//Description:  it converts a given string to integer and returns the value
//Input param:  char8
//Return Type:  int
int string_to_int(char* string)
{
    int size=0;
    size=strlen(string);
    int t=1;
    int ans=0;
    int i=0;
    for(i=size-1;i>=0;i--)
    {
        int x=0;
        x=t*(string[i]-'0');
        ans+=x;
        t*=10;
    }

    return ans;
}



//Function:     hash
//Description:  it finds the hash value for a given number
//Input param:  int
//Return Type:  int
int hash(int key)
{
    int ans=0;
    ans=key%SIZE_P;
    return ans;
}



//Function:     probe_parking
//Description:  it finds a parking space in the parking lot which is empty
//Input param:  int
//Return Type:  int
int probe_parking(int key)
{
    int index=0;
    index=hash(string_to_int(parking_hash[key].number));
    int i=0;

    int terminate=0;
    terminate=(index+i)%SIZE_P;

    while(parking_hash[(index+i)%SIZE_P].flag != 0)
    {
        i++;
        if(i==terminate)
        {
            return  -1;
        }
    }
    return (index+i)%SIZE_P;
}


//Function:     insert_parking
//Description:  it inserts all the parking vehicles into the parking hash array
//Input param:  NULL
//Return Type:  NULL
void insert_parking()
{
    int x=0;
    char car_number[20];
    char entry_time[20];
    while(1)
    {
        printf("\n");
        printf("0->Exit");
        printf("\n");
        printf("1->Vehicle entry");
        printf("\n");
        scanf("%d",&x);
        if(x==0)
        {
            break;
        }
        printf("\n");
        printf("Enter the car number : ");
        scanf("%s",car_number);
        printf("Enter the entry time : ");
        scanf("%s",entry_time);
        int y=0;
        y=hash(string_to_int(car_number));
        int z=0;
        z=probe_parking(y);
        if(z==-1)
        {
            printf("\n");
            printf("No parking space available");
            printf("\n");
        }
        else
        {
            strcpy(parking_hash[z].number,car_number);
            strcpy(parking_hash[z].entry_time,entry_time);
            parking_hash[z].flag=1;
            printf("\n");
            printf("Your parking slot number is : %d",z);
            printf("\n");
        }
    }
}



//Function:     Search_parking
//Description:  it verifies for a car which is present in the parking lot or not
//Input param:  int
//Return Type:  NULL
void search_parking(int key)
{
    if(parking_hash[key].flag==0)
    {
        printf("\n");
        printf("Wrong key entered");
        printf("\n");
        return;
    }
    printf("\n");
    printf("Vehicle space cleared successfully....");
    printf("\n");
    parking_hash[key].flag=0;
}


//Function:     generate_parking_ticket
//Description:  it inserts all the values from the parking string to the parking hash array
//Input param:  NULL
//Return Type:  NULL
void generate_parking_ticket()
{
    insert_parking();
}



//Function:     verify_parking_ticket
//Description:  it verifies if a vehicle with some phash value exists in the parking lot or not
//Input param:  struct customer*
//Return Type:  int
void verify_parking_ticket()
{
    int x=0;

    printf("\n");
    printf("Enter the key : ");
    scanf("%d",&x);
    printf("\n");
    search_parking(x);
}

///---------------------------------------------End of Parking-------------------------------------------------------