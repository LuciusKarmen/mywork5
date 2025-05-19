#include <stdio.h>    
#include <malloc.h>   
#include <stdlib.h>    
#include <string.h>
typedef struct man
{
	char id[11];
	char name[15];
	char age[10];
	char money[10];
	char place[20];
	struct man* next;

}M;
int menu()
{
	char s[2];
	int c;
	printf("   主人~~早上好呀！有什么可以吩咐卡特琳娜的吗           \n");
	printf("            一.输入员工的关键信息\n");
	printf("            二.审视光明科技有限公司的全体员工\n");
	printf("            三.公司员工的职位分布\n");
	printf("            四.新聘员工\n");
	printf("            五.开除员工\n");
	printf("            六.读入公司Redis数据库\n");
	printf("            七.从机密数据库中提取数据\n");
	printf("            八.我累了，要去卷《黑马程序员》的网课去了，爱你\n");
	printf("            九.查询功能\n");
	printf("\n");
	printf("                主人，卡特琳娜永远在你身边      ");
	do
	{
		printf("         请选择操作(1-9):");
		scanf("%s", s);
		c = atoi(s);
	} while (c < 0 || c>9);
	return(c);
}
M *create()
{
	M* h = NULL, * N;
	for (;;)
	{
		N = (M*)malloc(sizeof(M));
		if (!N)
		{
			printf("4040404040404");
		}
		printf("请您开始录入信息\n");
		printf("输入员工的电子号牌：",N->id);
		scanf("%s", N->id);
		printf("\n");
		if(N->id[0]=='@')
		printf("\n");
		printf("输入员工的名字：");
		scanf("%s", N->name);
		printf("\n");
		printf("输入员工的年龄：");
		scanf("%s", N->age);
		printf("\n");
		printf("输入员工的工资：");
		scanf("%s", N->money);
		printf("\n");
		printf("输入员工的职位：");
		scanf("%s", N->place);
		printf("\n");
		printf("输入成功！！");
		N->next = h;
		h = N;
		return h;
	}
}
void print(M* h)
{
	int i = 0;
	M* p;
	p = h;
	if (p == NULL)
	{
		printf("\n    主人，你还没有加上数据嗷~~！\n");
	}
	else {
		printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf(" 员工号码     姓名        年龄         月薪              职位      \n");

		while (p != NULL)
		{
			i++;
			printf(" %s         %s         %s        %s           %s        \n",p->id,p->name,p->age,p->money,p->place);
			
			p = p->next;
		}
		printf(" .......................................................\n");
		printf("共为主人查询到%d条员工信息\n", i);
	}
}
M *sort(M* h)
{
	M *p;
	int c=0;                      	
	char s[15];                    	
	printf("请输入您要查找的职位:\n");
	scanf("%s",s);                   
	p=h;                             
	while(p!=NULL)
	{
		if(strcmp(p->place,s)==0){
		p=p->next; 
		c++;
		}
		else
		{
			p=p->next;
		}
    }
    printf("干%s的数量是%d\n",s,c);
    c=0;
    return h;	
}
void search(M *h)
{
	M *p;                      	
	char s[15];                    	
	printf("请输入您要查找的员工姓名:\n");
	scanf("%s",s);                   
	p=h;                             
	while(p!=NULL&&strcmp(p->name,s))
		p=p->next;                   
	if(p==NULL)                      
		printf("\n您要查找的是%s，很遗憾，查无此人！\n",s);
	    else                             
	    {  
	    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	    printf(" 员工号码     姓名        年龄         月薪              职位      \n");
	    printf(" %s         %s         %s        %s           %s        \n",p->id,p->name,p->age,p->money,p->place);
	    printf(" .......................................................\n");
		
	}
}
M *insert(M* h)
{
	M *N;
	printf("\n请添加新记录！\n");
	N=(M *)malloc(sizeof(M));
	
		printf("请您开始录入信息\n");
		printf("输入员工的电子号牌：",N->id);
		scanf("%s", N->id);
		printf("\n");
		if(N->id[0]=='@')
		printf("\n");
		printf("输入员工的名字：");
		scanf("%s", N->name);
		printf("\n");

		printf("输入员工的年龄：");
		scanf("%s", N->age);
		printf("\n");

		printf("输入员工的工资：");
		scanf("%s", N->money);
		printf("\n");

		printf("输入员工的职位：");
		scanf("%s", N->place);
		printf("\n");
		
		N->next=NULL;
		N->next=h;
		h=N;
		
		printf("新成员的信息输入成功！！！");
	
	return h;
}
M *delete1(M* h)
{	
	return 0;
}
void save(M *h)
{
   FILE *fp;                                      /*定义指向文件的指针*/
   M *p;                                    /*定义移动指针*/
   char outfile[20];                              /*保存输出文件名*/
   printf("请输入导出文件名:");
   scanf("%s",outfile);
   fp=fopen(outfile,"wb");
	p=h;                                    
	   while(p!=NULL)                             
	   {
		  fprintf(fp, "%s  ", p->id);
		  fprintf(fp, "%s  ", p->name);
		  fprintf(fp, "%s  ", p->age);
		  fprintf(fp, "%s  ", p->money);
		  fprintf(fp, "%s\n", p->place);    
		  p=p->next;                           
	   }
	   fclose(fp);                              
	   printf("-----已经成功保存至文件%s中!-----\n",outfile); 
}
M *load()
{
   M *p,*q,*h=NULL;                      
   FILE *fp;                                   
   char infile[20];                     
   printf("请输入导入文件名，");
   scanf("%s",infile);                         
   if((fp=fopen(infile,"rb"))==NULL)              
   {  
		printf("文件打开失败！\n");             
		return h;
   }
   p=(M *)malloc(sizeof(M));       
   if(!p)
   {  
		printf("内存分配失败!\n");                
		return h;                                 
   }
   h=p;                                           
   while(!feof(fp))                              
   {
	   if(1!=fread(p,sizeof(M),1,fp))
			break;                                  
		p->next=(M *)malloc(sizeof(M)); 
		if(!p->next)
		{
			 printf("内存分配失败!\n");            
			 return h;
		}
		q=p;                                        
		p=p->next;                                  
	}
	q->next=NULL;                                  
	fclose(fp);                                  
	printf("已经成功从文件%s导入数据!!!\n",infile);
	return h;                                     
}
int main()
{
	M* head = NULL;       
	system("color 3e");       
	for (;;)					
	{
		switch (menu())  
		{
		case 1: head = create(); break;       
		case 2: print(head); break;         
		case 3: head = sort(head); break;     
		case 4: head = insert(head); break;	 
		case 5: head = delete1(head); break;   
		case 6: save(head); break;          
		case 7: head = load(); break;         
		case 8: exit(0);    
		case 9: search(head);break;            
		}
	}
}
