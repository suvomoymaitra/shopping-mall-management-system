#ifndef COURSEPROJECT_SHOPPINGMALL_H
#define COURSEPROJECT_SHOPPINGMALL_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>



struct employee
{
    char name[40];
    char employee_id[40];
    struct employee* next;
};


struct shop
{
    char shop_name[30];
    int shop_id;
    int block;
    char type[30];
    char contract_start_from[30];
    char contract_upto[30];
};


struct customer
{
    char customer_name[30];
    long long int trans_id;
    char date[30];
    char shop_id[30];
    float amount;
    int height;
    struct customer *lchild;
    struct customer *rchild;
};


struct parking
{
    char number[10];
    char entry_time[10];
    int flag;    /// 0 when it is empty and 1 when it is filled
};



char employee_str[30][2][40];
char shop_str[30][6][30];
char customer_str[50][5][30];



struct employee* employee_root=NULL;
struct shop* shop_root=NULL;
struct customer* customer_root=NULL;
struct parking parking_hash[30];



int arr[2000];
int dsusize[2000];
int block_number[10];


int load();
int file_empty_check(char*);
void employee_memory_deallocation();
void shop_memory_deallocation();
void customer_memory_deallocation();
int dump();

struct employee* load_to_struct_employee(struct employee*,char[][2][40],int);
struct customer* load_to_struct_customer(struct customer*,char[][5][30],int);
struct employee* new_employee(char*,char*);
struct customer* new_customer(char*,long long int,char*,char*,float);
struct customer* insert(struct customer*,char*,long long int,char*,char*,float);
int height(struct customer*);
int max(int,int);
struct customer* lr(struct customer*);
struct customer* rr(struct customer*);
int get_balance(struct customer*);
long long int string_to_ll(char*);
float string_to_float(char*);
void search_customer_trans_id();
void binary_search(struct customer*,long long int);
struct employee* employee_insert(struct employee*,char*,char*);
struct customer* customer_insert(struct customer*,char*,long long int,char*,char*,float);
void search_employee();
int string_to_int(char*);
int hash(int);
int probe_parking(int);
void insert_parking();
void search_parking(int);
void generate_parking_ticket();
void verify_parking_ticket();
void group_shops();
void search_shop();
void load_to_direct_adressing_table();
int dsuroot(int);
int dsufind(int,int);
void dsuinitialize();
void dsuunion(int,int);
void computeLPSArray(char*,int,int*);
int KMPSearch(char*,char*);
void print_shop_details();
void initialize_hash();
void print_all();

#endif //COURSEPROJECT_SHOPPINGMALL_H