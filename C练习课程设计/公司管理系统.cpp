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
	printf("   ����~~���Ϻ�ѽ����ʲô���ԷԸ��������ȵ���           \n");
	printf("            һ.����Ա���Ĺؼ���Ϣ\n");
	printf("            ��.���ӹ����Ƽ����޹�˾��ȫ��Ա��\n");
	printf("            ��.��˾Ա����ְλ�ֲ�\n");
	printf("            ��.��ƸԱ��\n");
	printf("            ��.����Ա��\n");
	printf("            ��.���빫˾Redis���ݿ�\n");
	printf("            ��.�ӻ������ݿ�����ȡ����\n");
	printf("            ��.�����ˣ�Ҫȥ���������Ա��������ȥ�ˣ�����\n");
	printf("            ��.��ѯ����\n");
	printf("\n");
	printf("                ���ˣ�����������Զ�������      ");
	do
	{
		printf("         ��ѡ�����(1-9):");
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
		printf("������ʼ¼����Ϣ\n");
		printf("����Ա���ĵ��Ӻ��ƣ�",N->id);
		scanf("%s", N->id);
		printf("\n");
		if(N->id[0]=='@')
		printf("\n");
		printf("����Ա�������֣�");
		scanf("%s", N->name);
		printf("\n");
		printf("����Ա�������䣺");
		scanf("%s", N->age);
		printf("\n");
		printf("����Ա���Ĺ��ʣ�");
		scanf("%s", N->money);
		printf("\n");
		printf("����Ա����ְλ��");
		scanf("%s", N->place);
		printf("\n");
		printf("����ɹ�����");
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
		printf("\n    ���ˣ��㻹û�м��������~~��\n");
	}
	else {
		printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf(" Ա������     ����        ����         ��н              ְλ      \n");

		while (p != NULL)
		{
			i++;
			printf(" %s         %s         %s        %s           %s        \n",p->id,p->name,p->age,p->money,p->place);
			
			p = p->next;
		}
		printf(" .......................................................\n");
		printf("��Ϊ���˲�ѯ��%d��Ա����Ϣ\n", i);
	}
}
M *sort(M* h)
{
	M *p;
	int c=0;                      	
	char s[15];                    	
	printf("��������Ҫ���ҵ�ְλ:\n");
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
    printf("��%s��������%d\n",s,c);
    c=0;
    return h;	
}
void search(M *h)
{
	M *p;                      	
	char s[15];                    	
	printf("��������Ҫ���ҵ�Ա������:\n");
	scanf("%s",s);                   
	p=h;                             
	while(p!=NULL&&strcmp(p->name,s))
		p=p->next;                   
	if(p==NULL)                      
		printf("\n��Ҫ���ҵ���%s�����ź������޴��ˣ�\n",s);
	    else                             
	    {  
	    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	    printf(" Ա������     ����        ����         ��н              ְλ      \n");
	    printf(" %s         %s         %s        %s           %s        \n",p->id,p->name,p->age,p->money,p->place);
	    printf(" .......................................................\n");
		
	}
}
M *insert(M* h)
{
	M *N;
	printf("\n������¼�¼��\n");
	N=(M *)malloc(sizeof(M));
	
		printf("������ʼ¼����Ϣ\n");
		printf("����Ա���ĵ��Ӻ��ƣ�",N->id);
		scanf("%s", N->id);
		printf("\n");
		if(N->id[0]=='@')
		printf("\n");
		printf("����Ա�������֣�");
		scanf("%s", N->name);
		printf("\n");

		printf("����Ա�������䣺");
		scanf("%s", N->age);
		printf("\n");

		printf("����Ա���Ĺ��ʣ�");
		scanf("%s", N->money);
		printf("\n");

		printf("����Ա����ְλ��");
		scanf("%s", N->place);
		printf("\n");
		
		N->next=NULL;
		N->next=h;
		h=N;
		
		printf("�³�Ա����Ϣ����ɹ�������");
	
	return h;
}
M *delete1(M* h)
{	
	return 0;
}
void save(M *h)
{
   FILE *fp;                                      /*����ָ���ļ���ָ��*/
   M *p;                                    /*�����ƶ�ָ��*/
   char outfile[20];                              /*��������ļ���*/
   printf("�����뵼���ļ���:");
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
	   printf("-----�Ѿ��ɹ��������ļ�%s��!-----\n",outfile); 
}
M *load()
{
   M *p,*q,*h=NULL;                      
   FILE *fp;                                   
   char infile[20];                     
   printf("�����뵼���ļ�����");
   scanf("%s",infile);                         
   if((fp=fopen(infile,"rb"))==NULL)              
   {  
		printf("�ļ���ʧ�ܣ�\n");             
		return h;
   }
   p=(M *)malloc(sizeof(M));       
   if(!p)
   {  
		printf("�ڴ����ʧ��!\n");                
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
			 printf("�ڴ����ʧ��!\n");            
			 return h;
		}
		q=p;                                        
		p=p->next;                                  
	}
	q->next=NULL;                                  
	fclose(fp);                                  
	printf("�Ѿ��ɹ����ļ�%s��������!!!\n",infile);
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
